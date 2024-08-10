#include<iostream>
#include<cstdio>
using namespace std;

char *getString()
{
  char *str = "dhiru"; /* Stored in read only part of shared segment */

  /* No problem: remains at address str after getString() returns*/
  return str;
}

int main()
{
    {
        char *s = getString();
        s[0] = 'M';
        printf("%s \n", s);

    }


    {
    char str[4] = "GfG";
    str[1] = 'D';
    /*As above string is stored in normal stack so, this can be changed*/
    cout << str << endl;
    }

   {
   char str[4] = {'G', 'f', 'G', '\0'};
    str[1] = 'H';
    /*As above string is stored in normal stack so, this can be changed*/
    cout << str << endl;
   }

  {
 char *str;
 str = "GfG";     /* Stored in read only part of data segment */
 *(str+1) = 'n'; /* Problem:  trying to modify read only memory */
 cout << "Dhiru this is not good " << str << endl;
 return 0;
}
    return 0;
}
