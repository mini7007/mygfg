
class Solution {
  public:
    Node* cloneGraph(Node* node) {
        if (!node) return 0;
        unordered_map<Node*, Node*> m;
        m[node] = new Node(node->val);
        queue<Node*> q{{node}};
        while (!q.empty()) {
            for (auto n : q.front()->neighbors) {
                if (!m[n]) q.push(n), m[n] = new Node(n->val);
                m[q.front()]->neighbors.push_back(m[n]);
            }
            q.pop();
        }
        return m[node];
    }
};
