#ifndef _H_FUNCTION_
#define _H_FUNCTION_
#include "BiTree.h"
//函数声明
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

/*判断输入序列的合法性*/
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
 * 函数名：InitialLists
 * 参数：线性表组指针
 * 返回值：初始化成功返回OK，失败返回ERROR
 * 初始化链表组
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
 * 函数名：InitialList
 * 参数：链表节点指针
 * 返回值：成功返回OK，失败返回ERROR
 * 初始化一个树
*/
status InitialList(ListNode *l)
{
    if(l->head = (BNode) malloc (sizeof(BiTNode)))
    {
        printf("请输入这个树的名字：\n");
        gets(l->name);
        l->head->lchild=NULL;
        printf("初始化成功\n");
        return OK;
    }
    else
    {
        perror("malloc");
        return ERROR;
    }
}

/*
 * 函数名：InitialTree
 * 参数：链表组指针,正在处理的树位序
 * 返回值：成功返回OK，失败返回ERROR
 * 初始化当前正在处理的树
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
 * 函数名：LocateTree
 * 参数：链表组指针，正在处理的树编号
 * 返回值：现在正在处理的树的根节点指针，参数有误返回null；
 * 定位到正在处理的树
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
        printf("输入参数有误!\n");
        return NULL;
    }
}

/*
 * 函数名：DeleteTree
 * 参数：链表组指针，正在处理的树编号
 * 返回值：删除成功返回OK，失败返回ERROR
 * 删除当前处理的树
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
            printf("成功删除当前树，现已没有树，请新建：\n");
            L->head->next = (ListNode *) malloc (sizeof(ListNode));
            L->num = 1;
            InitialList(L->head->next);
            L->head->next->next = NULL;
        }
        else
        {
            printf("成功删除当前树，当前树已不存在，请切换：\n");
            ChangeTree(L);
        }
        return OK;
    }
    else
    {
        printf("输入参数有误！\n");
        return ERROR;
    }
}

/*
 * 函数名：ClearTree
 * 参数：树的头指针的指针
 * 返回值：清空成功返回OK，失败返回ERROR
 * 清空正在操作的树
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
 * 函数名：DestoryTree
 * 参数：链表组指针，正在处理的树编号
 * 返回值：销毁成功返回OK，失败返回ERROR
 * 销毁当前处理的树
 */
