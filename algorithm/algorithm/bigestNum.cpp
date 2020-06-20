#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
/**
	@author sunny park
	숫자를 string 으로 바꾸어 두 개씩 합해본 후,
	합한 두 가지 경우 중 큰 것을 앞쪽으로 하여 '가장 큰 수' 구현

	ex) 
	'6' VS '346'
	('6346' VS '3466') -> (6346 > 3466) -> 6, 346
*/
using namespace std;
bool compare(string& a, string&b) {
	string tempAB = a+b; string tempBA = b+a;
	return stoi(tempAB) > stoi(tempBA);
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> numToString;
	for (int temp : numbers)
		numToString.push_back(to_string(temp));
	sort(numToString.begin(), numToString.end(), compare);

	if (numToString.at(0)== "0") return "0"; //맨 앞이 0이 되는 경우의 숫자는 0 밖에 없음.
	for (string temp : numToString)
		answer += temp;
	return answer;
}
int main() {
	cout << solution({ 3, 30, 34, 5, 9 });
}