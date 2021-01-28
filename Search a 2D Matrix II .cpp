class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=0;//matrix.size()-1;
        int col = matrix[0].size()-1;
        int r=0;
        while(row<matrix.size() && col>=0)
        {
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
            {
                --col;
            }
            else
            {
                row++;
            }
                
        }
        return false;
        
    }
};