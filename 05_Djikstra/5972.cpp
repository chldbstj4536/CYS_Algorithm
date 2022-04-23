#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using uint = unsigned int;

static const int _MAX = 50001;

uint costMap[_MAX];
//        <비용, 목적지>
vector<pair<uint, uint>> V[_MAX] = {};

int Djikstra(uint start, uint end)
{
	priority_queue<pair<uint, uint>, vector<pair<uint, uint>>, greater<pair<uint, uint>>> q;

	for (auto& e : V[start])
		q.push(e);

	while (!q.empty())
	{
		auto [cost, dest] = q.top();
		q.pop();

		if (dest == end)
			return cost;

		if (cost >= costMap[dest])
			continue;

		costMap[dest] = cost;

		for (auto [nextCost, nextDest] : V[dest])
			q.push(make_pair(cost + nextCost, nextDest));
	}

	return -1;
}

int main()
{
	int N, M;

	cin >> N >> M;
	memset(costMap, -1, sizeof(costMap));

	for (int i = 1; i <= M; ++i)
	{
		uint A_i, B_i, C_i;
		cin >> A_i >> B_i >> C_i;
		V[A_i].push_back(make_pair(C_i, B_i));
		V[B_i].push_back(make_pair(C_i, A_i));
	}

	int result = Djikstra(1, N);

	if (result == -1)
		return 0;

	cout << result << endl;

	return 0;
}