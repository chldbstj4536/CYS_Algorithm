#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

const int MAX_V = 1001;

int NxN[MAX_V][MAX_V];
int parentMap[MAX_V];

int FindParent(int v)
{
	if (v == parentMap[v] || parentMap[v] == -1)
		return v;

	return parentMap[v] = FindParent(parentMap[v]);
}

bool Merge(int x, int y)
{
	x = FindParent(x);
	y = FindParent(y);

	if (x == y)
		return false;

	parentMap[y] = x;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
	long N, C, result = 0;
	memset(parentMap, -1, sizeof(parentMap));

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> C;
			NxN[i][j] = C;
		}
	}

	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j)
			q.push(make_tuple(NxN[i][j], i, j));

	for (int i = 0; i < N - 1; ++i)
	{
		while (true)
		{
			auto [weight, x, y] = q.top();
			q.pop();

			if (Merge(x, y))
			{
				result += weight;
				break;
			}
		}
	}

	cout << result;

	return 0;
}