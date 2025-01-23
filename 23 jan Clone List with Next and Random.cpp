class Solution {
public:
    Node* cloneLinkedList(Node* head) {
        if (!head) return nullptr;
        for (Node* t = head; t; t = t->next->next) {
            Node* n = new Node(t->data);
            n->next = t->next;
            t->next = n;
        }
        for (Node* t = head; t; t = t->next->next)
            if (t->random) t->next->random = t->random->next;
        Node* newHead = head->next;
        for (Node* t = head; t; t = t->next) {
            Node* temp = t->next;
            t->next = temp->next;
            if (temp->next) temp->next = temp->next->next;
        }
        return newHead;
    }
};