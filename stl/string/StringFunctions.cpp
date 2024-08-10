#include<iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    //cin >> str;
    getline(cin, str);
    // Displaying string
    cout << "The initial string is : ";
    cout << str << endl;
    cout << "The string capecity is : " << str.capacity() << endl;

    str.push_back('M');
    cout << "The string after push back is : ";
    cout << str << endl;
    cout << "The string capecity is : " << str.capacity() << endl;

    str.resize(65);
    cout << "The string capacity after resize is : " << str.capacity() << endl;

    str.pop_back();
    cout << "The string after pop back is : ";
    cout << str << endl;

    {
        string::iterator it1 = str.begin();

        cout << "Iterating string using iterator : ";
        for (string::iterator it = it1; it != str.end(); it++)
            cout << *it ;
        cout << endl;
    }

    {
        string::reverse_iterator it1 = str.rbegin();

        cout << "Reverse Iterating string using iterator : ";
        for (string::reverse_iterator it = it1; it != str.rend(); it++)
            cout << *it ;
        cout << endl;

    }

    /*Swap*/
    {
        string str1 = "Dhirendra";
        string str2 = "Maurya";

        cout << "Before swapping " << endl;
        cout << "str1 " << str1 << " str2 " << str2 << endl;
        str1.swap(str2);
        cout << " After swapping " << endl;
        cout << "str1 " << str1 << " str2 " << str2 << endl;

    }


    return 0;
}
