#include <iostream>
#include <queue>
using namespace std;

class point {
	private:
		int x;
		int y;

	public:
		point(int x, int y);
		int getX();
		int getY();
	
};
point::point(int x, int y) {
	this->x = x;
	this->y = y;
}
int point::getX() {
	return this->x;
}
int point::getY() {
	return this->y;
}

int change_dir(bool left, int idx) {
	if (left)
		return (++idx) % 4;
	else
		return ((--idx)<0) ? 3 : idx;
}
bool out(int x, int y, int n) {
	if (x >= n || y >= n || x < 0 || y < 0)
		return true;
	return false;
}
int main() {
	int n = 0;
	cin >> n;

	int **map;
	map = new int*[n];

	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
		fill_n(map[i], n, 0);
	}

	int k = 0;
	cin >> k;

	int x = 0; int y = 0;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		map[x-1][y-1] = 2; //사과는 2
	}

	int l = 0;
	cin >> l;
	int *move = new int[l];
	for (int i = 0; i < l; i++) {
		char c = 'C';
		cin >> move[i] >> c;
		if (c == 'L') //왼쪽
			move[i] -= 2*move[i];
	}
	
	int move_idx = 0; //왼쪽 일 때 +1 

	int change_move_idx = 0;
	int move_x[4] = { 0,-1,0,1 };
	int move_y[4] = { 1,0,-1,0 };

	queue<point> trace;
	trace.push(point(0, 0));

	int time = 0;
	x = 0; y = 0;
	map[0][0] = 1;
	while (true) {
		time++;
		x += move_x[move_idx]; y +=move_y[move_idx];

		if (out(x,y,n) || map[x][y] == 1) //지도에서 벗어나거나 이미 왔던 곳
			break;
		trace.push(point(x, y));

		if (map[x][y] != 2) { //사과가 아니라면
				point front = trace.front();
				map[front.getX()][front.getY()] = 0;
				trace.pop();
			
		}

		map[x][y] = 1;

		if (time == move[change_move_idx]) { //오른쪽 전환
			move_idx = change_dir(false, move_idx);
			change_move_idx++;
		}
		else if ((time + move[change_move_idx]) == 0) { //왼쪽 전환
			move_idx = change_dir(true, move_idx);
			change_move_idx++;
		}
	}
	cout << time << endl;
	return 0;
}