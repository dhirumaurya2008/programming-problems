int maximumProfit(vector<int> &prices){
    // Write your code here.
    int lps = INT_MAX;
    int cp = 0;
    int op = 0;
    for (int i=0; i<prices.size(); i++)
    {
        if (prices[i] < lps)
            lps = prices[i];
        cp = prices[i] - lps;

        if (cp > op)
            op = cp;
        //op = max(cp, op);
    }
    return op;
}
