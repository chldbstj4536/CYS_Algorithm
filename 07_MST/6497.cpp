#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

const int MAX_V = 10001;

int parentMap[MAX_V];

int FindParent(const int& v)
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
	int V, E, A, B, C, result;


	while (true)
	{
		result = 0;
		memset(parentMap, -1, sizeof(parentMap));
		while (!q.empty()) q.pop();

		cin >> V >> E;

		if (V == 0 && E == 0)
			break;

		for (int i = 0; i < E; ++i)
		{
			cin >> A >> B >> C;
			q.push(make_tuple(C, A, B));
			result += C;
		}

		for (int i = 0; i < V - 1; ++i)
		{
			while (true)
			{
				auto [weight, x, y] = q.top();
				q.pop();

				if (Merge(x, y))
				{
					result -= weight;
					break;
				}
			}
		}

		cout << result << '\n';
	}

	return 0;
}