#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N, chart[100];

    cin >> N;

    // 이전값과 비교하기 위한 변수
    set<int> temp;
    set<int> result;

    for (int i = 0; i < N; ++i)
    {
        cin >> chart[i];
        result.insert(chart[i]);
    }

    // result의 크기가 N과 같다면 중복이 없으므로 결과는 result다
    if (result.size() != N)
    {
        while (temp.size() != result.size())
        {
            temp = result;
            result.clear();

            // 새롭게 나온 값들로 다시 참조 안하는 값을 제거
            for (auto i : temp)
                result.insert(chart[i - 1]);
        }
    }

    cout << result.size() << endl;
    for (auto i : result)
        cout << i << endl;

    return 0;
}