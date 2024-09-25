#!/usr/bin/python3
# -*- coding: UTF-8 -*-

import os, sys, argparse, traceback, hashlib
from datetime import date

def show_exception_and_exit(exc_type, exc_value, tb):
    traceback.print_exception(exc_type, exc_value, tb)
    sys.exit(-1)

def gen_tokens(string):
    pos = 0

    string = string.strip()

    while len(string) > 0:
        if string[0] == '"':
            pos = string.find('"', 1)

            if pos < 0:
                yield string[1:]
                break

            yield string[1:pos]
            string = string[(pos+2):]

        else:
            pos = string.find(' ', 1)

            if pos < 0:
                yield string[:]
                break

            yield string[0:pos]
            string = string[(pos+1):]

        string = string.strip()

class GfxEntry:
    def __init__(self, line):
        self.duration = 0
        self.fPath = ''
        self.hash = 0

        tokens = gen_tokens(line)

        try:
            self.duration = next(tokens)
            self.fPath = next(tokens)

        except StopIteration:
            sys.exit("Not enough components in line `{0}`.".format(line))

        self.hash = abs(hash(os.path.abspath(self.fPath)))

    def list_data_files(self, parentPath):
        realPath = os.path.join(os.path.dirname(parentPath), self.fPath)
        incBase = os.path.splitext(realPath)[0]

        yield incBase + '.img.bin'
        yield incBase + '.map.bin'
        yield incBase + '.pal.bin'

    def gen_event_gfx(self, parentPath):
        realPath = os.path.join(os.path.dirname(parentPath), self.fPath)

        if not os.path.exists(realPath):
            sys.exit("File `{0}` doesn't exist.".format(realPath))

        incBase = os.path.splitext(self.fPath)[0]

        yield '#ifndef EFX_IMG_{0}_INSTALLED\n'.format(self.hash)
        yield '#define EFX_IMG_{0}_INSTALLED\n'.format(self.hash)
        yield 'ALIGN 4\n'
        yield 'IMG_{0}:\n\t#incbin {1}\n'.format(incBase, incBase + '.img.bin')
        yield '#endif\n\n'

        yield '#ifndef EFX_TSA_{0}_INSTALLED\n'.format(self.hash)
        yield '#define EFX_TSA_{0}_INSTALLED\n'.format(self.hash)
        yield 'ALIGN 4\n'
        yield 'TSA_{0}:\n\t#incbin {1}\n'.format(incBase, incBase + '.map.bin')
        yield '#endif\n\n'

        yield '#ifndef EFX_PAL_{0}_INSTALLED\n'.format(self.hash)
        yield '#define EFX_PAL_{0}_INSTALLED\n'.format(self.hash)
        yield 'ALIGN 4\n'
        yield 'PAL_{0}:\n\t#incbin {1}\n'.format(incBase, incBase + '.pal.bin')
        yield '#endif\n\n'

