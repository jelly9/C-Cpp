Status CreateBiTree(BiTree &T) //���򴴽�������
 {  
         char ch;
    scanf("%c",&ch);       
    if (ch=='#')
                   T=NULL; //��ʾĳ�ڵ��Ѿ�����
    else {
                   T = (BiTNode *)malloc(sizeof(BiTNode));  //����ռ�
      if (!T)
                     return ERROR;
      T->data = ch;              // ���ɸ����
      CreateBiTree(T->lchild);   // ����������
      CreateBiTree(T->rchild);   // ����������
    }
    return OK; 
}
void PreOrderTraverse (BiTree T)// �������������
{
   if (T)
   {
        printf("%c",T->data);
      PreOrderTraverse(T->lchild); // ����������
      PreOrderTraverse(T->rchild);// ����������
   }
} 
void InOrderTraverse (BiTree T)// �������������
{
   if (T)
   {
      InOrderTraverse(T->lchild); // ����������
           printf("%c",T->data); 
   InOrderTraverse(T->rchild); // ����������
   }
}
void PostOrderTraverse(BiTree T) //�������������  ���Ҹ�
{
   if (T)
   {
      PostOrderTraverse(T->lchild); // ���������� 
      PostOrderTraverse(T->rchild);  // ����������
           printf("%c",T->data);
   }
}
Status InitStack(SqStack &S)//����һ����ջ
{
         S=(SqStack)malloc(sizeof(LNode));
         if(!S)
                   return ERROR;
         S->next=NULL;
         return OK;
}
Status StackEmpty(SqStack S)//ջ�п�
{
         if (S->next==NULL)
                   printf("\n����һ��������");
         else 
         {
         printf("\n�ⲻ��һ��������");
    return ERROR;
         }
         return OK;
}
Status Push(SqStack &S,BiTree T)
{
         SqStack p;
         p=(SqStack)malloc(sizeof(LNode)); 
if(!S||!p) return ERROR;
         p->data=T;
    p->next=S;
    S=p;
         return OK;
}
Status Pop(SqStack &S,BiTree &e)   //��ջ
{
         SqStack p;
         if (S==NULL) return ERROR;
     else
          {
                    p=S;
                    S=p->next;
                    e=p->data;
         free(p);       
      }
          return OK;
}
Status GetTop(SqStack S,BiTree T) //ȡջ��Ԫ��
{
         SqStack p;
      p=(SqStack)malloc(sizeof(LNode));
         if(!p)
                   return ERROR;
    while(p->next!=NULL)
         {
                   p=p->next;
         }
         T=p->data;
    return OK;  
}
//���в���
Status  InitQueue(LinkQueue &Q) 
{
          Q.front =Q.rear=(QueuePtr)malloc(sizeof(QNode));
         if (!Q.front)
                   return ERROR;                  
         Q.front->next = NULL;
         return OK;
}
Status  EnQueue(LinkQueue &Q,BiTree e)
{
         QueuePtr p;
         p=(QueuePtr)malloc(sizeof (QNode));
         if(!p)  
                   return ERROR;  
         p->data=e; 
         p->next=NULL;
         Q.rear->next = p;  
         Q.rear=p;
         return OK;
}
Status  QueueEmpty(LinkQueue &Q)
{
         if(Q.front->next==NULL)
                   return OK;
         return ERROR;
}                
Status  DeQueue(LinkQueue &Q,BiTree &e)
{
         QueuePtr p;
         if (Q.front == Q.rear)  
                   return ERROR;
         p = Q.front->next; 
         e = p->data;
         Q.front->next = p->next;
         if (Q.rear == p)
                   Q.rear = Q.front; 
         free (p);     
         return OK;
}
 void LevelOrder(BiTree T)//����α���������T�� QΪ����
{
     BiTree b=NULL;
          LinkQueue Q;
          InitQueue(Q);                 
          if (T!=NULL)
          {                                
                    EnQueue(Q,T);                                      
                    while (!QueueEmpty(Q))
                    {              
           DeQueue(Q,b);                     
                            printf("%c",b->data);        
                     if (b->lchild!=NULL)
                                     EnQueue(Q,b->lchild);//�������ǿգ��������
                     if (b->rchild!=NULL)
                                     EnQueue(Q,b->rchild);//�������ǿգ��������
                    }
          }//if
}
Status Depth (BiTree T) // ���ض����������  �ڵ���֮��
{ 
   int depthval,depthLeft,depthRight;
   if (!T) 
            depthval = 0;
   else  
   {
      depthLeft = Depth( T->lchild );  //����ֵΪdepthval
      depthRight= Depth( T->rchild );
      depthval = 1 + (depthLeft > depthRight ?depthLeft : depthRight);
   }
   return depthval; 
}
Status countLeaf(BiTree T) //.ͳ��Ҷ�ӽڵ����Ŀ
 { 
         int num1,num2,num;    
         if (T==NULL)
                   num=0;
         else
                     if((T->lchild==NULL)&&(T->rchild==NULL))
                              num=1;  //�ڵ����
                     else
                     {
                              num1=countLeaf(T->lchild);
                              num2= countLeaf(T->rchild);
                              num= num1+num2;
                     }
         return num;
}
Status CountSingle(BiTree T) //ͳ�Ƶ���֧���
{
         int num1,num2,num; //num1�󵥽��num2�ҵ����   
         if (T==NULL)       //��������
                   num=0;
         else
         {
                   if((T->lchild != NULL)&&(T->rchild == NULL)) //�ý��ֻ������
                   {
                            num1=1;
                            num2=0;
                            num=num1+CountSingle(T->lchild);
                            //num=CountSingle(T->lchild);
                   }
                   if((T->lchild == NULL)&&(T->rchild != NULL)) //�ý��ֻ���Һ���
                   {
                            num1=0;
                            num2=1;
                            num=CountSingle(T->rchild)+num2;      
                            //num=CountSingle(T->rchild); 
         }
                   if((T->lchild == NULL)&&(T->rchild == NULL))//�ý��ΪҶ�ӽ��
                   {
                            num1=0;
                            num2=0;
                            num=0;
                   }
                   if((T->lchild != NULL)&&(T->rchild != NULL)) //�ý��Ϊ��
                   {
                            num1=CountSingle(T->lchild);
                            num2=CountSingle(T->rchild);
                            num=num1+num2;
                   }                
         }
         return num;
}
Status CountDouble(BiTree T)  //ͳ��˫��֧���
{
         int num;  
         if (T==NULL)  //��������
                   num=0;
         else
         {
                   if((T->lchild != NULL)&&(T->rchild == NULL))//�ý��ֻ������
                            num=CountDouble(T->lchild);
                   if((T->lchild == NULL)&&(T->rchild != NULL))//�ý��ֻ���Һ���
                            num=CountDouble(T->rchild);
                   if((T->lchild == NULL)&&(T->rchild == NULL))//�ý��Ϊ�����  //***
                            num=0;
                   if((T->lchild != NULL)&&(T->rchild != NULL))//�ý��Ϊ��
                   {
                            num=CountDouble(T->lchild)+CountDouble(T->rchild)+1;
                   }                
         }
         return num;
}
int countsingle(BiTree T)//���㵥��֧�ڵ��� 
{
         if(T==NULL)
                   return 0;
         else
                   if((T->lchild==NULL)&&(T->rchild==NULL))
                            return 0;//���Ҿ�Ϊ��
                   else
                   {
                            if(!T->lchild && T->rchild)//����ֲ��գ���ݹ�����ұ�
                                     return countsingle(T->rchild)+1;
                            else
                            {
                                     if(T->lchild&&!T->rchild)//�󲻿��ҿգ��ݹ����������
                                               return countsingle(T->lchild)+1;
                                     else //���Ҿ����գ������
                                               return countsingle(T->rchild)+countsingle(T->lchild);
                            }
                   }
}
 int Count_Double(BiTree T)
 {
         //ͳ��˫��֧������Ŀ
         if (T==NULL)
                   return 0;//����
         else if (T->lchild==NULL && T->rchild==NULL)
                   return 0;//Ҷ�ӽ��
         else{         
                   if (!T->lchild && T->rchild)
                            return Count_Double(T->rchild);//ֻ���󵥷�֧
                   if (T->lchild  && !T->rchild)
                            return Count_Double(T->lchild);//ֻ���ҵ���֧
                   if (T->lchild && T->rchild)
                            return Count_Double(T->lchild)+Count_Double(T->rchild)+1;//˫��֧���         
         }
         return Count_Double(T); 
}      
void change_left_right(BiTree T)
{  
         BiTree temp;         
         if (T)
         {
                      change_left_right(T->lchild);
                      change_left_right(T->rchild);
                      temp=T->lchild;
                      T->lchild =T->rchild;
                      T->rchild=temp; 
                   }
}
Status Insert(BiTree &T,char x)
{  
   if (T==NULL)
   {
           T=(BiTree)malloc(sizeof(BiTNode));
      T->data=x;
      T->lchild=T->rchild=NULL;
   }
   else{
               if (x<T->data) Insert(T->lchild,x);
               if (x>T->data) Insert(T->rchild,x);
        }
   return OK;
}  
void CreateSBiTree(BiTree &T)
{
    char x;
    T=NULL;
         printf("������ַ���\n");
         scanf("%c",&x);
    while (x!='@')
         {
        Insert(T,x); 
                    scanf("%c",&x);
    }
}
Status InOrderTraverse(BiTree T)
{//��������ǵݹ��㷨,sΪ�洢���������ָ��ջ
         SqStack S;
         BiTree p;
    InitStack(S);
    p=T;
         while (p||!StackEmpty(S)) 
         {
                   if (p){ Push(S,p); 
               p=p->lchild;}//��ָ���վ������������
                            else
                            {
                                     Pop(S,p);              
                                     cout<<p->data; 
                                     p=p->rchild;
                            }
         }
         return OK;
}

