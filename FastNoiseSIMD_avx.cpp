// FastNoiseSIMD_avx.cpp
//
// MIT License
//
// Copyright(c) 2016 Jordan Peck
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// The developer's email is jorzixdan.me2@gzixmail.com (for great email, take
// off every 'zix'.)
//

#include "FastNoiseSIMD.h"

// To compile AVX support enable AVX code generation compiler flags for this file
#ifdef FN_COMPILE_AVX
#ifndef __AVX__
#ifdef __GNUC__
#error To compile AVX add build command "-march=core-avx" on FastNoiseSIMD_avx2.cpp, or remove "#define FN_COMPILE_AVX" from FastNoiseSIMD.h
#else
#error To compile AVX set C++ code generation to use /arch:AVX on FastNoiseSIMD_avx2.cpp, or remove "#define FN_COMPILE_AVX" from FastNoiseSIMD.h
#endif
#endif

#if defined(FN_COMPILE_SSE41)
#define SIMD_LEVEL_H FN_SSE41
#include "FastNoiseSIMD_internal.h"
#endif

#define SIMD_LEVEL_H FN_AVX
#include "FastNoiseSIMD_internal.h"
#include <immintrin.h> //AVX

#define SIMD_LEVEL FN_AVX
#include "FastNoiseSIMD_internal.cpp"
#endif