status DestoryTree(Mul_List* L, int k)
{
    ListNode *l = LocateTree(L, k);
    ClearTree(&(l->head));
    if(l)
    {
        free(l->head);
        l->head = NULL;
        printf("成功销毁树：%s\n", l->name);
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/*
 * 函数名：NewTree
 * 参数：链表组指针
 * 返回值：新建成功返回OK，失败返回ERROR
 * 新建一棵树
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
        printf("创建成功，是否切换到新树，按y/Y切换，其余键不切换\n");
        ch = getchar();
        if(ch == 'y' || ch == 'Y')
        {
            L->k = L->num - 1;
            printf("切换完成\n");
        }
        else
        {
            printf("未切换\n");
        }
        while ((ch = getchar()) != EOF && ch != '\n');
        return OK;
    }
    else
    {
        printf("创建失败\n");
        return ERROR;
    }

}

/*
 * 函数名：ShowAllTrees
 * 参数：链表组指针
 * 返回值：空
 * 遍历所有树，显示树的数量，并且打印每个树的名字
 */
void ShowAllTrees(Mul_List L)
{
    int k = 1;
    ListNode * l = L.head->next;
    while(l)
    {
        printf("树%d---name:%s\n", k++, l->name);
        l = l->next;
    }
}

/*
 * 函数名：ChangeTree
 * 参数：链表组指针
 * 返回值：空
 * 改变当前处理的树编号
 */
void ChangeTree(Mul_List *L)
{
    int k;
    char ch;
    ShowAllTrees(*L);
    printf("切换到：");
    while(1)

    {
        if(scanf("%d", &k) && k > 0 && k <= L->num)
        {
            L->k = k - 1;
            printf("切换完成\n");
            while ((ch = getchar()) != EOF && ch != '\n');
            break;
        }
        else
        {
            printf("输入数据不合法，重新输入\n");
        }
    }
}
/*
 * 函数名：Parent
 * 参数：树根节点，树的一个节点元素
 * 返回值：空
 * 返回节点的双亲指针
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
    return NULL;/*树空或者没找到*/
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
 * 函数名：compare
 * 参数：某一颗树的defination；defination中的节点数量，包括空枝；待比较index
 * 返回值：包含返回false，不包含返回true
 * 判断index是否重复
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
 * 函数名：setdefination
 * 参数：空
 * 返回值：树节点指针数组
 */
Defination setdefination()
{
    Defination* DF = (Defination *)malloc(sizeof(Defination));
    defination df = NULL;
    char index[10];
//保存现在有多少个结点，包括空枝
    int n = 0;
    printf("输入带空枝的前序遍历序列，用'#'代表空枝,用EOF结束输入\nindex:");
    while(scanf("%s",index) != EOF)
    {
        if(strcmp(index, "#"))
        {
            if(compare(df, n, index))
            {
                printf("名字重复!,重新输入\n");
            }
            else
            {
                n++;
                if(!(df = (defination)realloc(df, sizeof(BNode) * n)))
                    perror("realloc");
                df[n - 1] = (BNode)malloc(sizeof(BiTNode));
                strcpy(df[n - 1]->data.index, index);
                printf("id：");
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
 * 函数名：CreateBiTree
 * 参数：树根节点，定义，正在写入的位置，节点数量
 * 返回值：空
 * 功能：创建一颗二叉树
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
 * 函数名：ifDestory
 * 参数：树林地址
 * 返回值：当前树已被销毁返回null，未被销毁返回链表节点指针
 * 功能：判断二叉树是否存在
 */
LNode ifDestory(Mul_List *forest,int k)
{
    ListNode *t = LocateTree(forest, k);
    if(t->head == NULL)
    {
        printf("二叉树不存在!\n");
        return NULL;
    }
    return t;
}

/*
 * 函数名：Root
 * 参数：森林地址,当前处理的树的序号
 * 返回值：返回树的根指针
 * 功能：得到当前处理树的根节点
 */
BNode Root(LNode t)
{
    return t->head->lchild;
}
/*
 * 函数名：BiTreeEmpty
 * 参数：森林地址
 * 返回值：为空返回TRUE，非空返回FALSE
 * 功能：判断这个树是否为空
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
 * 函数名：PreOrderTraverse
 * 参数：树根节点
 * 返回值：空
 * 功能：前序遍历
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
 * 函数名：PostOrderTraverse
 * 参数：树根节点
 * 返回值：空
 * 功能：后序遍历
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
 * 函数名：InOrderTraverse
 * 参数：树根节点
 * 返回值：空
 * 功能：中序遍历
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
 * 函数名：PostOrderTraverse
 * 参数：树根节点
 * 返回值：空
 * 功能：后序遍历
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
 * 函数名：BiTreeDepth
 * 参数：树根节点
 * 返回值：深度
 * 功能：求当前处理的树的深度
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
 * 函数名：Value
 * 参数：树根节点，关键字
 * 返回值：待查找节点
 * 功能：依据关键字找节点
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
 * 函数名：Assign
 * 参数：树根节点，index，value
 * 返回值：赋值成功返回OK，失败返回ERROR
 * 功能：向关键字为key的节点赋值为value
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
 * 函数名：LeftChild
 * 参数：树根节点，待查找index值
 * 返回值：存在左儿子返回左儿子，没有返回NULL
 * 功能：获得指定节点的左儿子
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
 * 函数名：RightChild
 * 参数：树根节点，待查找index值
 * 返回值：存在右儿子返回右儿子指针，没有返回NULL
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
 * 函数名：LeftSibling
 * 参数：树根节点，index
 * 返回值：存在leftsibling返回指针，不存在返回NULL
 * 功能：求左兄弟
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
 * 函数名：RightSibling
 * 参数：树根节点，index
 * 返回值：存在rightsibling返回指针，不存在返回NULL
 * 功能：求右孩子
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
 * 函数名：DeleteChild
 * 参数：树根节点，index，左右指示符
 * 返回值：status
 * 功能：删除指定节点左或右子树
 */
status DeleteChild(BNode t, char *index, int d)
{
    t = Value(t, index);
    if(!t)
    {
        printf("没有对应节点\n");
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
            printf("该节点没有左子树\n");
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
            printf("该节点没有右子树\n");
            return ERROR;
        }
    }
}

/*
 * 函数名：InsertChild
 * 参数：树根节点，index，左右指示符，子树根节点
 * 返回值：插入成功返回OK，失败返回ERROR
 * 功能；插入子树
 */
status InsertChild(BNode t, char *index, int d, BNode n)
{
    t = Value(t, index);
    if(!t)
    {
        printf("未找到相应节点\n");
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
 * 函数名：Save
 * 参数：文件指针，树根节点
 * 返回值：空
 * 功能：保存一颗树
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
 * 函数名：Load
 * 参数：文件指针，树根节点
 * 返回值：空
 * 功能：从文件中恢复树的结构
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
