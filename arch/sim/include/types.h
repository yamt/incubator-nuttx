/****************************************************************************
 * arch/sim/include/types.h
 *
 *   Copyright (C) 2007, 2009, 2014 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/* This file should never be included directly but, rather,
 * only indirectly through sys/types.h
 */

#ifndef __ARCH_SIM_INCLUDE_TYPES_H
#define __ARCH_SIM_INCLUDE_TYPES_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/compiler_stdint.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Type Declarations
 ****************************************************************************/

#ifndef __ASSEMBLY__

/* These are the sizes of the standard integer types.  NOTE that these type
 * names have a leading underscore character.  This file will be included
 * (indirectly) by include/stdint.h and typedef'ed to the final name without
 * the underscore character.  This roundabout way of doings things allows
 * the stdint.h to be removed from the include/ directory in the event that
 * the user prefers to use the definitions provided by their toolchain header
 * files
 */

typedef signed char        _int8_t;
typedef unsigned char      _uint8_t;

typedef signed short       _int16_t;
typedef unsigned short     _uint16_t;

typedef signed int         _int32_t;
typedef unsigned int       _uint32_t;

/* Note about host OS types:
 * - int64_t is long long for 64-bit macOS
 * - int64_t is long for Ubuntu x86-64
 *
 * Note for sim/macOS modules:
 * For sim/macOS, usually x86_64-elf-gcc from homebrew is used
 * as MODULECC. It seems to be configured as __INT64_TYPE__ == long int.
 * The __APPLE_CC__ check below is to workaround it.
 * (The host cc defines __APPLE_CC__, while x86_64-elf-gcc doesn't.)
 * XXX It is a problem if you need C++ symbols in symtabs for modules.
 */

#if defined(CONFIG_HOST_MACOS) && defined(__APPLE_CC__) || !defined(_LP64)
typedef signed long long   _int64_t;
typedef unsigned long long _uint64_t;
#else
typedef signed long        _int64_t;
typedef unsigned long      _uint64_t;
#endif
#define __INT64_DEFINED

#if defined(CONFIG_HOST_X86_64) && !defined(CONFIG_SIM_M32)
/* 64-bit build on 64-bit machine: A size is 8 bytes */

#if defined(__SIZE_TYPE__)
/* If __SIZE_TYPE__ is defined we define ssize_t based on size_t.
 * We simply change "unsigned" to "signed" for this single definition
 * to make sure ssize_t and size_t only differ by their signedness.
 */

#define unsigned signed
typedef __SIZE_TYPE__      _ssize_t;
#undef unsigned
typedef __SIZE_TYPE__      _size_t;
#else
typedef signed long long   _ssize_t;
typedef unsigned long long _size_t;
#endif

#else
/* 32-bit build on 32- or 64-bit machine: A size is 4 bytes */

#if defined(__SIZE_TYPE__)
/* If __SIZE_TYPE__ is defined we define ssize_t based on size_t.
 * We simply change "unsigned" to "signed" for this single definition
 * to make sure ssize_t and size_t only differ by their signedness.
 */

#define unsigned signed
typedef __SIZE_TYPE__      _ssize_t;
#undef unsigned
typedef __SIZE_TYPE__      _size_t;
#elif defined(CONFIG_ARCH_SIZET_LONG)
typedef signed long        _ssize_t;
typedef unsigned long      _size_t;
#else
typedef signed int         _ssize_t;
typedef unsigned int       _size_t;
#endif

#endif

/* This is the size of the interrupt state save returned by
 * up_irq_save()
 */

typedef _uint64_t          irqstate_t;

#endif /* __ASSEMBLY__ */

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#endif /* __ARCH_SIM_INCLUDE_TYPES_H */
