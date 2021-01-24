#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
#include<limits>
class Solution {
public:
	bool isNumber(string s) {
		int len = s.length();
		int i = 0;
		int sign = 0;
		bool decpart = false;
		int bdec = 0;
		int afdec = 0;
		if (s[i] == '+' || s[i] == '-')
		{
			sign = 1;
			i++;
		}
		if (s[i] == '\0')
			return false;
		while (s[i] >= '0' && s[i] <= '9')
		{
			i++;
			decpart = true;
			bdec++;
		}
		if (s[i] == '\0')
			return true;
		if (s[i] == '.')
		{
			i++;
			while (s[i] >= '0' && s[i] <= '9')
			{
				i++;
				afdec++;
			}
			if (afdec == 0 && decpart == 0)
				return false;
			if (s[i] == '\0')
				return true;
			decpart = true;
		}

		if (decpart && (s[i] == 'e' || s[i] == 'E'))
		{
			i++;
			if (s[i] == '\0')
				return false;
			if (s[i] == '+' || s[i] == '-')
				i++;
			int inpart = 0;
			while (s[i] >= '0' && s[i] <= '9')
			{
				inpart++;
				i++;
			}
			if (inpart && s[i] == '\0')
				return true;
			
		}
		return false;

	}
};

int main()
{

	string s = "   -42";
	Solution sol;
	vector<string> num{ "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789" };
	vector<string>num2{ "4e-","abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53" };
	for (int i = 0; i < num2.size();i++)
		cout << sol.isNumber(num2[i]);


}