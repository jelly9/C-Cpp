#if 0

#include "LinkList.h"

int main()
{

	
	//PNode ret;
	//PNode L1;
	//PNode L2;
	//PNode pEnterNode;
	//
	//InitList(&L1);
	//InitList(&L2);

	
	//printf("%d\n", Size(L));

	//PushBack(&L1, 1);
	//PushBack(&L1, 2);
	//PushBack(&L1, 3);
	//PushBack(&L1, 4);
	//PushBack(&L1, 5);
	//PushBack(&L1, 6);
	//PushBack(&L1, 7);
	//PushBack(&L1, 8);

	//PushBack(&L2, 6);
	//PushBack(&L2, 10);
	//PushBack(&L2, 6); 
	//PushBack(&L2, 6); 
 
	//PrintList(L);
	//RemoveAll(&L, 6);
	//Erase(&L, Find(L, 8));
	//Back(L1)->next = Find(L1, 5);
	//pEnterNode = GetEnterNode(L1,HasCircle(L1));
	//printf("%d\n", GetEnterNode(L1,HasCircle(L1))->data);


	//PrintList(L);

	//printf("%d\n", Size(L));

	//Erase(&L, 11);
	
	
	//printf("%d\n", Size(L));


	//2��PushBack PushFront PopBack
	//PNode L;
	//InitList(&L);
	//PushBack(&L, 1);
	//PushBack(&L, 2);
	//PushBack(&L, 3);
	//PushBack(&L, 4);
	//PushBack(&L, 5);
	//PopFront(&L);
	//PopFront(&L);
	//PopFront(&L);
	//PopFront(&L);
	//PopFront(&L);
	//PopFront(&L);
	//PopFront(&L);
	//PushFront(&L, 6);
	//PushFront(&L, 7);
	//PushFront(&L, 8);
	//PushFront(&L, 9);
	//PushFront(&L, 10); 
	//PrintList(L);


	/*1����ʼ�� �����½ڵ�
	PNode link;
	PNode i = NULL, j = NULL;
               
	InitList(&link);

	i = BueNode(10);
	j = BueNode(20);

	printf("%d, %d\n", i->data, j->data);*/
	system("pause");
	return 0;
}

#endif




#if 0

#include "LinkList2.h"

/*��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��nextָ��
ָ����һ���ڵ㣬����һ��randomָ��ָ��������һ�����
�ڵ��NULL����Ҫ��������������ظ��ƺ������*/
PNode CopyComplexList(PNode pHead1)
{
	
}

int main()
{
	Node node1, node2, node3, node4;
	node1.data = 1;
	node1.next = &node2;
	node1.randem = &node3;

	node2.data = 2;
	node2.next = &node3;
	node2.randem = &node2;

	node3.data = 3;
	node3.next = &node4;
	node3.randem = NULL;

	node4.data = 4;
	node4.next = NULL;
	node4.randem = &node2;

	return 0;
}

#endif


#include "LinkList.h"

int main()
{

	PNode L;
	InitList(&L);
	PushBack(&L, 1);
	PushBack(&L, 2);
	PushBack(&L, 3);
	PushBack(&L, 4);
	PushBack(&L, 5);

	PrintList(L);
	Reverse(&L);
	PrintList(L);

	return  0;
}
