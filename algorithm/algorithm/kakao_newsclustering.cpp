#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> makeSet(string str) {
	vector<string> multipleSet;

	for (int i = 0; i < str.size() - 1; i++) {
		char first = str[i];
		if (first >= 'A'&&first <= 'Z') str[i] = tolower(first); first = tolower(first);
		if (!(first >= 'a'&&first <= 'z')) continue;
		
		char second = str[i+1];
		if (second >= 'A'&&second <= 'Z') str[i+1] = tolower(second); second = tolower(second);
		if (!(second >= 'a'&&second <= 'z')) continue;
		multipleSet.push_back(str.substr(i,2));
	}

	sort(multipleSet.begin(), multipleSet.end());
	return multipleSet;
}
int solution(string str1, string str2) {
	int answer = 0;
	vector<string> str1Set = makeSet(str1);
	for (auto i : str1Set)
		cout << i << endl;
	vector<string> str2Set = makeSet(str2);
	cout << endl;
	for (auto i : str2Set)
		cout << i << endl;
	vector<string> intersectionSet;

	if (str1Set.size() == 0 && str2Set.size() == 0)
		return 65536;

	set_intersection(str1Set.begin(), str1Set.end(), str2Set.begin(), str2Set.end(), back_inserter(intersectionSet));
	cout << endl;
	for (auto i : intersectionSet)
		cout << i << endl;
	
	double unionAnswer = str1Set.size() + str2Set.size() - intersectionSet.size();
	double oriJacard = (double)intersectionSet.size() / unionAnswer;
	cout << unionAnswer << intersectionSet.size();
	answer = oriJacard * 65536;
	return answer;
}
int main() {
	cout << solution("aa1+aa2", "AAAA12");
}


//#include <bits/stdc++.h>
//using namespace std;
//short a, b, C[676], D[676];
//int solution(string A, string B) {
//	for (int i = 1; i < A.size(); i++)
//		if (isalpha(A[i - 1]) && isalpha(A[i]))
//			C[(A[i - 1] & 31) * 26 + (A[i] & 31)]++;
//	for (int i = 1; i < B.size(); i++)
//		if (isalpha(B[i - 1]) && isalpha(B[i]))
//			D[(B[i - 1] & 31) * 26 + (B[i] & 31)]++;
//	for (int i = 0; i < 676; i++) a += min(C[i], D[i]), b += max(C[i], D[i]);
//	return b ? a * 65536 / b : 65536;
//}