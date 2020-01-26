#include <bits/stdc++.h>
using namespace std;


string removeDuplicates_usingStack(string s, int k) {

    stack<pair<char, int>> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty())
        {
            st.push({s[i], 1});
            continue;
        }
        auto temp = st.top();

        if (temp.first == s[i])
        {
            st.push({s[i], temp.second + 1});
        }
        else {
            st.push({s[i], 1});
        }

        if (st.top().second == k)
        {
            int t = k;
            while (t--) st.pop();
        }
    }

    string ans = "";
    while (!st.empty())
    {
        ans = st.top().first + ans;
        st.pop();
    }

    return ans;
}
// Better time complexity
string removeDuplicates_usingVector(string s, int k) {

    vector<pair<char, int>> st(s.length());
    int len = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (len == 0)
        {
            st[len] = {s[i], 1};
            len++;
            continue;
        }
        auto temp = st[len - 1];

        if (temp.first == s[i])
        {
            st[len] = {s[i], temp.second + 1};
        }
        else {
            st[len] = {s[i], 1};
        }

        if (st[len].second == k)
        {
            len -= k;
        }

        len++;
    }

    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans += st[i].first;
    }

    return ans;

}

int main() {
    cout << removeDuplicates_usingStack("deeedbbcccbdaa", 3) << endl;
    cout << removeDuplicates_usingVector("pbbcggttciiippooaais", 2);

}
