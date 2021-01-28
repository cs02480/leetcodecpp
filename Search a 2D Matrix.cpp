class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0;
        int r = matrix.size()*matrix[0].size();
        int col =matrix[0].size();
        
        while(l<r)
        {
            int mid = l+(r-l)/2;
            if(matrix[mid/col][mid%col] == target)
                return true;
            else if(target < matrix[mid/col][mid%col] )
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        return false;
    }
};