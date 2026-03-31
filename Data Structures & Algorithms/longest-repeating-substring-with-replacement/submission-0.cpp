class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i = 0;
        int len = 0;
        int maxf = 0;
        vector<int>freq(26,0);

        for(int j = 0; j < n; j++){
            freq[s[j] - 'A']++;

            maxf = max(maxf,freq[s[j] - 'A']);

            while((j-i+1) - maxf > k){
                freq[s[i]- 'A']--;
                i++;
            }

            len = max(len,j-i+1);
        }
        return len;
    }
};
