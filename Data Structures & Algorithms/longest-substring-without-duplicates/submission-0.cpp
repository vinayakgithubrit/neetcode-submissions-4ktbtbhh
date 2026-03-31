class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int len = 0;
        int i = 0;
        int j = 0;
        vector<bool>freq(256,0);
        while(j < n){
            if(freq[s[j]]){
                freq[s[i]] = 0;//UNMARK AS WE ARE SHRINKING WINDOW.
                i++;
            }
            else{
                freq[s[j]] = 1;
                len = max(len,j-i+1);
                j++;
            }
        }
        return len;
    }
};
