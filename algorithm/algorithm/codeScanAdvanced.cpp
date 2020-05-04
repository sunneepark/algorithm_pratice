#include<iostream>
#include <stack>
using namespace std;


int hexBase[16][4] = {
	{0,0,0,0},
	{0,0,0,1},
	{0,0,1,0},
	{0,0,1,1},
	{0,1,0,0},
	{0,1,0,1},
	{0,1,1,0},
	{0,1,1,1},
	{1,0,0,0},
	{1,0,0,1},
	{1,0,1,0},
	{1,0,1,1},
	{1,1,0,0},
	{1,1,0,1},
	{1,1,1,0},
	{1,1,1,1}
};
int checkRate(int* rate) {
	int one = rate[1]; int two = rate[2]; int three = rate[3];
	cout <<endl << rate[1] << rate[2] << rate[3] << endl;
	int division = 1;
	while (true) {
		rate[1] = one / division; rate[2] = two / division; rate[3] = three / division;
		cout << division << ": " << rate[1] << rate[2] << rate[3] << endl;
		if (rate[1] == 2 && rate[2] == 1 && rate[3] == 1)
			return 0;
		if (rate[1] == 2 && rate[2] == 2 && rate[3] == 1)
			return 1;
		if (rate[1] == 1 && rate[2] == 2 && rate[3] == 2)
			return 2;
		if (rate[1] == 4 && rate[2] == 1 && rate[3] == 1)
			return 3;
		if (rate[1] == 1 && rate[2] == 3 && rate[3] == 2)
			return 4;
		if (rate[1] == 2 && rate[2] == 3 && rate[3] == 1)
			return 5;
		if (rate[1] == 1 && rate[2] == 1 && rate[3] == 4)
			return 6;
		if (rate[1] == 3 && rate[2] == 1 && rate[3] == 2)
			return 7;
		if (rate[1] == 2 && rate[2] == 1 && rate[3] == 3)
			return 8;
		if (rate[1] == 1 && rate[2] == 1 && rate[3] == 2)
			return 9;
		division++;
	}
}
int hexToBinary(char hex) {
	int tenth = 0;
	if (hex >= '0' && hex <= '9')
		tenth = hex - '0';
	else
		tenth = hex - 'A' + 10;

	return tenth;
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
		int answer = 0;
		int N = 0; int M = 0;
		cin >> N >> M;

		
		char tempScan = '0'; 
		bool **code = new bool*[N];

		bool isChange = false;
		bool *visited = new bool[4*M];
		*visited = { 0 };

		int rate[4] = { 0 };
		int rateIdx = 1;

		int tempIdx = 0;
		int temp = 0;
		int sum = 0; int tempSum = 0;

		for (int i = 0; i < N; i++) { //입력받기
			code[i] = new bool[4 * M];
			for (int j = 0; j < 4 * M; ) {
				cin >> tempScan;
				int hex = hexToBinary(tempScan);
				for (int k = 0; k < 4; k++) { //16진수 2진수로 변환
					code[i][j] = hexBase[hex][k];
					
					if (code[i][j] != 0 && !isChange) { //1인데 바뀐적이 없으면
						if (visited[j] != code[i][j]) { //이전에 이미 계산한 구간이 아니면
							isChange = !isChange;
							rateIdx = 1; //새로운 숫자
							//cout << "why here " <<j <<":"<< visited[j] << ": " << code[i][j] << endl;
						}
					}
					if (isChange) { //바꾸고 있는중
						if (rateIdx % 2 != code[i][j])
							rateIdx++;

						if (rateIdx >= 4) { //한 숫자 끝났으면
							cout << j << endl;
							temp = checkRate(rate);
							if (tempIdx++ % 2 == 0)
								sum += temp * 3;
							else
								sum += temp;
							tempSum += temp;
							fill_n(rate, 4, 0);
							rateIdx = 0;
							if (tempIdx == 8) { //8자리 전부 종료
								if (sum % 10 == 0)
									answer += tempSum;
								tempIdx = 0; tempSum = 0; sum = 0;
								isChange = !isChange;
							}
						}
						rate[rateIdx]++;
					}
					visited[j] = code[i][j];
					j++;
				}
			}
		}
	
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}