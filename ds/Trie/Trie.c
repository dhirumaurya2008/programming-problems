#include<stdio.h>
#include <stdbool.h>
#define MAX_ALPHABETS 26

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode
{
 struct TrieNode* child[MAX_ALPHABETS];
 bool isEndOfWord;
};

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

struct TrieNode* getTrieNode(void)
{
    struct TrieNode* pNode = NULL;

    pNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));

    if(pNode)
    {
        pNode->isEndOfWord = false;
        for(int i=0; i<MAX_ALPHABETS; i++)
        {
            pNode->child[i] = NULL;
        }
    }

    return pNode;
}


bool search (struct TrieNode* root, char *pattern)
{
    int length = strlen(pattern);

    for(int level=0; level<length; level++)
   {
       int index = CHAR_TO_INDEX(pattern[level]);
       if(!root->child[index])
          return false;
       root = root->child[index];
   }

   return(root && root->isEndOfWord);

}



bool insert(struct TrieNode* root, const char *pattern)
{
   int length = strlen(pattern);

   for(int level=0; level<length; level++)
   {
       int index = CHAR_TO_INDEX(pattern[level]);
       if(!root->child[index])
          root->child[index] = getTrieNode();
       root = root->child[index];
   }

   root->isEndOfWord = true;

}


int main()
{
// Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};

    char output[][32] = {"Not present in trie", "Present in trie"};


    struct TrieNode *root = getTrieNode();
    int i;
    for (i = 0; i < ARRAY_SIZE(keys); i++)
        insert(root, keys[i]);
    printf("%s --- %s\n", "the", output[search(root, "the")] );
    printf("%s --- %s\n", "these", output[search(root, "these")] );
    printf("%s --- %s\n", "their", output[search(root, "their")] );
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );
    return 0;
}
