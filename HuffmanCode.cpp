#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

typedef struct
{
    int weight;                        //该结点权值
    int parent;                        //该节点父节点的编号，初始化为0，每当将该节点加入构造的Huffman树之后进行修改
    int left;                          //该节点左子树的编号
    int right;                         //右子树编号
} HuffmanTree;                         //一个HuffmanTree表示的是一个结点，用结构体数组表示所有的结点。从底到顶构造Huffman树

typedef char *HuffmanCode;

void SelectNode(HuffmanTree *ht,int n, int *bt1, int *bt2);  //选择两个结点

void createTree(HuffmanTree *ht, int n, int *w)
{
    int i, m = 2 * n - 1;              //Huffman树只有度为0(叶子结点)和度为2的结点，且N0 = N2 + 1,所以一共有2N0 - 1个结点
    int bt1, bt2;                      //选出的两个结点
    if (n < 1) return ;
    for (i = 1;i <= n; ++i)            //初始化编号1 ~ n为叶子结点，给出的字符串每个字符占一个结点
    {
        ht[i].weight = w[i-1];         //更新每个叶结点的权值，初始化的时候为森林，父节点左右子树编号均为0
        ht[i].parent = 0;
        ht[i].left = 0;
        ht[i].right = 0;
    }
    for(;i <= m; ++i)                  //编号从n+1 ~ m的是度为2的结点，初始化
    {
        ht[i].weight = 0;
        ht[i].parent = 0;
        ht[i].left = 0;
        ht[i].right = 0;
    }
    for (i = n + 1;i <= m; ++i)         //构造Huffman树的过程，也就是构造度为2的结点的过程
    {
        SelectNode(ht, i-1, &bt1, &bt2);   //从1 ~ i-1个结点中，选择权值最小且父节点编号为0的两个结点
        
        ht[bt1].parent = i;                //更新权值最小两个结点的父节点编号为当前编号
            ht[i].left = bt1;                  //更新当前结点的左子树及右子树编号
        ht[i].right = bt2;
        ht[i].weight = ht[bt1].weight + ht[bt2].weight;   //当前结点的权值为左右子树权值之和
    }
}


void SelectNode(HuffmanTree *ht,int n, int *bt1, int *bt2)  //选择两权值最小，且还没加入Huffman树的结点
{
    int i;
    HuffmanTree *ht1, *ht2, *t;
    ht1 = ht2 = NULL;
    for (i = 1;i <= n; ++i)
    {
        if (!ht[i].parent)
        {
            if(ht1 == NULL)
            {
                ht1 = ht + i;
                continue;
            }
            if(ht2 == NULL)
            {
                ht2 = ht + i;
                if (ht1 -> weight > ht2 -> weight)
                {
                    t = ht2;
                    ht2 = ht1;
                    ht1 = t;
                }
                continue;
            }
            if(ht1 && ht2)
            {
                if (ht[i].weight <= ht1->weight)
                {
                    ht2 = ht1;
                    ht1 = ht + i;
                }
                else if(ht[i].weight < ht2->weight){
                    ht2 = ht + i;
                }
            }
        }
    }
    if (ht1 > ht2)
    {
        *bt2 = int(ht1 - ht);
        *bt1 = int(ht2 - ht);
    }
    else{
        *bt1 = int(ht1 - ht);
        *bt2 = int(ht2 - ht);
    }
}

void HuffmanCoding(HuffmanTree *ht, int n, HuffmanCode *hc)
{
    char *cd;
    int start,i;
    int current,parent;
    cd = new char[n];
    cd[n-1] = '\0';
    for (i = 1;i <= n;i++)
    {
        start = n -1;
        current = i;
        parent = ht[current].parent;
        while (parent) {
            if (current == ht[parent].left)
                cd[--start] = '0';
            else
                cd[--start] = '1';
            
            current = parent;
            parent = ht[parent].parent;
        }
        hc[i-1] = new char[n-start];
        
        strcpy(hc[i-1], &cd[start]);
    }
    free(cd);
}

void Encode(HuffmanCode *hc, char *alphabet, char *str, char *code)
{
    int len = 0, i = 0, j;
    code[0] = '\0';
    while (str[i])
    {
        j = 0;
        while (alphabet[j] != str[i]) j++;
        strcpy(code + len, hc[j]);
        len = int(len + strlen(hc[j]));
        i++;
    }
    code[len] = '\0';
}

void Decode(HuffmanTree *ht,int m, char *code, char *alphabet, char *decode)
{
    int position = 0, i,j = 0;
    m = 2 * m - 1;
    while (code[position])
    {
        for (i = m;ht[i].left && ht[i].right; position++)
        {
            if (code[position] == '0')
                i = ht[i].left;
            else
                i = ht[i].right;
        }
        decode[j] = alphabet[i - 1];
        j++;
    }
    decode[j] = '\0';
}


int main()
{
    int i , n = 4, m;
    char test[] = "DBDBDABDCDADBDADBDADACDBDBD";
    char code[100],code1[100];
    char alphabet[] = {'A', 'B', 'C', 'D'};
    int w[] = {5, 7,2, 13};
    HuffmanTree *ht;
    HuffmanCode *hc;
    m = 2 * n -1;
    ht = new HuffmanTree[m+1];
    
    if (!ht)
    {
        printf("内存分配失败");
        exit(0);
    }
    hc = new HuffmanCode[n];
    
    createTree(ht, n, w);
    HuffmanCoding(ht, n, hc);
    
    for (i = 1;i <= n ; i++)
        printf("字母：%c,权重:%d,编码为 %s\n",alphabet[i-1], ht[i].weight,hc[i-1]);
    
    Encode(hc, alphabet, test, code);
    printf("\n 字符串：\n%s\n 转换后为:\n%s\n",test,code);
    
    Decode(ht, n, code, alphabet, code1);
    printf("\n 编码：\n%s\n 转换后为:\n%s\n", code, code1);
    getchar();
    return 0;
}


