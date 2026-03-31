/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarysearch(MountainArray &mountainArr, int target, int s , int e, bool ascending){
        while(s <= e){
            int mid = s + (e-s)/2;

            if(mountainArr.get(mid) == target){
                return mid;
            }

            if(ascending){
                if(mountainArr.get(mid) < target){
                    s = mid + 1;
                }
                else{
                    e = mid - 1; 
                }
            }
            else{
                if(mountainArr.get(mid) > target){
                    s = mid + 1;
                }
                else{
                    e = mid - 1; 
                }
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int l = 0;
        int r = n -1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        int peakidx = l;
        int idx = binarysearch(mountainArr,target,0,l,true);

        if(idx !=-1){
            return idx;
        }

        return binarysearch(mountainArr,target,l+1,n-1,false);
    }
};