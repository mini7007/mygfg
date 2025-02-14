class Solution {
    public:
        void correctBST(Node* root) {
            Node *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;
            function<void(Node*)> inorder = [&](Node* node) {
                if (!node) return;
                inorder(node->left);
                if (prev && node->data < prev->data) {
                    if (!first) first = prev, middle = node;
                    else last = node;
                }
                prev = node;
                inorder(node->right);
            };
            inorder(root);
            swap(first->data, last ? last->data : middle->data);
        }
    };