def gen_header():
    yield '/*\n'
    yield ' * Auto generated by efx-anim-creator on {}\n\n'.format(date.today())
    yield ' * struct EfxAnimConf {\n'
    yield ' *     u8 _unused_header[0x150];\n'
    yield ' *     const s16 * frame_confs;\n'
    yield ' *     u16 const *const * tsas;\n'
    yield ' *     u16 const *const * imgs;\n'
    yield ' *     u16 const *const * pals;\n'
    yield ' *     u16 sfx; // default: 0x3D1\n'
    yield ' *     u8 _pad_[2];\n'
    yield ' * };\n'
    yield ' */\n\n'
    yield 'ALIGN 4\n'
    yield 'BYTE 0xF0 0xB5 0x4F 0x46 0x46 0x46 0xC0 0xB4 0x04 0x1C 0x48 0x48 0x03 0x21 0x4A 0x4A 0x00 0xF0 0x88 0xF8 0x07 0x1C 0xFC 0x65 0x00 0x20 0xB8 0x85 0x78 0x64 0x4C 0x48 0xB8 0x64 0x4C 0x48 0xF8 0x64 0x38 0x65 0x4B 0x48 0x78 0x65 0x4B 0x48 0xB8 0x65 0x42 0x4A 0x00 0xF0 0x77 0xF8 0x3E 0x48 0x00 0x21 0x40 0x5E 0x00 0x28 0x12 0xD0 0xF8 0x6D 0x3F 0x4A 0x00 0xF0 0x6E 0xF8 0x00 0x28 0x06 0xD1 0x01 0x20 0x18 0x21 0x00 0x22 0x3C 0x4B 0x00 0xF0 0x67 0xF8 0x05 0xE0 0x01 0x20 0xE8 0x21 0x00 0x22 0x38 0x4B 0x00 0xF0 0x60 0xF8 0xFC 0x6D 0x32 0x4A 0x91 0x46 0x20 0x1C 0x34 0x4B 0x00 0xF0 0x59 0xF8 0xC0 0x00 0x48 0x44 0x06 0x68 0x20 0x1C 0x30 0x4B 0x00 0xF0 0x52 0xF8 0x40 0x00 0x01 0x30 0x80 0x00 0x48 0x44 0x01 0x68 0x20 0x8A 0x20 0x23 0x98 0x46 0x42 0x46 0x10 0x43 0x20 0x82 0x20 0x88 0x08 0x25 0x28 0x43 0x20 0x80 0x30 0x8A 0x10 0x43 0x30 0x82 0x30 0x88 0x28 0x43 0x30 0x80 0x08 0x8A 0x10 0x43 0x08 0x82 0x08 0x88 0x28 0x43 0x08 0x80 0xF8 0x6D 0x23 0x4B 0x00 0xF0 0x33 0xF8 0x04 0x1C 0x1F 0x4B 0x00 0xF0 0x2F 0xF8 0xC0 0x00 0x48 0x44 0x06 0x68 0x20 0x1C 0x1B 0x4B 0x00 0xF0 0x28 0xF8 0x40 0x00 0x01 0x30 0x80 0x00 0x48 0x44 0x01 0x68 0x20 0x8A 0x43 0x46 0x18 0x43 0x20 0x82 0x20 0x88 0x28 0x43 0x20 0x80 0x30 0x8A 0x18 0x43 0x30 0x82 0x30 0x88 0x28 0x43 0x30 0x80 0x08 0x8A 0x18 0x43 0x08 0x82 0x08 0x88 0x05 0x43 0x0D 0x80 0x16 0x48 0x80 0x21 0x49 0x00 0xFA 0x6D 0x02 0x23 0xD2 0x5E 0x01 0x23 0x0D 0x4C 0x00 0xF0 0x07 0xF8 0x18 0xBC 0x98 0x46 0xA1 0x46 0xF0 0xBC 0x04 0xBC 0x10 0x47 0x18 0x47 0x20 0x47 0xC0 0x46 0x18 0x93 0x5D 0x08 0x20 0xE1 0x03 0x02 0x00 0x00 0x00 0x02 0x7D 0x2C 0x00 0x08 0xB1 0x51 0x05 0x08 0x6D 0xA1 0x05 0x08 0x8D 0x14 0x00 0x08 0xB5 0xA2 0x05 0x08 0xA5 0x29 0x07 0x08\n'
    yield 'POIN FRAMEs TSAs IMGs PALs\n'
    yield 'SHORT 0x3D1\n'
    yield 'SHORT 0\n'

def main(args):
    sys.excepthook = show_exception_and_exit

    argParser = argparse.ArgumentParser(description = "")

    argParser.add_argument("input", help = "input list file")

    meg = argParser.add_mutually_exclusive_group()
    meg.add_argument("--list-files", action = 'store_true', help = "print installer dependencies")
    meg.add_argument("-o", "--output", help = "output installer filename")

    arguments = argParser.parse_args()

    if not os.path.exists(arguments.input):
        sys.exit("File `{0}` doesn't exist.".format(arguments.input))

    imgs = []

    with open(arguments.input, 'r') as f:
        for line in f.readlines():
            line = line.strip()

            if (len(line) == 0):
                continue

            if line[0] == '#':
                continue

            imgs.append(GfxEntry(line))

    # Generate dependence
    if arguments.list_files:
        for img in imgs:
            for filename in img.list_data_files(arguments.input):
                print(filename, end = ' ')

    else:
        sys.stdout.writelines('{\n')
        sys.stdout.writelines(gen_header())

        # Generate frame lut
        sys.stdout.writelines('\nFRAMEs:\n')
        for img in imgs:
            sys.stdout.writelines('\tSHORT {0} {1}\n'.format(hex(imgs.index(img)), img.duration))
        sys.stdout.writelines('\tSHORT 0xFFFF\n') # Terminator of frame_lut

        sys.stdout.writelines('\nALIGN 4')

        # Generate image lut
        sys.stdout.writelines('\nIMGs:\n')
        for img in imgs:
            sys.stdout.writelines('\tPOIN IMG_{0}\n'.format(os.path.splitext(img.fPath)[0]))

        # Generate palette lut
        sys.stdout.writelines('\nPALs:\n')
        for img in imgs:
            sys.stdout.writelines('\tPOIN PAL_{0}\n'.format(os.path.splitext(img.fPath)[0]))

        # Generate TSA lut
        sys.stdout.writelines('\nTSAs:\n')
        for img in imgs:
            sys.stdout.writelines('\tPOIN TSA_{0}\n'.format(os.path.splitext(img.fPath)[0]))

        # Insert generated img & tsa & pal
        sys.stdout.writelines('\n')

        for img in imgs:
            sys.stdout.writelines(img.gen_event_gfx(arguments.input))

        sys.stdout.writelines('}\n')

if __name__ == '__main__':
    main(sys.argv[1:])
