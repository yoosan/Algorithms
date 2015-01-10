/* These code just for binarytree implement, writed by Cliviazhou*/

#include <iostream>
#include <stack>
using namespace std;

#define MAX 100                                //Max length
typedef struct Node                            //The Node of the binarytree
{
    char data;
    Node *lchild,*rchild;
} *Btree;


void createBT(Btree &t);                       //Create a binarytree by preorder

void preorder(Btree &t);                       //Preorder by recursion
void inorder(Btree &t);                        //Inorder by recursion
void postorder(Btree &t);                      //Postorder by recursion

void preorderbyStack(Btree &t);                //Prorder using stack not recursion
void inorderbyStack(Btree &t);                 //Inorder using stack not recursion
void postorderbyStack(Btree &t);               //Postorder using stack not recursion

/*****************Latest Common Father*******************/  // This is the algorithm to find the latest common father of two binarytree node.
int findNode1(Btree &t,char ch,char p[]);      //Find the path which from node1 to root
int findNode2(Btree &t,char ch,char q[]);      //Find the path whick from node2 to root

void compare(char *p,char *q);                 //To compare the path to find the first common node
static int i = 0;
static int j = 0;

void createBT(Btree &t)                        //Create a binarytree , '#' means the NULL pointer.
{
    char ch;
    cin>>ch;
    if(ch == '#') t = NULL;
    
    else
    {
        if(!(t = new Node)) exit(1);
        
        t ->data = ch;                         //Create a binarytree by recursion
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
            cout<<p->data<<" ";                    //Preorder, first visiting root and then visiting the left-binarytree
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
            cout<<p->data<<" ";                     //Inorder, first visiting the left node and then root
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
        if(p)                                       //Postorder, first visiting the left node and the right node, finally root.
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            if( p->rchild&&p->rchild != flag)      //if the left-tree is not NULL and has not been visited
            {
                p = p->rchild;                     //Switch to right-tree
                s.push(p);
                p = p->lchild;
            }
            else                                   //if the rigit-tree is NULL, and then visit current node
            {
                s.pop();
                cout<<p->data<<" ";
                
                flag = p;                          //Mark the node which has been visited just now.
                p = nullptr;                       //Make the pointer p NULL
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
    else if(t->data == ch)                          //Search from the node to root, using string to record the path
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

void compare(char *p,char *q)                         //To compare the two path, the first uncommon node is the LCF
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
    /* Test example：abc##de#g##f### */
    
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
