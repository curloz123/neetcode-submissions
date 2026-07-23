class MinStack {
private:
    std::vector<int> mainStack;
    std::vector<int> minStack;

public:
    MinStack() {

    }
    
    void push(const int val) {
        mainStack.emplace_back(val);
        if (minStack.empty())
        {
            minStack.emplace_back(val);
            return;
        }

        if (val <= minStack[minStack.size() - 1])
        {
            minStack.emplace_back(val);
        }
    }
    
    void pop() {
        if (mainStack[mainStack.size() - 1] == 
            minStack[minStack.size() - 1])
        {
            minStack.pop_back();
        }

        mainStack.pop_back();
    }
    
    int top() {
        return mainStack[mainStack.size() - 1];
    }
    
    int getMin() {
        return minStack[minStack.size() - 1];
    }

};
