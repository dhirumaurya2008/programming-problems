#include<iostream>
#include<string>
using namespace std;

void print2DigitBinaryHelper(unsigned char digit, string prefix)
{
    if (digit == 0) {
        cout << prefix << endl;
    }
    else
    {
        print2DigitBinaryHelper((digit-1), prefix+"0");
        print2DigitBinaryHelper((digit-1), prefix+"1");
    }
}

void print2DigitBinary(unsigned char digit)
{
    string prefix = "";
    print2DigitBinaryHelper(digit, prefix);
}
int main()
{
    print2DigitBinary(4);
    return 0;
}
