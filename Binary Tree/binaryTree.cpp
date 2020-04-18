#include <iostream>
#include <stack>

using namespace std;

typedef struct BiTNode
{
    char data;
    int lvisited, rvisited; // 左右孩子是否访问过，1表示访问（此项只在后序非递归2算法中需要）
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void InitBiTree(BiTree &T) //构造空二叉树
{
    T = NULL;
}

void CreateBiTree(BiTree &T) //生成二叉树
{
    char ch;
    cin >> ch;
    if (ch == '0') // 0表示空
        T = NULL;
    else
    {
        T = (BiTree)malloc(sizeof(BiTree)); //生成根节点
        if (!T)
        {
            cout << "生成节点错误" << endl;
            return;
        }
        T->data = ch;
        T->lvisited = 0;
        T->rvisited = 0;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void PreOrder(BiTree T) //先序递归遍历
{
    if (T != NULL)
    {
        cout << T->data << " ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void SqlPreOrder(BiTree T) //先序非递归遍历
{
    stack<BiTree> s;
    BiTree p = T;
    while (p || !s.empty())
    {
        if (p)
        {
            cout << p->data << " ";
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            p = p->rchild;
            s.pop();
        }
    }
}

void InOrder(BiTree T) //中序递归遍历
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        cout << T->data << " ";
        InOrder(T->rchild);
    }
}
void SqInOrder(BiTree T) //中序非递归遍历
{
    stack<BiTree> s;
    BiTree p = T;
    while (p || !s.empty())
        if (p)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            cout << p->data << " ";
            s.pop();
            p = p->rchild;
        }
}

void PostOrder(BiTree T) //后序递归遍历
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout << T->data << " ";
    }
}

//后序非递归遍历1思路：因为后序非递归遍历二叉树的顺序是先访问左子树，再访问后子树，最后
//访问根结点。当用堆栈来存储结点，必须分清返回根结点时，是从左子树返回的，还是从右子树
//返回的。所以，使用辅助指针r，其指向最近访问过的结点。
void SqlPostOrder1(BiTree T) //后序非递归遍历1
{
    stack<BiTree> s;
    BiTree p = T, r;
    while (p || !s.empty())
    {
        if (p) //走到最左边
        {
            s.push(p);
            p = p->lchild;
        }
        else //向右
        {
            p = s.top();                     //取栈顶结点
            if (p->rchild && p->rchild != r) //如果右子树存在，且未被访问过
            {
                p = p->rchild;
                s.push(p);
                p = p->lchild; //再走到最左
            }
            else //否则，访问栈顶结点并弹出
            {
                cout << p->data << " ";
                r = p; //记录该结点
                s.pop();
                p = NULL; //结点访问完后，重置p指针
            }
        }
    }
}
//思路2：在结点中增加标志域，记录是否已被访问。
void SqlPostOrder2(BiTree T) //后序非递归遍历2
{
    stack<BiTree> s;
    BiTree p = T;
    while (p || !s.empty())
    {
        if (p && p->lvisited == 0) //左走，且左子树未被访问
        {
            p->lvisited = 1;
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            if (p->rchild != NULL && p->rvisited == 0) //右子树未被访问，右走一步
            {
                p->rvisited = 1;
                p = p->rchild;
            }
            else //访问栈顶元素并弹栈
            {
                cout << p->data << " ";
                s.pop();
                if (!s.empty())
                    p = s.top();
                else //当最后一个元素弹栈出去后，结束
                    return;
            }
        }
    }
}