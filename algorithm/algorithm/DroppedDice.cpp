#include <iostream>
using namespace std;

//Compiler version g++ 6.3.0
int dice[6] = {
  0
};

int move_dice(int move) {
		int top = dice[0];
		if (move == 1) { //µ¿
			dice[0] = dice[5];
			dice[5] = dice[3];
			dice[3] = dice[2];
			dice[2] = top;
		}
		else if (move == 2) { //¼­
			dice[0] = dice[2];
			dice[2] = dice[3];
			dice[3] = dice[5];
			dice[5] = top;
			return dice[0];
		}
		else if (move == 4) { //³²
			dice[0] = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[4];
			dice[4] = top;
		}
		else if (move == 3) { //ºÏ
			dice[0] = dice[4];
			dice[4] = dice[3];
			dice[3] = dice[1];
			dice[1] = top;
		}
		return dice[0];
}
int main()
{
	int n = 0; int m = 0; int x = 0; int y = 0; int k = 0;
	cin >> n >> m >> x >> y >> k;

	int **map = new int*[n];


	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int *move = new int[k]; // direction of moving

	int move_N[4] = {
	  0,0,-1,1
	};
	int move_M[4] = {
	  1,-1,0,0
	};

	for (int i = 0; i < k; i++)
		cin >> move[i];

	for (int inx = 0; inx < k; inx++) {
		int i = move[inx];
		if (x + move_N[i - 1] < 0 || x + move_N[i - 1] >= n)
			continue;

		if (y + move_M[i - 1] < 0 || y + move_M[i - 1] >= m)
			continue;

		//move map
		x += move_N[i - 1];
		y += move_M[i - 1];

		//move dice
		cout << move_dice(i) << endl;

		//change
		if (map[x][y] == 0) {
			map[x][y] = dice[3];
		}
		else {
			dice[3] = map[x][y];
			map[x][y] = 0;
		}

	}
}

