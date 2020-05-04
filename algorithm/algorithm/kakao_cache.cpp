#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class LRUCache {
private:
	list<string> lruList; //key, value pair, FILO(LRU)
	unordered_map<string, list<string>::iterator> cache; //<key,value> iterator map :likedhashmap 구현
	int capacity;

	void moveToFront(string key) {
		lruList.erase(cache[key]); //o(1)
		lruList.push_front(key);
		cache[key] = lruList.begin(); //iterator 재설정
	}
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	bool get(string key) {
		if (cache.find(key) == cache.end()) return false;

		moveToFront(key); //least recently
		return true;
	}

	void put(string key) {
			lruList.push_front(key);
			cache[key] = lruList.begin();
			if (capacity < lruList.size()) { //만약 size가 넘어갔을 경우
				cache.erase(lruList.back());
				lruList.pop_back();
			}
	}
};

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	LRUCache cache(cacheSize);

	for (string city : cities) {
		transform(city.begin(), city.end(), city.begin(), ::tolower);
		if (cache.get(city)) answer += 1; //cache hit
		else {
			answer += 5; //cache miss
			cache.put(city);
		}
	}
	return answer;
}
int main() {
	vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	int cacheSize = 3;
	cout << solution(cacheSize, cities);
	return 0;
}