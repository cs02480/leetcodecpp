class Tnode
{
public:
	Tnode * child[26];
	bool isend;
	int count;
	Tnode()
	{
		for (int i = 0; i < 26; i++)
		{
			child[i] = NULL;
		}
		isend = false;
		count = 0;
	}
};
int getIndex(char c)
{
	return c - 'a';
}
void insert(Tnode * trie, string s)
{
	if (trie == NULL)
	{
		return;
	}
	int i = 0;
	int len = s.length();
	Tnode * tmp;
	while (s[i] != '\0')
	{
		tmp = trie->child[getIndex(s[i])];
		if (tmp == NULL)
		{
			tmp = new Tnode();
			trie->child[getIndex(s[i])] = tmp;
			trie->count++;
		}
		i++;
		trie = tmp;
	}
	trie->isend = true;

}
Tnode * root;
string getprefix(Tnode * root,string ans)
{

	if (root == NULL || root->count == 0 || root->count > 1)
		return ans;
    	if (root->isend == true)
		return ans;
	for (int i = 0; i < 26; i++)
	{
		if (root->child[i])
		{
			ans += string(1, 'a' + i);
			return getprefix(root->child[i], ans);
		}
	}
	return ans;
}
class Solution {

public:
	string longestCommonPrefix(vector<string>& strs) {
		Tnode * root = new Tnode();
		int len = strs.size();
		for (int i = 0; i < len; i++)
		{
            if (strs[i].length() <= 0)
				root->count++;
			insert(root, strs[i]);
		}
		string ans = "";
		return getprefix(root, ans);

	}
};