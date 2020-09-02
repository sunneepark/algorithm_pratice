#include <iostream>
#include <string>
#include <vector>
#include <cstring>

#define DIR_SIZE 3 
using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	int prior = -1;

	bool** success = new bool*[m];
	for (int i = 0; i < m; i++) {
		success[i] = new bool[n];
		memset(success[i], false, sizeof(success[i]));
	}

	int dir_x[DIR_SIZE] = {1,0,1};
	int dir_y[DIR_SIZE] = { 0,1,1 };

	while (prior < answer) {
		prior = answer;

		for (string s : board)
			cout << s << endl;
		for (int i = 0; i < m-1; i++) {
			for (int j = 0; j < n-1; j++) {
				if (board[i][j] != 'a') { //빈칸이 아니라면 
					int k = 0;
					for (; k < DIR_SIZE; k++) {
						if (board[i][j] != board[i + dir_x[k]][j + dir_y[k]]) { //다르면 
							break;
						}
					}
					if (k >= DIR_SIZE) { //4칸 성공이면 처음 값과 옆에줄 값 push
						success[i][j] = true;
						for (k=0; k < DIR_SIZE; k++) {
							success[i + dir_x[k]][j + dir_y[k]] = true;
						}
					}
				}
				
			}
		}

		for (int i = 0; i < n; i++) {
			int first_y_idx = -1;
			bool change = false;
			for (int j = 0; j < m; j++) {
				if (success[j][i] == true) {
					answer++;
					if (!change) {
						change = true;
						first_y_idx = j;
					}
					board[j][i] = 'a';
				}
				if ((success[j][i] == false || j == m-1) && change) { //해당 칸 위에 성공한적이 있어서 밀어주어야 함.
					
					int k =1;
					int temp_y_idx = j - 1;
					if (j == m - 1 && success[j][i]) {
						temp_y_idx = j;
					}

					for ( ; temp_y_idx  >= 0; temp_y_idx--) {
						if (first_y_idx == 0 || first_y_idx - k < 0) {
							break;
						}

						cout << board[temp_y_idx][i] << " " <<"idx:" << first_y_idx-k <<" "<< board[first_y_idx - k][i] << endl;
						board[temp_y_idx][i] = board[first_y_idx - k][i];
						board[first_y_idx - k][i] = 'a';

						k++;

					}
					change = false;
				}

				success[j][i] = false;
			}
		}
	}
	return answer;
}

int main() {
	vector<string> board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
	cout << solution(8, 5, { "HGNHU", "CRSHV", "UKHVL", "MJHQB", "GSHOT", "MQMJJ", "AGJKK", "QULKK" });
	return 0;
}