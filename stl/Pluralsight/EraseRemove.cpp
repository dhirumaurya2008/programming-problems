#include<iostream>
#include<vector>
#include<algorithm>
#include<ostream>

using namespace std;


ostream& operator<<(ostream& os, const vector<int>& v)
{
    os << "[ ";
    for(auto x : v)
        os << x << " " ;
    os << " ]";
    return os;
}
bool IsOdd(int x)
{
    return ((x%2 == 1));
}

int main()
{
    vector<int> v{11,22,33,44,55,66};

    cout << "Initial vector : " << v << "\n\n";

    cout << " Removing odd numbers from vector \n\n";

    v.erase(remove_if(begin(v), end(v), IsOdd), end(v));

    cout << " vector content after erase-remove: " << v << "\n\n";

    return 0;


}
