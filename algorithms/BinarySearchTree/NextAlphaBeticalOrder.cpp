/*
Given a list of sorted characters consisting of both Uppercase and Lowercase Alphabets and a particular target value,
say K, the task is to find the smallest element in the list that is larger than K.
Letters also wrap around. For example, if K = ‘z’ and letters = [‘A’, ‘r’, ‘z’], then the answer would be ‘A’.
*/
#include<iostream>
#include<vector>
using namespace std;

char nextGreatestAlphabet(vector<char> vec, char key)
{
    int mid = -1;
    char res = '#';

    int start = 0, end = vec.size()-1;
    while (start <= end)
    {
        mid = start + (end -start)/2;

        if (key == vec[mid]){
            if (mid+1 <= end)
                return vec[mid+1];
            return res;
        }
        else if (key < vec[mid])
        {
             res = vec[mid];
             end = mid -1;
        }
        else
        {
           start = mid +1;
        }
    }
    return res;
}

// Driver Code
int main()
{
    vector<char> letters{ 'A', 'K', 'M', 'S' };
    char K = 'B';

    // Function call
    char result = nextGreatestAlphabet(letters, K);
    cout << result << endl;
    return 0;
}
