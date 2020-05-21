#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<long long, long long> hotelRoom; //���ȣ, ���� �� ��ȣ
long long dfs(long long findIdx, long long k) {
	if (findIdx > k) return k;
	if (hotelRoom[findIdx] == NULL) return findIdx; //�� ����� ��
	else { //�� �� ����� ��
		return hotelRoom[findIdx] = dfs(hotelRoom[findIdx],k);
	}
}
vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	
	for (long long i : room_number) {
		long long temp = dfs(i,k);
		answer.push_back(temp);
		hotelRoom[temp] = temp + 1;
	}
	return answer;
}
int main() {
	vector<long long> s = { 1,3,1000000000,1,3,1 };
	vector<long long> answerList = solution(1000000000, s);
	for (long i : answerList)
		cout << i;
}