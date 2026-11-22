#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int vertices;
    vector<int> adj[20];
    bool visited[20];

public:

    void createGraph()
    {
        int edges, u, v;

        cout << "Enter number of vertices: ";
        cin >> vertices;

        // Initialize visited array
        for(int i = 0; i < vertices; i++)
        {
            visited[i] = false;
        }

        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "Enter edges (source destination):\n";

        for(int i = 0; i < edges; i++)
        {
            cin >> u >> v;

            // Add edges for undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void displayGraph()
    {
        cout << "\nAdjacency List:\n";

        for(int i = 0; i < vertices; i++)
        {
            cout << i << " -> ";

            for(int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }

            cout << endl;
        }
    }

    void BFS(int start)
    {
        // Reset visited array
        for(int i = 0; i < vertices; i++)
        {
            visited[i] = false;
        }

        queue<int> q;

        visited[start] = true;

        q.push(start);

        cout << "BFS Traversal: ";

        while(!q.empty())
        {
            int current = q.front();

            q.pop();

            cout << current << " ";

            for(int i = 0; i < adj[current].size(); i++)
            {
                int next = adj[current][i];

                if(visited[next] == false)
                {
                    visited[next] = true;

                    q.push(next);
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph g;

    int choice, start;

    do
    {
        cout << "\n===== SOCIAL NETWORK MENU =====\n";

        cout << "1. Create Graph\n";
        cout << "2. Display Adjacency List\n";
        cout << "3. Perform BFS\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                g.createGraph();
                break;

            case 2:
                g.displayGraph();
                break;

            case 3:
                cout << "Enter starting vertex: ";
                cin >> start;

                g.BFS(start);
                break;

            case 4:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 4);

    return 0;
}