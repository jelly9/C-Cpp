#include <stdio.h>
#include <windows.h>

int main()
{
	printf("file: %s\n",__FILE__);
	printf("line: %d\n",__LINE__);
	printf("date: %s\n",__DATE__);
	printf("time: %s\n",__TIME__);
	//printf("stdc: %d\n",__STDC__);

	system("pause");
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <windows.h>
//
//#define SWAP_BIT(x) (( x & 0xaaaaaaaa) >> 1 | (x & 0x55555555) << 1) 
//
////       ȡ����ż��λ          111010          ȡ��������λ               111010
////10101010 10101010 10101010 10101010        01010101 01010101 01010101 01010101
////   �Ƶ�����λ   & >>1        100101       �Ƶ�ż��λ      &  <<1        010000 
////
//
//
//int main()
//{
//
//	int i = 0;
//	printf("Please input:");
//	scanf("%d", &i);
//	printf("After swap bits: %d\n", SWAP_BIT(i));
//
//	system("pause");
//	return 0;
//}