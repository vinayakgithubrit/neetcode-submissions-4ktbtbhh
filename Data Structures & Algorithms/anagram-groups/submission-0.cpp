class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;

        for(int i = 0; i < strs.size(); i++){
            string word = strs[i];
            sort(begin(word),end(word));
            mp[word].push_back(strs[i]);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
