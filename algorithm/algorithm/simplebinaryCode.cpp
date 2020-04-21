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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}