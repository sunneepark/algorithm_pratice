#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> ori, pair<int, int> comp) {
	if (ori.first == comp.first) {
		if (ori.second == comp.second)
			return false;
		return ori.second < comp.second;
	}
	else
		return ori.first < comp.first;
}
bool equal(pair<int, int> ori, pair<int, int> comp) {
	if (ori.first == comp.first) {
		if (ori.second == comp.second)
			return true;
	}
	return false;
}
pair<int, int> change_int(string time) {
	return make_pair(stoi(time.substr(0, 2)), stoi(time.substr(3, 2)));
}

pair<int, int> calculate_time(bool minus, int gap, int hour, int minute) {
	if (minus) {
		if (minute - gap < 0) {
			hour--;
			minute += 60;
		}
		minute -= gap;
	}
	else {
		minute += gap;
		while (minute >= 60) {
			hour++;
			minute -= 60;
		}
	}
	return make_pair(hour, minute);
}
string change_str(int hour, int minute) {
	string str = "";

	if (hour < 10)
		str += "0";
	str += to_string(hour);

	str += ":";
	if (minute < 10)
		str += "0";
	str += to_string(minute);
	return str;
}
int main() {
	int n = 2;
	int m = 2;
	int t = 10;

	vector<string> timetable = {"09:00","09:00","09:01" ,"09:01" };
	vector<pair<int,int>> tt;

	for (auto elem : timetable) {
		tt.push_back(change_int(elem));
	}
	sort(tt.begin(), tt.end(),compare);
	int **real_table = new int*[n];
	for (int i = 0; i < n; i++) {
		real_table[i] = new int[m];
		fill_n(real_table[i], m, 0);
	}

	pair<int, int> time = calculate_time(true,t,9,0);
	int crew_idx = 0;
	for (int i = 0; i < n; i++) {
		int nth_idx = 0;

		//시간 증가
		time = calculate_time(false, t, time.first, time.second);
		
		while (nth_idx < m) {
			if (crew_idx >= tt.size()) { //대기열에 더이상 사람이 없을때
				i = n;
				break;
			}
			else if (compare(time, tt[crew_idx])) { //시간이 더 클 때
				break;
			}
			else {
				real_table[i][nth_idx++] = ++crew_idx;
			}
		}	
	}

	time = calculate_time(false, t*(n - 1), 9, 0);
	//콘 확인
		int i = n - 1;
		int j = m - 1;
		pair<int, int> somebody;
		pair<int, int> temp;

				if (real_table[i][j] != 0) { //사람이 있으면
					somebody = tt[real_table[i][j] - 1];
					//1분 적게
					temp = calculate_time(true, 1, somebody.first, somebody.second);

				}
				else if (real_table[i][j] == 0) { //마지막에 사람이 없으면
					cout << change_str(time.first, time.second);
					return 0;
				}
	cout<< change_str(temp.first, temp.second);
	return 0;
}

