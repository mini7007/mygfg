class Solution {
    public:
      bool isBalanced(string& s) {
          stack<char> st;
          for (char c : s) {
              if (c == '(' || c == '{' || c == '[') st.push(c);
              else if (st.empty() || abs(st.top() - c) > 2) return false;
              else st.pop();
          }
          return st.empty();
      }
  };