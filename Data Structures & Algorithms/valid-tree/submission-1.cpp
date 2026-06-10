class Solution {
private:
    bool detectcycle(int src, vector<vector<int>>& adj, vector <int>& vis){
        vis[src] =1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parentnode = q.front().second;
            q.pop();

            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it] =1;
                    q.push({it, node});
                }
                else if(it != parentnode){
                    return true;
                }
            }
        }
        return false;
    }    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector <int> vis(n, 0);
        vector<vector<int>> adj(n);
        for(int i =0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
              if(detectcycle(i, adj, vis)) return false;
            }
        }

       /* for(int i = 0; i < n; i++){
            if(!vis[i]){
            return false;
            }
        }*/

        return true;
    }
};
