#include <stdio.h>
#include <windows.h>


//����һֻ5Ԫĸ��һֻ3ԪС��һֻ1Ԫ100Ԫ��һ��ֻ���ʹ�ĸС����ֻ
int main()
{

	int x = 0;
	int y = 0;
	int z = 0;
	for( x = 0; x < 20; x++ ){//������
		for( y = 0; y < 33; y++ ){//ĸ����
			z = 100 - x - y;
			if( (100 == (5*x + 3*y + z/3)) && 0 == z%3 ){
				printf("����:%d, ĸ��:%d, С��:%d.\n",x, y, z);
			}
		}
	}

	system("pause");
	return 0;
}