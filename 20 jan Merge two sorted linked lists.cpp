class Solution {
public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node dummy(0), *tail = &dummy;
        while (head1 && head2) {
            tail->next = (head1->data <= head2->data) ? head1 : head2;
            tail = tail->next;
            if (head1->data <= head2->data) head1 = head1->next;
            else head2 = head2->next;
        }
        tail->next = head1 ? head1 : head2;
        return dummy.next;
    }
};