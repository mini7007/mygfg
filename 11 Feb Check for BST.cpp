class Solution {
    public:
        bool isBST(Node* root, int min = INT_MIN, int max = INT_MAX) {
            return !root || (root->data > min && root->data < max &&
                             isBST(root->left, min, root->data) &&
                             isBST(root->right, root->data, max));
        }
    };
    