// Problem Link : https://leetcode.com/problems/range-sum-query-mutable/description/
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
    
    void update_tree(int i,int s,int e,int *arr,int *seg,int ind,int val){
        if(s==e){
            if(s==ind) arr[s]=val,seg[i]=val;
            return;
        }
        int mid=s+(e-s)/2;
        if(ind<=mid) update_tree(2*i+1,s,mid,arr,seg,ind,val);
        else update_tree(2*i+2,mid+1,e,arr,seg,ind,val);
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
    
    void update(int ind, int val) {
        update_tree(0,0,n-1,arr,seg,ind,val);
    }
    
    int sumRange(int l, int r) {
        int sum=query(0,0,n-1,l,r,seg);
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
