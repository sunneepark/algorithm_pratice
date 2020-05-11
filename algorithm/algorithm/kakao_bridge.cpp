#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 200000000;
	int max = 0;
	int maxIdx = 0;
	for (int i = 0; i < stones.size()-k; i++) {
			if (maxIdx == i) {
				max = 0;
				maxIdx = 0;
				
				for (int j = 1 ; j <= k && i+j < stones.size(); j++) {
					if (max < stones[i+j]) {
						max = stones[i+j];
						maxIdx = i + j;
					}
				}
				if (answer > max) answer = max;
			}
			else { //전적이 있으면
				if (max < stones[i + k]) {
					max = stones[i+k];
					maxIdx = i+k;

					if (answer > max) answer = max;
				}
			}
	}
	if (answer == 200000) {
		for (int i = 0; i < stones.size(); i++) {
			if (max < stones[i]) {
				max = stones[i];
				maxIdx = i;
			}
		}
		answer = max;
	}
	return answer;
}
int main() {
	solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3);
}