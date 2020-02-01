#include <bits/stdc++.h>
using namespace std;

int myAtoi(string str) {

    // st will be start index of number or sign
    int st = -1;
    for (int i = 0; i < str.length(); i++)
    {
        char cur = str[i];
        if (cur == '+' || cur == '-' || isdigit(cur))
        {
            st = i;
            break;
        }
    }
    // If no digit found return 0
    if (st == -1) return 0;

    // If letters occur before digit or white space
    for (int i = 0; i < st; i++)
    {
        if (str[i] != ' ') return 0;
    }

    char sign = '+';

    char cur = str[st];
    if (cur == '+' || cur == '-')
    {
        sign = cur;
        st++;
    }

    long long int ans = 0;
    while (isdigit(str[st]) && st < str.length())
    {
        ans = ans * 10 + (str[st] - '0');
        st++;

        if (sign == '-')
        {
            if (-ans <= INT_MIN) return INT_MIN;
        }
        else if (ans >= INT_MAX) return INT_MAX;
    }

    ans =  sign == '-' ? -ans : ans;

    return ans;
}

int main() {
    cout << myAtoi("-42") << endl;
    cout << myAtoi("42") << endl;
    cout << myAtoi("4193 with words") << endl;
    cout << myAtoi("words and 987") << endl;
    cout << myAtoi("-91283472332") << endl;
}
