class CustomStack {
public:
	vector<int> add;
	vector<int> v;
	int n;
	int idx;

	CustomStack(int maxSize) {
		add.resize(maxSize);
		idx = 0;
		n = maxSize;
	}

	void push(int x) {
		if (idx < n)
		{
			v.push_back(x);
			idx++;
		}
	}

	int pop() {

		if (!v.empty())
		{
			int ans = v.back() + add[idx - 1];
			if (idx > 1) {
				add[idx - 2] += add[idx - 1];
			}
			add[idx - 1] = 0;
			v.pop_back();
			idx--;
			return ans;
		}

		return -1;

	}

	void increment(int k, int val) {
		k = min(k, idx);
		if (k > 0)
			add[k - 1] += val;
	}
};
