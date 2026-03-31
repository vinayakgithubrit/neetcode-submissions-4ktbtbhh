class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int num : nums){
            mp[num]++;
        }

        vector<vector<int>>bucket(n+1);
        //index -> frequency;
        //element -> value 
        // vector of vector as many elements cn have same frequency.

        for(auto it : mp){
            int freq = it.second;
            int value = it.first;

            bucket[freq].push_back(value);
        }

        vector<int>result;
        for(int i = n; i >= 0 && result.size() < k ; i--){
            if(bucket[i].size() > 0){
                for(int num : bucket[i]){
                    result.push_back(num);
                    if(result.size() == k){
                        break;
                    }
                }
            }
        }
        return result;
    }
};
