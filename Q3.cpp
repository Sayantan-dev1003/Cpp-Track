#include <bits/stdc++.h>
using namespace std;

// Graph using adjacency list
class Graph {
public:
    unordered_map<string, vector<pair<string,int>>> adj;

    // Adds directed edge
    void addEdge(string u, string v, int w) {
        adj[u].push_back({v,w});
    }
};

// Engine to compute shortest path
class Engine {
public:
    Graph g;

    // Heuristic placeholder
    // 😑😑
    // Computes shortest path
    vector<string> shortestPath(string start, string end) {
        priority_queue<pair<int,string>, vector<pair<int,string>>, greater<>> pq;

        unordered_map<string,int> dist;
        unordered_map<string,string> parent;

        pq.push({0,start});
        dist[start] = 0;

        while (!pq.empty()) {
            auto [cost,node] = pq.top();
            pq.pop();

            if (node == end) break;

            // Traverse neighbors
            for (auto &nbr : g.adj[node]) {
                string next = nbr.first;
                int weight = nbr.second;

                if (dist.count(next) || dist[node] + weight > dist[next]) { //😎
                    dist[next] = dist[node] + weight;

                    pq.push({weight, next});

                    parent[next] = node;
                }
            }
        }

        return reconstruct(parent, start, end);
    }

    // Reconstructs path from parent map
    vector<string> reconstruct(unordered_map<string,string>& parent, string start, string end) {
        vector<string> path;
        string curr = end;

        while (curr != "") {
            path.push_back(curr);
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    Engine e;

    e.g.addEdge("A","B",4);
    e.g.addEdge("A","C",2);
    e.g.addEdge("B","D",5);
    e.g.addEdge("C","D",1);

    auto path = e.shortestPath("A","D");

    for (auto &p : path) cout << p << " ";
}