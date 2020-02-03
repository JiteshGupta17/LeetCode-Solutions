//Using MaxHeap 
int findKthLargest(vector<int>& nums, int k)
{
	priority_queue <int> pq(nums.begin(), nums.end());

	for (int i = 0; i < k - 1; i++)
	{
		pq.pop();
	}

	return pq.top();
}

//Using MinHeap
int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < k; i++)
	{
		pq.push(nums[i]);
	}

	for (int i = k; i < nums.size(); i++ )
	{
		if (pq.top() < nums[i])
		{
			pq.pop();
			pq.push(nums[i]);
		}
	}

	return pq.top();
}