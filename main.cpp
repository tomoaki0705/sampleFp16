#include <iostream>

int main(int argc, char**argv)
{
	std::cout << "Hello World !!" << std::endl;
	__fp16 halfPrecision = 0.1f;
	std::cout << "half precision:"       << halfPrecision << std::endl;
	std::cout << "half precision:sizeof" << sizeof(halfPrecision) << std::endl;
	std::cout << "half precision:0x"     << std::hex << *(short*)(void*)&halfPrecision << std::dec << std::endl;
	return 0;
}
