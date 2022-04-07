#pragma once

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <stack>
#include <vector>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
