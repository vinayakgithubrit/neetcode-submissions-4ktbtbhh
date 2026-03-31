class Solution {
public:
    int findMin(vector<int> &nums) {
        int mini = INT_MAX;

        for(int& num : nums){
            if(num < mini){
                mini = num;
            }
        }
        return mini;
    }
};
