#ifndef __LINKLIST2__
#define __LINKLIST2__

#include <stdio.h>
#include <windows.h>
#include <assert.h>

#pragma warning(disable:4996)

//ʵ����ͷ������������²���

typedef int DataType;

typedef struct Node
{
	struct Node* next;
	struct Node* randem;
	DataType data;
}Node, *PNode;

//��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��nextָ��\
ָ����һ���ڵ㣬����һ��randomָ��ָ��������һ�����\
�ڵ��NULL����Ҫ��������������ظ��ƺ������
PNode CopyComplexList(PNode pHead1);

#endif