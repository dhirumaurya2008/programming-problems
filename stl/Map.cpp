#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
    map<int,string> myMap;
    myMap.insert(pair<int ,string>(1, "dhiru"));
    myMap.insert(make_pair(2, "viru"));

    map<int, string>::iterator it = myMap.begin();

    it = myMap.find(2);

    cout << "key = " << (*it).first << " value = " << (*it).second << endl;
    return 0;
}
