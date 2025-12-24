#include <stdio.h>
#include <limits.h>

#define MAX 20

int minKey(int key[], int visited[], int n)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
    {
        if (visited[v] == 0 && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int n)
{
    int total = 0;
    printf("\nCourier Route (MST):\n");
    printf("Hostel A - Hostel B : Distance\n");

    for (int i = 1; i < n; i++)
    {
        printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("\nTotal Minimum Distance = %d\n", total);
}

void primMST(int graph[MAX][MAX], int n)
{
    int parent[MAX];
    int key[MAX];
    int visited[MAX];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

int main()
{
    int n;
    int graph[MAX][MAX];

    printf("Enter number of hostels: ");
    scanf("%d", &n);

    printf("Enter distance matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, n);

    return 0;
}
