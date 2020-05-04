#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

bool oneLetter(string ori, string comp) {
	int check = 0;
	for (int i = 0; (i < ori.length()) && (check < 2); i++) {
		if (ori.at(i) != comp.at(i))
			check++;
	}
	if (check == 0 || check >= 2)
		return false;
	else
		return true;
}
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	vector<string>::iterator it = find(words.begin(), words.end(), target);
	if (it == words.end()) //words에 target이 없으면
		return 0;
	words.erase(it);
	queue<pair<string,int>> change;

	change.push(make_pair(begin,0));
	bool finish = false;
	while (!change.empty() && !finish) {
		string ori = change.front().first;
		int depth = change.front().second;
		if (oneLetter(ori, target)) {
			answer = depth+1;
			finish = true;
			break;
		}
		if (depth + 1 > words.size()) {
			finish = true;
			break;
		}
		for (int i = 0; i < words.size(); i++) {
			if (oneLetter(ori, words[i]))
				change.push(make_pair(words[i], depth + 1));
		}
		change.pop();
	}
	return answer;
}

int main() {
	string begin = "hot";
	string target = "lot";
	vector<string>	words ={ "hot", "dot", "dog","lot" ,"log"};

	cout << solution(begin, target, words);
	return 0;
}