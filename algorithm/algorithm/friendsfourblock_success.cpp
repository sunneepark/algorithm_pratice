#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#define DIR_SIZE 3 
using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool isOut = false;
	vector<vector<bool>> success(m, vector<bool>(n));
	int dir_x[DIR_SIZE] = { 1,0,1 };
	int dir_y[DIR_SIZE] = { 0,1,1 };

	while (!isOut) {
		isOut = true;
		for (string s : board)
			cout << s << endl;

		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (board[i][j] != 'a') { //��ĭ�� �ƴ϶�� 
					int k = 0;
					for (; k < DIR_SIZE; k++) {
						if (board[i][j] != board[i + dir_x[k]][j + dir_y[k]]) { //�ٸ��� 
							break;
						}
					}
					if (k >= DIR_SIZE) { //4ĭ ���� �����̸�, 4ĭ�� block ó�� 
						isOut = false;
						success[i][j] = true;
						for (k = 0; k < DIR_SIZE; k++) {
							success[i + dir_x[k]][j + dir_y[k]] = true;
						}
					}
				}

			}
		}

		for (int i = 0; i < n; i++) {
			int first_y_idx = -1;

			//�� ���� 1.�� ��� 2.�� �Ʒ��� �б� 
			for (int j = 0; j < m; j++) {
				if (success[j][i] == true) {
					answer++;
					for (int k = j-1; k  >= 0; k--) {
						board[k+1][i] = board[k][i];
						board[k][i] = 'a';
					}
					success[j][i] = false;
				}
			}
		}
	}
	return answer;
}

int main() {
	cout << solution(2, 2, { "AA","AA" });
	return 0;
}