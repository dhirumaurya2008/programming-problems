#include<iostream>
#include<list>
using namespace std;

void print(list<int> &mylist)
{
  for(auto val  : mylist)
        cout << val << " ";

  cout << endl;
}

int main()
{
    /*1. Creating Linked List*/
    list<int> mylist;

    /*2. Inserting Element at the back in Linked List*/
    mylist.push_back(10);
    mylist.push_back(12);
    mylist.push_back(13);
    mylist.push_back(14);
        mylist.push_back(12);
            mylist.push_back(12);
    print(mylist);

    cout << "Pushing Values in front of Linked List" << endl;
    /*3. Inserting Element in front of Linked List*/
    mylist.push_front(45);
    print(mylist);

    cout << "Reversing a linked" << endl;
    /*4. Reversing linked List*/
    mylist.reverse();
    print(mylist);

    cout << "Getting Size of the linked" << endl;
    /*5. Getting Size of the linked*/
    cout << "Size of the linked " << mylist.size()<<endl;

    cout << "Sorting the linked" << endl;
    /*6. Sorting the Linked*/
    mylist.sort();
    print(mylist);


    cout << "Remove element from List" << endl;
    /*7. Remove element from List*/
    mylist.remove(12);
    print(mylist);

     cout << "Front of Linked List" << mylist.front() << endl;
     cout << "Back of Linked List" << mylist.back() << endl;


    return 0;
}
