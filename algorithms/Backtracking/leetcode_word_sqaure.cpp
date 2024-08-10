class Solution {
public:
    bool isValidWordSquare(vector<string> &res, int wordLength)
    {
        for (int i=0; i<wordLength; i++)
        {
            for (int j = 0; j<wordLength; j++)
            {
                if (res[i][j] != res[j][i])
                    return   false;
            }
        }
        return true;
    }
     void printTemp(vector<string> &res) {
        cout << "[";
        for (auto it : res)
            cout << it << " " ;
         cout << "]" << endl;
    }

    void getAllValidWordSquareWrapper(vector<string> &res, int wordLength, set<vector<string>> &ans, int index)
    {
        if (index == wordLength)
        {
            //printTemp(res);
            if (isValidWordSquare(res, wordLength))
            {

                ans.insert(res);
            }
            return;
        }
        else {

            for (int i =index; i<wordLength; i++)
            {
                swap(res[index], res[i]);
                getAllValidWordSquareWrapper(res, wordLength, ans, index+1);
                swap(res[i], res[index]);
            }
        }
    }
    void getAllValidWordSquare(vector<string> &res, int wordLength, set<vector<string>> &ans)
    {
        getAllValidWordSquareWrapper(res, wordLength, ans, 0);
    }
   // #endif

    void wordSquaresWrapper(vector<string>& words, int size, set<vector<string>> &ans, int wordLength, vector<string> &res)
    {
        if (res.size() == wordLength)
        {
            getAllValidWordSquare(res, wordLength, ans);
            //printTemp(res);
            return;
        }
        if (size == 0)
            return;

        res.push_back(words[size-1]);
        wordSquaresWrapper(words, size, ans, wordLength, res);
        res.pop_back();
        wordSquaresWrapper(words, size-1, ans, wordLength, res);
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        set<vector<string>> ans;
        vector<vector<string>> st;
        vector<string> res;
        wordSquaresWrapper(words, words.size(), ans, words[0].size(), res);
        for (auto it : ans)
            st.push_back(it);
        return st;
    }
};
