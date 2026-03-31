class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int n = nums.size();
      if(n == 0) return 0;
      sort(nums.begin(),nums.end());
      int last_smallest = nums[0];
      int cnt = 1;
      int longest = 1;

      for(int i = 1; i < n; i++){
        if(nums[i] == last_smallest + 1){//checks consecutive 
            cnt++;
            last_smallest = nums[i];
        }
        else if(nums[i] !=last_smallest){
            cnt = 1;
            last_smallest = nums[i];
        }
        longest = max(longest,cnt);
      } 
      return longest;
    }
};
