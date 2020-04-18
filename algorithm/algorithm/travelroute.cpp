#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool dfs(string from, unordered_map < string, vector<string>> tickets, vector<string> temp, vector<string>& answer) {

	temp.push_back(from);
	if (tickets.count(from) == 0) { //ticket 이 더이상 없으면
		if (tickets.size() == 0) {
			answer = temp;
			return true;
		}
		else 
			return false;
	}

	string findCountry;
	vector<string> values = tickets.find(from)->second;
	vector<string>::iterator it;
	
	int i = 0;
	for (i = 0;i<values.size();i++) {
		it = values.begin();
		findCountry = *it;
		values.erase(it);

		if (values.size() >= 1)
			tickets[from] = values;
		else
			tickets.erase(from);
		values.push_back(findCountry);
		if (dfs(findCountry, tickets, temp, answer))
			return true;
	}
	return false;
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	unordered_map<string, vector<string>> countryIdx;

	for (vector<string> elem : tickets) {
		string depart = elem[0];
		string destination = elem[1];

		vector<string> value;
		if (countryIdx.count(depart) == 0) {
			value.push_back(destination);
		}
		else {
			value = countryIdx.find(depart)->second;
			value.push_back(destination);

			sort(value.begin(), value.end());
			
		}
		countryIdx[depart]=value;
	}
	string findCountry = "ICN";
	vector<string> temp;
	dfs(findCountry, countryIdx, temp, answer);
	
	return answer;
}

int main() {
	vector<vector<string>> tickets =
	{ {"ICN", "BOO"},{"ICN","COO"}, {"COO","DOO"}, {"DOO","COO"},{"BOO","DOO"},{"DOO","BOO"}, {"COO", "BOO" }, { "BOO", "ICN" }
	};
	tickets = { {"ICN", "SFO"},{"SFO", "ICN"},{"ICN", "SFO"},{"SFO", "QRE"} };
	tickets = {{"ICN", "COO"
}, { "ICN", "BOO"
}, { "COO", "ICN"
}, { "BOO", "DOO"
}};
	vector<string> ticket = solution(tickets);
	for (string elem : ticket)
		cout << elem << " ";
	return 0;
}