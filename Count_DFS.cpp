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
void DFS(int node)
{
    visited[node] = true;
    for (int i = 1; i <= n; i++)
        if(!visited[i] && matrix[node][i] ==1)
        {
            DFS(i);
        }
}
void countTPLT()
{   
    int countt = 0;
    for (int i = 1; i <= n; i++)
        if(visited[i] == false)
            DFS(i);
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