class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        
        for(int &a : asteroids){
            while(!st.empty() && st.top() > 0 && a < 0){
                int sum = 0;

                sum = a + st.top();

                if(sum < 0){
                    st.pop();
                }
                else if(sum > 0){
                    a = 0;
                }
                else{
                    st.pop();
                    a = 0;
                }
            }
            if(a !=0){
                st.push(a);
            }
        }

        int sz = st.size();
        vector<int>result(sz);
        for(int i = sz-1; i >=0; i--){
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};