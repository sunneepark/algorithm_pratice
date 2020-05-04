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
			if (i == end && temp % 2 ==0 && isZero) { //�� ó�� 0 ���� �ʱ�
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
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
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
				if (code[i][j] == '0' && isChange) { //�ٽ� 0���� �ٲ������
					answer += solution(code[i], temp,j-1);
					temp = 0;
					isChange = !isChange;
				}
				else if (code[i][j] != '0' && !isChange) { //�ٲ����� ������
					if (visited[j] != code[i][j]) { //������ �̹� ����� ������ �ƴϸ�
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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}