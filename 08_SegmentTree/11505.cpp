#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using type = unsigned long long;

type InitTree(const vector<type>& datas, type node, type start, type end, vector<type>& tree)
{
	if (start == end)
		return tree[node] = datas[start];

	type mid = (start + end) / 2;

	return tree[node] = (InitTree(datas, node * 2, start, mid, tree) * InitTree(datas, node * 2 + 1, mid + 1, end, tree)) % 1000000007;
}

type GetPrefixSum(const vector<type>& tree, type node, type start, type end, type left, type right)
{
	if (left > end || right < start)
		return 1;

	if (left <= start && end <= right)
		return tree[node];

	type mid = (start + end) / 2;

	return (GetPrefixSum(tree, node * 2, start, mid, left, right) * GetPrefixSum(tree, node * 2 + 1, mid + 1, end, left, right)) % 1000000007;
}

type UpdateTree(vector<type>& tree, type node, type start, type end, type index, type difference)
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
		type mid = (start + end) / 2;
		return tree[node] = (UpdateTree(tree, node * 2, start, mid, index, difference) * UpdateTree(tree, node * 2 + 1, mid + 1, end, index, difference)) % 1000000007;
	}
}

int main()
{
	type N, M, K;
	cin >> N >> M >> K;

	vector<type> datas(N + 1);
	vector<type> tree;

	for (type i = 1; i <= N; ++i)
		cin >> datas[i];

	tree.assign(1 << (int)ceil(log2(N)) + 1, 0);
	InitTree(datas, 1, 1, N, tree);

	for (type i = 0; i < M + K; ++i)
	{
		type a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			UpdateTree(tree, 1, 1, N, b, c);
		else
			cout << GetPrefixSum(tree, 1, 1, N, b, c) % 1000000007 << endl;
	}

	return 0;
}