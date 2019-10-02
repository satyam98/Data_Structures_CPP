#include<bits/stdc++.h>
using namespace std;

//FUNCTION FOR BREADTH FIRST SEARCH
void BFS(vector<int>nodes[]) {
	int first;
	queue<int> q;
	bool visited[100];
	memset(visited, false, sizeof(visited));
	cout << "Enter the starting element"<<endl;
	cin >> first;
	cout << "Breadth First Search:" << endl;
	visited[first] = true;
	q.push(first);
	while (!q.empty()) {
		first = q.front();
		cout << first << " ";
		q.pop();
		for (vector<int>::iterator itr = nodes[first].begin(); itr != nodes[first].end(); itr++) {
			if (!visited[*itr]) {
				q.push(*itr);
				visited[*itr] = true;
			}
		}
	}
}

//SECONDARY-FUNCTION FOR DEPTH FIRST SEARCH (RECURSIVE)
void DFSUntil(int start, vector<int>nodes[], bool visited[]) {
	visited[start] = true;
	cout << start << " ";
	int size= nodes[start].size();
	for (int i = 0; i<size; i++) {
		if (!visited[nodes[start][i]]) {
			DFSUntil(nodes[start][i], nodes, visited);
		}
	}
}
void DFS(vector<int>nodes[]) {
	//RECURSIVE
	/*int start;
	cout << "Enter the starting node" << endl;;
	cin >> start;
	bool visited[100];
	memset(visited, false, sizeof(visited));
	cout << "Depth First Search:" << endl;
	DFSUntil(start, nodes,visited);*/

	//ITERATIVE
	int first;
	stack<int> stk;
	bool visited[100];
	memset(visited, false, sizeof(visited));
	cout << "Enter the starting node" << endl;;
	cin >> first;
	visited[first] = true;
	stk.push(first);
	cout << "Depth First Search:" << endl;
	while (!stk.empty()) {
		first = stk.top();
		cout << first << " ";
		stk.pop();
		for (/*auto itr : nodes[first]*/vector<int>::iterator itr = nodes[first].begin(); itr != nodes[first].end(); itr++) {
			if (!visited[*itr]) {
				visited[*itr] = true;
				stk.push(*itr);
			}
		}
	}
}
int main() {

	//CREATING A GRAPH
	int edges, a, b;
	vector<int>nodes[100];
	cout << "Enter the no of edges" << endl;
	cin >> edges;
	cout << "Enter the edges" << endl;
	for (int i = 0; i < edges; i++) {
		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	cout << endl;
	//DISPLAY THE GRAPH
	for (int i = 0; i < 100; i++) {
		if (!nodes[i].empty()) {
			cout << "[" << i << "]" << "-->";
			for (vector<int>::iterator itr = nodes[i].begin(); itr != nodes[i].end(); itr++) {
				cout << *itr << "-->";
			}
			cout << "NULL" << endl;
		}
	}
	cout << endl;
	//BREADTH FIRST SEARCH
	BFS(nodes);
	cout << endl;
	//DEPTH FIRST SEARCH
	DFS(nodes);
}
/*sample input
1	-	2
|	\	|
4	-	3
\		/
	5
/		\
6		7
1 2
1 3		
1 4		
2 3		
3 4		
3 5		
4 5		
5 6		
5 7*/