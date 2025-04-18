// ✅ Fixed‐Array Trie (26 pointers per node)
class Trie {
    struct N { N* c[26] = {}; bool e = 0; }*r = new N;
public:
    void insert(string &w) {
        auto n = r;
        for (char ch : w) n = n->c[ch - 'a'] ?: (n->c[ch - 'a'] = new N);
        n->e = 1;
    }
    bool search(string &w) {
        auto n = r;
        for (char ch : w) if (!(n = n->c[ch - 'a'])) return 0;
        return n->e;
    }
    bool isPrefix(string &w) {
        auto n = r;
        for (char ch : w) if (!(n = n->c[ch - 'a'])) return 0;
        return 1;
    }
};
