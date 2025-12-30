
#include <stdio.h>

#define MAXN 200

int n;
int adj[MAXN][MAXN];
int visited[MAXN];

void dfs(int u, int compId)
{
    visited[u] = compId;
    for (int v = 0; v < n; v++)
    {
        if (adj[u][v] && visited[v] == 0)
        {
            dfs(v, compId);
        }
    }
}

int main()
{

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    int compCount = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            compCount++;
            dfs(i, compCount);
        }
    }

    printf("Cluster sayisi (bagli bilesen): %d\n", compCount);

    for (int c = 1; c <= compCount; c++)
    {
        printf("Cluster %d: ", c);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == c)
                printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
