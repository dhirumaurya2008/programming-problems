class Solution {
public:
    void DFS(const string &src,  map<string, set<string>> &adjlist, set<string> &visited, vector<string> &ans)
    {
        visited.insert(src);
         ans.push_back(src);
        
        for (auto it: adjlist[src]) {
            if (visited.find(it) == visited.end()) {
               
              DFS(it, adjlist, visited, ans);  
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, set<string>> adjlist;
        set<string> visited;
        vector<string> ans;
        
        for (auto it : tickets) {
            if (adjlist.find(it[0]) != adjlist.end()){
                adjlist[it[0]].insert(it[1]);
            }
            else {
                set<string> st;
                adjlist[it[0]].insert(it[1]);
            }
        }
        
        string src = "JFK";
        visited.insert(src);
        ans.push_back(src);
        for (auto it : adjlist[src]) {
            //cout << "it = " << it << endl;
            if (visited.find(it) == visited.end()) {
                DFS(it, adjlist, visited, ans);
           }
        }
        return ans;
    }
};