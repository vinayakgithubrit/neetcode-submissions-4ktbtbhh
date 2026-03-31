class Solution {
public: 
    int pivot(vector<int>& nums, int l, int r){
        int n = nums.size();

        while(l < r){
            while(l < r && nums[l] == nums[l+1]){
                l++;
            }
            while(l < r && nums[r] == nums[r-1]){
                r--;
            }

            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            else if(nums[mid] < nums[r]){
                r = mid;
            }
        }
        return l;
    }
    
    bool binarysearch(vector<int>& nums, int l, int r, int target){
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot_idx = pivot(nums,0,n-1);

        if(binarysearch(nums,0,pivot_idx-1,target)){
            return true;
        }
        return binarysearch(nums,pivot_idx,n-1,target);
    }
};