class Solution{
private:
	vector<vector<char>> map{
		{ ' ' },
		{ ' ' },
		{ 'a', 'b', 'c' },
		{ 'd', 'e', 'f' },
		{ 'g', 'h', 'i' },
		{ 'j', 'k', 'l' },
		{ 'm', 'n', 'o' },
		{ 'p', 'q', 'r', 's' },
		{ 't', 'u', 'v' },
		{ 'w', 'x', 'y', 'z' }
	};
	void getallCombination(string s, int index, vector<string> & list, string ans)
	{
		if (s[index] == '\0')
		{
			list.push_back(ans);
			return;
		}
		vector<char> cond = map[s[index] - '0'];
		for (int i = 0; i<cond.size(); i++)
		{
			getallCombination(s, index + 1, list, ans + string(1, cond[i]));
		}
	}
public:
	vector<string> letterCombinations(string digits) {
        vector<string> list;
        if(digits == "")
            return list; 
		//vector<string> list;
		getallCombination(digits, 0, list, "");
		return list;
	}
};