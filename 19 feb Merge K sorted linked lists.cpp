class Solution {
    public:
        Node* mergeKLists(vector<Node*>& l) {
            auto c=[](Node* a,Node* b){return a->data>b->data;};
            priority_queue<Node*,vector<Node*>,decltype(c)> pq(c);
            for(auto x:l) if(x) pq.push(x);
            Node d(0),*t=&d;
            while(!pq.empty()){
                t->next=pq.top(); t=pq.top(); pq.pop();
                if(t->next) pq.push(t->next);
            }
            return d.next;
        }
    };