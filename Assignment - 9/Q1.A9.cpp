#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class Graph
{
    int vertices;
    int adjMatrix[20][20];
    int edges[100][3];
    int edgeCount;

public:
    Graph(int v)
    {
        vertices = v;
        edgeCount = 0;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, int weight)
    {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;

        edges[edgeCount][0] = u;
        edges[edgeCount][1] = v;
        edges[edgeCount][2] = weight;
        edgeCount++;
    }

    void BFS(int start)
    {
        bool visited[20] = {false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < vertices; i++)
            {
                if (adjMatrix[node][i] != 0 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void DFSHelper(int node, bool visited[])
    {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (adjMatrix[node][i] != 0 && !visited[i])
            {
                DFSHelper(i, visited);
            }
        }
    }

    void DFS(int start)
    {
        bool visited[20] = {false};
        cout << "DFS Traversal: ";
        DFSHelper(start, visited);
        cout << endl;
    }

    int findParent(int parent[], int i)
    {
        if (parent[i] == i)
        {
            return i;
        }
        return findParent(parent, parent[i]);
    }

    void unionSets(int parent[], int rank[], int x, int y)
    {
        int xroot = findParent(parent, x);
        int yroot = findParent(parent, y);

        if (rank[xroot] < rank[yroot])
        {
            parent[xroot] = yroot;
        }
        else if (rank[xroot] > rank[yroot])
        {
            parent[yroot] = xroot;
        }
        else
        {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    void kruskalMST()
    {
        int parent[20];
        int rank[20] = {0};

        for (int i = 0; i < vertices; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < edgeCount - 1; i++)
        {
            for (int j = 0; j < edgeCount - i - 1; j++)
            {
                if (edges[j][2] > edges[j + 1][2])
                {
                    int temp0 = edges[j][0];
                    int temp1 = edges[j][1];
                    int temp2 = edges[j][2];
                    edges[j][0] = edges[j + 1][0];
                    edges[j][1] = edges[j + 1][1];
                    edges[j][2] = edges[j + 1][2];
                    edges[j + 1][0] = temp0;
                    edges[j + 1][1] = temp1;
                    edges[j + 1][2] = temp2;
                }
            }
        }

        cout << "Kruskal's MST:" << endl;
        int totalWeight = 0;

        for (int i = 0; i < edgeCount; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            int x = findParent(parent, u);
            int y = findParent(parent, v);

            if (x != y)
            {
                cout << u << " - " << v << " : " << weight << endl;
                totalWeight += weight;
                unionSets(parent, rank, x, y);
            }
        }
        cout << "Total weight: " << totalWeight << endl;
    }

    void primMST()
    {
        int parent[20];
        int key[20];
        bool visited[20] = {false};

        for (int i = 0; i < vertices; i++)
        {
            key[i] = INT_MAX;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < vertices - 1; count++)
        {
            int minKey = INT_MAX;
            int minIndex = 0;

            for (int i = 0; i < vertices; i++)
            {
                if (!visited[i] && key[i] < minKey)
                {
                    minKey = key[i];
                    minIndex = i;
                }
            }

            visited[minIndex] = true;

            for (int i = 0; i < vertices; i++)
            {
                if (adjMatrix[minIndex][i] != 0 && !visited[i] && adjMatrix[minIndex][i] < key[i])
                {
                    parent[i] = minIndex;
                    key[i] = adjMatrix[minIndex][i];
                }
            }
        }

        cout << "Prim's MST:" << endl;
        int totalWeight = 0;
        for (int i = 1; i < vertices; i++)
        {
            cout << parent[i] << " - " << i << " : " << adjMatrix[i][parent[i]] << endl;
            totalWeight += adjMatrix[i][parent[i]];
        }
        cout << "Total weight: " << totalWeight << endl;
    }

    void dijkstra(int start)
    {
        int dist[20];
        bool visited[20] = {false};

        for (int i = 0; i < vertices; i++)
        {
            dist[i] = INT_MAX;
        }

        dist[start] = 0;

        for (int count = 0; count < vertices - 1; count++)
        {
            int minDist = INT_MAX;
            int minIndex = 0;

            for (int i = 0; i < vertices; i++)
            {
                if (!visited[i] && dist[i] < minDist)
                {
                    minDist = dist[i];
                    minIndex = i;
                }
            }

            visited[minIndex] = true;

            for (int i = 0; i < vertices; i++)
            {
                if (!visited[i] && adjMatrix[minIndex][i] != 0 && dist[minIndex] != INT_MAX &&
                    dist[minIndex] + adjMatrix[minIndex][i] < dist[i])
                {
                    dist[i] = dist[minIndex] + adjMatrix[minIndex][i];
                }
            }
        }

        cout << "Dijkstra's Shortest Path from vertex " << start << ":" << endl;
        for (int i = 0; i < vertices; i++)
        {
            cout << "Vertex " << i << " : Distance = " << dist[i] << endl;
        }
    }
};

int main()
{
    int vertices, edges, choice;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    while (true)
    {
        cout << "\n1. BFS Traversal" << endl;
        cout << "2. DFS Traversal" << endl;
        cout << "3. Kruskal's MST" << endl;
        cout << "4. Prim's MST" << endl;
        cout << "5. Dijkstra's Shortest Path" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        int startVertex;

        switch (choice)
        {
        case 1:
            cout << "Enter starting vertex: ";
            cin >> startVertex;
            g.BFS(startVertex);
            break;

        case 2:
            cout << "Enter starting vertex: ";
            cin >> startVertex;
            g.DFS(startVertex);
            break;

        case 3:
            g.kruskalMST();
            break;

        case 4:
            g.primMST();
            break;

        case 5:
            cout << "Enter starting vertex: ";
            cin >> startVertex;
            g.dijkstra(startVertex);
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}