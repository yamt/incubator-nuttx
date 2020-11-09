/****************************************************************************
 * include/nuttx/compiler_stdint.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __INCLUDE_NUTTX_COMPILER_STDINT_H
#define __INCLUDE_NUTTX_COMPILER_STDINT_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#if !defined(__ASSEMBLY__)

/* This file is intended to be included by arch types.h to
 * ensure it provides typedefs compatible with types the compiler is
 * configured to use.
 *
 * Note: the C standard allows duplicated typedefs as far as
 * they denote the same type.
 */

#if defined(__INT8_TYPE__)
typedef __INT8_TYPE__      _int8_t;
#endif
#if defined(__UINT8_TYPE__)
typedef __UINT8_TYPE__      _uint8_t;
#endif
#if defined(__INT16_TYPE__)
typedef __INT16_TYPE__      _int16_t;
#endif
#if defined(__UINT16_TYPE__)
typedef __UINT16_TYPE__      _uint16_t;
#endif
#if defined(__INT32_TYPE__)
typedef __INT32_TYPE__      _int32_t;
#endif
#if defined(__UINT32_TYPE__)
typedef __UINT32_TYPE__      _uint32_t;
#endif
#if defined(__INT64_TYPE__)
typedef __INT64_TYPE__      _int64_t;
#endif
#if defined(__UINT64_TYPE__)
typedef __UINT64_TYPE__      _uint64_t;
#endif
#if defined(__INTMAX_TYPE__)
typedef __INTMAX_TYPE__      _intmax_t;
#endif
#if defined(__UINTMAX_TYPE__)
typedef __UINTMAX_TYPE__      _uintmax_t;
#endif
#if defined(__SIZE_TYPE__)
typedef __SIZE_TYPE__         _size_t;
#endif

#endif /* !defined(__ASSEMBLY__) */

#endif /* __INCLUDE_NUTTX_COMPILER_STDINT_H */
