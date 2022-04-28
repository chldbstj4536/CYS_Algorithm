#include <iostream>

using namespace std;

int map[101][101] = {};

int main()
{
	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			map[i][j] = 100000000;

	for (int i = 0; i < M; ++i)
	{
		int s, e, c;
		cin >> s >> e >> c;
		if (map[s][e] > c)
			map[s][e] = c;
	}

	for (int via = 1; via <= N; ++via)
	{
		for (int from = 1; from <= N; ++from)
		{
			if (via == from)
				continue;

			for (int to = 1; to <= N; ++to)
			{
				if (via == to || from == to)
					continue;

				if (map[from][to] > map[from][via] + map[via][to])
					map[from][to] = map[from][via] + map[via][to];
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			cout << ((map[i][j] == 100000000) ? 0 : map[i][j]) << ' ';
		cout << endl;
	}

	return 0;
}