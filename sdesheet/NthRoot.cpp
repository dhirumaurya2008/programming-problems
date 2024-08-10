#include<bits/stdc++.h>
using namespace std;
double multiply(int n, int val) {
    double result = 1;
    for (int i=1; i<=n; i++){
         result = result *val;
    }
    return result;
}
double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double precesion = 10e-7;
    double li = 1;
    double hi = m;

    while ((hi-li)>precesion) {
        double mid = (hi+li)/2;
        if (multiply(n, mid) <m) {
            li = mid;
        }
        else {
            hi = mid;
        }
    }
    return li;
}

int main()
{
    int n = 4;
    long long m = 69;
    double pi = 3.14159, npi = -3.14159;
    cout << fixed << setprecision(0) << pi << " " << npi
        << endl;

    cout << setprecision(6) << 5.0 << endl;
    cout  << n<<"th root of " << m << " = " << setprecision(6) << findNthRootOfM(n, m);
    return 0;
}
