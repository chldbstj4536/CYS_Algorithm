#include <iostream>
#include <queue>

using namespace std;

int main()
{
	bool map[100001] = {};

	int N, K, result = 0;
	int temp;

	cin >> N >> K;

	queue<pair<int, int>> q;

	q.push(make_pair(0, N));

	while (true)
	{
		const auto [time, pos] = q.front();
		q.pop();

		// 이미 한번 갔던곳은 제외
		if (map[pos])
			continue;

		map[pos] = true;

		// 찾았으면 출력 후 종료
		if (pos == K)
		{
			cout << time << endl;
			break;
		}

		// 현재 움직일 수 있는 범위 탐색
		q.push(make_pair(time + 1, pos + 1));
		if (pos != 0)
		{
			q.push(make_pair(time + 1, pos - 1));
			if (pos <= 50000)
				q.push(make_pair(time + 1, pos * 2));
		}
	}

	return 0;
}