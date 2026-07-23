class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    MinStack() {
    }
    
    void push(const int val) {
        mainStack.push(val);
        if (minStack.empty())
        {
            minStack.push(val);
            return;
        }

        if (val <= minStack.top())
        {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (mainStack.top() == minStack.top())
        {
            minStack.pop();
        }

        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }

};
