#include<iostream>
#include<string>
using namespace std;

int result;
string ori_max;
void make_orimax(string num_board) {
	int num_structor[10] = { 0 };
	for (int i = 0; i < num_board.size(); i++) {
		num_structor[(int)(num_board.at(i) - '0')]++;
	}
	ori_max = "";
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < num_structor[i]; j++)
			ori_max += (char)(i+'0');
	}	
}
void solution(string num_board, int change, int cur) {
	
	if (cur == change) {
		cout << result << " o" << endl;
		if (result < atoi(num_board.c_str()))
			result = atoi(num_board.c_str());
		return;
	}
	if (num_board == ori_max) {
		int remain = change - cur;
		if (remain % 2 == 0) { //¦���̸� ok
			result = atoi(num_board.c_str());
			return;
		}
		else {
			string temp_board = num_board;
			temp_board.at(temp_board.size() - 1) = ori_max.at(ori_max.size() - 2);
			temp_board.at(temp_board.size() - 2) = ori_max.at(ori_max.size() - 1);

			result = atoi(temp_board.c_str());
		}
		
	}
	//max�� ��
	bool out = true;
	int start = cur;
	while (out && start < num_board.size()-1) {
		for (int j = start + 1; j < num_board.size(); j++) {
			if (ori_max.at(start) <= num_board.at(j)) {
				string change_board = num_board;
				change_board.at(start) = num_board.at(j);
				change_board.at(j) = num_board.at(start);

				out = false;
				solution(change_board, change, cur + 1);
			}
		}
		start++;
	}
	
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
	//freopen("C:\\Users\\USER\\Downloads\\input(7).txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string num_board = "";
		cin >> num_board;

		int change = 0;
		cin >> change;
		result = atoi(num_board.c_str());

		make_orimax(num_board);
		solution(num_board, change, 0);
		cout << "#" << test_case << " " << result << endl;

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}