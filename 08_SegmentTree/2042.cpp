#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long InitTree(const vector<long long>& datas, long long node, long long start, long long end, vector<long long>& tree);
long long GetPrefixSum(const vector<long long>& tree, long long node, long long start, long long end, long long left, long long right);
long long UpdateTree(vector<long long>& tree, long long node, long long start, long long end, long long index, long long difference);

int main()
{
	long long N, M, K;
	cin >> N >> M >> K;

	vector<long long> datas(N + 1);
	vector<long long> tree;

	for (long long i = 1; i <= N; ++i)
		cin >> datas[i];

	tree.assign(1 << (int)ceil(log2(N)) + 1, 0);
	InitTree(datas, 1, 1, N, tree);

	for (long long i = 0; i < M + K; ++i)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			UpdateTree(tree, 1, 1, N, b, c);
		else
			cout << GetPrefixSum(tree, 1, 1, N, b, c) << endl;
	}

	return 0;
}

long long InitTree(const vector<long long>& datas, long long node, long long start, long long end, vector<long long>& tree)
{
	if (start == end)
		return tree[node] = datas[start];

	long long mid = (start + end) / 2;

	return tree[node] = InitTree(datas, node * 2, start, mid, tree) + InitTree(datas, node * 2 + 1, mid + 1, end, tree);
}

long long GetPrefixSum(const vector<long long>& tree, long long node, long long start, long long end, long long left, long long right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	long long mid = (start + end) / 2;

	return GetPrefixSum(tree, node * 2, start, mid, left, right) + GetPrefixSum(tree, node * 2 + 1, mid + 1, end, left, right);
}

long long UpdateTree(vector<long long>& tree, long long node, long long start, long long end, long long index, long long difference)
{
	if (index < start || end < index)
		return tree[node];

	if (start == end)
	{
		tree[node] = difference;
		return tree[node];
	}
	else
	{
		long long mid = (start + end) / 2;
		return tree[node] = UpdateTree(tree, node * 2, start, mid, index, difference) + UpdateTree(tree, node * 2 + 1, mid + 1, end, index, difference);
	}
}