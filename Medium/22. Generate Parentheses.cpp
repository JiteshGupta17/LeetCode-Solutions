class Solution {
public:

    vector<string> ans;

    void generate(int open, int close, int n, string cur)
    {
        if (close == n) {
            ans.push_back(cur);
            return ;
        }

        if (open < n)
        {
            generate(open + 1, close, n, cur + '(');
        }

        if (open > close) generate(open, close + 1, n, cur + ')');
    }

    vector<string> generateParenthesis(int n) {

        generate(0, 0, n, "");
        return ans;
    }
};