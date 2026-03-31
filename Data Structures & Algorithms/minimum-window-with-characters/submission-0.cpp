class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char,int>mp;
        int i = 0;
        int j = 0;
        int start_i = 0;
        int window_size = INT_MAX;
        int reqcount = t.length();

        for(char &ch : t){
            mp[ch]++;
        }

        while(j < n){
            char ch = s[j];

            if(mp[ch] > 0){
                reqcount--;
            }

            mp[ch]--;

            while(reqcount == 0){
                int current_size = j-i+1;
                if(current_size < window_size){
                    window_size = current_size;
                    start_i = i;
                }

                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    reqcount++;
                }
                i++;
            }
            j++;
        }
        return window_size == INT_MAX ? "" : s.substr(start_i,window_size);
    }
};
