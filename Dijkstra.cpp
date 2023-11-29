#include <iostream>
#include <queue>
using namespace std;

int weights[21];

struct Edge {
public:
    int vertex;
    int weight;

    Edge(int vertex, int weight) {
        this->vertex = vertex;
        this->weight = weight;
    }

    bool operator<(const Edge &edge) const {
        return this->weight > edge.weight;
    }
};

int main() {
    fill_n(weights, 21, INT_MAX);
    int vertexNum;
    int edgeNum;
    cin >> vertexNum >> edgeNum;

    vector<pair<int, int>> graph[vertexNum + 1];
    for (int i = 0; i < edgeNum; ++i) {
        int vertex;
        int edge;
        int weight;
        cin >> vertex >> edge >> weight;
        graph[vertex].emplace_back(edge, weight);
    }


    priority_queue<Edge> queue;
    queue.emplace(1, 0);
    weights[1] = 0;
    while (!queue.empty()) {
        int vertex = queue.top().vertex;
        int weight = queue.top().weight;
        queue.pop();

        if (weight > weights[vertex]) {
            continue;
        }

        for (int i = 0; i < graph[vertex].size(); ++i) {
            int nextVertex = graph[vertex][i].first;
            int nextWeight = graph[vertex][i].second + weight;
            if (weights[nextVertex] > nextWeight) {
                weights[nextVertex] = nextWeight;
                queue.emplace(nextVertex, nextWeight);
            }
        }
    }

    for (int i = 1; i <= vertexNum; ++i) {
        if (weights[i] != INT_MAX) {
            cout << i << " : " << weights[i] << endl;
        } else {
            cout << i << " : impossible" << endl;
        }
    }
    return 0;
}