// ��������.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include<string.h>
using namespace std;
int T, V, E, N1, N2, p, c;
int Parent[10001];
int Gene[10001];
int Subtree[10001];

int findGen(int i, int ret) { //depth

	int par = 1;
	do {
		par = Parent[i];
		ret++;
		i = par;
	} while (par != 0);
	return ret;
}

void solve(int N1, int N2) {

	int p1, p2;
	p1 = Parent[N1];
	p2 = Parent[N2];

	do {

		if (Gene[p1] > Gene[p2]) {
			p1 = Parent[p1];
		}
		else if (Gene[p1] < Gene[p2]) {
			p2 = Parent[p2];
		}
		else {
			p1 = Parent[p1];
			p2 = Parent[p2];
		}
	} while (p1 != p2);

	cout << p1 << " " << Subtree[p1] << endl;

	return;
}

int max(int V) {
	int ret = 0;
	for (int i = 1; i < V + 1; ++i) {
		if (ret < Gene[i]) ret = Gene[i];
	}
	return ret;
}

int main()
{
	cin >> T;

	for (int t = 0; t < T; ++t) {

		memset(Parent, 0, sizeof(Parent));
		memset(Gene, 0, sizeof(Gene));

		cin >> V >> E >> N1 >> N2;

		for (int i = 1; i < E + 1; ++i) {
			cin >> p >> c;
			Parent[c] = p;
		}

		for (int i = 1; i < V + 1; ++i) {
			Gene[i] = findGen(i, 0);
		}

		int lastGen = max(V);
		for (int i = 1; i < V + 1; ++i)
			Subtree[i] = 1;
		for (int i = lastGen; i > 0; --i) {
			for (int j = 1; j < V + 1; ++j) {
				if (i == Gene[j]) { //�ش� ���̸�
					Subtree[Parent[j]] += Subtree[j];
				}
			}
		}

		cout << "#" << t + 1 << " ";
		solve(N1, N2);

	}

}