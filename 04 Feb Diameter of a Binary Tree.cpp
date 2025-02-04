struct Pair {
    int h, d; // h: height, d: diameter
};

struct Pair f(struct Node* r) {
    struct Pair p = {0, 0};         // Base case: empty node returns {0,0}
    if (!r) return p;
    // Recursively compute left and right subtree results
    struct Pair a = f(r->left), b = f(r->right);
    p.h = 1 + (a.h > b.h ? a.h : b.h);  // Height is max of left/right + 1
    int m = a.d > b.d ? a.d : b.d;        // m: max diameter from children
    int s = a.h + b.h;                    // s: diameter passing through current node
    p.d = m > s ? m : s;                  // Maximum diameter so far
    return p;
}

int diameter(struct Node* root) {
    return f(root).d;                   // Return computed diameter
}