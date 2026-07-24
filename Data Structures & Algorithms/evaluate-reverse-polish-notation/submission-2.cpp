class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<string> tokenStack;


        constexpr auto add = "+";
        constexpr auto sub = "-";
        constexpr auto mul = "*";
        constexpr auto div = "/";

        for (const auto t : tokens)
        {
            if (t == add)
            {
                int sum = std::atoi(tokenStack.top().c_str());
                tokenStack.pop();
                tokenStack.top() = std::to_string(std::atoi(tokenStack.top().c_str()) + sum);
                continue;
            }
            if (t == sub)
            {
                int minus = std::atoi(tokenStack.top().c_str());
                tokenStack.pop();
                tokenStack.top() = std::to_string(std::atoi(tokenStack.top().c_str()) - minus);
                continue;
            }
            if (t == mul)
            {
                int dot = std::atoi(tokenStack.top().c_str());
                tokenStack.pop();
                tokenStack.top() = std::to_string(std::atoi(tokenStack.top().c_str()) * dot);
                continue;
            }
            if (t == div)
            {
                int rdot = std::atoi(tokenStack.top().c_str());
                tokenStack.pop();
                tokenStack.top() = std::to_string(std::atoi(tokenStack.top().c_str()) / rdot);

                continue;
            }

            tokenStack.push(t);
        }

        return std::atoi(tokenStack.top().c_str());
    }
};
