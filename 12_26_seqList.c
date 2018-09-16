#include <stdio.h>
#include <windows.h>
#include <assert.h>

#define INIT_CAP 64

typedef int elemtype;

typedef struct seqList
{
	elemtype *elem;//Ԫ������
	int size;//��ǰ��С
	int cap;//����
}seqList;

//��ʼ�����Ա�
void initList(seqList *L)
{
	assert(L);

	L->elem = (elemtype*)malloc(INIT_CAP * sizeof(elemtype));//�����ڴ�ռ�
	if(NULL == L)//���
	{
		perror("malloc");
		exit(1);
	}

	L->size = 0;//��ʼ����С
	L->cap = INIT_CAP;//��ʼ������
}

void insertList(seqList *L, elemtype e)
{
	assert(L);

	L->elem[L->size] = e;
	L->size++;
}

void printList(seqList *L)
{
	int i = 0;

	assert(L);

	for(; i < L->size; i++)
	{
		printf("%d  ", L->elem[i]);
	}
	printf("\n");

}

void reversePrint(seqList *L, int s)
{
	
	if(s)
	{
		reversePrint(L, s-1);
	}
	printf("%d  ", L->elem[s]);
}

int main()
{
	int i = 0;
	seqList L;
	initList(&L);

	for(i = 0; i < 5; i++)
	{
		insertList(&L, i);
	}

	printList(&L);
	reversePrint(&L, 5);
	system("pause");
	return 0;
}