#include<bits/stdc++.h>
using namespace std;
// 
int n, matrix[1001][1001];
bool visited[1001];
void DFS(int node)
{   
    cout << node << " ";
    visited[node] = true;
    for (int i = 1; i <= n; i++)
        if(!visited[i] && matrix[node][i] == 1)
            DFS(i);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)       
        for (int j = 1; j <= n; j++ )
            cin >> matrix[i][j];
    int u; cin >> u;
    DFS(u);
    return 0;
}