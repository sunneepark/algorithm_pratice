#include <unordered_map>
using namespace std;

class LRUCache {
private:
	list<pair<int, int>> lruList; //key, value pair, FILO(LRU)
	unordered_map<int, list<pair<int, int>>::iterator> cache; //<key,value> iterator map :likedhashmap ����
	int capacity;
	
	void moveToFront(int key, int value) { 
		lruList.erase(cache[key]); //o(1)
		lruList.push_front(make_pair(key, value));
		cache[key] = lruList.begin(); //iterator �缳��
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
		if (cache.find(key) != cache.end()) { //�̹� ĳ�ÿ� ������ �� 
			moveToFront(key, value);
			return;
		}
		else { //ĳ�ÿ� �ֱ� 
			lruList.push_front(make_pair(key, value));
			cache[key] = lruList.begin();
			if (capacity < lruList.size()) { //���� size�� �Ѿ�� ���
				cache.erase(lruList.back().first);
				lruList.pop_back();
			}
		}

	}
};
