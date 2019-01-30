#ifndef _H_BiTree_
#define _H_BiTree_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//���������б�
typedef int status;
typedef int ElemType;
#define TRUE 1
#define ERROR 0
#define FALSE 0
#define OK 1
#define INFEASIBLE -1
#define OVERFLOW -2

//�洢�������͵Ķ���
typedef struct stu{
    char index[100];
    int  id;
}stu;
//������Ҷ�Ķ���
typedef struct BiTNode{
    stu data;
   struct BiTNode *lchild, *rchild;
}BiTNode, *BNode,**defination;

//��������ڵ�Ķ���
typedef struct ListNode
{
    char name[100];
    BNode head;
    struct ListNode *next;
}ListNode,*QueuePtr,*LNode;

//������������
typedef struct
{
//���ڴ��������ţ���0��ʼ
    int k;
    int num;
//ָ��������ͷ���
    ListNode* head;
}Mul_List;

typedef struct
{
    QueuePtr front,rear;
}LinkQueue;

typedef struct defination{
    defination df;
    int n;
}Defination;

void input(int *e)
{
    char ch;
    while(!scanf("%d", e))
    {
        printf("�Ƿ����룬����������\n");
        while ((ch = getchar()) != EOF && ch != '\n');
    }
    while ((ch = getchar()) != EOF && ch != '\n');
}

void printtree(BNode t)
{
    if(t)
        printf("%s\t%d\n",t->data.index,t->data.id);
}

void changeid(int *e)
{
    char ch;
    while(!scanf("%d", e))
    {
        printf("�Ƿ����룬����������!\n");
        while ((ch = getchar()) != EOF && ch != '\n');
    }
    while ((ch = getchar()) != EOF && ch != '\n');
}
#endif

