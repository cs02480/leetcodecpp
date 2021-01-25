class Solution {
    private:
	map<int, string>charmap {
		{ 1, "I" },
        {4,"IV"},
		{ 5, "V" },
        {9,"IX"},
		{ 10,"X"},
        {40,"XL"},
		{ 50 ,"L" },
        {90,"XC"},
		{ 100 ,"C" },
        {400,"CD"},
		{ 500,"D" },
        {900,"CM"},
		{ 1000,"M"}
	};
public:
	string intToRoman(int num) {
		if (num <= 0)
			return "";
		map<int, string>::reverse_iterator it = charmap.rbegin();
		it->first;
		while (it != charmap.rend() &&  num < it->first)
					it++;
		string ans = "";
		while (num / it->first)
		{
			ans += it->second;
			num -= it->first;
		}
		return ans + intToRoman(num);
	}
};