class Solution {
public:
    bool CanEatAll(vector<int>& piles, int mid, int h){
        long long actualHours = 0;

        for(int& x : piles){
            actualHours +=x/mid;

            if(x % mid !=0){
                actualHours++;
            }
        }
        return actualHours <=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(begin(piles),end(piles));

        while(l <= r){
            int mid = l + (r-l)/2;

            if(CanEatAll(piles,mid,h)){
                r = mid - 1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
