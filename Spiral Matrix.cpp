class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		int i, k = 0, l = 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> ans;
		if (m == 0 || n == 0)
			return ans;
		while (k<m && l<n)
		{
			for (int i = l; i<n; i++)   //first row in remaing
			{
				ans.push_back(matrix[k][i]);
			}
			k++;
			for (int i = k; i < m;i++)  //last column in remianig matrix
				ans.push_back(matrix[i][n-1]);
			n--;
			if (k < m){
				for (int i = n - 1; i >= l; i--) //last row in remianig matrix
					ans.push_back(matrix[m-1][i]);
				m--;
			}
			
			if (l < n)
			{
				for (int i = m - 1; i >= k; i--) //first column in remianig matrix
				{
					ans.push_back(matrix[i][l]);
				}
				l++;
			}

		}
		return ans;

	}
};