#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int set[10001];

class Edge {
public:
    int startEdge;
    int endEdge;
    int weight;

    Edge(int startEdge, int endEdge, int weight) {
        this->startEdge = startEdge;
        this->endEdge = endEdge;
        this->weight = weight;
    }

    bool operator<(const Edge &edge) const {
        return weight < edge.weight;
    }
};

int find(int value) {
    if(value == set[value]) {
        return value;
    } else {
        return set[value] = find(set[value]);
    }
}

void unionSet(int value1, int value2) {
    value1 = find(value1);
    value2 = find(value2);
    if(value1 != value2) {
        set[value1] = value2;
    }
}

int main(void) {

    vector<Edge> graph;
    int vertexNum;
    int edgeNum;

    cin >> vertexNum >> edgeNum;
    for(int i = 1; i <= vertexNum; ++i) {
        set[i] = i;
    }

    for(int i = 0; i < edgeNum; ++i) {
        int startEdge;
        int endEdge;
        int weight;
        cin >> startEdge >> endEdge >> weight;

        graph.push_back(Edge(startEdge, endEdge, weight));
    }

    sort(graph.begin(), graph.end());

    int min = 0;
    for(int i = 0; i < edgeNum; ++i) {
        int startEdge = graph[i].startEdge;
        int endEdge = graph[i].endEdge;

        int set1 = find(startEdge);
        int set2 = find(endEdge);

        if(set1 != set2) {
            min += graph[i].weight;
            unionSet(startEdge, endEdge);
        }
    }

    cout << min << endl;
    return 0;
}
