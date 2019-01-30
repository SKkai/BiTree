#include "BiTree.h"
#include "function.h"

int main()
{
    Mul_List forest;
    LNode tree;
    BNode  t;
    Defination df;
    FILE *fp;
    char index[10];
    int  op = 1, runonce = 1;
    ElemType d,s,id,loc;
    char ch;
    while(op)
    {
        system("cls");	printf("\n\n");
        printf("                    Menu for BiTree               \n");
        printf("-------------------------------------------------\n");
        printf("    	  1.  InitialLists       14. ClearBitree\n");
        printf("    	  2.  DeleteTree         15. BiTreeEmpty\n");
        printf("          3.  InitilaTree        16. BiTreeDepth\n");
        printf("          4.  DestroyTree        17. Value\n");
        printf("    	  5.  NewTree            18. Assign\n");
        printf("    	  6.  ShowAllTrees       19. LeftChild\n");
        printf("    	  7.  ChangeTree         20. RightChild \n");
        printf("    	  8.  CreatBiTree        21. LeftSibling \n");
        printf("          9.  Parent             22. RightSibling\n");
        printf("          10. Root               23. InsertChild\n");
        printf("    	  11. PreOrderTraverse   24. InOrderTraverse \n");
        printf("    	  12. PostOrderTraverse  25. LevelOrderTraverse\n");
        printf("    	  13. SaveTree           26. LoadTree\n");
        printf("          27. Deletechild          0.  EXIT\n");
        printf("-------------------------------------------------\n");
        printf("    输入执行项[0~26]:");
        while(!scanf("%d", &op))
        {
            printf("输入数据不合法!\n");
            while ((ch = getchar()) != EOF && ch != '\n');
        }
        while ((ch = getchar()) != EOF && ch != '\n');
//确保用户只能在内存中有树的情况下继续操作
        if(runonce)
        {
            if(op == 1 || op ==26)
            {
                runonce = 0;
            }
            else
            {
                printf("进入系统需要创建或导入一个森林否则无法进行后续操作\n");
                getchar();
                continue;
            }
        }
        switch(op){
        case 1:
            if(InitialLists(&forest) == OK)
                printf("创建树林成功！\n");
            else
                printf("创建树林失败！\n");
            system("pause");
            break;
        case 2:
            DeleteTree(&forest, forest.k);
            getchar();
            break;
        case 3:
            InitialTree(&forest, forest.k);
            getchar();
            break;
        case 4:
            DestoryTree(&forest, forest.k);
            getchar();
            break;
        case 5:
            NewTree(&forest);
            getchar();
            break;
        case 6:
            printf("现在共有%d颗树在树林内, 现在正在处理树%d\n", forest.num, forest.k + 1);
            ShowAllTrees(forest);
            getchar();
            break;
        case 7:
            printf("现在正在处理树%d\n", forest.k + 1);
            ChangeTree(&forest);
            getchar();
            break;
        case 8:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                t=tree->head->lchild;
                df = setdefination();
                if(judge(&df))
                {
                    loc = 0;
                    CreateBiTree(&t, df.df, &loc, df.n);
                    if(loc == df.n)
                    {
                        tree->head->lchild = t;
                        printf("树%s创建成功\n", tree->name);
                    }
                    else
                    {
                        printf("树%s创建失败\n", tree->name);
                    }
                }
                else
                {
                    printf("树%s创建失败\n", tree->name);
                }
            }
            else
            {
                printf("操作失败!\n");
            }
            getchar();
            break;
        case 9:
            tree = ifDestory(&forest,forest.k);
            if(tree){
                    BNode k=tree->head->lchild;

                if(k)
                {
                    printf("输入index：");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    k = Parent(k, index);
                    if(k)
                        printf("父节点index:%s\tid:%d", k->data.index,k->data.id);
                    else
                        printf("待查找元素父节点不存在\n");
                }
                else
                {
                    printf("空树!\n");
                }
            }
            else
            {
                printf("操作失败!\n");
            }
            getchar();
            break;
        case 10:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                t = Root(tree);
                if(t)
                {
                    printf("根节点index:%s\tid:%d\n",t->data.index,t->data.id);
                }
                else
                {
                    printf("树为空\n");
                }
            }
            else
            {
                printf("操作失败!\n");
            }
            getchar();
            break;
        case 11:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                t = tree->head->lchild;
                if(t)
                    PreOrderTraverse(t);
                else
                    printf("树为空！\n");
            }
            getchar();
            break;
        case 12:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                t = tree->head->lchild;
                if(t)
                    PostOrderTraverse(t);
                else
                    printf("树为空！\n");
            }
            getchar();
            break;
        case 24:
           tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                t = tree->head->lchild;
                if(t)
                    InOrderTraverse(t);
                else
                    printf("树为空！\n");
            }
            getchar();
            break;
        case 25:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                t = tree->head->lchild;
                if(t)
                    LevelOrderTraverse(t);
                else
                    printf("树为空！\n");
            }
            getchar();
            break;
        case 14:
                tree = ifDestory(&forest,forest.k);
                if(tree){
                s = ClearBiTree(&forest,forest.k);
                if(s == OK)
                    printf("清空成功\n");
                else
                    printf("清空失败\n");
                }
                else
            {
                printf("操作失败!\n");
            }
                getchar();
                break;
        case 15:
            s=BiTreeEmpty(&forest,forest.k);
            if(!s) printf("树不为空！");
            else printf("这是空树！");
            getchar();
            break;
        case 16:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                printf("树深度为：%d", BiTreeDepth(tree->head->lchild));
            }
            else printf("操作失败！");
            getchar();
            break;
        case 17:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                t = tree->head->lchild;
                if(t)
                {
                    printf("输入index：");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = Value(t, index);
                    if(t)
                        printtree(t);
                    else
                        printf("待查找节点不存在!\n");
                }
                else
                {
                    printf("树为空！\n");
                }
            }
            else
            {
                printf("操作失败！\n");
            }
            getchar();
            break;
        case 18:
             tree = ifDestory(&forest,forest.k);
             if(tree)
             {
                 t = tree->head->lchild;
                 if(t)
                 {
                     printf("输入要修改节点index：");
                     scanf("%s", index);
                     while ((ch = getchar()) != EOF && ch != '\n');
                     printf("输入要修改的id：");
                     changeid(&id);
                     s = Assign(t, index, id);
                     if(s == OK)
                        printf("赋值成功!\n");
                     else
                        printf("该index不存在！\n");
                 }
             }
            else
             {
                printf("操作失败!\n");
             }
             getchar();
             break;
        case 19:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                t = tree->head->lchild;
                if(t)
                {
                    printf("输入index：");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = LeftChild(t, index);
                    if(t)
                        printtree(t);
                    else
                        printf("待查找节点不存在\n");
                }
                else
                {
                    printf("树为空！\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 20:
             tree = ifDestory(&forest,forest.k);
             if(tree)
            {
                t = tree->head->lchild;
                if(t)
                {
                    printf("输入index：");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = RightChild(t, index);
                    if(t)
                        printtree(t);
                    else
                        printf("待查找节点不存在\n");
                }
                else
                {
                    printf("树为空！\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 21:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                t = tree->head->lchild;
                if(t)
                {
                    printf("输入index：");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = LeftSibling(t, index);
                    if(t)
                        printtree(t);
                    else
                        printf("待查找节点不存在\n");
                }
                else
                {
                    printf("树为空！\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 22:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                t = tree->head->lchild;
                if(t)
                {
                    printf("输入index：");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = RightSibling(t, index);
                    if(t)
                        printtree(t);
                    else
                        printf("待查找节点不存在\n");
                }
                else
                {
                    printf("树为空！\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 23:
             tree = ifDestory(&forest,forest.k);
             int m;
             BNode n=NULL;
             if(tree)
             {
                t=tree->head->lchild;
                df = setdefination();
                //if(judge(&df))
                //{
                    loc = 0;
                    CreateBiTree(&n, df.df, &loc, df.n);
                    if(loc == df.n)
                    {
                        if(!n->rchild)
                           {
                                printf("输入要插入节点的index:");
                                scanf("%s",index);
                                while ((ch = getchar()) != EOF && ch != '\n');
                                printf("插入到左子树输入0，右子树输入1\n");
                                scanf("%d", &d);
                                while(d != 1 && d!= 0)
                                {
                                    printf("非法输入，重新输入：");
                                    scanf("%d", &d);
                                }
                                while ((ch = getchar()) != EOF && ch != '\n');
                                m=InsertChild(t,index,d,n);
                                if(m) printf("插入成功!\n");
                                else  printf("插入失败!\n");
                           }
                        else
                            printf("所建子树右孩子不为空！插入失败！");
                    }
                    else
                    {
                        printf("子树创建失败！\n");
                    }
                //}
            }
            else
            {
                printf("操作失败!\n");
            }
            getchar();
            break;
        case 27:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                t=tree->head->lchild;
                if(t)
                {
                    printf("输入index：");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    printf("删除左子树输入0，右子树输入1\n");
                    scanf("%d", &d);
                    while(d != 1 && d!= 0)
                    {
                        printf("非法输入，重新输入：");
                        scanf("%d", &d);
                    }
                    s = DeleteChild(t, index, d);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    if(s == OK)
                        printf("删除成功!\n");
                    else
                        printf("删除失败!\n");
                }
                else
                {
                    printf("树为空！\n");
                }
            }
            else
            {
                printf("操作失败！\n");
            }
            getchar();
            break;
        case 13:
            {
             char filename[] = {"./"}, name[30];
             printf("输入文件名\n");
             gets(name);
             strcat(filename, name);
             fp = fopen(filename, "wb");
             if(fp)
             {
                 tree = ifDestory(&forest,forest.k);
                 if(tree)
                 {
                     Save(fp, tree->head->lchild);
                     printf("树%s已储存\n", tree->name);
                 }
                 else
                 {
                     printf("操作失败!\n");
                 }
             }
             else
             {
                 printf("文件创建失败！\n");
             }
             fclose(fp);
             getchar();
             break;
            }
        case 26:
            {
            char filename1[] = {"./"}, name1[30];
            printf("输入文件名\n");
            gets(name1);
            strcat(filename1, name1);
            fp = fopen(filename1, "rb");
            if(fp)
            {
                tree = ifDestory(&forest,forest.k);
                if(tree)
                {
                    ClearTree(&(tree->head->lchild));
                    Load(fp, &(tree->head->lchild));
                    printf("文件成功加载到树%s\n", tree->name);
                }
                else
                {
                    printf("操作失败!\n");
                }
            }
            else
            {
                perror("fopen");
                printf("读取失败!\n");
            }
            fclose(fp);
            getchar();
            break;
            }
        case 0:
            printf("欢迎下次使用本系统\n");
            getchar();
            break;
        default:
            printf("非法输入\n");
             break;
        }
    }
}
