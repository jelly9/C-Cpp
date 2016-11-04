#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#pragma warning(disable:4996)

#define MAXSIZE 100
typedef int ElemType;


typedef struct seqlist
{
	ElemType *data;
	int listlength;
	int listsize;
}seqlist;


int Initlist( seqlist *L );
int Insertelem(seqlist *L, int pos, ElemType e );
int Delectelem( seqlist *L, int pos );
int Printlist(seqlist *L);
int Exchelem(seqlist *L,int pos,ElemType e);

int Initlist( seqlist *L )//��ʼ�����Ա��
{
	printf("Start initseqlist...\n");
	L->data = ( ElemType* )malloc( MAXSIZE*sizeof(ElemType) );
	if( NULL == L->data){
		exit(1);
	}
	L->listlength = 0;
	L->listsize = MAXSIZE;
	printf("End initseqlist...\n");
	return 1;
}

int Initelem(seqlist *L)//��ʼ��Ԫ��
{
	int i = 0;
	int n = 0;
	int len = 0;
	printf("Start initelem...\n");
	printf("Please input length >: ");
	scanf("%d", &len);
	printf("Please input elem >:");
	for( i = 1; i<len+1; i++)
	{
		scanf("%d",&n);
		Insertelem( L, i, n );
	}
	printf("End initelem...\n");
	return 1;
}

int Insertelem(seqlist *L, int pos, ElemType e )//����
{
	int j = 0;
	if( L->listlength >= L->listsize ) {//�Ϸ��Լ���
		printf("List is full!\n");
		return 0;
	}
	 if(pos <= 0 || pos > L->listlength+1)
    {
        printf("Error pos\n");
        return 0;
    }
	for( j = L->listlength+1; j>pos-1; j--)
	{
		L->data[j] = L->data[j-1];
	}
	L->data[pos-1] = e;
	L->listlength++;
	return 1;
}
int Printlist(seqlist *L)//��ӡ
{
	int i = 0;
	printf(" =====================\n");
	for( i = 0; i<L->listlength; i++)
	{
		printf("%4d", L->data[i]);
		if( 4 == i%5 )
			printf("\n");
	}
	if( 0 != i%5 )//��ʽ����
			printf("\n");
	printf("\n   length = %d\n", L->listlength);
	printf("   size = %d\n", L->listsize);
	printf(" =====================\n");
	return 1;
}
int Delectelem( seqlist *L, int pos )//ɾ��
{
	int j = 0;
	int e = 0;
	if( L->listlength >= L->listsize ) {//�Ϸ��Լ���
		printf("List is full!\n");
		return 0;
	}
	 if(pos <= 0 || pos > L->listlength)
    {
        printf("Error pos\n");
        return 0;
    }
	e = L->data[pos-1];
	for( j = pos-1; j < L->listlength-1; j++ )
	{
		L->data[j] = L->data[j+1];
	}
	L->listlength--;
	return e;
}

//�滻posλ��Ԫ�ص�ֵ
int Exchelem(seqlist *L,int pos,ElemType e)
{
    if(pos<1 || pos>L->listlength){
        printf("Error pos!\n");
        return 0;
    }
    L->data[pos-1] = e;
    return 1;
} 


void meun()//��ӡ�˵�
{
	printf("\n       Welcome          \n");
	printf("--------------------------\n");
	printf("-----  1.Initelem.    ----\n");
	printf("-----  2.Insertelem.  ----\n");
	printf("-----  3.Delectelem.  ----\n");
	printf("-----  4.Exchelem.  ----\n");
	printf("-----  0.Exit.        ----\n");
	printf("--------------------------\n");
}

int main()
{
	int pos = 0;
	int e = 0;
	int select = 0;
	seqlist L;
	Initlist(&L);
	do
	{
		Printlist(&L);
		meun();
		printf("Please select >:");
		scanf("%d", &select);
		switch(select)
		{
			case 1:Initelem(&L);break;
			case 2:printf("Please pos and elem:");
				scanf("%d %d", &pos, &e);
				Insertelem(&L, pos, e);
				break;
			case 3:printf("Please pos:");
				scanf("%d", &pos);
				Delectelem( &L, pos );
				break;
			case 4:printf("Please pos and elem:");
				scanf("%d %d", &pos, &e);
				 Exchelem(&L, pos, e);
				break;
			case 0:printf("Exit...\n");break;
			default:printf("Error select...\n");
		}
	}while(select);
	

	system("pause");
	return 0;
}