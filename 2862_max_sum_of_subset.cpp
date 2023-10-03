class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        for(int i=1;i<=n;i++){
            long long ans=0;
            set<long long> st;
            st.insert(i);
            for(int j=i+1;j*j<=i*n;j++){
                if(j*j%i==0){
                    st.insert(j*j/i);
                }
            }
            
            for(auto &x:st){
                ans+=nums[x-1];
            }
            res=max(res,ans);
            
        }

        return res;
    }
    
};
