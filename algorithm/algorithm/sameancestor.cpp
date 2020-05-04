#include <iostream>
#include <algorithm>
#include <vector>
int sum_child;
using namespace std;

void find_parent(vector<int>& parent_f, int* make_graph, int f) {
	//sum_child++;
	parent_f.push_back(make_graph[f]);
	f = make_graph[f];

	if (f == 1)
		return;
	find_parent(parent_f, make_graph, f);
}
int find_sameparent(vector<int> parent_f, int* make_graph, int f) {
	//sum_child++;
	if (find(parent_f.begin(), parent_f.end() , make_graph[f]) != parent_f.end())
		return make_graph[f];
	else
		return find_sameparent(parent_f, make_graph, make_graph[f]);
}
void find_children(int* make_graph, int* twochild_arr, int result, int v) {
	cout << result << " " << sum_child << endl;
	int twice = 0;
	for (int i = 0; i < v + 1 && twice < twochild_arr[result]; i++) {
		if (make_graph[i] == result) {
			twice++;
			sum_child++;
			find_children(make_graph,twochild_arr, i, v);
		}
	}
	return;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int v = 0; int e = 0; int f1 = 0; int f2 = 0;

		cin >> v >> e >> f1 >> f2;
		int* make_graph = new int[v+1];
		make_graph[1] = 0;

		int* twochild_arr = new int[v + 1];
		fill_n(twochild_arr, v + 1, 0);

		vector<int> parent_f1;
		int result = 0;
		sum_child = 0;
		for (int i = 0; i < e; i++) {
			int parent = 0; int child = 0;
			cin >> parent >> child;
			make_graph[child] = parent;
			twochild_arr[parent]++;
		}
		//공통조상
		find_parent(parent_f1, make_graph, f1);
		result = find_sameparent(parent_f1, make_graph, f2);
		//자식 노드 갯수
		find_children(make_graph, twochild_arr, result, v);
		cout << "#" << test_case << " " << result << " " <<sum_child+1<< endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}