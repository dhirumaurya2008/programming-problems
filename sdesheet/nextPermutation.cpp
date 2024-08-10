vector<int> nextPermutation(vector<int> &permutation, int n)
{
    if (n == 1) {
   		return permutation;
    }
    int k = n-2;
    for (;k>=0; k--)
    {
        if (permutation[k] < permutation[k+1])
            break;
    }

    if (k<0) {
        reverse(permutation.begin(), permutation.end());
    }
    else
    {
        int l = n-1;
        for (;l>=0; l--)
        {
            if (permutation[l] > permutation[k])
                break;
        }
        swap(permutation[l], permutation[k]);
        reverse(permutation.begin() + k+1, permutation.end());
    }
    return permutation;
}
