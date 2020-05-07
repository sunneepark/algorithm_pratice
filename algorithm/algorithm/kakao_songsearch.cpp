#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
constexpr auto ALPHABETS = 26;

using namespace std;

int char_to_index(char c) {
	return c - 'a';
}

struct Trie {
	bool is_terminal; // this represents end of string
	Trie * children[ALPHABETS];
	int count ;
	// Constructor
	Trie() : is_terminal(false), count(0) {
		memset(children, 0, sizeof(children));
	}

	// Delete all children
	~Trie() {
		for (int i = 0; i < ALPHABETS; ++i) {
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char * key) {
		if (*key == '\0') {
			is_terminal = true;
		}
		else {
			int index = char_to_index(*key);
			if (children[index] == 0) {
				children[index] = new Trie();
			}
			count++;
			children[index]->insert(key + 1);
		}
	}

	Trie* sufFind(string::iterator key) {
		if (*key == '?')
			return this;

		int index = char_to_index(*key);
		if (!children[index]) {
			return NULL;
		}
		return children[index]->sufFind(key - 1);
	}
	Trie* preFind(string::iterator key ) {
		if (*key == '?') {
			return this;
		}
		
		int index = char_to_index(*key);
		if (!children[index]) {
			return NULL;
		}
		return children[index]->preFind(key + 1);
	}
};

Trie* preRoot[10001];
Trie* sufRoot[10001];
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	for (string word : words) {
		int size = word.size();
		if (preRoot[size] == NULL) preRoot[size] = new Trie();
		preRoot[size]->insert(word.c_str());

		reverse(word.begin(), word.end());
		if (sufRoot[size] == NULL) sufRoot[size] = new Trie();
		sufRoot[size]->insert(word.c_str());
	}

	for (string query : queries) {
		int size = query.size();

		Trie* fixTrie = NULL;
		auto it = query.begin();

		if (*it == '?') { // 접두사면
			fixTrie = sufRoot[size];
			if (query[query.size() - 1] != '?') {
				if(fixTrie) fixTrie = fixTrie->sufFind(query.end() - 1);
			}
		}
		else {
			if(preRoot[size]) fixTrie = preRoot[size]->preFind(it);
		}
		int result = 0;
		if(fixTrie) result = fixTrie->count;
		answer.push_back(result);
	}
	return answer;
}

int main() {
	vector<int> result = solution({"frodo", "front", "frost", "frozen", "addxsx", "afdxsx"}, { "????sx", "fro??",  "fr???", "fro???", "pro?" });
	for (auto i : result)
		cout << i;
}