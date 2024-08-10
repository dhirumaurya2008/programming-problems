#include<iostream>
#include<queue>
using namespace std;

class Stack{
queue<int> q1, q2;

public:
    void push(int x){

         while(!q1.empty())
         {
             q2.push(q1.front());
             q1.pop();
         }
         q1.push(x);

         while(!q2.empty()) {
            q1.push(q2.front());
             q2.pop();
         }

    }

    void pop()
    {
        if (q1.empty())
            return ;
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return (q1.front());
    }
};

int main()
{
    vector<int> keys = { 1, 2, 3, 4, 5 };

    // insert the above keys into the stack
    Stack s;
    for (int key: keys) {
        s.push(key);
    }

    cout << "Original Array \n" ;
     for (int key: keys) {
        cout << key << " " << endl;
    }

    for (int i = 0; i <= keys.size(); i++) {
        cout << s.top() << " " ;
        s.pop();
    }

    return 0;
}
