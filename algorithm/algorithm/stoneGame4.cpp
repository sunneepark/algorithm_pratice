#include <iostream>

using namespace std;

bool check(int n, int k) {
	if (k < n  && k>=0)
		return true;
	return false;
}
bool assign(bool ago) {
	if (ago)
		return false;
	return true;
}
int main() {
	int m;
	cin >> m;

	bool *arr = new bool[m]; //상근 true, 창영 false
	int i = 0;
	arr[i++] = true;
	
	for (; i < m; i++) {
		arr[i] = true;
		int k = i - 1;
		if (check(m, k)) {
			arr[i] = assign(arr[k]);
		}
		if (!arr[i])
			continue;
		k = i - 3;

		if (check(m, k)) {
			arr[i] = assign(arr[k]);
		}
		if (!arr[i])
			continue;
		k = i - 4;
		if (check(m, k)) {
			arr[i] = assign(arr[k]);
		}
		if (!arr[i])
			continue;
	}
	if (arr[m-1])
		cout << "CY";
	else
		cout << "SK";
	return 0;
}