class Solution {
public:
    int binarysearch(vector<int>& nums, int l, int r, int target){
        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] < target){
                l = mid + 1;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }

    int pivot(vector<int>& nums, int l, int r){
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;

        int pivot_idx = pivot(nums,0,n-1);

        int index = binarysearch(nums,0,pivot_idx - 1,target);

        if(index !=-1){
            return index;
        }

        index = binarysearch(nums,pivot_idx,n-1,target);
        return index;
    }
};
