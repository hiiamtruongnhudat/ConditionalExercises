#include<bits/stdc++.h>
using namespace std;

int matrix[1001][1001];
int n;
bool visited[1001];
void __init__()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> matrix[i][j];
    memset(visited,false,sizeof(visited));
}
void BFS(int node)
{
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        visited[u] = true;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && matrix[u][i] == 1)
            {
                visited[i] = true;
                q.push(i);
            }
    }
}
void countTPLT()
{   
    int countt = 0;
    for (int i = 1; i <= n; i++)
        if(visited[i] == false)
            BFS(i);
        else
            countt++;
    cout << countt;
}
int main()
{
    __init__();
    countTPLT();
    return 0;
}