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

		for (int i = 0; i < N; i++) { //�Է¹ޱ�
			code[i] = new bool[4 * M];
			for (int j = 0; j < 4 * M; ) {
				cin >> tempScan;
				int hex = hexToBinary(tempScan);
				for (int k = 0; k < 4; k++) { //16���� 2������ ��ȯ
					code[i][j] = hexBase[hex][k];
					
					if (code[i][j] != 0 && !isChange) { //1�ε� �ٲ����� ������
						if (visited[j] != code[i][j]) { //������ �̹� ����� ������ �ƴϸ�
							isChange = !isChange;
							rateIdx = 1; //���ο� ����
							//cout << "why here " <<j <<":"<< visited[j] << ": " << code[i][j] << endl;
						}
					}
					if (isChange) { //�ٲٰ� �ִ���
						if (rateIdx % 2 != code[i][j])
							rateIdx++;

						if (rateIdx >= 4) { //�� ���� ��������
							cout << j << endl;
							temp = checkRate(rate);
							if (tempIdx++ % 2 == 0)
								sum += temp * 3;
							else
								sum += temp;
							tempSum += temp;
							fill_n(rate, 4, 0);
							rateIdx = 0;
							if (tempIdx == 8) { //8�ڸ� ���� ����
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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}