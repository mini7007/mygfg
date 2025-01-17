class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;  // Tracks the previous node
        Node* current = head;  // Current node being processed
        Node* next = nullptr;  // Temporarily holds the next node

        while (current != nullptr) {
            next = current->next;    // Save the next node
            current->next = prev;   // Reverse the current node's pointer
            prev = current;         // Move prev to current
            current = next;         // Move to the next node
        }
        return prev;  // New head of the reversed list
    }
};
