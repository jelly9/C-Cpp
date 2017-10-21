#ifndef __LINKLIST__
#define __LINKLIST__

#include <stdio.h>
#include <windows.h>
#include <assert.h>

#pragma warning(disable:4996)

//ʵ����ͷ����������²���

typedef int DataType;

typedef struct Node
{
	struct Node* next;
	DataType data;
}Node, *PNode;


/////////////////////////////////////////////////
// ��ʼ��������---˼��ΪʲôҪ���ݶ���ָ��
void InitList(PNode* pHead);

// ������β������ֵΪdata���½��
void PushBack(PNode* pHead, DataType data);

// ɾ����������һ���ڵ�
void PopBack(PNode* pHead);

// ������ͷ��������Ϊdata���½ڵ�
void PushFront(PNode* pHead, DataType data);

// ɾ������ĵ�һ�����
void PopFront(PNode* pHead);

// ����������ֵΪdata�Ľ�㣬���ڷ��ظý��ĵ�ַ�����򷵻ؿ�
PNode Find(PNode pHead, DataType data);

//������posλ�ú����ֵΪdata���½ڵ�
void Insert(PNode pos, DataType data);

// ɾ��������posλ���ϵĽ��
void Erase(PNode* pHead, PNode pos);

// �Ƴ������е�һ��ֵΪdata�Ľ��
void Remove(PNode* pHead, DataType data);

// �Ƴ�����������ֵΪdata�Ľ��
void RemoveAll(PNode* pHead, DataType data);

// ��ȡ�����н����ܸ���
size_t Size(PNode pHead);

// ��ȡ�����е�һ�����
PNode Front(PNode pHead);

// ��ȡ���������һ���ڵ�
PNode Back(PNode pHead);

// �ж������Ƿ�Ϊ��
int Empty(PNode pHead);

// ��ӡ������
void PrintList(PNode pHead);

// �����½ڵ�
PNode BueNode(DataType data);

//��������
void Reverse(PNode* pHead);

////////////////////����������////////////////////////////////////
// ��β��ͷ��ӡ������
void PrintListFromTail(PNode pHead);

// ɾ����ͷ������ķ�β��㣬Ҫ�󣺲��ܱ���������
void DelectNotTailNode(PNode* pHead, PNode pos);
 
// ����ͷ�������ͷ���ǰ�����½ڵ�
void InsertNotHeadNode(PNode pos, DataType data);

//�ж����������Ƿ��ཻ��������
int IsListCross(PNode pHead1, PNode pHead2);
 
//����������Ľ���
PNode GetCrossNode(PNode pHead1, PNode pHead2);

//�ж������Ƿ�����������򷵻�������
PNode HasCircle(PNode pHead);

//�󻷵ĳ���
size_t GetCircleLen(PNode pMeetNode);

//�󻷵���ڵ�
PNode GetEnterNode(PNode pHead, PNode pMeetNode);

//�ж����������Ƿ��ཻ�����Ǵ������
int HasCircleWithircle(PNode pHead1, PNode pHead2);

#endif
