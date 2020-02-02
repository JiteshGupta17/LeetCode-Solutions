#include <bits/stdc++.h>
using namespace std;

map<string, int> solve(string formula, int &i)
{
	// cout<<i<<endl;

	map<string, int> m;
	string CombinedSoFar = "";

	while (i < formula.length())
	{
		char cur = formula[i];

		if (cur == ')')
		{
			if (CombinedSoFar != "")
			{
				m[CombinedSoFar] += 1;
				CombinedSoFar.clear();
			}

			return m;
		}
		else if (cur == '(')
		{
			int st = i + 1;
			map<string, int> m_recur = solve(formula, st);
			i = st;

			int num = 0;
			while (i + 1 < formula.length() && isdigit(formula[i + 1]))
			{
				num = num * 10 + formula[i + 1] - '0';
				i++;
			}

			for (auto f : m_recur)
			{
				m[f.first] += num * f.second;
			}

		}
		else if (islower(cur))
		{
			CombinedSoFar += cur;
		}
		else if (isupper(cur))
		{
			if (CombinedSoFar != "")
			{
				m[CombinedSoFar] += 1;
				CombinedSoFar.clear();

			}
			CombinedSoFar += cur;
		}
		else if (isdigit(cur))
		{
			int num = cur - '0';
			while (i + 1 < formula.length() && isdigit(formula[i + 1]))
			{
				num = num * 10 + formula[i + 1] - '0';
				i++;
			}

			m[CombinedSoFar] += num;
			CombinedSoFar.clear();
		}

		i++;
	}

	return m; // Just to return but never returns from here

}

string countOfAtoms(string formula)
{
	formula.push_back(')');
	int st = 0;
	map<string, int> m = solve(formula, st);

	string ans = "";

	for (auto f : m)
	{
		ans += f.first;
		int freq = f.second;
		if (freq > 1)
			ans += to_string(freq);
	}

	return ans;
}

int main() {
	cout << countOfAtoms("H2O") << endl;
	cout << countOfAtoms("K4(ON(SO3)2)2") << endl;
}
