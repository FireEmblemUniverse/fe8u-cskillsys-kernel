#include "common-chax.h"
#include "debuff.h"
#include "save-data.h"

struct StatDebuffStatus { u32 bitfile[2]; };

extern struct StatDebuffStatus sStatDebuffStatusAlly[CONFIG_UNIT_AMT_ALLY];
extern struct StatDebuffStatus sStatDebuffStatusEnemy[CONFIG_UNIT_AMT_ENEMY];
extern struct StatDebuffStatus sStatDebuffStatusNpc[CONFIG_UNIT_AMT_NPC];

static struct StatDebuffStatus * const sStatDebuffStatusPool[0x100] = {
    [FACTION_BLUE + 0x01] = sStatDebuffStatusAlly + 0,
    [FACTION_BLUE + 0x02] = sStatDebuffStatusAlly + 1,
    [FACTION_BLUE + 0x03] = sStatDebuffStatusAlly + 2,
    [FACTION_BLUE + 0x04] = sStatDebuffStatusAlly + 3,
    [FACTION_BLUE + 0x05] = sStatDebuffStatusAlly + 4,
    [FACTION_BLUE + 0x06] = sStatDebuffStatusAlly + 5,
    [FACTION_BLUE + 0x07] = sStatDebuffStatusAlly + 6,
    [FACTION_BLUE + 0x08] = sStatDebuffStatusAlly + 7,
    [FACTION_BLUE + 0x09] = sStatDebuffStatusAlly + 8,
    [FACTION_BLUE + 0x0A] = sStatDebuffStatusAlly + 9,
    [FACTION_BLUE + 0x0B] = sStatDebuffStatusAlly + 10,
    [FACTION_BLUE + 0x0C] = sStatDebuffStatusAlly + 11,
    [FACTION_BLUE + 0x0D] = sStatDebuffStatusAlly + 12,
    [FACTION_BLUE + 0x0E] = sStatDebuffStatusAlly + 13,
    [FACTION_BLUE + 0x0F] = sStatDebuffStatusAlly + 14,
    [FACTION_BLUE + 0x10] = sStatDebuffStatusAlly + 15,
    [FACTION_BLUE + 0x11] = sStatDebuffStatusAlly + 16,
    [FACTION_BLUE + 0x12] = sStatDebuffStatusAlly + 17,
    [FACTION_BLUE + 0x13] = sStatDebuffStatusAlly + 18,
    [FACTION_BLUE + 0x14] = sStatDebuffStatusAlly + 19,
    [FACTION_BLUE + 0x15] = sStatDebuffStatusAlly + 20,
    [FACTION_BLUE + 0x16] = sStatDebuffStatusAlly + 21,
    [FACTION_BLUE + 0x17] = sStatDebuffStatusAlly + 22,
    [FACTION_BLUE + 0x18] = sStatDebuffStatusAlly + 23,
    [FACTION_BLUE + 0x19] = sStatDebuffStatusAlly + 24,
    [FACTION_BLUE + 0x1A] = sStatDebuffStatusAlly + 25,
    [FACTION_BLUE + 0x1B] = sStatDebuffStatusAlly + 26,
    [FACTION_BLUE + 0x1C] = sStatDebuffStatusAlly + 27,
    [FACTION_BLUE + 0x1D] = sStatDebuffStatusAlly + 28,
    [FACTION_BLUE + 0x1E] = sStatDebuffStatusAlly + 29,
    [FACTION_BLUE + 0x1F] = sStatDebuffStatusAlly + 30,
    [FACTION_BLUE + 0x20] = sStatDebuffStatusAlly + 31,
    [FACTION_BLUE + 0x21] = sStatDebuffStatusAlly + 32,
    [FACTION_BLUE + 0x22] = sStatDebuffStatusAlly + 33,
    [FACTION_BLUE + 0x23] = sStatDebuffStatusAlly + 34,
    [FACTION_BLUE + 0x24] = sStatDebuffStatusAlly + 35,
    [FACTION_BLUE + 0x25] = sStatDebuffStatusAlly + 36,
    [FACTION_BLUE + 0x26] = sStatDebuffStatusAlly + 37,
    [FACTION_BLUE + 0x27] = sStatDebuffStatusAlly + 38,
    [FACTION_BLUE + 0x28] = sStatDebuffStatusAlly + 39,
    [FACTION_BLUE + 0x29] = sStatDebuffStatusAlly + 40,
    [FACTION_BLUE + 0x2A] = sStatDebuffStatusAlly + 41,
    [FACTION_BLUE + 0x2B] = sStatDebuffStatusAlly + 42,
    [FACTION_BLUE + 0x2C] = sStatDebuffStatusAlly + 43,
    [FACTION_BLUE + 0x2D] = sStatDebuffStatusAlly + 44,
    [FACTION_BLUE + 0x2E] = sStatDebuffStatusAlly + 45,
    [FACTION_BLUE + 0x2F] = sStatDebuffStatusAlly + 46,
    [FACTION_BLUE + 0x30] = sStatDebuffStatusAlly + 47,
    [FACTION_BLUE + 0x31] = sStatDebuffStatusAlly + 48,
    [FACTION_BLUE + 0x32] = sStatDebuffStatusAlly + 49,
    [FACTION_BLUE + 0x33] = sStatDebuffStatusAlly + 50,
    [FACTION_BLUE + 0x34] = sStatDebuffStatusAlly + 51,

