class Solution {
public:
    int maxArea(vector<int>& height) {
        int size  = height.size();
        if(size<=0)
            return 0;
        int left =0;
        int right =size-1;
        int maxArea = 0;
        while(left < right)
        {
            int area =min(height[left],height[right])*(right-left);
            maxArea = max(maxArea,area);
            if(height[right]<height[left])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return maxArea;
    }
};