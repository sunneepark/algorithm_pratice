#include <iostream>
#include <vector>
using namespace std;

bool assign(bool ago) {
	if (ago)
		return false;
	return true;
}
int main() {
	int m;
	cin >> m;

	int k;
	cin >> k;

	vector<int> possible;
	for (int i = 0; i < k; i++) {
		int stone;
		cin >> stone;
		possible.push_back(stone);
	}

	int success = 0;
	bool *stone_dp = new bool[m];

	int finish_idx = -1;

	for (int i = 0; i < m; i++) {
		stone_dp[i] = true;
		if (finish_idx+1 < k)
			if(i >= possible[finish_idx + 1])
				finish_idx++;

		int success_idx = 0;
		while(success_idx <= finish_idx) {
			int k = i - possible[success_idx++];
			stone_dp[i] = assign(stone_dp[k]);
			if (!stone_dp[i])
				break;
		}
		if (stone_dp[i])
			success++;
	}
	cout << success;
	return 0;
}