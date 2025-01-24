class Solution {
public:
    bool detectLoop(Node* head) {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            if ((slow = slow->next) == (fast = fast->next->next))
                return true;
        }
        return false;
    }
};