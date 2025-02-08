class Solution {
    void lb(Node* r, vector<int>& v) {
        if (!r || (!r->left && !r->right)) return;
        v.push_back(r->data);
        lb(r->left ? r->left : r->right, v);
    }
    void rb(Node* r, vector<int>& v) {
        if (!r || (!r->left && !r->right)) return;
        rb(r->right ? r->right : r->left, v);
        v.push_back(r->data);
    }
    void leaf(Node* r, vector<int>& v) {
        if (!r) return;
        leaf(r->left, v);
        if (!r->left && !r->right) v.push_back(r->data);
        leaf(r->right, v);
    }
public:
    vector<int> boundaryTraversal(Node* r) {
        if (!r) return {};
        vector<int> v = {r->data};
        lb(r->left, v);
        leaf(r->left, v);
        leaf(r->right, v);
        rb(r->right, v);
        return v;
    }
};