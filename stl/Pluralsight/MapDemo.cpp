#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{

    map<int, string> numbers{};

    numbers[1] = "one";
    numbers[2] = "two";
    numbers[64] = "sixty-four";
    numbers[3]  = "three";

    //Print numbers

    for(auto it : numbers)
        cout << " key " << it.first << " value " << it.second << endl;

    auto it = numbers.find(64);

    if(it !=numbers.end())
    {
        cout << "\n Key " << it->first << " value found in map " << it->second << endl;

    }
    else
    {
        cout << "\n 64 is not found in Map \n" ;
    }

    return 0;
}
