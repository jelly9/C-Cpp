#include <stdio.h>


//1��δ�Ľ���

//void BubbleSort(int a[], int len)
//{
//	int i = 0;
//	int j = 0;
//	for( i = 0; i < len-1; i++)
//	{
//		for( j = 0; j < len-i-1; j++ )
//		{
//			if(a[j]>a[j+1])
//			{
//				*(a+j)   = *(a+j) ^ *(a+j+1);
//				*(a+j+1) = *(a+j) ^ *(a+j+1);
//				*(a+j)   = *(a+j) ^ *(a+j+1);
//			}
//		}
//	}
//}



//2���Ľ������ñ���pos��¼��󽻻���λ�ã���

//void BubbleSort(int a[], int len)
//{
//	int i = len - 1;
//	int j = 0;
//	while( i )
//	{
//		int pos = 0;           //ÿ��ѭ����ʼǰ����δ����
//		for( j = 0; j < i; j++)
//		{
//			if( a[j] > a[j+1] )
//			{
//				*(a+j)   = *(a+j) ^ *(a+j+1);
//				*(a+j+1) = *(a+j) ^ *(a+j+1);
//				*(a+j)   = *(a+j) ^ *(a+j+1);
//				pos = j;                   //��¼������λ��
//			}
//		}
//		i = pos;   //����ֻ��Ƚϵ�posλ�ô���ok
//	}
//
//}
//3���ٸĽ���ÿ�˱Ƚ����Σ��ֱ��ҳ�һ�����ֵ��һ����Сֵ����

void BubbleSort(int a[], int len)
{
	int j = 0;
	int low = 0;
	int high = len - 1;
	while(low<high)
	{
		for( j = low; j<high; j++)
		{
			if(a[j]>a[j+1])
			{
				*(a+j)   = *(a+j) ^ *(a+j+1);
				*(a+j+1) = *(a+j) ^ *(a+j+1);
				*(a+j)   = *(a+j) ^ *(a+j+1);
			}
		}
		high--;
		for( j = high; j>low; j--)
		{
			if(a[j]>a[j+1])
			{
				*(a+j)   = *(a+j) ^ *(a+j+1);
				*(a+j+1) = *(a+j) ^ *(a+j+1);
				*(a+j)   = *(a+j) ^ *(a+j+1);
			}
		}
		low++;
	}
}

//void BubbleSort(int a[])
//{
//	int len = sizeof(a)/sizeof(a[0]);
//	for( int i = 0; i < len-1; i++)
//	{
//		for( int j = 0; j < len-i-1; j++ )
//		{
//			if(a[j]>a[j+1])
//			{
//				//int t    = *(a+j);
//                //*(a+j)   = *(a+j+1);
//                //*(a+j+1) = t;
//				*(a+j)   = *(a+j) ^ *(a+j+1);
//				*(a+j+1) = *(a+j) ^ *(a+j+1);
//				*(a+j)   = *(a+j) ^ *(a+j+1);
//			}
//		}
//	}
//}

//������

int main()
{
    void BubbleSort(int *a, int l);        //void BubbleSort(int *a);
	int arr[] = {398,37,687,65,456,998,876,156,587,294};
	int i = 0;
	int j = 0;
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("����ǰ: ");
    for( i = 0; i < len; i++ )
	{
		printf("%d  ", *(arr+i));
	}
    BubbleSort(arr,len);                 //BubbleSort(arr);
    printf("\n�����: ");
    for( i = 0; i < len; i++ )
	{
		printf("%d  ", *(arr+i));
	}
	printf("\n");
	return 0;
}