    [FACTION_RED + 0x01] = sStatDebuffStatusEnemy + 0,
    [FACTION_RED + 0x02] = sStatDebuffStatusEnemy + 1,
    [FACTION_RED + 0x03] = sStatDebuffStatusEnemy + 2,
    [FACTION_RED + 0x04] = sStatDebuffStatusEnemy + 3,
    [FACTION_RED + 0x05] = sStatDebuffStatusEnemy + 4,
    [FACTION_RED + 0x06] = sStatDebuffStatusEnemy + 5,
    [FACTION_RED + 0x07] = sStatDebuffStatusEnemy + 6,
    [FACTION_RED + 0x08] = sStatDebuffStatusEnemy + 7,
    [FACTION_RED + 0x09] = sStatDebuffStatusEnemy + 8,
    [FACTION_RED + 0x0A] = sStatDebuffStatusEnemy + 9,
    [FACTION_RED + 0x0B] = sStatDebuffStatusEnemy + 10,
    [FACTION_RED + 0x0C] = sStatDebuffStatusEnemy + 11,
    [FACTION_RED + 0x0D] = sStatDebuffStatusEnemy + 12,
    [FACTION_RED + 0x0E] = sStatDebuffStatusEnemy + 13,
    [FACTION_RED + 0x0F] = sStatDebuffStatusEnemy + 14,
    [FACTION_RED + 0x10] = sStatDebuffStatusEnemy + 15,
    [FACTION_RED + 0x11] = sStatDebuffStatusEnemy + 16,
    [FACTION_RED + 0x12] = sStatDebuffStatusEnemy + 17,
    [FACTION_RED + 0x13] = sStatDebuffStatusEnemy + 18,
    [FACTION_RED + 0x14] = sStatDebuffStatusEnemy + 19,
    [FACTION_RED + 0x15] = sStatDebuffStatusEnemy + 20,
    [FACTION_RED + 0x16] = sStatDebuffStatusEnemy + 21,
    [FACTION_RED + 0x17] = sStatDebuffStatusEnemy + 22,
    [FACTION_RED + 0x18] = sStatDebuffStatusEnemy + 23,
    [FACTION_RED + 0x19] = sStatDebuffStatusEnemy + 24,
    [FACTION_RED + 0x1A] = sStatDebuffStatusEnemy + 25,
    [FACTION_RED + 0x1B] = sStatDebuffStatusEnemy + 26,
    [FACTION_RED + 0x1C] = sStatDebuffStatusEnemy + 27,
    [FACTION_RED + 0x1D] = sStatDebuffStatusEnemy + 28,
    [FACTION_RED + 0x1E] = sStatDebuffStatusEnemy + 29,
    [FACTION_RED + 0x1F] = sStatDebuffStatusEnemy + 30,
    [FACTION_RED + 0x20] = sStatDebuffStatusEnemy + 31,
    [FACTION_RED + 0x21] = sStatDebuffStatusEnemy + 32,
    [FACTION_RED + 0x22] = sStatDebuffStatusEnemy + 33,
    [FACTION_RED + 0x23] = sStatDebuffStatusEnemy + 34,
    [FACTION_RED + 0x24] = sStatDebuffStatusEnemy + 35,
    [FACTION_RED + 0x25] = sStatDebuffStatusEnemy + 36,
    [FACTION_RED + 0x26] = sStatDebuffStatusEnemy + 37,
    [FACTION_RED + 0x27] = sStatDebuffStatusEnemy + 38,
    [FACTION_RED + 0x28] = sStatDebuffStatusEnemy + 39,
    [FACTION_RED + 0x29] = sStatDebuffStatusEnemy + 40,
    [FACTION_RED + 0x2A] = sStatDebuffStatusEnemy + 41,
    [FACTION_RED + 0x2B] = sStatDebuffStatusEnemy + 42,
    [FACTION_RED + 0x2C] = sStatDebuffStatusEnemy + 43,
    [FACTION_RED + 0x2D] = sStatDebuffStatusEnemy + 44,
    [FACTION_RED + 0x2E] = sStatDebuffStatusEnemy + 45,
    [FACTION_RED + 0x2F] = sStatDebuffStatusEnemy + 46,
    [FACTION_RED + 0x30] = sStatDebuffStatusEnemy + 47,
    [FACTION_RED + 0x31] = sStatDebuffStatusEnemy + 48,
    [FACTION_RED + 0x32] = sStatDebuffStatusEnemy + 49,

