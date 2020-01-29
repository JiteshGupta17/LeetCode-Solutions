#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {

    if (path.length() == 0) return "";

    string combinedSoFar = "";

    stack<string> s;
    path += '/';

    for (int i = 0; i < path.length(); i++)
    {
        char cur = path[i];

        if (cur == '/')
        {
            if ( combinedSoFar == "." || combinedSoFar == "")
            {
                combinedSoFar.clear();
                continue;
            }
            else if (combinedSoFar == "..")
            {
                if (!s.empty()) s.pop();
            }
            else {
                s.push(combinedSoFar);
            }
            combinedSoFar.clear();

        }
        else combinedSoFar += cur;
        // cout<<i<<" "<<combinedSoFar<<" "<<endl;
    }

    if (s.empty())return "/";

    string ans = "";
    while (!s.empty())
    {
        ans = s.top() + ans;
        ans = '/' + ans;
        s.pop();
    }
    return ans;
}



int main() {
    cout << simplifyPath("/a/./b/../../c/") << endl;
    cout << simplifyPath("/a/../../b/../c//.//") << endl;
    cout << simplifyPath("/a//b////c/d//././/..") << endl;
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath("") << endl;



}
