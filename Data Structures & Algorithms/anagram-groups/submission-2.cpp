class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> ans;
       unordered_map<string, vector<string>> res;
      
      for(auto& s: strs){
        vector<int> freq(26, 0);
        for(char ch : s){
          freq[ch - 'a']++;
        }

        string key = to_string(freq[0]);
        for(int i = 1; i < 26; i++){
           key += ',' +  to_string(freq[i]);
        }

        res[key].push_back(s);
      }

      for(auto & j: res){
        ans.push_back(j.second);
      }
        
       return ans;
    }
};
