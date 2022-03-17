#include <iostream>
#include <queue>

using namespace std;

int main()
{
	pair<bool, int> map[100001] = {};
	int N, K, result = 100001, way = 0;

	cin >> N >> K;

	queue<pair<int, int>> q;

	q.push(make_pair(0, N));

	while (!q.empty())
	{
		const auto [time, pos] = q.front();
		q.pop();

		auto& [bPassed, passTime] = map[pos];

		// 맵을 통해 지나간 곳이면서 더 늦은시간에 지나간다면 건너 뛰고, 도착시간보다 오래 걸린 시간들도 건너 뛴다.
		if ((bPassed && passTime < time) || time > result)
			continue;

		// 찾았으면 최소값 저장 및 방법 수 증가
		if (pos == K)
		{
			result = time;
			++way;
			continue;
		}

		// 맵 세팅
		bPassed = true;
		passTime = time;


		// 현재 움직일 수 있는 범위 탐색
		q.push(make_pair(time + 1, pos + 1));
		if (pos != 0)
		{
			q.push(make_pair(time + 1, pos - 1));
			if (pos <= 50000)
				q.push(make_pair(time + 1, pos * 2));
		}
	}

	cout << result << endl << way << endl;

	return 0;
}