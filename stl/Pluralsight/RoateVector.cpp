#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec {1,2,3,4,5,6,7};
    for(auto x: vec)
        cout << x << ' ';

cout << endl;
    rotate(begin(vec), begin(vec)+vec.size()-3, end(vec));

        for(auto x: vec)
        cout << x << ' ';

    return 0;
}
