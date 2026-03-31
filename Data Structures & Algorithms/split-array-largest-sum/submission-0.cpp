class Solution {
public:
    bool CanSplit(vector<int>& nums, int k, int mid){
        int subarrays = 1;
        int curr = 0;

        for(int& num : nums){
            if(curr + num > mid){
                subarrays++;
                curr = num;
            }
            else{
                curr +=num;
            }
        }
        return subarrays <=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(begin(nums),end(nums));
        int h = accumulate(begin(nums),end(nums),0);
        int result = h;

        while(l <= h){
            int mid = l + (h-l)/2;
            if(CanSplit(nums,k,mid)){
                result = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return result;
    }
};