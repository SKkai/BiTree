#ifndef _H_BiTree_
#define _H_BiTree_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//返回类型列表
typedef int status;
typedef int ElemType;
#define TRUE 1
#define ERROR 0
#define FALSE 0
#define OK 1
#define INFEASIBLE -1
#define OVERFLOW -2

//存储数据类型的定义
typedef struct stu{
    char index[100];
    int  id;
}stu;
//单个树叶的定义
typedef struct BiTNode{
    stu data;
   struct BiTNode *lchild, *rchild;
}BiTNode, *BNode,**defination;

//整个链表节点的定义
typedef struct ListNode
{
    char name[100];
    BNode head;
    struct ListNode *next;
}ListNode,*QueuePtr,*LNode;

//用来管理多个树
typedef struct
{
//正在处理的树编号，从0开始
    int k;
    int num;
//指向链表组头结点
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
        printf("非法输入，请重新输入\n");
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
        printf("非法输入，请重新输入!\n");
        while ((ch = getchar()) != EOF && ch != '\n');
    }
    while ((ch = getchar()) != EOF && ch != '\n');
}
#endif

