#include "LinkList.h"

///////////////////////////////////////////////////
// ˼��ΪʲôҪ���ݶ���ָ��?                     //
//ʹ��һ��ָ�룬���ú���ʱ�β�ѹջ����������ʱ��/
// �βλ���֮�ͷţ��ڼ������������в�������Ч��//
///////////////////////////////////////////////////

 //��ʼ��������
void InitList(PNode* pHead)
{
	assert(pHead);
	*pHead = NULL;
}

// �����½ڵ�
PNode BuyNode(DataType data)
{
	 //�����ڴ�
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if(NULL == pNewNode)
	{
		perror("malloc");
		exit(1);
	}

	pNewNode->data = data;
	pNewNode->next = NULL;

	return pNewNode;
}

// ������β������ֵΪdata���½��
void PushBack(PNode* pHead, DataType data)
{
	PNode pCurNode = *pHead;

	assert(pHead);

	//����Ϊ����ֱ�Ӳ���
	if(NULL == *pHead)
	{
		*pHead = BuyNode(data);
	}
	else
	{
		//����Ѱ��β�ڵ�
		while(pCurNode->next)
		{
			pCurNode = pCurNode->next;
		}
		//����
		pCurNode->next = BuyNode(data);
	}
}

// ɾ����������һ���ڵ�
void PopBack(PNode* pHead)
{
 	PNode pCurNode = *pHead;
	PNode pTailNode = NULL;

	assert(pHead);

	//������Ϊ���򷵻�
	if(NULL == *pHead)
	{
		return ;
	}
	//��ֻ��һ���ڵ�
	else if(NULL == (*pHead)->next)
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		//�ڵ��������һ
		//Ѱ�ҵ����ڶ����ڵ�
		while(pCurNode->next->next)
		{
			pCurNode = pCurNode->next;
		}
		pTailNode = pCurNode->next;//��¼β�ڵ�
		free(pTailNode);//�ͷ�β�ڵ�
		pCurNode->next = NULL;
	}
}

// ������ͷ��������Ϊdata���½ڵ�
void PushFront(PNode* pHead, DataType data)
{
	PNode pNewHead = BuyNode(data);

	pNewHead->next = *pHead;
	*pHead = pNewHead;
}

// ɾ������ĵ�һ�����//
void PopFront(PNode* pHead)
{
	PNode pDelNode = NULL;

	assert(pHead);

	if(NULL == *pHead)
	{
		return ; 
	}
	else
	{
		pDelNode = *pHead;
		*pHead = (*pHead)->next;
		free(pDelNode);
	}
}

// ����������ֵΪdata�Ľ�㣬���ڷ��ظý��ĵ�ַ�����򷵻ؿ�
PNode Find(PNode pHead, DataType data)
{
	PNode pCurNode = pHead;

	//��������
	while(pCurNode)
	{
		if(data == pCurNode->data)
		{
			return pCurNode;
		}
		pCurNode = pCurNode->next;
	}		

	return NULL;
}

//������posλ�ú����ֵΪdata���½ڵ�
void Insert(PNode pos, DataType data)
{
	PNode pNewNode = NULL;

	if(NULL == pos)
	{
		return ;
	}

	pNewNode = BuyNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
}

// ɾ��������posλ���ϵĽ��
void Erase(PNode* pHead, PNode pos)
{
	PNode pPreNode = NULL;

	assert(pHead);

	if(NULL == *pHead || NULL == pos)
	{
		return ;
	}
	//����ɾ�ڵ�Ϊͷ��������⴦��
	if(pos == *pHead)
	{
		(*pHead) = pos->next;
		free(pos);
	}
	//�ҵ���ɾ�ڵ����һ���ڵ�
	else
	{
		pPreNode = *pHead;
		while(pos != pPreNode->next)
		{
			pPreNode = pPreNode->next;
		}
		pPreNode->next = pos->next;
		free(pos);
	}
}

// �Ƴ������е�һ��ֵΪdata�Ľ��
void Remove(PNode* pHead, DataType data)
{
	assert(pHead);

	Erase(pHead, Find(*pHead, data));
}

// �Ƴ�����������ֵΪdata�Ľ��
void RemoveAll(PNode* pHead, DataType data)
{
	PNode pDelNode = NULL;
	PNode pPreNode = NULL;

	pPreNode = *pHead;
	pDelNode = (*pHead)->next;

	assert(pHead);

	//�ȴӵڶ����ڵ㿪ʼ����
	while(pDelNode)
	{
		if(pDelNode->data == data)
		{
			pPreNode->next = pDelNode->next;
			free(pDelNode);
			pDelNode = pPreNode;
		}
		pPreNode = pDelNode;
		pDelNode = pDelNode->next;
	}

	//�������ٴ����һ���ڵ�
	if((*pHead)->data == data)
	{
		pDelNode = *pHead;
		*pHead = pDelNode->next;
		free(pDelNode);
	}
}

////////////////////////////////////////////

// ��ȡ�����н����ܸ���
size_t Size(PNode pHead)
{
	size_t count = 0;
	PNode pCurNode = pHead;

	while(pCurNode)
	{
		count++;
		pCurNode = pCurNode->next;
	}

	return count;
}

// ��ȡ�����е�һ�����
PNode Front(PNode pHead)
{
	return pHead;
}

// ��ȡ���������һ���ڵ�
PNode Back(PNode pHead)
{
	PNode pCurNode = pHead;

	//��Ϊ��ֱ�ӷ���
	if(NULL == pHead)
	{
		return NULL;
	}

	//���������
	else
	{
		while(pCurNode->next)
		{
			pCurNode = pCurNode->next;
		}
		return pCurNode;
	}
}

