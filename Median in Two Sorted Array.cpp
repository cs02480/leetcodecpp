class Solution {
public:
     const int inf = 10000001;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() == 0 && nums2.size() == 0)
        {
            return 0;
        }
        if(nums1.size() == 0)
        {
            int len = nums2.size();
            if(len %2 ==0 )
                return (double)(nums2[len/2]+nums2[(len/2)-1])/2;
            
            return nums2[len/2];
        }
        
        
        if(nums2.size() == 0)
        {
            int len = nums1.size();
            if(len %2 ==0 )
                return (double)(nums1[len/2]+nums1[(len/2)-1])/2;
            
            return nums1[len/2];
        }
        
        if(nums1.size() > nums2.size())
        {
            vector<int>  tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
        }
        
        int x = nums1.size();
        int y = nums2.size();
        int lo = 0;
        int hi = x;
        int pX,pY;
        int maxleftx,minrightx;
        int maxlefty,minrighty;
        while(lo <= hi)
        {
            pX = (lo + hi)/2;
            pY = ((x+y+1)/2) - pX;
            if(pX >0)
            {
                maxleftx = nums1[pX-1];
            }
            else
                maxleftx = -inf;
            
            if(pX == x)
                minrightx = inf;
            else
                minrightx = nums1[pX];
            
            if(pY >0)
            {
                maxlefty = nums2[pY-1];
            }
            else
                maxlefty = -inf;
            
            if(pY == y)
                minrighty = inf;
            else
                minrighty = nums2[pY];
            
            if(maxleftx <= minrighty && minrightx >= maxlefty)
            {
                if((x+y)%2 == 0)
                    return (double)(max(maxleftx,maxlefty) + min(minrightx,minrighty))/2;
                
                return max(maxleftx,maxlefty) ;
                   
            }
            else if(maxleftx > minrighty)
                hi = pX -1;
            else
                lo = pX + 1;
                
        }
        return inf;
    }
};