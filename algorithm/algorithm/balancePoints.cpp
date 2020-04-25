#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define RATE 1e-24
vector<double> one_testcase_answer;
double cal_sqrt(double x) {
	return x * x;
}
double calculate(vector<pair<int, int>> points, double answer) {
	double result = 0.0;
	for (int i = 0; i < points.size(); i++) {
		if (answer > points.at(i).first) {
			result += points.at(i).second / cal_sqrt(answer - points.at(i).first);
			cout << points.at(i).first << answer << endl;
		}
		else {
			result += points.at(i).second / cal_sqrt(points.at(i).first - answer);
		}
	}
	return result;
}
void solution(vector<pair<int, int>> points, double start, double end) {
	double answer;

	answer = (start + end) / 2;

	if (answer - start < RATE || end - answer < RATE) {
		cout << "end" << endl;
		return;
	}

	cout << start << end << answer << endl;
	vector<pair<int, int>> left;
	vector<pair<int, int>> right;
	for (int i = 0; i < points.size(); i++) {
		if (points.at(i).first < answer)
			left.push_back(points.at(i));
		else
			right.push_back(points.at(i));
	}
	cout << "left" << endl;
	double left_result = calculate(left, answer);
	cout << "right" << endl;
	double right_result = calculate(right, answer);

	if (left_result > right_result) {
		if (left_result - right_result < RATE) {
			one_testcase_answer.push_back(answer);
			return;
		}
		solution(points, answer, end);
	}
	else if (left_result < right_result) {
		if (right_result - left_result < RATE) {
			one_testcase_answer.push_back(answer);
			return;
		}
		solution(points, start, answer);
	}
	else {
		one_testcase_answer.push_back(answer);
		return;
	}
}
int main() {
	int test_case;
	int T;
	cin >> T;

	int n = 0;
	//소수점 10자리
	cout << fixed;
	cout.precision(10);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		vector<pair<int, int>> points;
		for (int i = 0; i < n; i++) {
			int d = 0;
			cin >> d;
			points.push_back(std::make_pair(d, 0));
		}
		for (int i = 0; i < n; i++) {
			int m = 0;
			cin >> m;
			points.at(i).second = m;
		}

		for(int i=0;i<points.size()-1;i++)
			solution(points, points.at(i).first, points.at(i+1).first);
		cout << "#" << test_case;
		for (int i = 0; i < one_testcase_answer.size(); i++) {
			cout << " " << one_testcase_answer.at(i);
		}
		cout << endl;
		one_testcase_answer.clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}