class Solution {
public:
    
    bool canComplete(int start, vector<int> adj[], vector<bool> &visited , vector<bool> &dfsVisited, stack<int> &st)
    {
        visited[start] = true;
        dfsVisited[start] = true;
        
        for (auto it : adj[start]) {
            if (!visited[it]) {
                if (!canComplete(it, adj, visited, dfsVisited, st)) {
                    return false;
                }
            }
            else if(dfsVisited[it]) {
                return false;
            }
        }
        
        dfsVisited[start] = false;
        st.push(start);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        
        stack<int> st;
        vector<bool> visited(numCourses, false);
        vector<bool> dfsVisited(numCourses, false);
        vector<int> ans;
        
        for (int i=0; i<numCourses; i++) {
            
            if (!visited[i]) {
                if (!canComplete(i, adj, visited, dfsVisited, st))
                {
                    return ans;
                }
            }
        }
        
        while ( !st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};