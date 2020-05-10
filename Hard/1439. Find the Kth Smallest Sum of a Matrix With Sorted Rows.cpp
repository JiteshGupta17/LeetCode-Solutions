class Solution {
public:

	// https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/

	int kthSmallest(vector<vector<int>>& mat, int k) {

		int n = mat.size(), m = mat[0].size();

		// vector of indices
		vector<int> temp(n, 0);
		set<vector<int>> st; // to map the indices

		// to mark which seq has beed added previously
		st.insert(temp);
		int sum = 0;
		for (int i = 0; i < n; i++) sum += mat[i][0];

		priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

		pq.push({sum, temp});

		k--;
		while (k-- && !pq.empty())
		{
			int cur_sum = pq.top().first;
			// cout<<cur_sum<<endl;
			auto vec = pq.top().second;
			pq.pop();

			for (int i = 0; i < n; i++)
			{
				// index of ith row element
				if (vec[i] + 1 < m)
				{
					vec[i]++;
					if (st.count(vec) == 0)
					{
						pq.push({cur_sum + mat[i][vec[i]] - mat[i][vec[i] - 1], vec});
						st.insert(vec);
					}
					vec[i]--;
				}
			}
		}

		return pq.top().first;
	}
};
