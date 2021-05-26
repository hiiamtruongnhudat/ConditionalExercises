#include<bits/stdc++.h>
using namespace std;

int n, matrix[1001][1001];

void __init__()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)    
            cin >> matrix[i][j];
}
void EulerCycle(int node)
{
    stack<int> st,CE;
    st.push(node);
    while (!st.empty())
    {   
        int counter = 0;
        int u = st.top();
        for (int i = 1; i <= n; i++)
            if(matrix[u][i] == 0)
                counter++;
        if (counter != n)
        {
            for (int i = 1; i <= n; i++)
                if(matrix[u][i] == 1)
                {
                    st.push(i);
                    matrix[u][i] = matrix[i][u] = 0;
                    break;
                }
        }
        else
        {   
            CE.push(u);
            st.pop();

        }
    }
    while (!CE.empty())
    {
        cout << CE.top() << " -> ";
        CE.pop();
    }
}
int main()
{
    __init__();
    EulerCycle(1);
    return 0;
}