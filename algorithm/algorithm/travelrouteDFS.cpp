#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool dfs(string from, bool* check, vector<vector<string>> tickets, vector<string> temp, vector<string>& answer) {

	for (int i = 0; i < tickets.size();i++) {
		if (tickets[i][0] == from && check[i] == false) {
			temp.push_back(from);
			check[i] = true;
			if (dfs(tickets[i][1], check, tickets, temp, answer)) {
				return true;
			}
			temp.pop_back(); //아니면 제외
			check[i] = false;
		}
	}
	for (int i = 0; i < tickets.size(); i++) {
		if (check[i] == false) {
			return false;
		}
	}
	temp.push_back(from);
	answer = temp;
	return true;
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	sort(tickets.begin(), tickets.end());
	vector<string> temp;
	bool* check = new bool[tickets.size()];
	fill_n(check, tickets.size(), false);
	dfs("ICN", check, tickets, temp, answer);
	return answer;
}
int main() {
	vector<vector<string>> tickets =
	{ {"ICN", "BOO"},{"ICN","COO"}, {"COO","DOO"}, {"DOO","COO"},{"BOO","DOO"},{"DOO","BOO"}, {"COO", "BOO" }, { "BOO", "ICN" }
	};
	tickets = { {"ICN", "SFO"},{"SFO", "ICN"},{"ICN", "SFO"},{"SFO", "QRE"} };
	tickets = { {"ICN", "COO"
}, { "ICN", "BOO"
}, { "COO", "ICN"
}, { "BOO", "DOO"
} };
	vector<string> ticket = solution(tickets);
	for (string elem : ticket)
		cout << elem << " ";
	return 0;
}
