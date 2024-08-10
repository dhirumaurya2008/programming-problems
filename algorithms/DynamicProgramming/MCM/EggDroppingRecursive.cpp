/*
The following is a description of the instance of this famous puzzle involving n=2 eggs and a building with k=36 floors.
Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the eggs to break on landing. We make a few assumptions:
…..An egg that survives a fall can be used again.
…..A broken egg must be discarded.
…..The effect of a fall is the same for all eggs.
…..If an egg breaks when dropped, then it would break if dropped from a higher floor.
…..If an egg survives a fall then it would survive a shorter fall.
…..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.
If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out in only one way. Drop the egg from the first-floor window; if it survives, drop it from the second-floor window. Continue upward until it breaks. In the worst case, this method may require 36 droppings. Suppose 2 eggs are available. What is the least number of egg-droppings that is guaranteed to work in all cases?
The problem is not actually to find the critical floor, but merely to decide floors from which eggs should be dropped so that the total number of trials are minimized.
*/
#include<bits/stdc++.h>

using namespace std;

int solveEggDrop(int e, int f, vector<vector<int>> &t)
{
    //printf(" (e,f) = (%d, %d) \n", e, f );

    if (f == 0 || f == 1)
        return f;

    if (e == 1)
        return f;

    #if 0
    if (t[e][f] != -1)
        return t[e][f];
    #endif

    int mn = INT_MAX;

    for (int k=1; k<=f; k++)
    {
        int temp =  1+ max(solveEggDrop(e-1, k-1, t), solveEggDrop(e, f-k, t));
        mn = min(mn, temp);
    }
    t[e][f] = mn;
    return mn;

}

int main() {

    int n = 2, k = 36;
    vector<vector<int>> vec(n+1, vector<int> (k+1, -1));
    //memset(t, -1, sizeof(t));
    cout<<solveEggDrop(n, k, vec);
    return 0;
}
