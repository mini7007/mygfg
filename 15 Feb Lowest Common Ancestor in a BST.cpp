class Solution {
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        while (root && (root->data > max(n1->data, n2->data) || root->data < min(n1->data, n2->data)))
            root = (root->data > n1->data) ? root->left : root->right;
        return root;
    }
};
