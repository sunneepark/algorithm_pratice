#include <string>
#include <vector>
#include <iostream>
/**
	@author sunny park
	@date 20/07/07
*/
using namespace std;

string input = "";
int answer = 0;

bool isPrime(int num) {
	if (num == 0 || num == 1) return false;
	for (int i = 2; i < num; i++){
		if(num % i == 0) return false;
	}
	return true;
}
bool dfs(string cur, int curIdx, vector<bool> visited) {
	cur += to_string(input[curIdx]-'0');

	if (isPrime(stoi(cur))) answer++;
	visited[curIdx] = true;

	if (cur.size() == input.size()) return true;
	for (int i = 0; i < input.size(); i++) {
		if (!visited[i]) dfs(cur, i, visited);
	}
	return true;
}

int solution(string numbers) {
	input = numbers;
	bool isExistNum[10] = { false };
	for (int i = 0; i < input.size(); i++) {
		vector<bool> visited(input.size());
		int num = input.at(i) - '0';
		if (num != 0 && !isExistNum[num]) dfs("",i, visited);
		isExistNum[num] = true;
	}
	return answer;
}
int main() {
	cout << solution("011") << endl;
}
