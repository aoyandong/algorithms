class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        int tmp;
        tmp = top();
        stack2.pop();
        return tmp;
    }

    int top() {
        // write your code here
        int tmp;
        if (stack2.empty()){
            while (!stack1.empty()){
                tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }
        return stack2.top();
    }
};

