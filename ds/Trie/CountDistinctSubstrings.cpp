#include<bits/stdc++.h>
using namespace std;
typedef struct Node {
    Node *links[26];
    Node () {
        for (int i = 0; i< 26; i++) {
            links[i] = NULL;
        }
    }
    bool containsKey(char ch) {
        return ( links[ch - 'a'] != NULL);
    }

    void putKey(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* getKey(char ch) {
        return (links[ch - 'a']);
    }
};


int countDistinctSubstrings(string str) {
    Node *root = new Node();
    int count = 0;
    for (int i = 0; i<str.length(); i++) {
        Node *node = root;
        for (int j = i; j<str.length(); j++) {
            if (!node->containsKey(str[j])) {
                count++;
                node->putKey(str[j], (new Node()));
            }
            node = node->getKey(str[j]);
        }
    }
    return (count +1);
}
int main ()
{

  string s1 = "ababa";
  cout << "Total number of distinct substrings : " << countDistinctSubstrings(s1);
  cout << "\n";

  string s2 = "ccfdf";
  cout << "Total number of distinct substrings : " << countDistinctSubstrings(s2);

  return 0;
}
