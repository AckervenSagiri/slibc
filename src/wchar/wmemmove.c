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
 * Copy a memory segment to another, possibly overlapping, segment.
 * 
 * This is a GNU extension.
 * 
 * @param   whither  The destination memory segment.
 * @param   whence   The source memory segment.
 * @param   size     The number of wide characters to copy.
 * @return           `whither` is returned.
 */
wchar_t* wmemmove(wchar_t* whither, const wchar_t* whence, size_t size)
{
  wchar_t* r = whither;
  if ((size_t)(whither - whence) < size)
    while (size--)
      whither[size] = whence[size];
  else
    while (size--)
      *whither++ = *whence++;
  return r;
}


/**
 * Copy a memory segment to another, possibly overlapping, segment.
 * 
 * This is a slibc extension added for completeness.
 * It is only available if GNU extensions are available.
 * 
 * @param   whither  The destination memory segment.
 * @param   whence   The source memory segment.
 * @param   size     The number of wide characters to copy.
 * @return           `whither + size` is returned.
 */
wchar_t* wmempmove(wchar_t* whither, const wchar_t* whence, size_t size)
{
  return wmemmove(whither, whence, size) + size;
}
