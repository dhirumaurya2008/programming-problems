#include<bits/stdc++.h>
using namespace std;


int main() {
    double eps = 1e-6;
    int x = 2;
    double  mid, low = 1, high = x;

    while ((high-low) > eps ) {

        mid = low + (high-low)/2;

        if (mid*mid < x) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    cout << "Squareroot of X " << x << " = " << low << endl;
    return 0;
}
