#include <iostream>
#include <queue>

using namespace std;

using pairInt = pair<int, int>;

struct cmp
{
    bool operator()(pairInt lhs, pairInt rhs)
    {
        // 끝나는 시간이 같으면 시작시간이 짧은 순으로 정렬
        if (lhs.second == rhs.second)
            return lhs.first > rhs.first;

        return lhs.second > rhs.second;
    }
};

int main()
{
    int N, result = 0, ctime = 0;
    
    priority_queue<pairInt, vector<pairInt>, cmp> q;

    cin >> N;

    // 우선순의 큐에 회의를 끝나는시간이 짧은순으로 넣는다
    for (int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;
        q.push(make_pair(s, e));
    }

    // 회의 끝나는 시간이 가장 짧은순으로 배정해준다
    for (int i = 0; i < N; i++)
    {
        pairInt top = q.top();
        q.pop();

        // 회의시간이 짧게 끝나지만 시작시간이 늦은경우
        if (ctime > top.first)
            continue;

        ctime = top.second;
        ++result;
    }

    cout << result;

    return 0;
}