#include <iostream>
#include <vector>

using namespace std;

int weights[101];

struct Edge {
    int start;
    int end;
    int weight;

    Edge(int start, int end, int weight) {
        this->start = start;
        this->end = end;
        this->weight = weight;
    }
};

int main(void) {

    int vertexNum;
    int edgeNum;
    cin >> vertexNum >> edgeNum;


    vector<Edge> edges;

    for (int i = 0; i < edgeNum; ++i) {
        int start;
        int end;
        int weight;
        cin >> start >> end >> weight;
        edges.emplace_back(start, end, weight);
    }

    for (int i = 1; i <= vertexNum; ++i) {
        weights[i] = INT_MAX;
    }

    int startCity;
    int endCity;
    cin >> startCity >> endCity;

    weights[startCity] = 0;
    bool isCycle = false;

    for (int i = 1; i <= vertexNum; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            int start = edges[j].start;
            int end = edges[j].end;
            int weight = edges[j].weight;

            if (weights[start] != INT_MAX && weights[start] + weight < weights[end]) {
                if (i == vertexNum) {
                    isCycle = true;
                    break;
                }
                weights[end] = weights[start] + weight;
            }
        }
    }

    if (isCycle) {
        cout << -1 << endl;
    } else {
        cout << weights[endCity] << endl;
    }

    return 0;
}