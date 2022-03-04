#include <iostream>

using namespace std;

int main()
{
    int N, K;
    int A[1000000] = {};
    int result = 0;

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = N - 1; i >= 0; --i)
    {
        result += K / A[i];
        K %= A[i];

        if (K == 0)
            break;
    }

    cout << result;

    return 0;
}