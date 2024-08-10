#include<iostream>
using namespace std;
int main()
{
    unsigned int weight =0;
    scanf("%d", &weight);

    if((weight <1) || (weight > 100))
        return 0;

    if((weight%2 == 0) && (weight > 2))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
