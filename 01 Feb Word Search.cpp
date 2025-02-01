class Solution {
public:
    bool dfs(vector<vector<char>> &b, string &w, int i, int j, int k) {
        if(k == w.size()) return true;
        if(i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || b[i][j] != w[k]) return false;
        char t = b[i][j]; 
        b[i][j] = '#';
        bool f = dfs(b, w, i-1, j, k+1) || dfs(b, w, i+1, j, k+1) ||
                 dfs(b, w, i, j-1, k+1) || dfs(b, w, i, j+1, k+1);
        b[i][j] = t;
        return f;
    }
    
    bool isWordExist(vector<vector<char>> &b, string w) {
        for(int i = 0; i < b.size(); i++)
            for(int j = 0; j < b[0].size(); j++)
                if(b[i][j] == w[0] && dfs(b, w, i, j, 0))
                    return true;
        return false;
    }
};