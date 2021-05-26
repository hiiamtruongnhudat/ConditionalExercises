#include<bits/stdc++.h>
using namespace std;

int matrix[1001][1001];
int n;
bool visited[1001];
vector<pair<int, int>> T;
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
                T.push_back({u,i});
                q.push(i);
            }
    }
}
void TreeBFS()
{
    memset(visited,false,sizeof(visited));
    BFS(1);
    if (T.size() <  n-1)
        return;
    else
        for (int i = 0; i < T.size(); i++)
            cout << T[i].first << " " << T[i].second << "\n";
}
int main()
{
    __init__();
    TreeBFS();
    return 0;
}