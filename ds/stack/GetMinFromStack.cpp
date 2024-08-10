#include<iostream>
#include<stack>
using namespace std;

class Stack{
    stack<int> s, ss;
public:
    void Push(int x){
        if (s.empty()){
            ss.push(x);
        }
        else {
            if (x <= ss.top())
                ss.push(x);
        }
        s.push(x);
    }

     void Pop(){
        if (s.empty()){
            return;
        }
        else {
            if (s.top() == ss.top())
                ss.pop();
        }
        s.pop();
    }

    int  Top()
    {
         if (s.empty()){
            return -1;
        }
        return s.top();
    }
    int getMin()
    {
         if (s.empty()){
            return -1;
        }
        return ss.top();
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
