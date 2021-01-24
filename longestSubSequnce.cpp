class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1len = text1.length();
        int t2len = text2.length();
        int lcs[t1len+1][t2len+1];
        for(int i=0;i<=t1len ;i++)   //j ===0 case
            lcs[i][0]=0;
        for(int i=0;i<=t2len ;i++)  //i ==0 case
            lcs[0][i]=0;
        
        for(int i=1;i<=t1len;i++)
        {
            for(int j = 1;j<=t2len;j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    lcs[i][j] = lcs[i-1][j-1]+1;
                }
                else
                {
                    lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
        }
        return lcs[t1len][t2len];
    }
};