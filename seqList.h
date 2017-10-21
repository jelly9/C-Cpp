#ifndef __SEQLIST__
#define __SEQLIST__

#include <stdio.h>
#include <windows.h>
#include <assert.h>

#pragma warning(disable:4018)
#pragma warning(disable:4996)

typedef int DataType;

#define CAPACITY 0
#define INCREASMENT 1

typedef struct SeqList
{
	DataType *data;//������
	size_t size;   //��Ч����Ԫ�صĸ���
	size_t cap; //˳�������
}SeqList;

// ��ʼ��˳���
void InitSeqList(SeqList* pSeq);

// �ݻ�˳���
void DestroySeqList(SeqList* pSeq);

// ��ӡ���Ա�
void PrintSeqList(SeqList* pSeq);

// ��˳����β������ֵΪdata��Ԫ��
void PushBack(SeqList* pSeq, DataType _data);

// ����
int IncSeqList(SeqList* pSeq);

// ����
int IsFull(SeqList* pSeq);

// �п�
int IsEmpty(SeqList* pSeq);

// ��ǰ��ЧԪ�ظ���
int SizeSeqList(SeqList* pSeq);

//������
int CapSeqList(SeqList* pSeq);

// ɾ��˳�������һ��Ԫ��
void PopBack(SeqList* pSeq);

// ��˳����ͷ������ֵΪdata��Ԫ��
void PushFront(SeqList* pSeq, DataType data);

// ɾ��˳���ͷ��Ԫ��
void PopFront(SeqList* pSeq);

// ��˳�����posλ���ϲ���ֵΪdata��Ԫ��
void Insert(SeqList* pSeq, size_t pos, DataType data);

// ɾ��˳�����posλ���ϵ�Ԫ��
void Erase(SeqList* pSeq, size_t pos);

// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ�ص�λ�ã����򷵻�-1
int Find(SeqList* pSeq, DataType data);

// ɾ��˳����е�һ��ֵΪdata��Ԫ��
void Remove(SeqList* pSeq, DataType data);

// ɾ��˳���������ֵΪdata��Ԫ��
void RemoveAll(SeqList* pSeq, DataType data);

// ʹ��ð�������˳����е�Ԫ������
void BubbleSort(SeqList* pSeq);

// ʹ��ѡ�������˳����е�Ԫ������
void SelectSort(SeqList* pSeq);

// ʹ�ö��ֲ�����˳����в���ֵΪdata
int BinarySearch(SeqList* pSeq, DataType data);




#endif

