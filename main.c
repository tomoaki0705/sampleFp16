#include <stdio.h>

void float2half(float* src, short* dst, int length);

int main(int argc, char**argv)
{
	printf("Hello World !!\n");
	__fp16 halfPrecision = 1.5f;
	printf("half precision:%f\n", halfPrecision);
	printf("half precision:sizeof %d\n", sizeof(halfPrecision));
	printf("half precision:0x%04x\n", *(short*)(void*)&halfPrecision);

	float original[]  = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f, };
	for (unsigned int i = 0;i < 16;i++)
	{
		__fp16 stub = original[i];
		printf("% 2d 0x%04x\n", original[i], *(short*)&stub);
	}
	return 0;
}

void float2half(float* src, short* dst, int length) {
	const unsigned int cParallel = 1;
	for (int i = 0; i < length-(cParallel-1); i+=cParallel)
	{
		__fp16 stub = (__fp16)src[i];
		dst[i] = *(short*)&stub;
	}

}

