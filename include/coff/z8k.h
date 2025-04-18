/* coff information for Zilog Z800N
   
   Copyright (C) 2001-2025 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#define L_LNNO_SIZE 4
#include "coff/external.h"

/* Type of cpu is stored in flags */
#define F_Z8001    0x1000
#define F_Z8002    0x2000
#define F_MACHMASK 0xf000

#define	Z8KMAGIC   0x8000

#define Z8KBADMAG(x) (((x).f_magic != Z8KMAGIC))
  
/********************** RELOCATION DIRECTIVES **********************/

/* The external reloc has an offset field, because some of the reloc
   types on the z8k don't have room in the instruction for the entire
   offset - eg with segments.  */

struct external_reloc
{
  char r_vaddr[4];
  char r_symndx[4];
  char r_offset[4];
  char r_type[2];
  char r_stuff[2];
};

#define RELOC struct external_reloc
#define RELSZ 16

/* Z8k relocations.  */
#define R_IMM16   0x01		/* 16 bit abs */
#define R_JR      0x02		/* jr  8 bit disp */
#define R_IMM32   0x11		/* 32 bit abs */
#define R_IMM8    0x22		/* 8 bit abs */
#define R_IMM4L   0x23		/* low nibble */
#define R_REL16   0x04		/* 16 bit PC rel */
#define R_CALLR   0x05		/* callr 12 bit disp */
#define R_SEG     0x10		/* set if in segmented mode */
#define R_IMM4H   0x24		/* high nibble */
#define R_DISP7   0x25		/* djnz displacement */
