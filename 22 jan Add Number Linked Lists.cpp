class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addTwoLists(Node* l1, Node* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        Node* dummy = new Node(0);
        Node* tail = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) sum += l1->data, l1 = l1->next;
            if (l2) sum += l2->data, l2 = l2->next;
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
        }

        Node* res = reverse(dummy->next);
        delete dummy;
        while (res && res->data == 0 && res->next) {
            Node* temp = res;
            res = res->next;
            delete temp;
        }
        return res;
    }
};