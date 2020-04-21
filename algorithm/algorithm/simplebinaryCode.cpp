#include<iostream>

using namespace std;

int whichNum(int arr) {
	if ((arr ^ 0b0001101) == 0)
		return 0;
	else if ((arr ^ 0b0011001) == 0)
		return 1;
	else if ((arr ^ 0b0010011) == 0)
		return 2; 
	else if ((arr ^ 0b0111101) == 0)
		return 3;
	else if ((arr ^ 0b0100011) == 0)
		return 4;
	else if ((arr ^ 0b0110001) == 0)
		return 5;
	else if ((arr ^ 0b0101111) == 0)
		return 6;
	else if ((arr ^ 0b0111011) == 0)
		return 7;
	else if ((arr ^ 0b0110111) == 0)
		return 8;
	else if ((arr ^ 0b0001011) == 0)
		return 9;
	
}
int solution(char** code, int N, int M) {
	int i = N - 1; int j = M - 1;
	int temp = 1;
	for (; i >= 0 && temp; i--) {
		for (j = M - 1; j >= 0; j--) {
			if (code[i][j]=='1') {
				temp = 0;
				break;
			}
		}
	}

	int validCode[8] = { 0 };
	int idx = 0;
	int store = 0;
	for (int x = j-56+1; x <= j; x++, temp++) {
		store <<= 1;
		store += (int)(code[i][x]-'0');
		//cout << store << endl;
		if (temp == 6) {
			//cout << x << " "<< store << " " ;
			validCode[idx++] = whichNum(store);
			//cout << ":" << validCode[idx-1] << endl;
			store = 0;
			temp = -1;
		}
	}
	temp = 0;
	int sum = 0;
	for (idx=0; idx < 8;idx++) {
		if (idx % 2 == 0)
			temp += validCode[idx] * 3;
		else
			temp += validCode[idx];
		sum += validCode[idx];
	}
	if (temp % 10 == 0)
		return sum;
	return 0;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N = 0; int M = 0;
		cin >> N >> M;
	
		char **code = new char*[N];
		for (int i = 0; i < N; i++) {
			code[i] = new char[M];
			for (int j = 0; j < M; j++) {
				cin >> code[i][j];
			}
		}

		cout << "#" << test_case <<" "<< solution(code,N,M) << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}