#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
bool *visited;

void dfs(vector<vector<int>> computer, int i, int j, int n) {
	if (i> n-1 || j > n-1)
		return;
	else if(i==j  ||  visited[j] || computer[i][j]==0)
		dfs(computer, i, j+1, n);
	else if (computer[i][j] == 1) {
		visited[i] = true;
		visited[j] = true;
		dfs(computer, j, 1, n);
		dfs(computer,i, j+1, n);
	}
	return;
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	visited = new bool[n];
	fill_n(visited, n, false);

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(computers, i, i+1, n);
			answer++;
		}		
	}
	return answer;
}

int main() {
	int n = 3;
	vector<vector<int>> computers = { 
		vector<int>{1, 1, 0},
		vector<int>{1, 1, 1},
		vector<int>{0, 1, 1} };
	cout << solution(n, computers);
	return 0;
}