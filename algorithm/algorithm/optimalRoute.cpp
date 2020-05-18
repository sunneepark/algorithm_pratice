#include<iostream>
#include <vector>
#include <limits.h>
using namespace std;
int minResult;
vector<pair<int, int>> nPoint;

void solution(int idx, int nth, vector<bool> visited, int dist) {
	if (nth == visited.size()-1) {
		dist += abs(nPoint[0].first - nPoint[idx].first) + abs(nPoint[0].second - nPoint[idx].second);
		if (minResult > dist) minResult = dist;
		return;
	}
	if (dist > minResult) return;
	for (int i = 1; i < visited.size(); i++) {
		if (visited[i] == false) {
			visited[i] = true;
			solution(i,nth+1,visited, dist + abs(nPoint[i].first - nPoint[idx].first) + abs(nPoint[i].second - nPoint[idx].second));
			visited[i] = false;
		}
	}
	return;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n = 0;
		cin >> n;

		int startX = 0; int startY = 0;
		nPoint = vector<pair<int,int>>(n + 1);
		cin >> startX >> startY;

		minResult = INT_MAX;
		for (int i = 0; i < n + 1; i++)
			cin >> nPoint[i].first >> nPoint[i].second;
	
		for (int i = 1; i < n + 1; i++) {
			int dist = abs(nPoint[i].first - startX) + abs(nPoint[i].second - startY);
			vector<bool> visited(n + 1, false);
			visited[i] = true;
			solution(i, 1,visited, dist);
		}
		cout << "#" << test_case << " " << minResult << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}