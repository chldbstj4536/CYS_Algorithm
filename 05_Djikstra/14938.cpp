#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#include <cmath>

using namespace std;
using uint = unsigned int;

//  <아이템>          <목적지, 비용>
pair<uint, vector<pair<uint, uint>>> V[101] = {};

int Djikstra(uint start, uint maxDistance)
{
	//		  <도착지, 거리>
	queue<pair<uint, uint>> q;
	bool visitMap[101] = {};
	uint maxItem;

	auto [item, edge] = V[start];
	maxItem = item;
	visitMap[start] = true;

	for (int i = 0; i < edge.size(); ++i)
		q.push(edge[i]);

	while (!q.empty())
	{
		auto [area, curDist] = q.front();
		q.pop();

		if (curDist > maxDistance)
			continue;

		auto [curItem, route] = V[area];

		if (!visitMap[area])
		{
			visitMap[area] = true;
			maxItem += curItem;
		}

		for (auto [nextArea, dist] : route)
			q.push(make_pair(nextArea, curDist + dist));
	}

	return maxItem;
}

int main()
{
	int N, M, R, maxItem = 0;;

	cin >> N >> M >> R;

	for (int i = 1; i <= N; ++i)
	{
		auto& [item, edge] = V[i];
		cin >> item;
	}

	for (int i = 1; i <= R; ++i)
	{
		uint A_i, B_i, C_i;

		cin >> A_i >> B_i >> C_i;

		auto& [A_item, A_edge] = V[A_i];
		auto& [B_item, B_edge] = V[B_i];

		A_edge.push_back(make_pair(B_i, C_i));
		B_edge.push_back(make_pair(A_i, C_i));
	}

	for (int i = 1; i <= N; ++i)
		maxItem = max(maxItem, Djikstra(i, M));

	cout << maxItem << endl;

	return 0;
}