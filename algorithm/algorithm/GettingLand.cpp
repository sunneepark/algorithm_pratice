#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n = 0;
	cin >> n;
	

	int **map;
	int *map_size;

	map = new int*[n];
	map_size = new int[n];
	for (int i = 0; i < n; i++) {
		int k = 0;
		cin >> k;

		map_size[i] = k;
		k *= k;
		map[i] = new int[k];

		int idx = 0;
		while (idx < k) {
			cin >> map[i][idx++];
		}

	}

	for (int i = 0; i < n; i++) {

		stack<int> correct;
		int size = map_size[i];

		correct.push(0);
		while (!correct.empty()) {
			int idx = correct.top();

			int map_content = map[i][idx];
			if (map_content == 0)
				break;
			if (map_content == 10) {
				correct.pop();
			}
			else {
				correct.pop();

				//오른쪽
				int temp_idx = idx + map_content;
				if (((temp_idx / size) == (idx / size)) && temp_idx < size*size) {
					correct.push(temp_idx);
				}
				//아래
				temp_idx = idx + map_content * size;
				if (temp_idx < size*size) {
					correct.push(temp_idx);
				}
			}
			map[i][idx] = 10; //온 적 있음을 표시

		}
		cout << (correct.empty() ? "NO" : "YES") << endl;
	}
	return 0;
}