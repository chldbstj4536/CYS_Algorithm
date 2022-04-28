#include <iostream>
#include <string>

using namespace std;

bool map[26][26] = {};

int main()
{
	int N, M;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		char a, b;
		string temp;
		cin >> a >> temp >> b;
		map[a - 'a'][b - 'a'] = true;
	}


	for (int via = 0; via < 26; ++via)
	{
		for (int from = 0; from < 26; ++from)
		{
			if (via == from)
				continue;

			for (int to = 0; to < 26; ++to)
			{
				if (via == to)
					continue;

				if (from == to || map[from][via] && map[via][to])
					map[from][to] = true;
			}
		}
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		char a, b;
		string temp;
		cin >> a >> temp >> b;
		cout << (map[a - 'a'][b - 'a'] ? 'T' : 'F') << endl;
	}

	return 0;
}