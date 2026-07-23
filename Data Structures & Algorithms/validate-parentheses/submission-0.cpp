class Solution {
public:
    bool isValid(string s) {
        std::map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        std::stack<char> ourStack;

        for (const char c : s)
        {
            if (c == '(' ||
                c == '[' ||
                c == '{')
            {
                ourStack.push(c);
            }
            else
            {
                if (ourStack.empty())
                    return false;
                else if (ourStack.top() != bracketMap[c])
                    return false;
                else
                    ourStack.pop();
            }
        }

        return ourStack.empty();
    }
};
