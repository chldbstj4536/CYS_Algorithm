#include <iostream>
#include <vector>

using namespace std;

int gameTable[100000][3] = {};

inline int max(const int a, const int b, const int c)
{
	return max(max(a, b), c);
}
inline int min(const int a, const int b, const int c)
{
	return min(min(a, b), c);
}
inline void GetNewRecordMax(const int recordLine[], const int newLine[], int newMaxRecordLine[])
{
	newMaxRecordLine[0] = max(recordLine[0] + newLine[0], recordLine[1] + newLine[0]);
	newMaxRecordLine[1] = max(recordLine[0] + newLine[1], recordLine[1] + newLine[1], recordLine[2] + newLine[1]);
	newMaxRecordLine[2] = max(recordLine[1] + newLine[2], recordLine[2] + newLine[2]);
}
inline void GetNewRecordMin(const int recordLine[], const int newLine[], int newMinRecordLine[])
{
	newMinRecordLine[0] = min(recordLine[0] + newLine[0], recordLine[1] + newLine[0]);
	newMinRecordLine[1] = min(recordLine[0] + newLine[1], recordLine[1] + newLine[1], recordLine[2] + newLine[1]);
	newMinRecordLine[2] = min(recordLine[1] + newLine[2], recordLine[2] + newLine[2]);
}


int main()
{
	int N;
	int lastLineMax[2][3] = {};
	int lastLineMin[2][3] = {};
	int minScore, maxScore;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> gameTable[i][0] >> gameTable[i][1] >> gameTable[i][2];

		int newRecord = (i + 1) % 2;
		int record = i % 2;

        // 새로 주어진 3개의 위치에 대하여 기록된 3개의 숫자 중 선택 할 수 있는 숫자중 가장 큰(작은) 숫자를 선택해 기록
		GetNewRecordMax(lastLineMax[record], gameTable[i], lastLineMax[newRecord]);
		GetNewRecordMin(lastLineMin[record], gameTable[i], lastLineMin[newRecord]);
	}

	int finalRecord = N % 2;

    // 마지막으로 기록된 숫자중 가장 큰 숫자와 작은 숫자를 찾아 출력
	maxScore = max(lastLineMax[finalRecord][0], lastLineMax[finalRecord][1], lastLineMax[finalRecord][2]);
	minScore = min(lastLineMin[finalRecord][0], lastLineMin[finalRecord][1], lastLineMin[finalRecord][2]);

	cout << maxScore << ' ' << minScore << endl;

	return 0;
}