#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

	// first = distance and second is index
	// Making a maxHeap of size k
	priority_queue <pair<int, int>> pq;

	for (int i = 0; i < k; i++)
	{
		int dist = points[i][0] * points[i][0] +  points[i][1] * points[i][1];
		pq.push(make_pair(dist, i));
	}

	for (int i = k; i < points.size(); i++)
	{
		int dist = points[i][0] * points[i][0] +  points[i][1] * points[i][1];

		if (dist < pq.top().first)
		{
			pq.pop();
			pq.push(make_pair(dist, i));
		}
	}

	vector<vector<int>> ans;

	while (!pq.empty())
	{
		int i = pq.top().second;
		ans.push_back(points[i]);
		pq.pop();

	}

	return ans;
}

//2nd approach is to make a min heap and add all dist and pop the first k
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	for (int i = 0; i < points.size(); i++)
	{
		int dist = points[i][0] * points[i][0] +  points[i][1] * points[i][1];
		pq.push(make_pair(dist, i));
	}

	vector<vector<int>> ans;

	for (int i = 0; i < k; i++)
	{
		int j = pq.top().second;
		ans.push_back(points[j]);
		pq.pop();
	}
}