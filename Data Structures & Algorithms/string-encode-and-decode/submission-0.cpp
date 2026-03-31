#include<bits/stdc++.h>
class Solution {
public:

    string encode(vector<string>& strs) {
        // (length) + '#' + s;
        string encoded = "";
        for(string &s : strs){
            encoded +=to_string(s.length())+ "#" + s;
        }
        return encoded;
    } 

    vector<string> decode(string s) {
    vector<string> decoded;
    int i = 0;
    while (i < s.size()) {
        // 1. Find the delimiter '#'
        size_t found = s.find('#', i);
        if (found == string::npos) break; // Safety check
        
        // 2. Extract the length (the part from i to the #)
        int length = stoi(s.substr(i, found - i));
        
        // 3. Move 'i' to the first character of the actual string
        i = found + 1;
        
        // 4. Use the length to extract the string
        decoded.push_back(s.substr(i, length));
        
        // 5. Jump 'i' past this string to the next length-prefix
        i += length;
    }
    return decoded;
}
    };
