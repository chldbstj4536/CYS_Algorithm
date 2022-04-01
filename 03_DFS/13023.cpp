#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct Node
{
    list<int> linkedNodesIndex;
    bool bVisit;
};

Node nodes[2000];

bool FindABCDE(int n, int linkCount)
{
    if (nodes[n].bVisit)
        return false;

    if (++linkCount == 5)
        return true;

    nodes[n].bVisit = true;

    for (auto linkedNode : nodes[n].linkedNodesIndex)
    {
        if (FindABCDE(linkedNode, linkCount))
            return true;
    }
    nodes[n].bVisit = false;

    return false;
}

int main()
{
    int N, M;
    cin >> N >> M;

    // 그래프 구성
    for (int i = 0; i < M; ++i)
    {
        int s, e;
        cin >> s >> e;
        nodes[s].linkedNodesIndex.push_back(e);
        nodes[e].linkedNodesIndex.push_back(s);
    }

    for (int i = 0; i < N; ++i)
    {
        // 모든 노드에서 찾아보고 못찾으면 ABCDE가 존재하지 않는것
        if (FindABCDE(i, 0))
        {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}