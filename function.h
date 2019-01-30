#ifndef _H_FUNCTION_
#define _H_FUNCTION_
#include "BiTree.h"
//��������
int judge(Defination *df);
status InitialLists(Mul_List* L);
status InitialList(ListNode *l);
status InitialTree(Mul_List * L, int k);
status DeleteTree(Mul_List* L, int k);
ListNode * LocateTree(Mul_List *L, int k);
status DeleteTree(Mul_List* L, int k);
void ClearTree(BNode *t);
status ClearBiTree(Mul_List *forest,int k);
status DestoryTree(Mul_List* L, int k);
status NewTree(Mul_List *L);
void ShowAllTrees(Mul_List L);
void ChangeTree(Mul_List *L);
BNode Parent(BNode* t, char *index);
status InitQueue(LinkQueue *Q);
status EnQueue(LinkQueue *Q,BNode e);
status QueueEmpty(LinkQueue Q);
status DeQueue(LinkQueue *Q,BNode *e);
status compare(defination df, int n, char *s);
Defination setdefination();
void CreateBiTree(BNode *t, defination df, int *loc, int n);
LNode ifDestory(Mul_List *forest, int k);
BNode Root(LNode t);
status BiTreeEmpty(Mul_List *forest,int k);
void PreOrderTraverse(BNode t);
void PostOrderTraverse(BNode t);
void InOrderTraverse(BNode t);
void LevelOrderTraverse(BNode t);
void level(BNode t,int h);
int BiTreeDepth(BNode t);
BNode Value(BNode t,char *index);
status Assign(BNode t, char *index, int v);
BNode LeftChild(BNode t, char *index);
BNode RightChild(BNode t, char *index);
BNode LeftSibling(BNode t, char *index);
BNode RightSibling(BNode t, char *index);
status DeleteChild(BNode t, char *index, int d);
status InsertChild(BNode t, char *index, int d, BNode n);
void Save(FILE *fp, BNode t);
void Load(FILE *fp, BNode *t);

/*�ж��������еĺϷ���*/
int judge(Defination *df)
{
    if(df->n == 0)
        return 0;
    if(df->n == 1 && df->df[0] == NULL)
        return 1;
    if(df->n == 1 && df->df[0] != NULL)
        return 0;
    if(df->df[df->n -  1] == NULL && df->df[df->n - 2] == NULL)
        return 1;
    else
        return 0;
}

/*
 * ��������InitialLists
 * ���������Ա���ָ��
 * ����ֵ����ʼ���ɹ�����OK��ʧ�ܷ���ERROR
 * ��ʼ��������
*/
status InitialLists(Mul_List* L)
{
    if(!(L->head = (ListNode *)malloc(sizeof(ListNode))))
        return ERROR;
    if(!(L->head->next = (ListNode *)malloc(sizeof(ListNode))))
        return ERROR;
    L->head->next->next = NULL;
    if(InitialList(L->head->next) == OK)
    {
        L->k = 0;
        L->num = 1;
        return OK;
    }
    else
        return ERROR;
}

/*
 * ��������InitialList
 * ����������ڵ�ָ��
 * ����ֵ���ɹ�����OK��ʧ�ܷ���ERROR
 * ��ʼ��һ����
*/
status InitialList(ListNode *l)
{
    if(l->head = (BNode) malloc (sizeof(BiTNode)))
    {
        printf("����������������֣�\n");
        gets(l->name);
        l->head->lchild=NULL;
        printf("��ʼ���ɹ�\n");
        return OK;
    }
    else
    {
        perror("malloc");
        return ERROR;
    }
}

/*
 * ��������InitialTree
 * ������������ָ��,���ڴ������λ��
 * ����ֵ���ɹ�����OK��ʧ�ܷ���ERROR
 * ��ʼ����ǰ���ڴ������
 */
status InitialTree(Mul_List * L, int k)
{
    ListNode *l = LocateTree(L, k);
    if(!l)
        return ERROR;
    if(InitialList(l) == OK)
        return OK;
    else
        return ERROR;
}

/*
 * ��������LocateTree
 * ������������ָ�룬���ڴ���������
 * ����ֵ���������ڴ�������ĸ��ڵ�ָ�룬�������󷵻�null��
 * ��λ�����ڴ������
 */
