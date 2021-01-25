class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        if(s == "")
            return true;
        int i=0;
        while(s[i] != '\0')
        {
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(!st.empty() && s[i] == '}' && st.top() == '{')
            {
                st.pop();
            }
            else if(!st.empty() && s[i] == ']' && st.top() == '[')
            {
                st.pop();
            }
            else if(!st.empty() && s[i] == ')' && st.top() == '(')
            {
                st.pop();
            }
            else
                return false;
            i++;
        }
        if(st.empty() && s[i] == '\0') return true;
            
            return false;
        
    }
};