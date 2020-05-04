#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int find(int idx, int* parent) {
	if (parent[idx] == idx)
		return idx;
	else
		return find(parent[idx],parent);
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	int *parent = new int[n];
	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (computers[i][j] == 1)
				parent[find(j,parent)] = find(i,parent);
		}
	}
	for (int i = 0; i < n; i++) {
		if (parent[i] == i)
			answer++;
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