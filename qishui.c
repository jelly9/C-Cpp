#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int main()
{

	int money = 0; 
	scanf("%d",&money);
	printf("%d\n",2*money - 1);

	system("pause");
	return 0;
}
//����
//���Ⱥ����ÿ�ƿ�����������ÿ�ƿ����������ܻ���ʱ�����п϶�ֻʣһ��һ����ƿ
//������N��Ǯ���������N����ƿ�����ϰ��N-1����ƿ������ٻ�N-1ƿ��ˮ��
//����֮��Ѻ����N-1����ƿ�����ϰ壬��պú���2N-1ƿ��ˮ,����������һ����ƿ

//
//int count_bottle_num(int money)
//{
//	int num = 0;
//	int null_bottle = 0;
//	int full_bottle = money;
//	while (1)
//	{
//		num += full_bottle;
//		null_bottle = full_bottle+null_bottle%2;
//		full_bottle = null_bottle / 2;
//		if (null_bottle == 1)
//		{
//			return num+1;
//			
//		}
//	}
//	
//}
//int main()
//{
//	int money = 0;
//	printf("�������");
//	scanf("%d",&money);
//	printf("%dԪǮ���Ժ�%dƿ��ˮ����\n",money,count_bottle_num(money));
//
//
//	system("pause");
//	return 0;
//}