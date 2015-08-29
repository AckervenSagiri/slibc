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
#ifndef _ASSERT_H
#define _ASSERT_H
#include <slibc/version.h>



/* The `assert` macro shall be redefined according to the the
 * current state of `NDEBUF` each time <assert.h> is included. */
#ifdef assert
# undef assert
#endif


/**
 * Unless `NDEBUG` is defined, print an error message
 * and abort the process, if the expression evaluates to
 * non-zero.
 * 
 * POSIX specifies that `assert` shall not evaluate the
 * expression if `NDEBUG` is defined. This is probably
 * to save CPU-cycles.
 */
#ifdef NDEBUG
# define assert(expression)   ((void)0)
#else
# define assert(expression)  \
  ((void)((expression) ? 0 : (__assert_fail(#expression, 0, __FILE__, __LINE__, __func__), 0)))
#endif


/**
 * A compile-time error should occur if the expression
 * evaluates to zero.
 * 
 * @param  expression:scalar    The expression to evaluate.
 * @param  message:const char*  The message to print on error.
 */
#define static_assert _Static_assert


/**
 * Unless `NDEBUG` is defined, print an error message
 * and abort the process, if `errnum` is non-zero.
 * 
 * @param  errnum:int  The error code, describing the error that occurred.
 * 
 * `assert_perror` is a GNU extension.
 */
#if defined(_SLIBC_SOURCE) || defined(_GNU_SOURCE)
#ifdef assert_perror
# undef assert_perror
#endif
#ifdef NDEBUG
# define assert_perror(errnum)  ((void)0)
#else
# define assert_perror(errnum)  \
  ((void)((errnum == 0) ? 0 : (__assert_fail(NULL, errnum, __FILE__, __LINE__, __func__), 0)))
__USE_GNU
#endif



/**
 * The function that is called if an assertion fails.
 * 
 * @param  expression  The expression that failed, `NULL` if `assert_perror` failed
 * @param  errnum      The code of the fatal error, 0 if `assert` failed
 * @param  file        The filename of the source cose whence the assertion was made
 * @param  line        The line in the source code whence the assertion was made
 * @param  func        The function in the source code whence the assertion was made
 */
void __attribute__((noreturn, nonnull(3, 4, 5)))
__assert_fail(const char* expression, int errnum, const char* file, int line, const char* func);



#endif
