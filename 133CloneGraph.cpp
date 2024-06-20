/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;

        int val = node->val;

        vector<Node*> nodes(101, nullptr); nodes[val] = new Node(val);

        queue<Node*> pending; pending.push(node);
        
        while(!pending.empty()) {
            node = pending.front(); pending.pop();

            val = node->val;

            nodes[val]->neighbors.reserve(node->neighbors.size());
 
            for(Node* neighbor : node->neighbors) {
                if(!nodes[neighbor->val]) {
                    nodes[neighbor->val] = new Node(neighbor->val);
                    pending.push(neighbor);
                }

                nodes[val]->neighbors.push_back(nodes[neighbor->val]);
            }
        }

        return nodes[1];
    }
};