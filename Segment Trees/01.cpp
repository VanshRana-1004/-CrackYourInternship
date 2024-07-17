// Problem Link : https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
public:
    int *arr;
    int *seg;
    int n;
    void built(int i,int s,int e,int *arr,int *seg){
        if(s==e){
            seg[i]=arr[s];
            return;
        }
        int mid=s+(e-s)/2;
        built(2*i+1,s,mid,arr,seg);
        built(2*i+2,mid+1,e,arr,seg);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    int query(int i,int s,int e,int &l,int &r,int *seg){
        // if out of bound
        if(e<l || r<s) return 0;
        // if lies fully
        if(l<=s && e<=r) return seg[i];
        // if lies partially
        int mid=s+(e-s)/2;
        int left=query(2*i+1,s,mid,l,r,seg);
        int right=query(2*i+2,mid+1,e,l,r,seg);
        return left+right;
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        arr=new int[n];
        seg=new int[4*n];
        for(int i=0;i<n;i++) arr[i]=nums[i];
        built(0,0,n-1,arr,seg);
    }
    
    int sumRange(int l, int r) {
        int sum=query(0,0,n-1,l,r,seg);
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
