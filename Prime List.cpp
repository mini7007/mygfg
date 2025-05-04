class Solution {
public:
    Node* primeList(Node* h) {
        int m = 0;
        for (auto p = h; p; p = p->next) m = max(m, p->val);
        vector<char> s(2*m+1, 1);
        s[0] = s[1] = 0;
        for (int i = 2; i*i <= 2*m; ++i)
            if (s[i])
                for (int j = i*i; j <= 2*m; j += i)
                    s[j] = 0;
        for (auto p = h; p; p = p->next) {
            int x = p->val, d = 0;
            while (1) {
                if (x-d > 1 && s[x-d]) { p->val = x-d; break; }
                if (x+d <= 2*m && s[x+d]) { p->val = x+d; break; }
                ++d;
            }
        }
        return h;
    }
};
