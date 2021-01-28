class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 1 || x ==0)
            return x;
        int lo = 2;
        int hi = x/2;
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(mid == x/mid)return mid;
            
            if(mid > (x/mid))
            {
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }
        return hi;
    }
};