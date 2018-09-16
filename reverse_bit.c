#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>  
#include<math.h>  

#define DEBUG1 0             //��������
#define DEBUG2 1

typedef unsigned int uint;

#if DEBUG1
uint reverse_bit(uint x)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
{  
    uint i, ret=0;  
    for (i = 0; i < 32; i++)  
    {  
        ret += ((x >> i) & 1)*(uint)pow(2, 31 - i); //ʵ����û�з�ת��ֻ�Ǵ����λ�����λ��չ���  
    }
	printf("DEBUG1\n");
    return ret;  
}  
#endif

#if DEBUG2
int reverse_bit(int num)
{
	int ret = 0;
	int count = 0;
	while(num)
	{
		count++;                      //00000000 00000000 00000000 00000001
		ret = ret + num%2;
		ret <<= 1;
		num >>= 1;
	}
	ret <<= (31-count);
	printf("DEBUG2\n");
	return ret;
}
#endif

int main()  
{  
    uint num = 0;
	uint ret = 0;  
    printf("Please input a number:");
    scanf("%u", &num);  
    ret = reverse_bit(num);  
    printf("��ת���ֵΪ:%u\n", ret);

    return 0;  
} 