#include <iostream>

using namespace std;

int main()
{
    int N;
    int result = 0;

    cin >> N;

    // 5킬로봉지로 담을 수 있는 큰 수 구하기
    // 처음 i의 값은 담을 수 있는 가장 큰 5킬로봉지 갯수
    for (int i = N / 5; i >= 0; --i)
    {
        // i갯수만큼 5킬로봉지에 담고 남은 설탕의 양
        int rest = N - (i * 5);
        // 남은 양이 3킬로봉지에 모두 담을 수 있으면 5킬로봉지로 담을 수 있는 가장 큰 수가 i
        if (rest % 3 == 0)
        {
            result = i + (rest / 3);
            break;
        }
    }

    if (result == 0)
        cout << -1;
    else
        cout << result;

    return 0;
}