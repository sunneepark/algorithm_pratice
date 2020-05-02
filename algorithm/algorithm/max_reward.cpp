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
		if (remain % 2 == 0) { //짝수이면 ok
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
	//max랑 비교
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
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("C:\\Users\\USER\\Downloads\\input(7).txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
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
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}