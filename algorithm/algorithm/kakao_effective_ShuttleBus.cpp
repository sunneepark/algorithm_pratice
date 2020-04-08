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

	vector<string> timetable = { "08:00","09:09" ,"09:10" };
	vector<pair<int, int>> tt;

	for (auto elem : timetable) {
		tt.push_back(change_int(elem));
	}
	sort(tt.begin(), tt.end(), compare); //timetable 정리
	

	pair<int, int> time = make_pair(9,0);
	int crew_idx = 0;
	int crew_size = tt.size();
	int bus_idx = 0;
	int i = 0;
	for (i = 0; i < n; i++) {
		bus_idx = 0;
		while (bus_idx < m && crew_idx < crew_size) {
			if (compare(time, tt[crew_idx])) //늦게 도착하면 아웃
				break;
			else { //버스 태우기
				bus_idx++;
				crew_idx++;
			}
		}
		time = calculate_time(false, t, time.first, time.second); //다음 버스
	}

	time = calculate_time(false, t*(n - 1), 9, 0); //가장 막차
	
	if (i != n || bus_idx  < m || crew_idx == 0) {//막차에 자리가 있을 때 
		cout << change_str(time.first, time.second);
	}
	else { //막차에 자리가 없을 때
		pair<int, int> temp = tt[crew_idx-1];
		temp = calculate_time(true, 1, temp.first, temp.second);
		cout << change_str(temp.first, temp.second);
	}
	
	return 0;
}