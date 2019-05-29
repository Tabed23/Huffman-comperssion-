#include"HuffMan_Compression.h"

int main()
{
	HuffMan_Compression hf("Eerie eye seen near lake");
	hf.encode("Eerie eye seen near lake");
	hf.decode("10100011011110111101111000011010110100011011110111101111011110111100001101");
	system("pause");
	return 0;
}