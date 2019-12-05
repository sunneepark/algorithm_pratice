#include <iostream>
#include <string>
#include <vector>

using namespace std;

int take_time(string start, string end) { //take time to minutes
	int minute = 0;
	int hour = stoi(end) - stoi(start);

	if (hour == 0)  //동일한 시간대이면,
		minute = stoi(end.substr(3)) - stoi(start.substr(3));
	else
		minute = (60 - stoi(start.substr(3))) + stoi(end.substr(3));

	return minute + 60 * hour;
}
bool is_that_song(int time, string code, string memory_code) { // check the correct song
	string whole_code = "";
	int idx = 0;
	while (time-- > 0) {
		idx = idx % code.length();
			
		if (idx+1 < code.length() && code.at(idx+1) == '#')
			whole_code += code.at(idx++) - ('A' - 'a');
		else
			whole_code += code.at(idx);

		idx++;
	}
	for (int i = 0; i < memory_code.length(); i++) {
		if (memory_code.at(i) == '#') {
			memory_code.at(i - 1) = memory_code.at(i - 1)-('A' - 'a');
			memory_code.replace(i--, 1,"");
		}
	}
	if (memory_code.find("e") != string::npos ||
		whole_code.find("e") != string::npos)
		return false;
	int check_sharp = 0;
	while ((check_sharp = whole_code.find(memory_code))>=0) {
		check_sharp += memory_code.length()-1;

		if (check_sharp + 1 < whole_code.length() && whole_code.at(check_sharp + 1) == '#') {
			whole_code = whole_code.substr(check_sharp+2);
		}

		else
			return true;
	}
	
	return false;
}
string solution(string m, vector<string> musicinfos) {
	string answer = "";
	int max_answer = -1;

	vector<string>::iterator it;
	for (it = musicinfos.begin(); it != musicinfos.end(); it++) {
		string str = *it;
		
		string *arr = new string[4];
		int idx = 0;
		int cut_At = -1;
		while ((cut_At = str.find_first_of(",")) < str.length()) {
			if (cut_At > 0) {
				arr[idx++] = str.substr(0, cut_At);
				str = str.substr(cut_At+1);
			}
		}
		arr[idx] = str;

		int time = take_time(arr[0], arr[1]);
		
		if (is_that_song(time, arr[3],m)) {
			if (answer == "" || max_answer < time) {
				answer = arr[2];
				max_answer = time;
			}
		}
	}
	
	if (answer == "") //답이 없는 경우
		answer = "(None)";

	return answer;
}

int main() {
	vector<string> musicinfos = { "12:00,12:12,HELLO,AC#DE#FGAB", "13:00,13:05,WORLD,ABCDEF" };
	cout << solution("AC#", musicinfos);
	return 0;
}