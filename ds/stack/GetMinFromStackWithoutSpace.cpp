#include<iostream>
#include<stack>
using namespace std;

class Stack{
    stack<int> s;
    int minVal;
public:
    void Push(int x){
        if (s.empty()){
            minVal = x;
            s.push(x);

        }
        else {
            if (x <= s.top()) {
                s.push(2*x - minVal);
                minVal = x;
            }
            else
            {
               s.push(x);
            }
        }

    }

     void Pop(){
        if (s.empty()){
            return;
        }
        else {
            if (s.top() < minVal) {}
             minVal = (2*minVal - s.top());
        }
        s.pop();
    }

    int  Top()
    {
         if (s.empty()){
            return -1;
        }
        else {
            if (s.top() < minVal) {}
             return minVal;
        }
       return s.top();
    }

    int getMin()
    {
         if (s.empty()){
            return -1;
        }
        return minVal;
    }
};
int main()
{
Stack s;

    s.Push(6);
    cout << s.getMin() << endl;

    s.Push(7);
    cout << s.getMin() << endl;

    s.Push(5);
    cout << s.getMin() << endl;

    s.Push(3);
    cout << s.getMin() << endl;

    s.Pop();
    cout << s.getMin() << endl;

    s.Pop();
    cout << s.getMin() << endl;

    return 0;
}
