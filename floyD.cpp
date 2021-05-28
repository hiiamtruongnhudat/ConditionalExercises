#include<bits/stdc++.h>
using namespace std;
#define MAXX 999999
// define
int n, matrix[1001][1001], dist[1001][1001] ={MAXX},Next[1001][1001];
void __init__()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == MAXX)
                Next[i][j] = MAXX;
            else
                Next[i][j] = j;
            dist[i][j] = matrix[i][j];
        }
}
void floydWarshall()
{
    for (int k = 1; k <= n; k++) 
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (dist[i][k] == MAXX
                    || dist[k][j] == MAXX)
                    continue;
 
                if (dist[i][j] > dist[i][k]
                                    + dist[k][j]) 
                {
                    dist[i][j] = dist[i][k]
                                + dist[k][j];
                    // cout <<  i << " - " << j << ":" <<  dist[i][j] << "\n";
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}
void ReconstructPath(int u, int v)
{
    if (Next[u][v] == MAXX)
        cout << -1;
    vector<int> path;
    cout << "Dist = " << dist[u][v] << "\n";
    while(u!=v)
    {
        path.push_back(u);
        u = Next[u][v];
    }
    path.push_back(v);
    for (int i = 0; i < path.size() - 1; i++)
        cout << path[i] << " -> ";
    cout << path[path.size() - 1];
}
int main()
{
    __init__();
    floydWarshall();
    ReconstructPath(1,3);
}
/*
9
0 7 999999 9 4 999999 999999 999999 999999
999999 0 3 999999 -4 999999 999999 999999 999999
999999 999999 0 999999 -8 999999 -3 999999 999999
999999 999999 999999 0 999999 999999 999999 -4 999999
999999 999999 999999 5 0 2 999999 3 999999
999999 999999 999999 999999 999999 0 5 999999 2
999999 999999 999999 999999 999999 999999 0 999999 -7
999999 999999 999999 999999 999999 -2 999999 0 -3
999999 999999 999999 999999 999999 999999 999999 999999 0
*/