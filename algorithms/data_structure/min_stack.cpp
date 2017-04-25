//Using 2 stacks, requires worst case 2n space.
class MinStack{
    stack<int> s1, s2;
public:
    MinStack(){}
    
    void push(int number){
        s1.push(number);
        if (s2.empty() || number<=s2.top()) s2.push(number);
    }
    
    int pop(){
        int cur;
        cur = s1.top();
        s1.pop();
        if (cur==s2.top()) s2.pop();
        return cur;
    }
    
    int min(){
        return s2.top();
    }
};

//Using only 1 stack, requires worst case 2n space.
/*
class MinStack {
    int min_val;
    stack<int> minS;
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        if (minS.empty()){
            min_val = number;
        }
        if (number<=min_val){
            minS.push(min_val);
            min_val = number;
        }
        minS.push(number);
    }

    int pop() {
        // write your code here
        int cur = minS.top();
        minS.pop();
        if (cur==min_val && !minS.empty()){
            min_val = minS.top();
            minS.pop();
        }
        return cur;
    }

    int min() {
        // write your code here
        return min_val;
    }
};
*/
