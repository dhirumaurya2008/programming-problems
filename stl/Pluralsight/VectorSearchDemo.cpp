#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


int main()
{
    vector<string> v{"Galileo", "C64", "Connie", "Amiga"};
    cout << "String vector contains \n";

    for(const auto &x : v)
      cout << " " << x << "\n";

    cout << endl;

    cout << "Please enter string to search: " ;

    string s;
    cin >> s;
    cout << "\n";

    auto pos = find(v.begin(), v.end(), s);

    if(pos != end(v))
    {
        cout << " " << s << " was found in vector " << endl;
    }
    else
        cout << " Vector does not contain " << s << endl;


    return 0;
}
