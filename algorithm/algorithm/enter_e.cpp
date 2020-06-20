#include <iostream>
#include <algorithm>
#include <math.h>

#define RATE 1e-12
using namespace std;
int main() {
	int n = 0;
	int k = 0;
	cin >> n >> k;
	double* lenCollection = new double[n];
	for (int i = 0; i < n; i++)
		cin >> lenCollection[i];
	sort(lenCollection, lenCollection + n);
	double left=0.0;
	double right=lenCollection[0];
	double answer=0.0;
	bool out = false;
	while(!out) {
		double temp = (left+right)/2.0;
		int compTemp = 0;
		for (int i = 0; i < n; i++)
			compTemp += (int)(lenCollection[i] / temp);

		if (compTemp > k) left = temp;
		else if (compTemp < k) right = temp;
		else {
			if (abs(answer - temp) < RATE) out = true;
			if (answer < temp) answer = temp;

			left = temp;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << round(answer*100)/100;
	return 0;
}