class Solution {
    int c(Node* r) { return r ? 1 + c(r->left) + c(r->right) : 0; }
    bool p(Node* r, int i, int n) {
        return !r
            || (i < n
                && (!r->left  || r->data >= r->left->data)
                && (!r->right || r->data >= r->right->data)
                && p(r->left,  2*i+1, n)
                && p(r->right, 2*i+2, n)
              );
    }
  public:
    bool isHeap(Node* tree) {
        return p(tree, 0, c(tree));
    }
};
