/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

int peakIndexInMountainArray(MountainArray &arr,int n) {
    int l = 0, r = n - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr.get(mid) < arr.get(mid + 1)) {
            // We are in the increasing part of the mountain
            l = mid + 1;
        } else {
            // We are in the decreasing part of the mountain
            r = mid;
        }
    }
    return l; // or return r; both are equal here
}

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();

        int piv = peakIndexInMountainArray(arr, n);
        //binary_search, 0, piv & [piv+1, n-1]
        
        int l=0, r=piv;
        int ans=n;
        
        while(l<=r){
            int mid=(l+r)/2;
            int midEle = arr.get(mid);
            if(midEle==target){
                ans=mid;break;
            }
            
            if(midEle>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        l=piv+1; r=n-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            int midEle = arr.get(mid);
            if(midEle==target){
                ans=min(ans, mid);break;
            }
            
            if(midEle>target){
                l=mid+1;
            }else{
                 r=mid-1;
            }
        }
        
        if(ans==n)ans=-1;
        return ans;
        
        
    }
};