ListNode * LocateTree(Mul_List *L, int k)
{
    ListNode *l = L->head->next;
    while(l && k--)
    {
        l = l->next;
    }
    if(l)
    {
        return l;
    }
    else
    {
        printf("�����������!\n");
        return NULL;
    }
}

/*
 * ��������DeleteTree
 * ������������ָ�룬���ڴ���������
 * ����ֵ��ɾ���ɹ�����OK��ʧ�ܷ���ERROR
 * ɾ����ǰ�������
 */
status DeleteTree(Mul_List* L, int k)
{
    ListNode *l = L->head->next, *p = L->head;
    while(l && k--)
    {
        p = l;
        l = l->next;
    }
    if(l)
    {
        p->next = l->next;
        free(l);
        L->num--;
        if(!L->num)
        {
            printf("�ɹ�ɾ����ǰ��������û���������½���\n");
            L->head->next = (ListNode *) malloc (sizeof(ListNode));
            L->num = 1;
            InitialList(L->head->next);
            L->head->next->next = NULL;
        }
        else
        {
            printf("�ɹ�ɾ����ǰ������ǰ���Ѳ����ڣ����л���\n");
            ChangeTree(L);
        }
        return OK;
    }
    else
    {
        printf("�����������\n");
        return ERROR;
    }
}

/*
 * ��������ClearTree
 * ����������ͷָ���ָ��
 * ����ֵ����ճɹ�����OK��ʧ�ܷ���ERROR
 * ������ڲ�������
 */
void ClearTree(BNode *t)
{
   if(*t)
   {
        ClearTree(&((*t)->lchild));
        ClearTree(&((*t)->rchild));
        free(*t);
        *t = NULL;
   }
}

status ClearBiTree(Mul_List *forest,int k)
{
    LNode tree = ifDestory(forest,k);
    if(tree->head->lchild)
    {
        ClearTree(&(tree->head->lchild));
    }
    else
    {
        return ERROR;
    }
    return OK;
}

/*
 * ��������DestoryTree
 * ������������ָ�룬���ڴ���������
 * ����ֵ�����ٳɹ�����OK��ʧ�ܷ���ERROR
 * ���ٵ�ǰ�������
 */
status DestoryTree(Mul_List* L, int k)
{
    ListNode *l = LocateTree(L, k);
    ClearTree(&(l->head));
    if(l)
    {
        free(l->head);
        l->head = NULL;
        printf("�ɹ���������%s\n", l->name);
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/*
 * ��������NewTree
 * ������������ָ��
 * ����ֵ���½��ɹ�����OK��ʧ�ܷ���ERROR
 * �½�һ����
 */
status NewTree(Mul_List *L)
{
    char ch;
    ListNode *l = LocateTree(L, L->num - 1);
    if(!l)
    {
        return ERROR;
    }
    l->next = (ListNode *)malloc(sizeof(ListNode));
    l = l->next;
    l->next = NULL;
    L->num++;
    if(InitialList(l) == OK)
    {
        printf("�����ɹ����Ƿ��л�����������y/Y�л�����������л�\n");
        ch = getchar();
        if(ch == 'y' || ch == 'Y')
        {
            L->k = L->num - 1;
            printf("�л����\n");
        }
        else
        {
            printf("δ�л�\n");
        }
        while ((ch = getchar()) != EOF && ch != '\n');
        return OK;
    }
    else
    {
        printf("����ʧ��\n");
        return ERROR;
    }

}

/*
 * ��������ShowAllTrees
 * ������������ָ��
 * ����ֵ����
 * ��������������ʾ�������������Ҵ�ӡÿ����������
 */
void ShowAllTrees(Mul_List L)
{
    int k = 1;
    ListNode * l = L.head->next;
    while(l)
    {
        printf("��%d---name:%s\n", k++, l->name);
        l = l->next;
    }
}

/*
 * ��������ChangeTree
 * ������������ָ��
 * ����ֵ����
 * �ı䵱ǰ����������
 */
void ChangeTree(Mul_List *L)
{
    int k;
    char ch;
    ShowAllTrees(*L);
    printf("�л�����");
    while(1)

    {
        if(scanf("%d", &k) && k > 0 && k <= L->num)
        {
            L->k = k - 1;
            printf("�л����\n");
            while ((ch = getchar()) != EOF && ch != '\n');
            break;
        }
        else
        {
            printf("�������ݲ��Ϸ�����������\n");
        }
    }
}
/*
 * ��������Parent
 * �����������ڵ㣬����һ���ڵ�Ԫ��
 * ����ֵ����
 * ���ؽڵ��˫��ָ��
 */
BNode Parent(BNode* t, char *index)
{
    LinkQueue q;
    int m,n;
    BNode a;
    if(t)
    {
        InitQueue(&q);
        EnQueue(&q,t);
        while(!QueueEmpty(q))
        {
            DeQueue(&q,&a);
            if(a->lchild)
                m=strcmp(a->lchild->data.index, index);
            else m=1;
            if(a->rchild)
                n=strcmp(a->rchild->data.index, index);
            else n=1;
            if(m==0 || n==0)
                return a;
            else
            {
                if(a->lchild) EnQueue(&q,a->lchild);
                if(a->rchild) EnQueue(&q,a->rchild);
            }
        }
    }
    return NULL;/*���ջ���û�ҵ�*/
}

status InitQueue(LinkQueue *Q)
{
    (*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(ListNode));
    if(!(*Q).front) exit(OVERFLOW);
    (*Q).front->next=NULL;
    return OK;
}

status EnQueue(LinkQueue *Q,BNode e)
{
    QueuePtr p=(QueuePtr)malloc(sizeof(ListNode));
    if(!p)
        exit(OVERFLOW);
    p->head=e;
    p->next=NULL;
    (*Q).rear->next=p;
    (*Q).rear=p;
    return OK;
}

status QueueEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear) return 1;
    else return FALSE;
}

