class Solution {
public:
    vector<string> result;
vector<string> generateParenthesis(int n) {
    helper("", n, 0);
    return result;
}

void helper(string s, int leftpare_need, int moreleft)
{
	if(leftpare_need == 0 && moreleft == 0)
	{
	    result.push_back(s);
	    return;
	}
	if(leftpare_need > 0)
		helper(s + "(", leftpare_need - 1, moreleft+1);
	if(moreleft > 0)
		helper(s + ")", leftpare_need, moreleft - 1);
}
};