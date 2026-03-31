class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Fix 1: Change set type from <char> to <string>
        unordered_set<string> st;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                // Fix 2: Skip empty cells (usually '.')
                if (board[i][j] == '.') continue;

                string val = string(1, board[i][j]);
                string row = val + "_ROW_" + to_string(i);
                string col = val + "_COL_" + to_string(j);
                string box = val + "_BOX_" + to_string(i/3) + "_" + to_string(j/3);

                if(st.find(row) != st.end() || st.find(col) != st.end() || st.find(box) != st.end()){
                    return false;
                }
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
};