status DeQueue(LinkQueue *Q,BNode *e)
{
    QueuePtr p;
    if((*Q).front==(*Q).rear) return ERROR;
    p=(*Q).front->next;
    *e=p->head;
    (*Q).front->next=p->next;
    if((*Q).rear==p)
        (*Q).rear=(*Q).front;
    free(p);
    return OK;
}

/*
 * ��������compare
 * ������ĳһ������defination��defination�еĽڵ�������������֦�����Ƚ�index
 * ����ֵ����������false������������true
 * �ж�index�Ƿ��ظ�
 */
status compare(defination df, int n, char *s)
{
    for(int i = 0; i < n; i++)
    {
        if(df[i])
        {
            if(!strcmp(df[i]->data.index, s))
            return TRUE;
        }
    }
    return FALSE;
}

/*
 * ��������setdefination
 * ��������
 * ����ֵ�����ڵ�ָ������
 */
Defination setdefination()
{
    Defination* DF = (Defination *)malloc(sizeof(Defination));
    defination df = NULL;
    char index[10];
//���������ж��ٸ���㣬������֦
    int n = 0;
    printf("�������֦��ǰ��������У���'#'�����֦,��EOF��������\nindex:");
    while(scanf("%s",index) != EOF)
    {
        if(strcmp(index, "#"))
        {
            if(compare(df, n, index))
            {
                printf("�����ظ�!,��������\n");
            }
            else
            {
                n++;
                if(!(df = (defination)realloc(df, sizeof(BNode) * n)))
                    perror("realloc");
                df[n - 1] = (BNode)malloc(sizeof(BiTNode));
                strcpy(df[n - 1]->data.index, index);
                printf("id��");
                input(&df[n - 1]->data.id);
                df[n - 1]->lchild = df[n - 1]->rchild = NULL;
            }
        }
        else
        {
            n++;
            if(!(df = (defination)realloc(df, sizeof(BNode) * n)))
                perror("realloc");
            df[n - 1] = NULL;
        }
        printf("index:");
    }
    DF->df = df;
    DF->n = n;
    return *DF;
}

/*
 * ��������CreateBiTree
 * �����������ڵ㣬���壬����д���λ�ã��ڵ�����
 * ����ֵ����
 * ���ܣ�����һ�Ŷ�����
 */
void CreateBiTree(BNode *t, defination df, int *loc, int n)
{
    if(*loc < n)
    {
        if(!df[*loc])
        {
            *t = NULL;
            (*loc)++;
        }
        else
        {
            *t = df[*loc];
            (*loc)++;
            CreateBiTree(&((*t)->lchild), df, loc, n);
            CreateBiTree(&((*t)->rchild), df, loc, n);
        }
    }
}

