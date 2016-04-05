#include <stdio.h>

int main(int argc, char**argv)
{
	printf("Hello World !!\n");
	__fp16 halfPrecision = 1.5f;
	printf("half precision:%f\n", halfPrecision);
	printf("half precision:sizeof %d\n", (int)sizeof(halfPrecision));
	printf("half precision:0x%04x\n", *(short*)(void*)&halfPrecision);

	float original[]  = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f, };
	for (unsigned int i = 0;i < 16;i++)
	{
		__fp16 stub = original[i];
		printf("%2d 0x%04x\n", (int)original[i], *(short*)&stub);
		
	}
	return 0;
}

