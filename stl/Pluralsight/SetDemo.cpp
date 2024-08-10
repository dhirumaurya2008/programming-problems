#include<iostream>
#include<ostream>
#include<set>
#include<string>
using namespace std;

ostream& operator<<(ostream &os, const set<string>& strings)
{
    os << "{ " ;
    bool isFisrt = true;

    for(auto const& s : strings)
    {
        if(isFisrt)
        {
            os << s ;
            isFisrt = false;
        }
        else
        {
            os << ", " << s;
        }
    }

    os << " }" ;

    return os;
}

int main()
{
    set<string> color{"red", "yellow", "blue"};

    cout << "Initial set of colors: \n\n" ;
    cout << " " << color << "\n\n";

    color.insert("green");
    cout << "After inserting green: \n";
     cout << " " << color << "\n\n";

    color.insert("green");
    cout << "Try  to insert green again: \n";
    cout << " " << color << "\n\n";

    color.erase("red");
    cout << "After removing red: \n";
    cout << " " << color << "\n\n";


    auto it = color.find("blue");
    if(it != color.end())
    {
        cout << "The set contains blue color: \n";
    }
    else
    {
        cout << "The set does not contains blue color: \n";
    }

return 0;


}

