#include <unordered_map>
using namespace std;

class LRUCache {
private:
	list<pair<int, int>> lruList; //key, value pair, FILO(LRU)
	unordered_map<int, list<pair<int, int>>::iterator> cache; //<key,value> iterator map :likedhashmap 구현
	int capacity;
	
	void moveToFront(int key, int value) { 
		lruList.erase(cache[key]); //o(1)
		lruList.push_front(make_pair(key, value));
		cache[key] = lruList.begin(); //iterator 재설정
	}
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (cache.find(key) == cache.end()) return -1;

		int value = (*cache[key]).second;
		moveToFront(key, value); //least recently
		return (*cache[key]).second;
	}

	void put(int key, int value) {
		if (cache.find(key) != cache.end()) { //이미 캐시에 존재할 때 
			moveToFront(key, value);
			return;
		}
		else { //캐시에 넣기 
			lruList.push_front(make_pair(key, value));
			cache[key] = lruList.begin();
			if (capacity < lruList.size()) { //만약 size가 넘어갔을 경우
				cache.erase(lruList.back().first);
				lruList.pop_back();
			}
		}

	}
};
