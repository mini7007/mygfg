class Solution {
public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        for (auto &s : arr) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else st.push(a / b);
            } else st.push(stoi(s));
        }
        return st.top();
    }
};
