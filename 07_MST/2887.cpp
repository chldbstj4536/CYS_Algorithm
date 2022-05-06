#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

const int MAX_V = 100000;

struct Planet
{
	int x, y, z;

	int Cost(Planet p)
	{
		return min(min(abs(x - p.x), abs(y - p.y)), abs(z - p.z));
	}
};

Planet planets[MAX_V];
int parentMap[MAX_V];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;

int FindParent(const int& v)
{
	if (v == parentMap[v] || parentMap[v] == -1)
		return v;

	return parentMap[v] = FindParent(parentMap[v]);
}

bool Merge(const int& x, const int& y)
{
	int px = FindParent(x);
	int py = FindParent(y);

	if (px == py)
		return false;

	parentMap[py] = px;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long N, result = 0;
	memset(parentMap, -1, sizeof(parentMap));

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> planets[i].x >> planets[i].y >> planets[i].z;

	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N; ++j)
			q.push(make_tuple(planets[i].Cost(planets[j]), i, j));

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