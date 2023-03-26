class Solution {
public:
    int result = -1;
    
    void dfs(int u, vector<int>& edges, vector<bool> &visited, vector<int>& dist, vector<bool> &inRecursion) {
        
        if(u != -1) {
            
            visited[u] = true;
            inRecursion[u] = true;
            
            int v = edges[u];
            
            if(v != -1 && !visited[v]) {
                
                dist[v] = dist[u] + 1;
                
                dfs(v, edges, visited, dist, inRecursion);

            } else if(v != -1 && inRecursion[v] == true) { //cycle
                
                result = max(result, dist[u] - dist[v] +1);
                
            }
        
            inRecursion[u] = false;
        }
        
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        
        vector<bool> visited(n, false);
        
        vector<int> dist(n, 1);
        vector<bool> inRecursion(n, false);
        
        for(int i = 0 ; i<n; i++) {
            
            if(!visited[i]) {
                dfs(i, edges, visited, dist, inRecursion);
            }
            
        }
        
        return result;
        
    }
};
