#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int *visited;
class ptp {
public :
	int firstPoint;
	int secondPoint;
	long long distance;
public : ptp() {
	}
public : ptp(int f, int s, long long d) {
		firstPoint = f; secondPoint = s; distance = d;
	}
};
long long calL(int x1, int x2, int y1, int y2) {
	long long disX = (x1 - x2)*(x1 - x2);
	long long disY = (y1 - y2)*(y1 - y2);
	return disX + disY;
}
bool compare(ptp a, ptp b) {
	return a.distance < b.distance;
}
int find(int idx) {
	if (visited[idx] == idx)
		return idx;
	else
		return visited[idx] = find(visited[idx]);
}
bool SameParent(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x != y) return false;
	else return true;
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x != y) visited[y] = x;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		//input 받기
		int n = 0;
		cin >> n;
		//vector<pair<long long, long long>> 
		pair<long long, long long > *point = new pair<long long, long long>[n];
		for (int i = 0; i < n; i++) {
			cin >> point[i].first >> point[i].second;
		}
		long long e =0.0;
		cin >> e;
		cin.ignore();
		visited = new int[n];
		for (int i = 0; i < n; i++)
			visited[i] = i;

		vector<ptp> map;
		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {
				long long dis = e * calL(point[i].first, point[j].first, point[i].second, point[j].second);
				ptp temp(i, j, dis);
				map.push_back(temp);
			}
		}
		sort(map.begin(), map.end(), compare); //오름차순 정렬
		int sum = 0;
		for (int i = 0; i < map.size();i++) {
			int first = map.at(i).firstPoint;
			int second = map.at(i).secondPoint;
			if (!SameParent(first, second)) {
				Union(first, second);
				sum += map.at(i).distance;
			}
		}
		map.clear();
		cout << "#" << test_case << " " << sum << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}