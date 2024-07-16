// Problem Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=1e18;
        if(n==1) return 0;
        vector<int> pre=nums,suf=nums;
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];
        for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]+nums[i];
        for(int i=0;i<n;i++){
            long long cur=0;
            if(i-1>=0) cur+=(long long)nums[i]*i-(long long)pre[i-1];
            if(i+1<n) cur+=(long long)suf[i+1]-(long long)nums[i]*(n-i-1);
            ans=min(ans,cur);
        }
        return ans;
    }
};
