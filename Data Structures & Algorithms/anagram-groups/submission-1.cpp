class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++){
            string orderstrs = strs[i];
            sort(orderstrs.begin(), orderstrs.end());
            if(mp.find(orderstrs)!=mp.end() || mp.find(strs[i]) != mp.end()){
               mp[orderstrs].push_back(strs[i]);
            }
            else{
                mp[orderstrs] = {strs[i]};
            }
        }

        for(auto &it:mp){
            ans.push_back(vector<string>(it.second.begin(), it.second.end()));
        }
    
        return ans;
    }
};
