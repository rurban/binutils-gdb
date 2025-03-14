/* Copyright 2025 Free Software Foundation, Inc.

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

#include <unistd.h>
#include <hip/hip_runtime.h>

__global__ void
kern ()
{
  while (true)
    __builtin_amdgcn_s_sleep (8);
}

int
main ()
{
  /* This program will run outside of GDB, make sure that if anything goes
     wrong it eventually gets killed.  */
  alarm (30);

  kern<<<1, 1>>> ();
  return hipDeviceSynchronize () != hipSuccess;
}

