class Solution {
public:
    long long maximumSumOfHeights(vector<int>& nums) {
        int n=nums.size();
        vector<long long> lf(n),rf(n),sum1(n),sum2(n);
        vector<int> nums1=nums;
        reverse(nums1.begin(),nums1.end());
        stack<int> s1,s2;
        for(int i=0;i<n;i++){
            while(!s1.empty() and nums[s1.top()]>nums[i]){
                s1.pop();
            }

            if(s1.empty()) lf[i]=(i+1)*1ll*nums[i];
            else lf[i]=sum1[s1.top()]+(i-s1.top())*1ll*nums[i];
            sum1[i]=lf[i];

            // cout<<lf[i]<<" \n"[i==n-1];
            s1.push(i);
        }



        for(int i=0;i<n;i++){
            while(!s2.empty() and nums1[s2.top()]>nums1[i]){
                s2.pop();
            }

            if(s2.empty()) rf[n-1-i]=(i+1)*1ll*nums1[i];
            else rf[n-1-i]=sum2[s2.top()]+(i-s2.top())*1ll*nums1[i];
            sum2[i]=rf[n-1-i];
            s2.push(i);
        }

        long long ans=0,cur;
        for(int i=0;i<n;i++){
            // cout<<rf[i]<<" \n"[i==n-1];
            cur=-nums[i]+lf[i]+rf[i];
            ans=max(cur,ans);
        }

        return  ans;

    }
};