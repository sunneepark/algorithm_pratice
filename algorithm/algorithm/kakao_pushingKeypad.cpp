#include <string>
#include <iostream>
#include <vector>
/**
	@author sunny park
	@date 20/07/03
*/
using namespace std;
pair<int, int> calCoor(int n) {
	pair<int, int> result;
	n = (n == 0) ? 11 : n;

	if (n%3 != 0) { result.first = n / 3; result.second = n % 3 -1; }
	else { result.first = n / 3 - 1; result.second = n % 3 + 2; }
	return result;
}
int calDis(pair<int, int> coorCur, pair<int, int> coorDes) {
	int dis = 0;

	dis += (coorCur.first > coorDes.first) ? 
		(coorCur.first - coorDes.first) : (coorDes.first - coorCur.first);

	dis += (coorCur.second > coorDes.second) ? 
		(coorCur.second - coorDes.second) : (coorDes.second - coorCur.second);
	return dis;
}
string solution(vector<int> numbers, string hand) {
	string answer = "";
	int left = 10; int right = 12; //현재위치

	for (int i : numbers) {
		if ((i == 0) || i % 3 == 2) { //가운데줄
			i = (i == 0) ? 11 : i;

			int leftDis = 0;
			if ((left % 3) == 1) { leftDis += 1; leftDis += abs(left + 1 - i) / 3;}
			else leftDis += abs(left - i) / 3;

			int rightDis = 0;
			if ((right % 3) == 0) { rightDis += 1; rightDis += abs(right-1 - i) / 3;}
			else rightDis += abs(right - i) / 3;		

			if(leftDis > rightDis) { answer += "R";  right = i; }
			else if(leftDis < rightDis) { answer += "L";  left = i; }
			else {
				if(hand == "right") { answer += "R";  right = i; }
				else { answer += "L";  left = i; }
			}
		}
		else if (i % 3 == 1) { answer += "L";  left = i; } //왼쪽 줄
		else if (i % 3 == 0) { answer += "R";  right = i; } // 오른쪽 줄
	}

	return answer;
}

int main() {
	cout << solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }, "right");
	return 0;
}