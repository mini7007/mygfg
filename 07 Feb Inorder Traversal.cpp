class Solution {
    public:
        void f(Node* r, vector<int>& a) {
            if (!r)
                return;
            f(r->left, a);
            a.push_back(r->data);
            f(r->right, a);
        }
        
        vector<int> inOrder(Node* r) {
            vector<int> a;
            f(r, a);
            return a;
        }
    };