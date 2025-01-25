class Solution {
public:
    Node* findFirstNode(Node* head) {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            if ((slow = slow->next) == (fast = fast->next->next)) {
                for (slow = head; slow != fast; slow = slow->next, fast = fast->next);
                return slow;
            }
        }
        return nullptr;
    }
};