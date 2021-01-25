class Solution{
	private:
		map<char, int>charmap{
			{ 'I', 1 },
			//{ "IV", 4 },
			{ 'V', 5 },
			//{ "IX", 9 },
			{ 'X', 10 },
			//{ "XL", 40 },
			{ 'L', 50 },
			//{ "XC", 90 },
			{ 'C', 100 },
			//{ "CD", 400 },
			{ 'D', 500 },
			// "CM", 900 },
			{ 'M', 1000 }
		};
public:
	int romanToInt(string s) {
		int len = s.length();
        if(len <=0)
            return 0;
		int i = 0;
		map<char, int>::iterator it;
		int num = 0;
		while (s[i] != '\0')
		{
			//int num = 0;
			if (s[i] == 'I' || s[i] == 'X' || s[i] == 'C')
			{
				if (s[i] == 'I')
				{
					switch (s[i + 1])
					{
					case 'V':
						num += 4;
						i += 2;
						break;
					case 'X':
						num += 9;
						i += 2;
						break;
					default:
						num += 1;
						i++;
					}
				}
				else if (s[i] == 'X')
				{
					switch (s[i + 1])
					{
					case 'L':
						num += 40;
						i += 2;
						break;
					case 'C':
						num += 90;
						i += 2;
						break;
					default:
						num += 10;
						i++;
					}
				}
				else if (s[i] == 'C') 
				{
					switch (s[i + 1])
					{
					case 'D':
						num += 400;
						i += 2;
						break;
					case 'M':
						num += 900;
						i += 2;
						break;
					default:
						num += 100;
						i++;
					}
				}
			}
			else
			{
				it = charmap.find(s[i]);
				if ( it == charmap.end())
				{
					return 0;
				}
				num += it->second;
				i++;
			}
		}
        return num;
	}
};