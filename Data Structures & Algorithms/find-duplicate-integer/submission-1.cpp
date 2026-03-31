class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int>number(n,0);

        for(int& num : nums){
            number[num]++;
        }

        for(int i = 0; i < number.size(); i++){
            if(number[i] > 1){
                return i;
            }
        }
        return -1;
    }
};
