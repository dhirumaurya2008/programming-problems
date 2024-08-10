#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    int ew = 0;
    int cp = 0;
    Node()
    {
        for (int i = 0; i<26; i++) {
            links[i] = NULL;
        }
    }
    bool containsKey(char ch){

        return (links[ch - 'a'] != NULL);
    }

    void putKey(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node *getKey(char ch) {
        return (links[ch - 'a']);
    }

    void increaseEndWith() {
        ew++;
    }

    void increaseCountPrefix() {
        cp++;
    }

    int getEndWithWord()
    {
        return ew;
    }
    int getCountPrefix()
    {
        return cp;
    }
};

class Trie {
    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }
        int insert(string word) {
            Node *node = root;
            for (int i = 0; i<word.size(); i++) {
                if (!node->containsKey(word[i])) {
                    node->putKey(word[i], (new Node()));
                }
                node = node->getKey(word[i]);
                node->increaseCountPrefix();
            }
            node->increaseEndWith();
            //cout << "For word " << word << " count of EndWithWord " << node->getEndWithWord() << endl;
            return 0;
        }

        int countWordsEqualTo(string word) {
            Node *node = root;
            for (int i = 0; i<word.size(); i++) {
                if (!node->containsKey(word[i]))
                    return 0;
                else
                    node = node->getKey(word[i]);
            }
            return (node->getEndWithWord());
        }

        int countWordsStartingWith(string word) {
             Node *node = root;
            for (int i = 0; i<word.size(); i++) {
                if (!node->containsKey(word[i]))
                    return 0;
                else
                    node = node->getKey(word[i]);
            }
            return (node->getCountPrefix());
        }
#if 0
        int erase(string word) {

        }
        #endif

};
int main() {

  Trie T;
  T.insert("apple");
  T.insert("apple");
  T.insert("apps");
  T.insert("apps");
  string word1 = "apps";
  cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  string word2 = "abc";
  cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
  string word3 = "ap";
  cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)
  <<endl;
  string word4 = "appl";
  cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)
  <<endl;
  #if 0
  T.erase(word1);
  cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  #endif
  return 0;
}