    [FACTION_GREEN + 0x01] = sStatDebuffStatusNpc + 0,
    [FACTION_GREEN + 0x02] = sStatDebuffStatusNpc + 1,
    [FACTION_GREEN + 0x03] = sStatDebuffStatusNpc + 2,
    [FACTION_GREEN + 0x04] = sStatDebuffStatusNpc + 3,
    [FACTION_GREEN + 0x05] = sStatDebuffStatusNpc + 4,
    [FACTION_GREEN + 0x06] = sStatDebuffStatusNpc + 5,
    [FACTION_GREEN + 0x07] = sStatDebuffStatusNpc + 6,
    [FACTION_GREEN + 0x08] = sStatDebuffStatusNpc + 7,
    [FACTION_GREEN + 0x09] = sStatDebuffStatusNpc + 8,
    [FACTION_GREEN + 0x0A] = sStatDebuffStatusNpc + 9,
    [FACTION_GREEN + 0x0B] = sStatDebuffStatusNpc + 10,
    [FACTION_GREEN + 0x0C] = sStatDebuffStatusNpc + 11,
    [FACTION_GREEN + 0x0D] = sStatDebuffStatusNpc + 12,
    [FACTION_GREEN + 0x0E] = sStatDebuffStatusNpc + 13,
    [FACTION_GREEN + 0x0F] = sStatDebuffStatusNpc + 14,
    [FACTION_GREEN + 0x10] = sStatDebuffStatusNpc + 15,
    [FACTION_GREEN + 0x11] = sStatDebuffStatusNpc + 16,
    [FACTION_GREEN + 0x12] = sStatDebuffStatusNpc + 17,
    [FACTION_GREEN + 0x13] = sStatDebuffStatusNpc + 18,
    [FACTION_GREEN + 0x14] = sStatDebuffStatusNpc + 19,
};

static inline void _BIT_SET(u32 * bits, int idx)
{
    bits[idx / 32] |= 1 << (idx % 32);
}

static inline void _BIT_CLR(u32 * bits, int idx)
{
    bits[idx / 32] &= ~(1 << (idx % 32));
}

static inline bool _BIT_CHK(u32 * bits, int idx)
{
    if (bits[idx / 32] & (1 << (idx % 32)))
        return true;

    return false;
}

#define STAT_SET(unit, stat) _BIT_SET(sStatDebuffStatusPool[(unit)->index]->bitfile, stat)
#define STAT_CHK(unit, stat) _BIT_CHK(sStatDebuffStatusPool[(unit)->index]->bitfile, stat)
#define STAT_CLR(unit, stat) _BIT_CLR(sStatDebuffStatusPool[(unit)->index]->bitfile, stat)

void MSU_SaveStatDebuff(u8 * dst, const u32 size)
{
    if (size < (sizeof(sStatDebuffStatusAlly) + sizeof(sStatDebuffStatusEnemy) + sizeof(sStatDebuffStatusNpc)))
    {
        Errorf("ENOMEM: %d", size);
        return;
    }

    WriteAndVerifySramFast(
        sStatDebuffStatusAlly,
        dst,
        sizeof(sStatDebuffStatusAlly));

    dst += sizeof(sStatDebuffStatusAlly);

    WriteAndVerifySramFast(
        sStatDebuffStatusEnemy,
        dst,
        sizeof(sStatDebuffStatusEnemy));

    dst += sizeof(sStatDebuffStatusEnemy);

    WriteAndVerifySramFast(
        sStatDebuffStatusNpc,
        dst,
        sizeof(sStatDebuffStatusNpc));
}

void MSU_LoadStatDebuff(u8 * src, const u32 size)
{
    if (size < (sizeof(sStatDebuffStatusAlly) + sizeof(sStatDebuffStatusEnemy) + sizeof(sStatDebuffStatusNpc)))
    {
        Errorf("ENOMEM: %d", size);
        return;
    }

    ReadSramFast(
        src,
        sStatDebuffStatusAlly,
        sizeof(sStatDebuffStatusAlly));

    src += sizeof(sStatDebuffStatusAlly);

    WriteAndVerifySramFast(
        src,
        sStatDebuffStatusEnemy,
        sizeof(sStatDebuffStatusEnemy));

    src += sizeof(sStatDebuffStatusEnemy);

    WriteAndVerifySramFast(
        src,
        sStatDebuffStatusNpc,
        sizeof(sStatDebuffStatusNpc));
}

void TickUnitStatDebuff(struct Unit * unit, enum DEBUFF_INFO_TYPE type)
{
    int i;
    for (i = 0; i < UNIT_STAT_DEBUFF_MAX; i++)
    {
        if (STAT_CHK(unit, i) && gpStatDebuffInfos[i].type == type)
        {
            STAT_CLR(unit, i);
        }
    }
}
