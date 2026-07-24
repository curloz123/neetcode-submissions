class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        st.reserve(tokens.size());
        for (const string& t : tokens) {
            if (t == "+") 
            {
                int b = st.back(); 
                st.pop_back();
                int a = st.back(); 
                st.pop_back();
                st.push_back(a + b);

            } 
            else if (t == "-") 
            {
                int b = st.back(); 
                st.pop_back();
                int a = st.back(); 
                st.pop_back();
                st.push_back(a - b);
            } 
            else if (t == "*") 
            {
                int b = st.back(); 
                st.pop_back();
                int a = st.back(); 
                st.pop_back();
                st.push_back(a * b);
            } 
            else if (t == "/") 
            {
                int b = st.back(); 
                st.pop_back();
                int a = st.back(); 
                st.pop_back();
                st.push_back(a / b);
            } 
            else 
            {
                st.push_back(stoi(t));
            }
        }
        return st.back();
    }
};