/*
 * ��������ifDestory
 * ���������ֵ�ַ
 * ����ֵ����ǰ���ѱ����ٷ���null��δ�����ٷ�������ڵ�ָ��
 * ���ܣ��ж϶������Ƿ����
 */
LNode ifDestory(Mul_List *forest,int k)
{
    ListNode *t = LocateTree(forest, k);
    if(t->head == NULL)
    {
        printf("������������!\n");
        return NULL;
    }
    return t;
}

/*
 * ��������Root
 * ������ɭ�ֵ�ַ,��ǰ������������
 * ����ֵ���������ĸ�ָ��
 * ���ܣ��õ���ǰ�������ĸ��ڵ�
 */
BNode Root(LNode t)
{
    return t->head->lchild;
}
/*
 * ��������BiTreeEmpty
 * ������ɭ�ֵ�ַ
 * ����ֵ��Ϊ�շ���TRUE���ǿշ���FALSE
 * ���ܣ��ж�������Ƿ�Ϊ��
 */
status BiTreeEmpty(Mul_List *forest,int k)
{
    ListNode *t = ifDestory(forest,k);
    if(t)
    {
        if(t->head->lchild)
            return FALSE;
        else
            return TRUE;
    }
    else return FALSE;
    return INFEASIBLE;
}

/*
 * ��������PreOrderTraverse
 * �����������ڵ�
 * ����ֵ����
 * ���ܣ�ǰ�����
 */
void PreOrderTraverse(BNode t)
{
    if(t)
    {
        printtree(t);
        PreOrderTraverse(t->lchild);
        PreOrderTraverse(t->rchild);
    }
}

/*
 * ��������PostOrderTraverse
 * �����������ڵ�
 * ����ֵ����
 * ���ܣ��������
 */
void PostOrderTraverse(BNode t)
{
    if(t)
    {
        PostOrderTraverse(t->lchild);
        PostOrderTraverse(t->rchild);
        printtree(t);
    }
}

/*
 * ��������InOrderTraverse
 * �����������ڵ�
 * ����ֵ����
 * ���ܣ��������
 */
void InOrderTraverse(BNode t)
{
    if(t)
    {
        InOrderTraverse(t->lchild);
        printtree(t);
        InOrderTraverse(t->rchild);
    }
}

/*
 * ��������PostOrderTraverse
 * �����������ڵ�
 * ����ֵ����
 * ���ܣ��������
 */
void LevelOrderTraverse(BNode t)
{
    int h,i;
    if(t)
    {
        h=BiTreeDepth(t);
        for(i=1;i<=h;i++)
        {
            level(t,i);
        }
    }
}
void level(BNode t,int h)
{
    if(t)
    {
        if(h==1) printtree(t);
        else
        {
            level(t->lchild,h-1);
            level(t->rchild,h-1);
        }
    }
}

/*
 * ��������BiTreeDepth
 * �����������ڵ�
 * ����ֵ�����
 * ���ܣ���ǰ������������
 */
int BiTreeDepth(BNode t)
{
    int l, r, d;
    if(t == NULL)
        return 0;
    else
    {
        l = BiTreeDepth(t->lchild);
        r = BiTreeDepth(t->rchild);
        d = l>r?l:r;
        return d + 1;
    }
}

/*
 * ��������Value
 * �����������ڵ㣬�ؼ���
 * ����ֵ�������ҽڵ�
 * ���ܣ����ݹؼ����ҽڵ�
 */
BNode Value(BNode t,char *index)
 {
     BNode p;
     if(t)
     {
         if(!(strcmp(t->data.index, index)))
            return t;
         else
         {
             p=Value(t->lchild,index);
             if(p)
                return p;
             else
             {
                 return Value(t->rchild,index);
             }
         }
     }
     return NULL;
 }

/*
 * ��������Assign
 * �����������ڵ㣬index��value
 * ����ֵ����ֵ�ɹ�����OK��ʧ�ܷ���ERROR
 * ���ܣ���ؼ���Ϊkey�Ľڵ㸳ֵΪvalue
 */
