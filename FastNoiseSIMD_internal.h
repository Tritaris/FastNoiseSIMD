// FastNoiseSIMD_internal.h
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

#ifndef SIMD_LEVEL_H
#error Dont include this file without defining SIMD_LEVEL_H
#else
#define FASTNOISE_SIMD_CLASS2(x) FastNoiseSIMD_L##x
#define FASTNOISE_SIMD_CLASS(level) FASTNOISE_SIMD_CLASS2(level)

#if SIMD_LEVEL_H == FN_AVX && defined(FN_COMPILE_SSE41)
#define FN_PARENT FASTNOISE_SIMD_CLASS(FN_SSE41)
#else
#define FN_PARENT FastNoiseSIMD
#endif

namespace FastNoiseSIMD_internal
{
	class FASTNOISE_SIMD_CLASS(SIMD_LEVEL_H) : public FN_PARENT
	{
	public:
		// Do not call this, use SetSIMDLevel(int) to have NewFastNoiseSIMD() return the level you want
		FASTNOISE_SIMD_CLASS(SIMD_LEVEL_H)(int seed = 1337);

		static float* GetEmptySet(int size);
		static int AlignedSize(int size);

		void FillSampledNoiseSet(float* noiseSet, int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, int sampleScale);
		void FillSampledNoiseSet(float* noiseSet, FastNoiseVectorSet* vectorSet, int xSize, int ySize, int zSize, float xOffset = 0.0f, float yOffset = 0.0f, float zOffset = 0.0f);

		void FillWhiteNoiseSet(float* floatSet, int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier = 1.0f);
		void FillWhiteNoiseSet(float* noiseSet, FastNoiseVectorSet* vectorSet, float xOffset = 0.0f, float yOffset = 0.0f, float zOffset = 0.0f);

		void FillValueSet(float* floatSet, int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier = 1.0f);
		void FillValueFractalSet(float* floatSet, int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier = 1.0f);
		void FillValueSet(float* noiseSet, FastNoiseVectorSet* vectorSet, float xOffset = 0.0f, float yOffset = 0.0f, float zOffset = 0.0f);
		void FillValueFractalSet(float* noiseSet, FastNoiseVectorSet* vectorSet, float xOffset = 0.0f, float yOffset = 0.0f, float zOffset = 0.0f);

		void FillGradientSet(float* floatSet, int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier = 1.0f);
		void FillGradientFractalSet(float* floatSet, int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier = 1.0f);
		void FillGradientSet(float* noiseSet, FastNoiseVectorSet* vectorSet, float xOffset = 0.0f, float yOffset = 0.0f, float zOffset = 0.0f);
		void FillGradientFractalSet(float* noiseSet, FastNoiseVectorSet* vectorSet, float xOffset = 0.0f, float yOffset = 0.0f, float zOffset = 0.0f);

		void FillSimplexSet(float* floatSet, int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier = 1.0f);
		void FillSimplexFractalSet(float* floatSet, int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier = 1.0f);
		void FillSimplexSet(float* noiseSet, FastNoiseVectorSet* vectorSet, float xOffset = 0.0f, float yOffset = 0.0f, float zOffset = 0.0f);
		void FillSimplexFractalSet(float* noiseSet, FastNoiseVectorSet* vectorSet, float xOffset = 0.0f, float yOffset = 0.0f, float zOffset = 0.0f);

#if SIMD_LEVEL_H != FN_AVX || !defined(FN_COMPILE_SSE41)
		void FillCellularSet(float* floatSet, int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier = 1.0f);
		void FillCellularSet(float* noiseSet, FastNoiseVectorSet* vectorSet, float xOffset = 0.0f, float yOffset = 0.0f, float zOffset = 0.0f);
#endif
	};
}
#undef SIMD_LEVEL_H
#endif
