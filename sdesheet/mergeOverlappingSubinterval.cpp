#include<algorithm>
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    #define VVI vector<vector<int>>
    #define VI vector<int>
    VVI result;
    if (intervals.size() <=0)
        return result;
    sort(intervals.begin(), intervals.end());
    VI lastElem = intervals[0];
    for (auto val : intervals) {
        /*Overlapping*/
        if (val[0] <= lastElem[1]) {
           lastElem[1] = max(lastElem[1], val[1]);
        }
        else
        {
           result.push_back(lastElem);
           lastElem = val;
        }
    }
    result.push_back(lastElem);
    return result;
     #undef VI vector<int>
    #undef VVI vector<vector<int>>

}
