#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<pair<bool, bool>>> answer;
int n;
bool isRight(int x, int y, bool status) {
	if (!status) { //보이면
		if (answer[x][y - 1].first || (x + 1 < n && answer[x + 1][y - 1].first)) return true; //한쪽 끝이 기둥
		if (x - 1 >= 0 && x + 1 < n && answer[x - 1][y].second && answer[x + 1][y].second) return true; //양쪽 끝이 보 위
		//if (x-1 >=0 && x+1 < n && answer[x-1][y].second && answer[x + 1][y].second) return true; //양쪽 끝이 보

	}
	else { //기둥이면
		if (y == 0) return true; //바닥이면 됨.
		if ((x - 1 >= 0 && answer[x - 1][y].second) || answer[x][y].second) return true; //보의 한쪽 끝 부분 위
		//if ((y+1<n)&& ((x - 1 >= 0 && answer[x - 1][y+1].second) || answer[x][y+1].second)) return true; //보의 한쪽 끝 부분 위
		if (answer[x][y - 1].first) return true; //다른 기둥 위
	}
	return false;
}
bool isEntireRight() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (answer[i][j].first) {
				if (!isRight(i, j, true)) return false; //기둥이면
			}
			if (answer[i][j].second) {
				if (!isRight(i, j, false)) return false; //보이면
			}
		}
	}
	return true;
}
vector<vector<int>> solution(int size, vector<vector<int>> build_frame) {
	n = size + 1;
	answer = vector<vector<pair<bool, bool>>>(n, vector<pair<bool, bool>>(n, make_pair(false, false))); //기둥, 보
	for (int i = 0; i < build_frame.size(); i++) {
		int x = build_frame[i][0]; int y = build_frame[i][1];
		pair<bool, bool> prior = answer[x][y];

		if (!build_frame[i][3]) { //삭제
			if (build_frame[i][2]) //보
				answer[x][y].second = false;
			else
				answer[x][y].first = false;
			if (!isEntireRight()) answer[x][y] = prior;
		}
		else { //설치
			if (build_frame[i][2]) //보
				answer[x][y].second = true;
			else
				answer[x][y].first = true;
			if (!isRight(x, y, !build_frame[i][2])) answer[x][y] = prior;
		}
	}

	vector <vector<int>> result;
	for (int i = 0; i < n; i++) { //x 오름차순
		for (int j = 0; j < n; j++) {
			if (answer[i][j].first) {
				vector<int> temp;
				temp.push_back(i);
				temp.push_back(j);
				temp.push_back(0);
				result.push_back(temp);
			}
			if (answer[i][j].second) {
				vector<int> temp;
				temp.push_back(i);
				temp.push_back(j);
				temp.push_back(1);
				result.push_back(temp);
			}
		}
	}
	return result;
}
int main() {
	vector<vector<int>> result = solution(5, { {1, 0, 0, 1},{1, 1, 1, 1},{2, 1, 0, 1},{2, 2, 1, 1},{5, 0, 0, 1},{5, 1, 0, 1},{4, 2, 1, 1} ,{3, 2, 1, 1},{2,1,0,0} });

	for(int i=0;i<result.size();i++)
		for (auto i : result[i])
			cout << i;
}