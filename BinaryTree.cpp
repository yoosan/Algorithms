#include <iostream>
#include <stack>
using namespace std;

#define MAX 100           //字符串最大长度
typedef struct Node       //二叉树结点
{
    char data;
    Node *lchild,*rchild;
} *Btree;


void createBT(Btree &t);  //先序构造二叉树

void preorder(Btree &t);  //二叉树递归先序遍历
void inorder(Btree &t);   //递归中序遍历
void postorder(Btree &t); //递归后序遍历

void preorderbyStack(Btree &t); //先序非递归遍历
void inorderbyStack(Btree &t);  //中序非递归遍历
void postorderbyStack(Btree &t);//后序非递归遍历

/*****************Latest Common Father*******************/
int findNode1(Btree &t,char ch,char p[]); //找出结点1到根的路径
int findNode2(Btree &t,char ch,char q[]); //找出结点2到根的路径

void compare(char *p,char *q);            //比较两条路径，找到第一个公共结点
static int i = 0;
static int j = 0;

void createBT(Btree &t)   //先序创建二叉树 #表示空指针
{
    char ch;
    cin>>ch;
    if(ch == '#') t = NULL;
    
    else
    {
        if(!(t = new Node)) exit(1);
        
        t ->data = ch;    //递归创建二叉树
        createBT(t->lchild);
        createBT(t->rchild);
    }
}



void preorder(Btree &t)
{
    if(t == NULL)
        return ;
    else
    {
        cout<<t->data<<" ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void inorder(Btree &t)
{
    if(!t)
        return;
    else
    {
        inorder(t->lchild);
        cout<<t->data<<" ";
        inorder(t->rchild);
    }
}

void postorder(Btree &t)
{
    if(!t)
        return;
    else
    {
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data<<" ";
    }
}

void preorderbyStack(Btree &t)
{
    stack<Node*>s;
    Node *p = t;
    while (p || !s.empty())
    {
        if(p)
        {
            cout<<p->data<<" ";    //先序遍历二叉树，先访问根节点，再访问左子树
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}

void inorderbyStack(Btree &t)
{
    stack<Node*>s;
    
    Node *p = t;
    
    while (p || !s.empty())
    {
        if(p)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            cout<<p->data<<" ";             //中序遍历二叉树，先访问左子树
            s.pop();
            p = p->rchild;
        }
    }
}

void postorderbyStack(Btree &t)
{
    stack<Node*> s;
    
    Node *p = t;
    Node *flag = nullptr;
    
    while (p || !s.empty())
    {
        if(p)                                   //后序遍历先访问左结点，再右结点，最后根结点
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            if( p->rchild&&p->rchild != flag) //如果右子树不为空且没有被访问过
            {
                p = p->rchild;                 //转到右子树
                s.push(p);
                p = p->lchild;
            }
            else                               //如果右子树为空，当前结点为访问结点
            {
                s.pop();
                cout<<p->data<<" ";
                
                flag = p;                     //把刚刚访问的结点做标记，防止重复访问
                p = nullptr;                  //把p置为空指针，如果不置位空。还要压入栈一次，就造成死循环
            }
        }
    }
}

bool isEmpty(Btree &t)
{
    return t == NULL?true:false;
}

int findNode1(Btree &t,char ch,char p[])
{
    if(!t)
        return 0;
    else if(t->data == ch)                    //从所给的结点出发，搜索到达根节点的路径，并将路径记录下来
    {
        *(p+i) = t->data;
        ++i;
        return 1;
    }
    else
    {
        if(findNode1(t->lchild, ch, p))
        {
            *(p+i) = t->data;
            ++i;
            return 1;
        }
        else if(findNode1(t->rchild, ch, p))
        {
            *(p+i) = t->data;
            ++i;
            return 1;
        }
        else
            return 0;
    }
}

int findNode2(Btree &t,char ch,char q[])
{
    if(!t)
        return 0;
    else if(t->data == ch)
    {
        *(q+j) = t->data;
        ++j;
        return 1;
    }
    else
    {
        if(findNode2(t->lchild, ch, q))
        {
            *(q+j) = t->data;
            ++j;
            return 1;
        }
        else if(findNode2(t->rchild, ch, q))
        {
            *(q+j) = t->data;
            ++j;
            return 1;
        }
        else
            return 0;
    }
}

void compare(char *p,char *q)                     //比较两条路径，第一个不同的路径点的父结点就是其公共父结点
{
    i--;
    j--;
    while(p[i] == q[j])
    {
        i--;
        j--;
    }
    
    cout<<"LCF is :"<<p[i+1]<<endl;
}

int main()
{
    //测试用例：abc##de#g##f###
    
    Btree t = new Node;
    createBT(t);
    preorder(t);
    cout<<endl;
    preorderbyStack(t);
    cout<<endl;
    inorder(t);
    cout<<endl;
    inorderbyStack(t);
    cout<<endl;
    postorder(t);
    cout<<endl;
    postorderbyStack(t);
    cout<<endl;
    
    char a[MAX];
    char b[MAX];

    findNode1(t, 'c',a);
    findNode2(t, 'e',b);
    
    compare(a, b);
    return 0;
}