status Assign(BNode t, char *index, int v)
{
    t = Value(t, index);
    if(t)
    {
        t->data.id = v;
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/*
 * ��������LeftChild
 * �����������ڵ㣬������indexֵ
 * ����ֵ����������ӷ�������ӣ�û�з���NULL
 * ���ܣ����ָ���ڵ�������
 */
BNode LeftChild(BNode t, char *index)
{
    t = Value(t, index);
    if(t)
        return t->lchild;
    else
        return NULL;
}

/*
 * ��������RightChild
 * �����������ڵ㣬������indexֵ
 * ����ֵ�������Ҷ��ӷ����Ҷ���ָ�룬û�з���NULL
 */
BNode RightChild(BNode t, char *index)
{
    t = Value(t, index);
    if(t)
        return t->rchild;
    else
        return NULL;
}

/*
 * ��������LeftSibling
 * �����������ڵ㣬index
 * ����ֵ������leftsibling����ָ�룬�����ڷ���NULL
 * ���ܣ������ֵ�
 */
BNode LeftSibling(BNode t, char *index)
{
    t=Parent(t,index);
    if(t){
            if(t->lchild){
                            if(!strcmp(t->lchild->data.index, index))
                            {
                                return NULL;
                            }
                            else
                                return t->lchild;
                        }
            else
                return NULL;
         }
    else
        return NULL;
}

/*
 * ��������RightSibling
 * �����������ڵ㣬index
 * ����ֵ������rightsibling����ָ�룬�����ڷ���NULL
 * ���ܣ����Һ���
 */
BNode RightSibling(BNode t, char *index)
{
    t=Parent(t,index);
    if(t){
            if(t->rchild){
                            if(!strcmp(t->rchild->data.index, index))
                            {
                                return NULL;
                            }
                            else
                                return t->rchild;
                        }
            else
                return NULL;
         }
    else
        return NULL;
}

/*
 * ��������DeleteChild
 * �����������ڵ㣬index������ָʾ��
 * ����ֵ��status
 * ���ܣ�ɾ��ָ���ڵ����������
 */
status DeleteChild(BNode t, char *index, int d)
{
    t = Value(t, index);
    if(!t)
    {
        printf("û�ж�Ӧ�ڵ�\n");
        return ERROR;
    }
    if(d == 0)
    {
        if(t->lchild)
        {
            ClearTree(&(t->lchild));
            return OK;
        }
        else
        {
            printf("�ýڵ�û��������\n");
            return ERROR;
        }
    }
    else
    {
        if(t->rchild)
        {
            ClearTree(&(t->rchild));
            return OK;
        }
        else
        {
            printf("�ýڵ�û��������\n");
            return ERROR;
        }
    }
}

/*
 * ��������InsertChild
 * �����������ڵ㣬index������ָʾ�����������ڵ�
 * ����ֵ������ɹ�����OK��ʧ�ܷ���ERROR
 * ���ܣ���������
 */
status InsertChild(BNode t, char *index, int d, BNode n)
{
    t = Value(t, index);
    if(!t)
    {
        printf("δ�ҵ���Ӧ�ڵ�\n");
        return ERROR;
    }
    if(d == 0)
    {
        n->rchild = t->lchild;
        t->lchild = n;
    }
    else
    {
        n->rchild = t->rchild;
        t->rchild = n;
    }
    return OK;
}

/*
 * ��������Save
 * �������ļ�ָ�룬�����ڵ�
 * ����ֵ����
 * ���ܣ�����һ����
 */
void Save(FILE *fp, BNode t)
{
    if(t)
    {
        int i = 1;
        fwrite(&i, sizeof(int), 1, fp);
        fwrite(t, sizeof(BiTNode), 1, fp);
        Save(fp, t->lchild);
        Save(fp, t->rchild);
    }
    else
    {
        int i = 0;
        fwrite(&i, sizeof(int), 1, fp);
    }
}

/*
 * ��������Load
 * �������ļ�ָ�룬�����ڵ�
 * ����ֵ����
 * ���ܣ����ļ��лָ����Ľṹ
 */
void Load(FILE *fp, BNode *t)
{
    int i;
    fread(&i, sizeof(int), 1, fp);
    if(i)
    {
        *t = (BNode)malloc(sizeof(BiTNode));
        fread(*t, sizeof(BiTNode), 1, fp);
        Load(fp, &((*t)->lchild));
        Load(fp, &((*t)->rchild));
    }
    else
    {
        *t = NULL;
    }
}
#endif
