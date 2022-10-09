#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    map<int, Node*> node_lookup;

    /**
     * The graph is undirected. Therefore if node 1's neighbor is node 2, then
     * node 2's neighbors also contains node 1.
     * 
     * All edges (front and back) have to be visited exactly once.
     * All nodes are created exactly once, and we can check this using the
     * `node_lookup` map.
     */
    Node* cloneGraph(Node* node) {
        if (!node) {  // Input can be empty graph
            return nullptr;
        }

        int val = node->val;
        if (node_lookup.find(val) == node_lookup.end()) {
            Node* node_copy = new Node(val); 
            node_lookup[val] = node_copy;  // Basically DFS `visited` array

            vector<Node*> neighbors_copy;
            for (Node* neighbor : node->neighbors) {
                neighbors_copy.push_back(cloneGraph(neighbor));
            }
            node_copy->neighbors = neighbors_copy;
        }

        return node_lookup[val];
    }
};