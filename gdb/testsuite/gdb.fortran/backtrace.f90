! Copyright 2023-2025 Free Software Foundation, Inc.
!
! This program is free software; you can redistribute it and/or modify
! it under the terms of the GNU General Public License as published by
! the Free Software Foundation; either version 3 of the License, or
! (at your option) any later version.
!
! This program is distributed in the hope that it will be useful,
! but WITHOUT ANY WARRANTY; without even the implied warranty of
! MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
! GNU General Public License for more details.
!
! You should have received a copy of the GNU General Public License
! along with this program.  If not, see <http://www.gnu.org/licenses/>.

subroutine bar ()
  return                ! Break here
end subroutine bar

subroutine foo ()
  call bar ()
end subroutine foo

program main
  interface
    subroutine bar ()
    end subroutine bar
    subroutine foo ()
    end subroutine foo
  end interface
  call foo ()
end program main
