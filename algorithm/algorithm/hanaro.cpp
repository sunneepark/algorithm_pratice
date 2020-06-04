#include<iostream>
#include <vector>
#include<algorithm>
#include <math.h>
using namespace std;

int *visited;
class ptp {
public:
	long long firstPoint;
	long long secondPoint;
	long long distance;
public: ptp() {
}
public: ptp(long long f, long long s, long long d) {
	firstPoint = f; secondPoint = s; distance = d;
}
};
long long calL(long long x1, long long x2, long long y1, long long y2) {
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
		vector<pair<long long, long long>> point(n);
		for (int i = 0; i < n; i++) {
			cin >> point[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> point[i].second;
		}
		double e = 0.0;
		cin >> e;

		/*long long e = 0;
		cin >> e;
		cin.ignore(256,'\n');*/ //long long 입력 받기
	
		visited = new int[n];
		for (int i = 0; i < n; i++)
			visited[i] = i;

		vector<ptp> map;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				long long dis = calL(point[i].first, point[j].first, point[i].second, point[j].second);
				ptp temp(i, j, dis);
				map.push_back(temp);
			}
		}
		sort(map.begin(), map.end(), compare); //오름차순 정렬
		long long sum = 0;
		for (int i = 0; i < map.size(); i++) {
			long long first = map.at(i).firstPoint;
			long long second = map.at(i).secondPoint;
			if (!SameParent(first, second)) {
				Union(first, second);
				sum += map.at(i).distance;
			}
		}
		map.clear();
		cout << "#" << test_case << " " << (long long)round((double)(e*sum)) << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}