// �ж������Ƿ�Ϊ��
int Empty(PNode pHead)
{
	if(NULL == pHead)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// ��ӡ������
void PrintList(PNode pHead)
{
	PNode pCurNode = pHead;

	while(pCurNode)
	{
		printf("%d->", pCurNode->data);
		pCurNode = pCurNode->next;
	}
	printf("NULL\n");
}

////////////////////��������///////////////////////////////

//�����ӡ
void PrintListFromTail(PNode pHead)
{
	//�ݹ�
	if(pHead->next)
	{
		PrintListFromTail(pHead->next);
	}
	printf("%d->", pHead->data);
}

//ɾ����β�ڵ�
void DelectNotTailNode(PNode* pHead, PNode pos)
{
	PNode posNextNode = NULL;

	if(NULL == pos || NULL == pos->next)
	{
		return;
	}
	//����ɾ�ڵ��һ���ڵ�data�򸳸���ɾ�ڵ㣬��ɾ������Ľڵ�
	posNextNode = pos->next;
	pos->data = posNextNode->data;
	pos->next = posNextNode->next;
	free(posNextNode);
}

//�ڷ�ͷ�ڵ�ǰ����
void InsertNotHeadNode(PNode pos, DataType data)
{
	PNode pNewNode = NULL;

	if(NULL == pos)
	{
		return ;
	}

	//�嵽�ýڵ�ĺ��棬�ٽ��ýڵ����佻��
	pNewNode = BuyNode(pos->data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
	pos->data = data;
}


//�ж����������Ƿ��ཻ
int IsListCross(PNode pHead1, PNode pHead2)
{
	PNode pTailNodeNode1 = pHead1;
	PNode pTailNodeNode2 = pHead2;

	if(NULL == pHead1 || NULL == pHead2)
	{
		return 0;
	}

	//�ֱ��ҵ����������β�ڵ�
	while(pTailNodeNode1->next)
	{
		pTailNodeNode1 = pTailNodeNode1->next;
	}

	while(pTailNodeNode2->next)
	{
		pTailNodeNode2 = pTailNodeNode2->next;
	}

	if(pTailNodeNode1 == pTailNodeNode2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//����������Ľ���
PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	int gap = Size(pHead1) - Size(pHead2);
	PNode pCurNode1 = pHead1;
	PNode pCurNode2 = pHead2;
	
	//�ó�����������
	if(IsListCross(pHead1, pHead2))
	{
		if(gap>0)
		{
			while(gap--)
			{
				pCurNode1 = pCurNode1->next;
			}
		}
		else
		{
			gap = -gap;
			while(gap--)
			{
				pCurNode1 = pCurNode1->next;
			}
		}
		
		while(pCurNode1 != pCurNode2)
		{
			pCurNode1 = pCurNode1->next;
			pCurNode2 = pCurNode2->next;
		}

		return pCurNode1;
	}
	else
	{
		return NULL;
	}
}


//�ж������Ƿ����,�����򷵻�������
PNode HasCircle(PNode pHead)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;

	while(pFast && pFast->next)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
		if(pSlow == pFast)
		{
			return pSlow;
		}
	}

	return NULL;
}

//�󻷵ĳ���
size_t GetCircleLen(PNode pMeetNode)
{
	size_t count = 0;
	PNode pCurNode = pMeetNode;

	if(NULL == pMeetNode)
	{
		return 0;
	}
	 
	while(pCurNode != pMeetNode)
	{
		count++;
		pCurNode = pCurNode->next;
	}

	return count;
	
}

//�󻷵���ڵ�
PNode GetEnterNode(PNode pHead, PNode pMeetNode)
{
	PNode pH = pHead;
	PNode pM = pMeetNode;

	if(NULL == pHead || NULL == pMeetNode)
	{
		return NULL;
	}

	while(pH != pM)
	{
		pH = pH->next;
		pM = pM->next;
	}
	return pH;
}

//�ж����������Ƿ��ཻ�����Ǵ������
int HasCircleWithircle(PNode pHead1, PNode pHead2)
{
	PNode pL1 = pHead1;
	PNode pL2 = pHead2;

	PNode pCurNode = NULL;

	PNode pMeetNode1 = HasCircle(pHead1);
	PNode pMeetNode2 = HasCircle(pHead2);

	//������������
	if(NULL == pMeetNode1 && NULL == pMeetNode2)
	{
		while(pL1->next)
		{
			pL1 = pL1->next;
		}

		while(pL2->next)
		{
			pL2 = pL2->next;	
		}

		if(pL1 == pL2)
		{
			return 1;
		}
	}
	//����������
	else if(pMeetNode1 && pMeetNode2)
	{
		pCurNode = pMeetNode1;
		while(pCurNode->next != pMeetNode1)
		{
			if(pCurNode == pMeetNode2)
			{
				return 2;
			}
			pCurNode = pCurNode->next;
		}
		if(pCurNode == pMeetNode2)
		{
			return 2;
		}
	}

	return 0;
}

//��������
void Reverse(PNode* pHead)
{
	PNode pCurNode = *pHead;
	PNode pPreNode = NULL;
	PNode pNextNode = pCurNode->next;

	assert(pHead);

	while(pCurNode->next)
	{
		pCurNode->next = pPreNode;
		pPreNode = pCurNode;
		pCurNode = pNextNode;
		pNextNode = pNextNode->next;
	}

	pCurNode->next = pPreNode;
	*pHead = pCurNode;

}







