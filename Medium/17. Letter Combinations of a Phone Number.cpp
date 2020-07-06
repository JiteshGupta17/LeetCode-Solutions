class Solution {
public:

    vector<string> nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits, int i = 0) {

        if (digits.empty()) return {};

        if (i == digits.length())
        {
            return {""};
        }

        int dig = digits[i] - '0';
        vector<string> recAns = letterCombinations(digits, i + 1);

        vector<string> ans;

        for (char ch : nums[dig])
        {
            for (string t : recAns)
            {
                ans.push_back(ch + t);
            }
        }

        return ans;

    }
};