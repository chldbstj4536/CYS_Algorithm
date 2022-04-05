#include <iostream>

using namespace std;

int main()
{
	int N;
	int f[1001] = {};

	cin >> N;

	f[0] = 1;
	f[1] = 1;

    // N번째까지의 피보나치 수열 구하기
	for (int i = 2; i <= N; ++i)
		f[i] = (f[i - 1] + f[i - 2]) % 10007;

    // N번째 피보나치 수열 출력
	cout << f[N] << endl;

	return 0;
}