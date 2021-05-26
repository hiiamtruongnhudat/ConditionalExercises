#include<bits/stdc++.h>
using namespace std;
#define MAXX 9999999
int n, matrix[1001][1001], dist[1001], s;
bool visited[1001];
int parent[1001];
void __init__()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <=n ; j++)
            cin >> matrix[i][j];
    for(int i = 1; i <= n ;i++)
        dist[i] = MAXX;
    dist[s] = 0;
    parent[s] = -1;
}
int findMinVertex()
{
    int minVertex = -1;
    for (int i = 1; i <= n; i++)
        if(!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex]))
            minVertex = i;
    return minVertex;
}
void Dijkstra(int s)
{
    for (int i = 1; i <= n -1; i++)
    {
        int minVertex = findMinVertex();
        visited[minVertex] = true;
        for (int j = 1; j <= n; j++)
            if(!visited[j] && dist[j] > dist[minVertex] + matrix[minVertex][j] && matrix[minVertex][j] != MAXX)
            {   
                parent[j] = minVertex;
                dist[j] = dist[minVertex] + matrix[minVertex][j];
            }
    }
}
void display(int u , int v)
{
    vector<int> a;
    a.push_back(v);
    while (u != v)
    {
        v = parent[v];
        a.push_back(v);
    }
    reverse(a.begin(),a.end());
    for (int i = 0; i < a.size() -1 ; i++)
        cout << a[i] << "-> ";
    cout << a[a.size()-1];
    
}
int main()
{
    __init__();
    Dijkstra(s);
    display(3,1);
    return 0;
}