#include "LintCodeStructTypes.h"

void bfs(vector<UndirectedGraphNode*>& nodes, int i, unordered_set<UndirectedGraphNode*>& visited, vector<int>& component) {
    queue<UndirectedGraphNode*> s;
    s.push(nodes[i]);
    visited.insert(nodes[i]);

    while(!s.empty()) {
        UndirectedGraphNode* cur = s.front();
        s.pop();
        component.push_back(cur->label);

        for(int j = 0; j < cur->neighbors.size(); ++j) {
            if(visited.find(cur->neighbors[j]) != visited.end()) continue;
            s.push(cur->neighbors[j]);
            visited.insert(cur->neighbors[j]);
        }
    }
}

vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
    // Use BFS to iterate the graph
    vector<vector<int>> res;
    unordered_set<UndirectedGraphNode*> visited;

    for(int i = 0; i < nodes.size(); ++i) {
        if(visited.find(nodes[i]) != visited.end()) continue;
        vector<int> component;
        bfs(nodes, i, visited, component);
        sort(component.begin(), component.end());
        res.push_back(component);
    }

    return res;
}

int main() {
    UndirectedGraphNode* n1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* n2 = new UndirectedGraphNode(2);
    UndirectedGraphNode* n3 = new UndirectedGraphNode(3);
    UndirectedGraphNode* n4 = new UndirectedGraphNode(4);
    UndirectedGraphNode* n5 = new UndirectedGraphNode(5);

    // Component group 1,2,4
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);

    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n4);

    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n2);

    // Component group 3,5
    n3->neighbors.push_back(n5);

    n5->neighbors.push_back(n3);

    vector<UndirectedGraphNode*> nodes = {n1, n2, n3, n4, n5};

    vector<vector<int>> res = connectedSet(nodes);

    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }    

    return 0;
}