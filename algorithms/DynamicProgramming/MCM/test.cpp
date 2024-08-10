#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


int solveEggDrop(int n, int k) {

    if (k == 1 || k == 0)
      return k;

    if (n == 1)
      return k;

    int min = INT_MAX, x, res;

    for (x = 1; x <= k; x++) {
      res = max(
        solveEggDrop(n - 1, x - 1),
        solveEggDrop(n, k - x));
      if (res < min)
        min = res;
    }

    return min + 1;
  }

int main() {

    int n = 2, k = 36;
    cout<<solveEggDrop(n, k);
    return 0;
}
