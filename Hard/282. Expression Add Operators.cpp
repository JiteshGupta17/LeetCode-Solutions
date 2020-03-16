class Solution {
public:
    vector<string> finalans;

    // Sofar = expression/ans evaluated so far
    // prev = prev operator along with operand, need to keep this just because of multiplication
    // as 1+2*3 should be evaluated as 7 not 9

    void addOperators(string num, int target, string ans, int idx, long Sofar, long prev)
    {
        if (idx == num.length())
        {
            if (Sofar == target)
            {
                finalans.push_back(ans);
            }
            return;
        }

        for (int i = idx; i < num.length(); i++)
        {
            if (i != idx && num[idx] == '0') break; // Imagine with 120,3

            long cur = stol(num.substr(idx, i - idx + 1));

            if (idx == 0)
            {
                addOperators(num, target, ans + to_string(cur), i + 1, cur, cur);
            }
            else {

                //Plus
                addOperators(num, target, ans + '+' + to_string(cur), i + 1, Sofar + cur, cur);

                //Minus
                addOperators(num, target, ans + '-' + to_string(cur), i + 1, Sofar - cur, -cur);

                // Multipy
                addOperators(num, target, ans + '*' + to_string(cur), i + 1, Sofar - prev + cur * prev, cur * prev);
            }
        }

    }

    vector<string> addOperators(string num, int target) {

        finalans = {};
        if (num.length() == 0) return finalans;

        addOperators(num, target, "", 0, 0, 0);

        return finalans;
    }
};
