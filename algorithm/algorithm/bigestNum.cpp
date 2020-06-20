#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
/**
	@author sunny park
	���ڸ� string ���� �ٲپ� �� ���� ���غ� ��,
	���� �� ���� ��� �� ū ���� �������� �Ͽ� '���� ū ��' ����

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

	if (numToString.at(0)== "0") return "0"; //�� ���� 0�� �Ǵ� ����� ���ڴ� 0 �ۿ� ����.
	for (string temp : numToString)
		answer += temp;
	return answer;
}
int main() {
	cout << solution({ 3, 30, 34, 5, 9 });
}