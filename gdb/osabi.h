/* OS ABI variant handling for GDB.
   Copyright (C) 2001-2025 Free Software Foundation, Inc.
   
   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef GDB_OSABI_H
#define GDB_OSABI_H

#include "gdbsupport/osabi.h"

/* Register an OS ABI sniffer.  Each arch/flavour may have more than
   one sniffer.  This is used to e.g. differentiate one OS's a.out from
   another.  The first sniffer to return something other than
   GDB_OSABI_UNKNOWN wins, so a sniffer should be careful to claim a file
   only if it knows for sure what it is.  */
void gdbarch_register_osabi_sniffer (enum bfd_architecture,
				     enum bfd_flavour,
				     enum gdb_osabi (*)(bfd *));

/* Register a handler for an OS ABI variant for a given architecture
   and machine type.  There should be only one handler for a given OS
   ABI for each architecture and machine type combination.  */
void gdbarch_register_osabi (enum bfd_architecture, unsigned long,
			     enum gdb_osabi,
			     void (*)(struct gdbarch_info,
				      struct gdbarch *));

/* Lookup the OS ABI corresponding to the specified BFD.  */
enum gdb_osabi gdbarch_lookup_osabi (bfd *);

/* Return true if there's an OS ABI handler for INFO.  */
bool has_gdb_osabi_handler (struct gdbarch_info info);

/* Initialize the gdbarch for the specified OS ABI variant.  */
void gdbarch_init_osabi (struct gdbarch_info, struct gdbarch *);

/* Helper routine for ELF file sniffers.  This looks at ABI tag note
   sections to determine the OS ABI from the note.  */
void generic_elf_osabi_sniff_abi_tag_sections (bfd *, asection *,
					       enum gdb_osabi *);

/* Return a string version of OSABI.  This is used when generating code
   which calls set_tdesc_osabi and an 'enum gdb_osabi' value is needed.  */
const char *gdbarch_osabi_enum_name (enum gdb_osabi osabi);

#endif /* GDB_OSABI_H */
