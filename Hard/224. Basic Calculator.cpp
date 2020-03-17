class Solution {
public:
    int idx;

    // Using recursion which is itself works as a stack

    int calc(string s)
    {

        int sum = 0;
        int sign = 1; //+ve

        while (idx < s.length())
        {

            if (s[idx] == ')')
            {
                return sum;
            }
            if (s[idx] == '(')
            {
                idx++;
                sum += sign * calc(s);
            }

            // To form the number as it might be more than sigle digit
            if (isdigit(s[idx])) {

                int cur = s[idx] - '0';
                while (idx + 1 < s.length() && isdigit(s[idx + 1]))
                {
                    cur = cur * 10 + (s[idx + 1] - '0');
                    idx++;
                }
                sum += sign * cur;

            }

            if (s[idx] == '+')
            {
                sign = 1;
            }
            else if (s[idx] == '-')
            {
                sign = -1;
            }
            idx++;
        }

        return sum;
    }


    int calculate(string s) {
        idx = 0;
        s = s + ')';
        return calc(s);


    }
};
