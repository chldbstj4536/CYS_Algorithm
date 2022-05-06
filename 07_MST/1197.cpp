#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_V = 10001;

int parentMap[MAX_V];

int FindParent(int v)
{
	if (v == parentMap[v] || parentMap[v] == 0)
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
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
	int V, E, A, B, C, result = 0;

	cin >> V >> E;
	for (int i = 0; i < E; ++i)
	{
		cin >> A >> B >> C;
		q.push(make_tuple(C, A, B));
	}

	for (int i = 0; i < V - 1; ++i)
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