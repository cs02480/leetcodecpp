class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size <=0)
            return 0;
        const int int_max = 214748364;
        int left[size];   //left[i] will contain max height on left of current not i;
        left[0]=-int_max;
        for(int i=1;i<size-1;i++)
        {
            left[i] = max(left[i-1],height[i-1]);
        }
        int water=0;
        int right=-int_max;
        for(int i=size-2;i>0;i--)
        {
            right = max(height[i+1],right);
            if(min(left[i],right)>height[i])
                water += (min(left[i],right) - height[i]);
        }
        return water;
    }
};