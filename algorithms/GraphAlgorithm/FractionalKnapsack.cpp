//https://www.codingninjas.com/codestudio/problems/975286?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include<algorithm>
bool cmp(pair<int, int> &p1, pair<int, int> &p2) {

    double r1 = (double)p1.second/p1.first;
    double r2 = (double)p2.second/p2.first;
    return r1 > r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    sort(items.begin(), items.end(), cmp);

    double totPrice = 0;
    double curWeight = 0;

    for(int i=0;i<items.size(); i++) {

        if (curWeight + items[i].first <= w) {
            curWeight = curWeight + items[i].first;
            totPrice += items[i].second;
        }
        else {
            totPrice +=  double(w-curWeight) * ( (double)items[i].second/items[i].first);
            break;
        }
    }
    return totPrice;
}
