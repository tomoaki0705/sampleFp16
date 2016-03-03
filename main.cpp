#include <iostream>

void float2half(float* src, short* dst, int length);

int main(int argc, char**argv)
{
	std::cout << "Hello World !!" << std::endl;
	__fp16 halfPrecision = 0.1f;
	std::cout << "half precision:"       << halfPrecision << std::endl;
	std::cout << "half precision:sizeof" << sizeof(halfPrecision) << std::endl;
	std::cout << "half precision:0x"     << std::hex << *(short*)(void*)&halfPrecision << std::dec << std::endl;

	float original[]  = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, };
	for (unsigned int i = 0;i < 8;i++)
	{
		__fp16 stub = original[i];
		std::cout << original[i] << "  0x" << std::hex << *(short*)&stub << std::dec << std::endl;
	}
	return 0;
}

void float2half(float* src, short* dst, int length) {
	const unsigned int cParallel = 1;
	for (int i = 0; i < length-(cParallel-1); i+=cParallel)
	{
	//	__m256 float_vector = _mm256_load_ps(src + i);
	//	__m128i half_vector = _mm256_cvtps_ph(float_vector, 0);
	//	*(__m128i*)(dst + i) = half_vector;
		__fp16 stub = (__fp16)src[i];
		dst[i] = *(short*)&stub;
	}

}

//void multiply(unsigned char* src, short* gain, unsigned char* dst, unsigned int cSize)
//{
//	__m128i v_zero = _mm_setzero_si128();
//	for (int x = 0;x <= cSize - 4;x += 4)
//	{
//		// _mm_loadl_epi64
//		// load lower 64bit and 
//		// fill higher 64bit as 0
//		__m128i src_integer = _mm_loadl_epi64((__m128i const *)(src + x));
//		__m128i gain_half = _mm_loadl_epi64((__m128i const *)(gain + x));
//
//		// uchar -> ushort
//		src_integer = _mm_unpacklo_epi8(src_integer, v_zero);
//
//		// ushort -> uint
//		src_integer = _mm_unpacklo_epi16(src_integer, v_zero);
//
//		// half -> float
//		__m128 src_float   = _mm_cvtepi32_ps(src_integer);
//
//		// uint -> float
//		__m128 gain_float = _mm_cvtph_ps(gain_half);
//
//		// float * float (per elment)
//		__m128 dst_float = _mm_mul_ps(src_float, gain_float);
//
//		//__m256 _mm256_mul_ps (__m256 a, __m256 b)
//
//		// float -> uint
//		__m128i dst_integer = _mm_cvtps_epi32(dst_float);
//
//		// uint -> ushort
//		dst_integer = _mm_packs_epi32(dst_integer, v_zero);
//
//		// ushort -> uchar
//		dst_integer = _mm_packus_epi16(dst_integer, v_zero);
//
//		// sotre
//		_mm_storel_epi64((__m128i *)(dst + x), dst_integer);
//
//	}
//}
