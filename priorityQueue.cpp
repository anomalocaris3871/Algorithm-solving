#include<iostream>
#include<vector>
#include <queue>

using namespace std;

bool isMarked[26];

class Edge {
public:
    int num;
    int weight;

    Edge(int edge, int weight) {
        this->num = edge;
        this->weight = weight;
    }

    bool operator<(const Edge &edge) const {
        return this->weight > edge.weight;
    }
};


int main(void) {

    int vertexNum;
    int edgeNum;
    cin >> vertexNum >> edgeNum;

    vector<pair<int, int>> graph[26];
    for (int i = 1; i <= edgeNum; ++i) {
        int startEdge;
        int endEdge;
        int weight;
        cin >> startEdge >> endEdge >> weight;
        graph[startEdge].push_back(make_pair(endEdge, weight));
        graph[endEdge].push_back(make_pair(startEdge, weight));
    }

    priority_queue<Edge> queue;
    queue.push(Edge(1, 0));
    int min = 0;
    while (!queue.empty()) {
        Edge edge = queue.top();
        queue.pop();
        if (isMarked[edge.num] == false) {
            isMarked[edge.num] = true;
            min += edge.weight;

            for (int i = 0; i < graph[edge.num].size(); ++i) {
                queue.push(Edge(graph[edge.num][i].first, graph[edge.num][i].second));
            }
        }
    }

    cout << min << endl;
    return 0;
}
