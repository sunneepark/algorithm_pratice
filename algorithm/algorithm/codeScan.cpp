#include<iostream>
#include <stack>
using namespace std;

int checkRate(int* rate) {
	if (rate[0] == 3 && rate[1] == 2 && rate[2] == 1 && rate[3] == 1)
		return 0;
	if (rate[0] == 2 && rate[1] == 2 && rate[2] == 2 && rate[3] == 1)
		return 1;
	if (rate[0] == 2 && rate[1] == 1 && rate[2] == 2 && rate[3] == 2)
		return 2;
	if (rate[0] == 1 && rate[1] == 4 && rate[2] == 1 && rate[3] == 1)
		return 3;
	if (rate[0] == 1 && rate[1] == 1 && rate[2] == 3 && rate[3] == 2)
		return 4;
	if (rate[0] == 1 && rate[1] == 2 && rate[2] == 3 && rate[3] == 1)
		return 5;
	if (rate[0] == 1 && rate[1] == 1 && rate[2] == 1 && rate[3] == 4)
		return 6;
	if (rate[0] == 1 && rate[1] == 3 && rate[2] == 1 && rate[3] == 2)
		return 7;
	if (rate[0] == 1 && rate[1] == 2 && rate[2] == 1 && rate[3] == 3)
		return 8;
	if (rate[0] == 3 && rate[1] == 1 && rate[2] == 1 && rate[3] == 2)
		return 9;
}
int hexChange(char base) {
	if (base >= '0' && base <= '9')
		return (int)(base - '0');
	else {
		switch (base) {
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
		}
	}
}

int solution(char* code, int start, int end) {
	int rate[8][4] = {0};
	int size = end - start + 1;
	int eachCodeRowSize = (int)(size * 4 / 56)*7;
	int rate_x = 7; int rate_y = 0; 
	stack<int> store_binary;

	bool isZero = true;
	for (int i = end; i >=0; i--) {
		int temp = hexChange(code[i]);

		for (int j = 0; j < 4 && rate_x >=0 ; j++) {
			if (i == end && temp % 2 ==0 && isZero) { //맨 처음 0 넣지 않기
				temp /= 2; continue;
			}
			if (i == end && isZero)
				isZero = false;
			store_binary.push(temp % 2);
			temp /= 2;

			if (store_binary.size() == eachCodeRowSize) {
				while (!store_binary.empty()) {
					if (store_binary.top() != (rate_y % 2))
						rate_y++;
					rate[rate_x][rate_y]++;
					store_binary.pop();
				}
				rate_x--; rate_y = 0;
			}
		}
	}
	int sum = 0;
	int digitSum = 0;
	for (int i = 0; i < 8; i++) {
		int temp = checkRate(rate[i]);
		if (i % 2 == 0)
			sum += temp * 3;
		else
			sum += temp;
		digitSum += temp;
	}
	if (sum % 10 == 0)
		return digitSum;
	else
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
		int answer = 0;
		int N = 0; int M = 0;
		cin >> N >> M;

		int temp = 0;
		bool isChange = false;

		char *visited = new char[M];
		*visited = { '0' };
		char **code = new char*[N];
		for (int i = 0; i < N; i++) {
			code[i] = new char[M];
			for (int j = 0; j < M; j++) {
				cin >> code[i][j];
				if (code[i][j] == '0' && isChange) { //다시 0으로 바뀌었으면
					answer += solution(code[i], temp,j-1);
					temp = 0;
					isChange = !isChange;
				}
				else if (code[i][j] != '0' && !isChange) { //바뀐적이 없으면
					if (visited[j] != code[i][j]) { //이전에 이미 계산한 구간이 아니면
						isChange = !isChange;
						temp = j;
						//cout << "why here " << visited[j] << ": " << code[i][j] << endl;
						visited[j] = code[i][j];
					}
				}
				else if(code[i][j]!='0' && isChange)
					visited[j] = code[i][j];
			}
		}
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}