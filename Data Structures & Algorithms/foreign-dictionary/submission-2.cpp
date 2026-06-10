class Solution {
private:

vector<int> toposort(vector<int> adj[], int v){
vector<int> indegree(26, 0);
vector<int> topo;
queue<int> q;
for(int i = 0; i < v;i++)
for(auto it: adj[i]){
    indegree[it]++;
}
for(int i = 0; i < indegree.size(); i++){
    if(indegree[i] ==0){
        q.push(i);
    }
}

while(!q.empty()){
    int node = q.front();
    q.pop();
    topo.push_back(node);

    for(auto it: adj[node]){
        indegree[it]--;
        if(indegree[it] ==0){
            q.push(it);
        }
    }
}
return topo;
}

public:
    string foreignDictionary(vector<string>& words) {
        vector<int> adj[26];
        int n = words.size();
        for(int i = 0; i < n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int size = s1.size() > s2.size() ?
            s2.size() : s1.size();
            bool foundDiff = false;
            for(int j = 0; j < size; j++){
                if(s1[j]!= s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    foundDiff = true;
                    break;
                }
            }
            if (!foundDiff && s1.size() > s2.size()) {
    return "";
}
        }

       vector <int> ans;
       ans = toposort(adj, 26);
        if (ans.size() < 26) {
        return "";
    }
       string str ="";
       for(int i = 0; i < ans.size(); i++){
        str += char(ans[i] + 'a');
       }
       return str;
    }
};
