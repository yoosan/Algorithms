#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define MAX 100
#define INF 32767
typedef string vertexType;
typedef int EdgeType;

typedef struct
{
    vertexType vexs[MAX];
    EdgeType edges[MAX][MAX];
    int n, e;
}mGraph;

void createmGraph(mGraph* &G)
{
    int i, j, k, e, n, w;
    cout << "please input num of vexs, edges"<<endl;
    cin >> n >> e;
    G->e = e;
    G->n = n;
    cout << "please input vexs with char" <<endl;
    for (i = 0; i < G->n; i++)
        cin >> G->vexs[i];
    for (i = 0; i < G->n; i++)
        for (j = 0; j < G->n; j++)
            G->edges[i][j] = INF;
    cout << "please vexs which are adjacent and the weight of this edge" <<endl;
    for (k = 0; k < G->e; k++)
    {
        cin >> i >> j >> w;
        G->edges[i][j] = w;
        //G->edges[j][i] = w;
    }
}

void printGraph(mGraph* &G)
{
    for (int i = 0; i < G->n; i++)
        cout << "---";
    cout << endl;
    for (int i = 0; i < G->n; i++)
    {
        for (int j = 0; j < G->n; j++)
            printf("%4d", G->edges[i][j]);
        cout << endl;
    }
    for (int i = 0; i < G->n; i++)
        cout << "---";
    cout<< endl;
}

int visited[] = {0};
void bfs(mGraph* &G,int k)
{
    int i,j;
    queue<int>q;
    
    cout << "visit vertex: " << G->vexs[k] << endl;
    visited[k] = 1;
    q.push(k);
    
    while (!q.empty())
    {
        i = q.front();
        q.pop();
        for (j = 0; j < G->n; j++)
            if (G->edges[i][j] != INF && !visited[j])
            {
                cout << "visit vertex: "<<G ->vexs[j] << endl;
                visited[j] = 1;
                q.push(j);
            }
    }
}

void bfsTravl(mGraph* &G)
{
    cout << "-------BFSTRAVLE---------" <<endl;
    int i;
    for (i = 0; i < G->n; i++)
        visited[i] = 0;
    for (i = 0; i < G->n; i++)
        if (!visited[i])
            bfs(G, i);
    cout << "----------END------------"<<endl;
}

void dfs(mGraph* &G, int i)
{
    cout << "visit vertex: " << G->vexs[i]<<endl;
    visited[i] = 1;
    int j;
    for (j = 0;j < G->n; j++)
    {
        if (!visited[j] && (G->edges[i][j]) != INF)
            dfs(G,j);
    }
}


void dfsTravl(mGraph* &G )
{
    cout << "-------DFSTRAVLE---------" <<endl;
    int i;
    for (i = 0;i < G ->n;i++)
        visited[i] = 0;
    for (i = 0;i < G->n; i++)
    {
        if(!visited[i])
            dfs(G, i);
    }
    cout << "----------END------------"<<endl;
}

void dispath(int dist[], int path[], int s[], int n, int v)
{
    int i, k;
    for (i = 0; i < n; i++)
        if (s[i] == 1)
        {
            k = i;
            printf("v%d to v%d shortestpath is :",v,i);
            while (k != v)
            {
                printf ("v%d <- ", k);
                k = path[k];
            }
            printf("v%d length is: %d\n",v,dist[i]);
        }
    else
        printf("there is no existence path v%d <- v%d\n",i,v);
}
void dijkstra(mGraph* &G, int v)
{
    int dist[MAX],path[MAX];
    int s[MAX];
    int mindis, i, j, k;
    for (i = 0; i < G->n; i++)
    {
        dist[i] = G->edges[v][i];
        s[i] = 0;
        if (G -> edges[v][i] < INF)
            path[i] = v;
        else
            path[i] = -1;
    }
    s[v] = 1;
    for (i = 0; G->n; i++)
    {
        mindis = INF;
        k = v;
        for (j = 0; j < G->n; j++)
        {
            if (s[j] == 0 && dist[j] < mindis)
            {
                k = j;
                mindis = dist[j];
            }
        }
        s[k] = 1;
        for (j = 0; j < G->n; j++)
        {
            if (s[j] == 0 &&G->edges[k][j] < INF && dist[k] + G->edges[k][j] < dist[j])
            {
                dist[j] = dist[k] + G->edges[k][j];
                path[j] = k;
            }
        }
    }
    dispath(dist, path, s, G->n, v);
}

int main()
{
    mGraph *gra = new mGraph;
    createmGraph(gra);
    printGraph(gra);
    bfsTravl(gra);
    dfsTravl(gra);
    dijkstra(gra, 0);
    return 0;
}