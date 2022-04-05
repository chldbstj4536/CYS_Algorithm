#include <iostream>
#include <vector>
using namespace std;

pair<int, int> items[100000] = {};
int valueChart[101][100001] = {};

int main()
{
	int N, K;
	
	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		auto& [W, V] = items[i];
		cin >> W >> V;
	}

    // 첫번째 물건부터 N번째 물건까지 넣을 수 있는 무게만큼 가장 가치가 크도록 가방에 담는다
	for (int i = 0; i < N; ++i)
	{
        // 가방의 크기가 1일경우부터 N일 경우까지일때 가장 가치가 높은 물건들로 구성한다
        // 가방의 크기가 0인 경우는 아무 물건도 못넣으므로 가치는 모두 0이다
		for (int bagSize = 1; bagSize <= K; ++bagSize)
		{
			auto [W, V] = items[i];
			
            // 가방의 크기보다 물건의 무게가 많이나가면 넣지 못하므로, 지난번의 넣었던 가치로 현재 물건을 넣었을때의 가치를 결정한다
			if (W > bagSize)
				valueChart[i + 1][bagSize] = valueChart[i][bagSize];
            // 가방의 크기보다 물건의 무게가 적게 나간다면 2가지 경우가 존재
            // 1. 현재 물건을 넣는경우 (현재 물건을 넣고 남는 공간에 가장 높은 가치를 가지도록 구성된 물건들로 채우기)
            // 2. 현재 물건을 넣지 않는경우 (그 이전에 가장 높은 가치를 가지도록 구성된 물건들로 채우기)
            // 1번과 2번중 더 높은 가치를 가진 경우를 선택하여 현재 무게일때 가장 높은 가치를 결정
			else
				valueChart[i + 1][bagSize] = max(valueChart[i][bagSize - W] + V, valueChart[i][bagSize]);
		}
	}

	cout << valueChart[N][K] << endl;

	return 0;
}