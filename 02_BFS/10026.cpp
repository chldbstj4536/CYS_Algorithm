#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<pair<int, int>> q;

	bool map[101][101] = {};
	bool mapRG[101][101] = {};
	string picture[101] = {};

	int N, result = 0, resultRG = 0;

	cin >> N;

	// 그림 얻기
	for (int i = 0; i < N; ++i)
	{
		cin >> picture[i];
	}

	// 왼쪽 위부터 영역 탐색
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			// 영역의 값 설정
			int areaChar = picture[i][j];

			// 탐색을 했던 곳인지 확인
			if (!map[i][j])
			{
				// 차례대로 탐색 위치 삽입
				q.push(make_pair(i, j));

				// 탐색하지 않은곳이기에 새로운 영역
				++result;

				// 새로운 영역 구역 탐색
				while (!q.empty())
				{
					auto [row, coloum] = q.front();
					q.pop();

					// 자기 구역이 아니고 이미 탐색헀던곳이라면 패스
					if (map[row][coloum] || picture[row][coloum] != areaChar)
						continue;

					// 탐색 완료 표시
					map[row][coloum] = true;

					// 자신의 주변영역이 막다른 곳이거나 탐색했던곳이 아니라면 탐색 범위 추가
					if (row != 0)			q.push(make_pair(row - 1, coloum));
					if (row != N - 1)		q.push(make_pair(row + 1, coloum));
					if (coloum != 0)		q.push(make_pair(row, coloum - 1));
					if (coloum != N - 1)	q.push(make_pair(row, coloum + 1));
				}
			}

			// 적록 영역 탐색을 했던 곳인지 확인
			if (!mapRG[i][j])
			{
				// 위와 동일
				q.push(make_pair(i, j));
				++resultRG;

				while (!q.empty())
				{
					auto [row, coloum] = q.front();
					q.pop();

					if (mapRG[row][coloum])
						continue;

					// 탐색 영역 문자가 파랑이면
					if (areaChar == 'B')
					{
						// 파랑이 아닐경우 패스
						if (picture[row][coloum] != areaChar)
							continue;
					}
					// 탐색 영역이 적록이면
					else
					{
						// 파랑일 경우 패스
						if (picture[row][coloum] == 'B')
							continue;
					}



					mapRG[row][coloum] = true;

					if (row != 0)			q.push(make_pair(row - 1, coloum));
					if (row != N - 1)		q.push(make_pair(row + 1, coloum));
					if (coloum != 0)		q.push(make_pair(row, coloum - 1));
					if (coloum != N - 1)	q.push(make_pair(row, coloum + 1));
				}
			}
		}
	}

	cout << result << ' ' << resultRG << endl;
}