// SPDX-License-Identifier: GPL-2.0-only

#include "common-chax.h"
#include "kernel-lib.h"

const struct Vec1 gVecs_1x1[4] = {
			  { 0, -1},
	{-1,  0},           { 1,  0},
			  { 0,  1},
};

const struct Vec1 gVecs_2x2[12] = {
						{ 0, -2},
			  {-1, -1}, { 0, -1}, { 1, -1},
	{-2,  0}, {-1,  0},	          { 1,  0}, { 2,  0},
			  {-1,  1}, { 0,  1}, { 1,  1},
						{ 0,  2}
};

const struct Vec1 gVecs_3x3[24] = {
								  { 0, -3},
						{-1, -2}, { 0, -2}, { 1, -2},
			  {-2, -1}, {-1, -1}, { 0, -1}, { 1, -1}, { 2, -1},
	{-3,  0}, {-2,  0}, {-1,  0},           { 1,  0}, { 2,  0}, { 3,  0},
			  {-2,  1}, {-1,  1}, { 0,  1}, { 1,  1}, { 2,  1},
						{-1,  2}, { 0,  2}, { 1,  2},
								  { 0,  3}
};

const u8 gRange1_In2x2[ARRAY_COUNT_RANGE2x2] = {
		  0,
	   0, 1, 0,
	0, 1,    1, 0,
	   0, 1, 0,
		  0,
};

const u8 gRange1_In3x3[ARRAY_COUNT_RANGE3x3] = {
			 0,
		  0, 0, 0,
	   0, 0, 1, 0, 0,
	0, 0, 1,    1, 0, 0,
	   0, 0, 1, 0, 0,
		  0, 0, 0,
			 0
};

const u8 gRange2_In3x3[ARRAY_COUNT_RANGE3x3] = {
			 0,
		  0, 1, 0,
	   0, 1, 1, 1, 0,
	0, 1, 1,    1, 1, 0,
	   0, 1, 1, 1, 0,
		  0, 1, 0,
			 0
};
