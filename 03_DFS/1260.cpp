#include <iostream>
#include <list>
#include <queue>

using namespace std;

// 그래프의 노드
struct Node
{
    // 연결된 노드들의 인덱스
    list<int> linkedNodesIndex;
    bool bVisitInDFS;
    bool bVisitInBFS;
};

Node nodes[1000];

void DFS(int v)
{
    if (nodes[v - 1].bVisitInDFS)
        return;

    nodes[v - 1].bVisitInDFS = true;

    cout << v << ' ';

    for (auto linkedIndex : nodes[v - 1].linkedNodesIndex)
        DFS(linkedIndex);
}

int main()
{
    int N, M, V;
    queue<int> q;
    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i)
    {
        int s, e;
        cin >> s >> e;
        nodes[s - 1].linkedNodesIndex.push_back(e);
        nodes[e - 1].linkedNodesIndex.push_back(s);
    }

    for (int i = 0; i < N; ++i)
        nodes[i].linkedNodesIndex.sort();


    DFS(V);

    cout << endl;

    q.push(V);

    while (!q.empty())
    {
        int curPosition = q.front();
        q.pop();

        if (nodes[curPosition - 1].bVisitInBFS)
            continue;

        nodes[curPosition - 1].bVisitInBFS = true;
        cout << curPosition << ' ';

        for (auto linkedIndex : nodes[curPosition - 1].linkedNodesIndex)
            q.push(linkedIndex);
    }

    return 0;
}