// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int length;
int datas[1000];
int DPplus[1000];
int DPminus[1000];
int answer = 0;
int main()
{
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cin >> datas[i];
		for (int j = 0; j < i; j++)
		{
			if (datas[i] > datas[j])
			{
				DPplus[i] = max(DPplus[i], DPplus[j] + 1);
			}
		}
	}
	for (int i = length - 1; i >= 0; i--)
	{
		for (int j = length - 1; j >= i; j--)
		{
			if (datas[i] > datas[j])
			{
				DPminus[i] = max(DPminus[i], DPminus[j] + 1);
			}
		}
	}
	for (int i = 0; i < length; i++)
	{
		answer = max(DPplus[i] + DPminus[i], answer);
	}
	cout << answer + 1;

}

