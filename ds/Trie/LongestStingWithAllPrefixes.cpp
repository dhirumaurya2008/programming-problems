#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    bool flag = false;

    Node() {
        for (int i =0; i<26; i++) {
            links[i] = NULL;
        }
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void putKey(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* getKey(char ch) {
        return (links[ch - 'a']);
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node *node = root;
        for (int i = 0; i<word.size(); i++) {
            if (!node->containsKey(word[i])){
                node->putKey(word[i], (new Node()));
            }
            node = node->getKey(word[i]);
        }
        node->setEnd();
    }

    bool checkIfAllPrefixesExist(string word) {
        Node *node = root;
        for (int i =0; i<word.size(); i++) {
            if (node->containsKey(word[i])) {
                node = node->getKey(word[i]);
                if (node->isEnd() == false)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};
string longestWordWithAllPrefixes(vector<string> &words)
{
    Trie trie;
    /*Insert each word in trie*/
    for (auto it : words) {
        trie.insert(it);
    }

    string longest = "";

    for (auto it : words) {

        if (trie.checkIfAllPrefixesExist(it)){
            if (it.length() > longest.length()){
                longest = it;
            }
            else if ((it.length() == longest.length()) && (it < longest)) {
                longest = it;
            }
        }
    }

    if (longest == "")
        return "None";

    return longest;
}

int main()
{
    vector<string> words = {"n", "ni", "nin" , "ninj" , "ninja", "ninga"};

    cout << "Longest Word with all prefixes " << longestWordWithAllPrefixes(words) << endl;

    return 0;
}
