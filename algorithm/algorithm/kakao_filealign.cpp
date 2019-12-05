#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int find_num(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) >= '0' && str.at(i) <= '9') {
			return i;
		}
	}
	return 0;
}
int cal_num(string str, int idx) {
	string num = "";
	for (int i=idx; i<str.length() && i < idx+5; i++) {
		if (str.at(i) >= '0' && str.at(i) <= '9') {
			num += str.at(i);
		}
		else
			break;
	}
	return atoi(num.c_str());
}
bool compare(string str1,string str2) { //HEAD 비교
	int num1 = find_num(str1);
	int num2 = find_num(str2);

	//int result = stricmp(str1.substr(0, num1).c_str(), str2.substr(0, num2).c_str());
	string trans_str1=str1.substr(0,num1);
	transform(trans_str1.begin(), trans_str1.end(), trans_str1.begin(), (int(*)(int))toupper);

	string trans_str2 = str2.substr(0, num2);
	transform(trans_str2.begin(), trans_str2.end(), trans_str2.begin(), (int(*)(int))toupper);

	int result = trans_str1.compare(trans_str2);

	if (result < 0) { //사전 높은 순
		return true;
	}
	else if (result == 0) { //HEAD가 같아 NUMBER 확인
		int num_str1 = cal_num(str1, num1);
		int num_str2 = cal_num(str2, num2);

		if(num_str1<num_str2)
			return true;
		else
			return false;
	}
	else 
		return false;
}
vector<string> solution(vector<string> files) {
	stable_sort(files.begin(), files.end(),compare);

	return files;
}

int main() {
	vector<string> files = { "F5 Freedom Fighter", "B01050 Superfortress", "A-10 Thunderbolt II", "F0-14 Tomcat" };
	files = solution(files);

	for (vector<string>::iterator iter = files.begin(); iter != files.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}