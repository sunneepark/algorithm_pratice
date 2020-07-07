#include <string>
#include <vector>
#include <set>
#include <iostream>
/**
	@author sunny park
	@date 20/07/07
*/
using namespace std;

string input = "";
set<string> combInputs; //중복제거

bool isPrime(int num) {
	if (num == 0 || num == 1) return false;
	for (int i = 2; i < num; i++){
		if(num % i == 0) return false;
	}
	return true;
}
bool dfs(string cur, int curIdx, vector<bool> visited) {
	cur += to_string(input[curIdx]-'0');
	combInputs.insert(cur);
	visited[curIdx] = true;

	if (cur.size() == input.size()) return true;
	for (int i = 0; i < input.size(); i++) {
		if (!visited[i]) dfs(cur, i, visited);
	}
	return true;
}

int solution(string numbers) {
	input = numbers;
	int answer = 0;

	bool isExistNum[10] = { false };
	for (int i = 0; i < input.size(); i++) {
		vector<bool> visited(input.size());
		int num = input.at(i) - '0';
		if (num != 0 && !isExistNum[num]) dfs("",i, visited);
		isExistNum[num] = true;
	}
	for (string temp : combInputs)
		if (isPrime(stoi(temp))) answer++;
	return answer;
}
int main() {
	cout << solution("011") << endl;
}
