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
        printf("    ����ִ����[0~26]:");
        while(!scanf("%d", &op))
        {
            printf("�������ݲ��Ϸ�!\n");
            while ((ch = getchar()) != EOF && ch != '\n');
        }
        while ((ch = getchar()) != EOF && ch != '\n');
//ȷ���û�ֻ�����ڴ�������������¼�������
        if(runonce)
        {
            if(op == 1 || op ==26)
            {
                runonce = 0;
            }
            else
            {
                printf("����ϵͳ��Ҫ��������һ��ɭ�ַ����޷����к�������\n");
                getchar();
                continue;
            }
        }
        switch(op){
        case 1:
            if(InitialLists(&forest) == OK)
                printf("�������ֳɹ���\n");
            else
                printf("��������ʧ�ܣ�\n");
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
            printf("���ڹ���%d������������, �������ڴ�����%d\n", forest.num, forest.k + 1);
            ShowAllTrees(forest);
            getchar();
            break;
        case 7:
            printf("�������ڴ�����%d\n", forest.k + 1);
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
                        printf("��%s�����ɹ�\n", tree->name);
                    }
                    else
                    {
                        printf("��%s����ʧ��\n", tree->name);
                    }
                }
                else
                {
                    printf("��%s����ʧ��\n", tree->name);
                }
            }
            else
            {
                printf("����ʧ��!\n");
            }
            getchar();
            break;
        case 9:
            tree = ifDestory(&forest,forest.k);
            if(tree){
                    BNode k=tree->head->lchild;

                if(k)
                {
                    printf("����index��");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    k = Parent(k, index);
                    if(k)
                        printf("���ڵ�index:%s\tid:%d", k->data.index,k->data.id);
                    else
                        printf("������Ԫ�ظ��ڵ㲻����\n");
                }
                else
                {
                    printf("����!\n");
                }
            }
            else
            {
                printf("����ʧ��!\n");
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
                    printf("���ڵ�index:%s\tid:%d\n",t->data.index,t->data.id);
                }
                else
                {
                    printf("��Ϊ��\n");
                }
            }
            else
            {
                printf("����ʧ��!\n");
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
                    printf("��Ϊ�գ�\n");
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
                    printf("��Ϊ�գ�\n");
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
                    printf("��Ϊ�գ�\n");
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
                    printf("��Ϊ�գ�\n");
            }
            getchar();
            break;
        case 14:
                tree = ifDestory(&forest,forest.k);
                if(tree){
                s = ClearBiTree(&forest,forest.k);
                if(s == OK)
                    printf("��ճɹ�\n");
                else
                    printf("���ʧ��\n");
                }
                else
            {
                printf("����ʧ��!\n");
            }
                getchar();
                break;
        case 15:
            s=BiTreeEmpty(&forest,forest.k);
            if(!s) printf("����Ϊ�գ�");
            else printf("���ǿ�����");
            getchar();
            break;
        case 16:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                printf("�����Ϊ��%d", BiTreeDepth(tree->head->lchild));
            }
            else printf("����ʧ�ܣ�");
            getchar();
            break;
        case 17:
            tree = ifDestory(&forest,forest.k);
            if(tree)
            {
                t = tree->head->lchild;
                if(t)
                {
                    printf("����index��");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = Value(t, index);
                    if(t)
                        printtree(t);
                    else
                        printf("�����ҽڵ㲻����!\n");
                }
                else
                {
                    printf("��Ϊ�գ�\n");
                }
            }
            else
            {
                printf("����ʧ�ܣ�\n");
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
                     printf("����Ҫ�޸Ľڵ�index��");
                     scanf("%s", index);
                     while ((ch = getchar()) != EOF && ch != '\n');
                     printf("����Ҫ�޸ĵ�id��");
                     changeid(&id);
                     s = Assign(t, index, id);
                     if(s == OK)
                        printf("��ֵ�ɹ�!\n");
                     else
                        printf("��index�����ڣ�\n");
                 }
             }
            else
             {
                printf("����ʧ��!\n");
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
                    printf("����index��");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = LeftChild(t, index);
                    if(t)
                        printtree(t);
                    else
                        printf("�����ҽڵ㲻����\n");
                }
                else
                {
                    printf("��Ϊ�գ�\n");
                }
            }
            else
            {
                printf("����ʧ��\n");
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
                    printf("����index��");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = RightChild(t, index);
                    if(t)
                        printtree(t);
                    else
                        printf("�����ҽڵ㲻����\n");
                }
                else
                {
                    printf("��Ϊ�գ�\n");
                }
            }
            else
            {
                printf("����ʧ��\n");
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
                    printf("����index��");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = LeftSibling(t, index);
                    if(t)
                        printtree(t);
                    else
                        printf("�����ҽڵ㲻����\n");
                }
                else
                {
                    printf("��Ϊ�գ�\n");
                }
            }
            else
            {
                printf("����ʧ��\n");
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
                    printf("����index��");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = RightSibling(t, index);
                    if(t)
                        printtree(t);
                    else
                        printf("�����ҽڵ㲻����\n");
                }
                else
                {
                    printf("��Ϊ�գ�\n");
                }
            }
            else
            {
                printf("����ʧ��\n");
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
                                printf("����Ҫ����ڵ��index:");
                                scanf("%s",index);
                                while ((ch = getchar()) != EOF && ch != '\n');
                                printf("���뵽����������0������������1\n");
                                scanf("%d", &d);
                                while(d != 1 && d!= 0)
                                {
                                    printf("�Ƿ����룬�������룺");
                                    scanf("%d", &d);
                                }
                                while ((ch = getchar()) != EOF && ch != '\n');
                                m=InsertChild(t,index,d,n);
                                if(m) printf("����ɹ�!\n");
                                else  printf("����ʧ��!\n");
                           }
                        else
                            printf("���������Һ��Ӳ�Ϊ�գ�����ʧ�ܣ�");
                    }
                    else
                    {
                        printf("��������ʧ�ܣ�\n");
                    }
                //}
            }
            else
            {
                printf("����ʧ��!\n");
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
                    printf("����index��");
                    scanf("%s", index);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    printf("ɾ������������0������������1\n");
                    scanf("%d", &d);
                    while(d != 1 && d!= 0)
                    {
                        printf("�Ƿ����룬�������룺");
                        scanf("%d", &d);
                    }
                    s = DeleteChild(t, index, d);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    if(s == OK)
                        printf("ɾ���ɹ�!\n");
                    else
                        printf("ɾ��ʧ��!\n");
                }
                else
                {
                    printf("��Ϊ�գ�\n");
                }
            }
            else
            {
                printf("����ʧ�ܣ�\n");
            }
            getchar();
            break;
        case 13:
            {
             char filename[] = {"./"}, name[30];
             printf("�����ļ���\n");
             gets(name);
             strcat(filename, name);
             fp = fopen(filename, "wb");
             if(fp)
             {
                 tree = ifDestory(&forest,forest.k);
                 if(tree)
                 {
                     Save(fp, tree->head->lchild);
                     printf("��%s�Ѵ���\n", tree->name);
                 }
                 else
                 {
                     printf("����ʧ��!\n");
                 }
             }
             else
             {
                 printf("�ļ�����ʧ�ܣ�\n");
             }
             fclose(fp);
             getchar();
             break;
            }
        case 26:
            {
            char filename1[] = {"./"}, name1[30];
            printf("�����ļ���\n");
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
                    printf("�ļ��ɹ����ص���%s\n", tree->name);
                }
                else
                {
                    printf("����ʧ��!\n");
                }
            }
            else
            {
                perror("fopen");
                printf("��ȡʧ��!\n");
            }
            fclose(fp);
            getchar();
            break;
            }
        case 0:
            printf("��ӭ�´�ʹ�ñ�ϵͳ\n");
            getchar();
            break;
        default:
            printf("�Ƿ�����\n");
             break;
        }
    }
}
