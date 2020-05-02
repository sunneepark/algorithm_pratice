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
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
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
		//��������
		find_parent(parent_f1, make_graph, f1);
		result = find_sameparent(parent_f1, make_graph, f2);
		//�ڽ� ��� ����
		find_children(make_graph, twochild_arr, result, v);
		cout << "#" << test_case << " " << result << " " <<sum_child+1<< endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}