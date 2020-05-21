#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> rotateKey(vector<vector<int>> key) {
	int m = key.size();
	vector<vector<int>> result(m);
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < m; j++) 
			result[i].push_back(key[m-j-1][i]);
	return result;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	int m = lock.size(); int n = key.size(); int moveKeyIdx = n+m;
	for (int r = 0; r < 4 && !answer; r++) { // answer가 true 면 out
		for (int i = 0; i < moveKeyIdx && !answer; i++) {
			for (int j = 0; j < moveKeyIdx && !answer; j++) {
				int bigBoard[100][100] = { 0, };
				//1. key 복사
				for (int keyX = 0; keyX < n ; keyX++) {
					for (int keyY = 0; keyY < n; keyY++) {
						bigBoard[keyX + i][keyY + j] = key[keyX][keyY];
					}
				}
				//2. lock xor 하면서 점검
				bool check = true;
				for (int lockX = 0; lockX < m && check; lockX++) {
					for (int lockY = 0; lockY < m; lockY++) {
						if ((bigBoard[lockX + n - 1][lockY + n - 1] ^ lock[lockX][lockY]) == 0) {
							check = false;
							break;
						}
					}
				}
				if (check) answer = true;
			}
		}
		key = rotateKey(key);
	}
	return answer;
}
int main() {
	cout << solution({ {0, 0, 0},{1, 0, 0},{0, 1, 1} }, { {1, 1, 1},{1, 1, 0},{1, 0, 1} });
}