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
#ifndef _STDDEF_H
#define _STDDEF_H
#include <slibc/version.h>



/**
 * `NULL` is a zero-values constant, conventionally
 * a `void`-pointer (it is specified this way in
 * POSIX, it does not really matter and ISO C does
 * not specify it this way), use to indicate that
 * a pointer does not point to anything.
 */
#define NULL  ((void*)0)


/**
 * Get the offset of a member in a `struct`, in bytes.
 * 
 * For example. Consider the structure
 * ```
 * struct example
 * {
 *   char offset_is_0[16];
 *   char offset_is_16[16];
 * }
 * ```
 * `offsetof(struct example, offset_is_0)` evaluates to
 * 0 because it is at the top of the structure.
 * `offsetof(struct example, offset_is_16)` evaluates to
 * 16 because the member above it in the structure
 * has offset 0 and size 16. 0 + 16 = 16.
 * 
 * @param   type:identifier    The identifier for a structure.
 * @param   member:identifier  The identifier for a member, direct or indirect,
 *                             of the structure.
 * @return  :size_t            The offset of the member.
 */
#define offsetof(type, member)  \
  ((size_t)((char*)&(((type*)NULL)->member) - (char*)NULL))



#define __NEED_ptrdiff_t
#define __NEED_wchar_t
#define __NEED_size_t
#if __STDC_VERSION__ >= 201112L
# define __NEED_max_align_t
#endif

#include <bits/types.h>



#endif
