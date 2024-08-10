#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[2];

    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }

    void putKey(int bit, Node *node) {
        links[bit] = node;
    }

    Node *getKey(int bit) {
        return (links[bit]);
    }

    Node() {
        links[0] = NULL;
        links[1] = NULL;
    }
};

class Trie {
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num) {
        Node *node = root;
        for (int i = 31; i>=0; i--)  {
            int bit = (num >> i) & 1;
            //cout << "bit  = " << bit << " i= " << i<< endl;
            if (!node->containsKey(bit)) {
                node->putKey(bit, (new Node()));
            }
            node = node->getKey(bit);
        }
    }

    int getMax(int num) {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i>=0; i--)  {
            int bit = (num >> i) & 1;
            if (node->containsKey(1-bit)) {
                maxNum = maxNum | (1<<i);
                node = node->getKey(1-bit);
            }
            else {
                node = node->getKey(bit);
            }
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    Trie trie;
    int maxi = 0;
    /*Insert first array into the trie*/
    for (auto x : arr1) {
        //cout << "Trie insertion of x = " << x << endl;
        trie.insert(x);
    }
   // cout << "Trie creation done successfully " << endl;
    for (auto x : arr2) {
        maxi = max(maxi, trie.getMax(x));
    }
    return maxi;
}

int main() {
  vector < int > arr1 = {6, 8};
  vector < int > arr2 = {7, 8, 2};
  int n = 2, m = 3;
  cout << maxXOR(n, m, arr1, arr2) << endl;
  return 0;
}
