/**
 * slibc — Yet another C library
 * Copyright © 2015  Mattias Andrée (maandree@member.fsf.org)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <wchar.h>



/**
 * Duplicate a string.
 * 
 * This is a GNU-compliant slibc extension.
 * 
 * @param   string  The string to duplicate.
 * @return          The new string. `NULL` is returned on error
 *                  and `errno` is set to indicate the error.
 * 
 * @throws  ENOMEM  The process could not allocate sufficient amount of memory.
 */
wchar_t* wcsdup(const wchar_t* string)
{
  size_t n = wcslen(string) + 1;
  wchar_t* r = malloc(n * sizeof(char));
  return r == NULL ? NULL : wmemcpy(r, string, n);
}


/**
 * Duplicate a string.
 * 
 * This is a slibc extension added for completeness.
 * It is only available if GNU extensions are available.
 * 
 * @param   string  The string to duplicate.
 * @param   maxlen  Truncate the string to this length, if it is longer.
 *                  A NUL wide character is guaranteed to always be
 *                  written upon successful completion.
 * @return          The new string. `NULL` is returned on error
 *                  and `errno` is set to indicate the error.
 * 
 * @throws  ENOMEM  The process could not allocate sufficient amount of memory.
 */
wchar_t* wcsndup(const wchar_t* string, size_t maxlen)
{
  size_t n = wcsnlen(string, maxlen) + 1;
  wchar_t* r = malloc(n * sizeof(wchar_t));
  return r == NULL ? NULL : wmemcpy(r, string, n);
}


/**
 * Duplicate a memory segment.
 * 
 * This is a slibc extension added for completeness.
 * 
 * @param   segment  The memory segment to duplicate.
 * @param   size     The size of the memory segment.
 * @return           The new segment. `NULL` is returned on error
 *                   and `errno` is set to indicate the error.
 * 
 * @throws  ENOMEM  The process could not allocate sufficient amount of memory.
 */
wchar_t* wmemdup(const wchar_t* segment, size_t size)
{
  wchar_t* r = malloc(size * sizeof(wchar_t));
  return r == NULL ? NULL : wmemcpy(r, segment, size);
}

