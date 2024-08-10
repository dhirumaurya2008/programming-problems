#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &vec) {

    cout << "\n Start Printing " << endl;
    for (auto it : vec) {
        cout << it << " " ;
    }
}

bool isSwapNeeded(int a, int b) {
    if (a < b)
        return true;
    return false;
}

int main()
{
    vector<int> vec {7, 4, 5,9,6};

    for (int i = 0; i<vec.size(); i++) {
        for (int j = i+1; j<vec.size(); j++) {

            //if (vec[i] > vec[j])
            if (isSwapNeeded(vec[i], vec[j]))
                swap(vec[i], vec[j]);
        }
    }

    print(vec);

    return 0;
}
