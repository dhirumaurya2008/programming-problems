#include<iostream>
#include<ostream>
#include<vector>

using namespace std;

ostream& operator<<(ostream& os, const vector<int> &v)
{
    os << "[ " ;
    for(auto x : v)
        os << x <<" ";
     os << "]" ;

     return os;
}

int main()
{
    vector<int> v{11, 22, 33, 44, 55, 66};

    cout << "Initial vector " << v  << endl << endl;

    cout << "Inserting Single Element (99) " << endl;

    v.insert(begin(v)+1, 99);
    cout << "  " << v  << endl << endl;

    cout << "Inserting 3 copy of (100) " << endl;

    v.insert(begin(v)+2, 3, 100);
    cout << "  " << v  << endl << endl;

    vector<int> s{-11, -22, -33};
    cout << "Inserting values from source range " << endl;

    v.insert(begin(v)+1, begin(s), end(s));
    cout << "  " << v  << endl << endl;

    cout << "Inserting values from initalizer list " << endl;

    v.insert(begin(v)+4, {111, 222, 333});
    cout << "  " << v  << endl << endl;

    return 0;
}
