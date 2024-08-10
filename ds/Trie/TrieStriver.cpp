#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool flag = false;

    Node()
    {
        for(int i = 0; i<26; i++) {
            links[i] = NULL;
        }
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node *getKey(char ch)
    {
        return links[ch - 'a'];
    }

    void putKey(char ch, Node *nextNode) {

        links[ch - 'a'] = nextNode;
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
    Trie()
    {
      Node *root = new Node;
    }

    void insert(string word) {
        Node *node = root;

        for (int i=0; i<word.size(); i++) {
            if (!node->containsKey(word[i]))
                    node->putKey(word[i], (new Node));
            node = node->getKey(word[i]);
        }

        node->setEnd();
    }

    bool search(string word) {
       Node *node = root;

        for (int i=0; i<word.size(); i++) {
            if (!node->containsKey(word[i]))
                    return false;
            node = node->getKey(word[i]);
        }
        return node->isEnd();
    }

     bool startsWith (string word) {
       Node *node = root;
        for (int i=0; i<word.size(); i++) {
            if (!node->containsKey(word[i]))
                    return false;
            node = node->getKey(word[i]);
        }
        return true;
    }

};

int main() {
    int n = 5 ;
    vector<int> type = {1,1,2,3,2};
    vector<string> value = {"hello", "help", "help", "hel", "hel"};
    Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
            cout << "Inserting word into trie : " << value[i] << endl;
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << value[i] << " : is Found in trie \n";
			}
			else {
				cout <<  value[i] << " : is not Found in trie \n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "Word is starts with  : " << value[i] << " Found in trie \n";
			}
			else {
				cout << "Word is starts with : " << value[i] << "not Found in trie\n";
			}
		}
	}

	return 0;

}
