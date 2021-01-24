class Solution {
public:
    int myAtoi(string s) {
        int sign =1;
        int len = s.length();
        int i=0;
        int num = 0;
        while(s[i] ==' ')
            i++;
        
        if(s[i] == '-' || s[i] =='+')
        {
            if(s[i] == '-')
                sign =-1;
            i++;
        }
        while(s[i] =='0')
            i++;
        int count =0;
        int dig=0;
        while(s[i] !='\0' && s[i]>='0' && s[i]<= '9')
        {
            dig = s[i] - '0';
            if (sign ==-1) 
            {
                dig = -dig ;
            } 
            if(sign == -1 && (num < -214748364 || (num == -214748364 && dig < -8 )))
            {
                return -2147483648;
            }
            
            if(sign == 1 && (num > 214748364 || (num == 214748364 && dig >7)))
            {
                return 2147483647;
            }
    
                              
            num = num*10 + dig;
            i++;
        }
             
        return num;
    }
};