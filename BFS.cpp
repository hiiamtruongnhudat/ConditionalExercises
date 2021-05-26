#include<bits/stdc++.h>
using namespace std;
int n, matrix[1001][1001];
bool visited[1001];
void BFS(int node)
{
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        cout << u << " ";
        visited[u] = true;
        for (int i = 1; i <= n; i++)
            if(!visited[i] && matrix[u][i] == 1)
            {
                visited[i] = true;
                q.push(i);
            }
    }
}
int main()
{
    cin >> n;
    for (int i =1 ; i <= n; i++)
        for (int j =1 ; j <= n; j++)
            cin >> matrix[i][j];
    int node; cin >> node;
    BFS(node);
    return 0;
}