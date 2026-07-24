class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> tokenStack;

        constexpr auto add = INT_MAX - 0;
        constexpr auto sub = INT_MAX - 1;
        constexpr auto mul = INT_MAX - 2;
        constexpr auto div = INT_MAX - 3;

        std::vector<int> tVec;
        for (const auto& s : tokens)
        {
            if (s == "+")
                tVec.push_back(add);
            else if (s == "-")
                tVec.push_back(sub);
            else if (s == "*")
                tVec.push_back(mul);
            else if (s == "/")
                tVec.push_back(div);
            else
                tVec.push_back(std::atoi(s.c_str()));
        }

        for (const auto t : tVec)
        {
            if (t == add)
            {
                int sum = tokenStack.top();
                tokenStack.pop();
                tokenStack.top() = tokenStack.top() + sum;
                continue;
            }
            if (t == sub)
            {
                int minus = tokenStack.top();
                tokenStack.pop();
                tokenStack.top() = tokenStack.top() - minus;
                continue;
            }
            if (t == mul)
            {
                int dot = tokenStack.top();
                tokenStack.pop();
                tokenStack.top() = tokenStack.top()* dot;
                continue;
            }
            if (t == div)
            {
                int rdot = tokenStack.top();
                tokenStack.pop();
                tokenStack.top() = tokenStack.top() / rdot;

                continue;
            }

            tokenStack.push(t);
        }

        return tokenStack.top();
    }
};
