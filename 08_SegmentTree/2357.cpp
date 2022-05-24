#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

using type = long long;

type InitMinTree(const vector<type>& datas, type node, type start, type end, vector<type>& tree)
{
	if (start == end)
		return tree[node] = datas[start];

	type mid = (start + end) / 2;

	return tree[node] = min(InitMinTree(datas, node * 2, start, mid, tree), InitMinTree(datas, node * 2 + 1, mid + 1, end, tree));
}
type GetPrefixMin(const vector<type>& tree, type node, type start, type end, type left, type right)
{
	if (left > end || right < start)
		return LLONG_MAX;

	if (left <= start && end <= right)
		return tree[node];

	type mid = (start + end) / 2;

	return min(GetPrefixMin(tree, node * 2, start, mid, left, right), GetPrefixMin(tree, node * 2 + 1, mid + 1, end, left, right));
}
type UpdateMinTree(vector<type>& tree, type node, type start, type end, type index, type difference)
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
		return tree[node] = min(UpdateMinTree(tree, node * 2, start, mid, index, difference), UpdateMinTree(tree, node * 2 + 1, mid + 1, end, index, difference));
	}
}

type InitMaxTree(const vector<type>& datas, type node, type start, type end, vector<type>& tree)
{
	if (start == end)
		return tree[node] = datas[start];

	type mid = (start + end) / 2;

	return tree[node] = max(InitMaxTree(datas, node * 2, start, mid, tree), InitMaxTree(datas, node * 2 + 1, mid + 1, end, tree));
}
type GetPrefixMax(const vector<type>& tree, type node, type start, type end, type left, type right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	type mid = (start + end) / 2;

	return max(GetPrefixMax(tree, node * 2, start, mid, left, right), GetPrefixMax(tree, node * 2 + 1, mid + 1, end, left, right));
}
type UpdateMaxTree(vector<type>& tree, type node, type start, type end, type index, type difference)
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
		return tree[node] = max(UpdateMaxTree(tree, node * 2, start, mid, index, difference), UpdateMaxTree(tree, node * 2 + 1, mid + 1, end, index, difference));
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	type N, M;
	cin >> N >> M;

	vector<type> datas(N + 1);
	vector<type> minTree;
	vector<type> maxTree;

	for (type i = 1; i <= N; ++i)
		cin >> datas[i];

	minTree.assign(1 << (int)ceil(log2(N)) + 1, 0);
	maxTree.assign(1 << (int)ceil(log2(N)) + 1, 0);

	InitMinTree(datas, 1, 1, N, minTree);
	InitMaxTree(datas, 1, 1, N, maxTree);

	for (type i = 0; i < M; ++i)
	{
		type a, b;
		cin >> a >> b;

		cout << GetPrefixMin(minTree, 1, 1, N, a, b) << ' ' << GetPrefixMax(maxTree, 1, 1, N, a, b) << '\n';
	}

	return 0;
}