#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
const int MAX_V = 251;

bool map[MAX_V][MAX_V] = {};
unsigned int minChange[MAX_V][MAX_V] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			minChange[i][j] = 1000000;

	for (int i = 0; i < m; ++i)
	{
		int u, v, b;
		bool bInter;

		cin >> u >> v >> b;

		bInter = b == 1;

		map[u][v] = map[v][u] = true;

		minChange[u][v] = 0;
		if (bInter)
			minChange[v][u] = 0;
		else
			minChange[v][u] = 1;
	}

	for (int via = 1; via <= n; ++via)
	{
		for (int from = 1; from <= n; ++from)
		{
			if (via == from)
				continue;

			for (int to = 1; to <= n; ++to)
			{
				if (via == to)
					continue;

				if (from == to)
				{
					minChange[from][to] = 0;
					continue;
				}

				if (map[from][via] && map[via][to])
				{
					map[from][to] = true;
					if (minChange[from][to] > minChange[from][via] + minChange[via][to])
						minChange[from][to] = minChange[from][via] + minChange[via][to];
				}
			}
		}
	}

	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		int s, e;
		cin >> s >> e;
		cout << minChange[s][e] << '\n';
	}

	return 0;
}