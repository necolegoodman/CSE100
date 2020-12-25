#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct E
{
    int src, d, w;
};
struct G
{
    int c, r;
    struct E* edges;
};
struct G* Graph(int c, int r)
{
    struct G* graph = new G;
    graph->c = c;
    graph->r = r;
    graph->edges = new E[r];
    return graph;
}
void print(int d[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (d[i] == INT_MAX)
            printf("INFINITY\n");
        else
            printf("%d\n", d[i]);
    }
}
void BellmanFord(struct G* graph, int src)
{
    int c = graph->c;
    int r = graph->r;
    int d[c];
    for (int i = 0; i < c; i++)
        d[i] = INT_MAX;
    d[src] = 0;
    for (int i = 1; i <= c - 1; i++)
    {
        for (int j = 0; j < r; j++)
        {
            int u = graph->edges[j].src;
            int v = graph->edges[j].d;
            int w = graph->edges[j].w;
            if (d[u] != INT_MAX && d[u] + w < d[v])
                d[v] = d[u] + w;
        }
    }
    for (int i = 0; i < r; i++)
    {
        int u = graph->edges[i].src;
        int v = graph->edges[i].d;
        int w = graph->edges[i].w;
        if (d[u] != INT_MAX && d[u] + w < d[v])
        {
            cout << "FALSE";
            return;
        }
    }
    cout << "TRUE\n";
    print(d, c);
}
main()
{
    int c, r;
    cin >> c >> r;
    int u, v, l;
    struct G* graph = Graph(c, r);
    for (int i = 0; i < r; i++)
    {
        cin >> u >> v >> l;
        graph->edges[i].src = u;
        graph->edges[i].d = v;
        graph->edges[i].w = c;
    }
    BellmanFord(graph, 0);
}
