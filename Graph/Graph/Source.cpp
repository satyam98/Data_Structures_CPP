#include<bits/stdc++.h>
#include<algorithm>
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
/*void DFSUntil(int start, vector<int>nodes[], bool visited[]) {
	visited[start] = true;
	cout << start << " ";
	int size= nodes[start].size();
	for (int i = 0; i<size; i++) {
		if (!visited[nodes[start][i]]) {
			DFSUntil(nodes[start][i], nodes, visited);
		}
	}
}*/
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

//FUNCTION TO FIND CYCLES IN A GRAPH
bool bfs(vector<int> adj[]) {
	int vis[100];
	queue<int> q;
	memset(vis, -1, sizeof(vis));
	for (int i = 0; i < 100; i++) {				//traversing nodes
		if (!adj[i].empty()) {					//find valid nodes
			if (vis[i] == -1)					//if nodes is not visited
				q.push(i);						//push it to Queue
			while (!q.empty()) {				//while Queue is not empty
				int front = q.front();			//node at top of queue becomes current node
				if (vis[front] == -1)			//if not visited then mark as visited
					vis[front] = 0;		
				for (auto itr : adj[front]) {	//iterate in the connected nodes of current node
					if (vis[itr] == -1) {		//if node is not visited then push it into queue and mark it as visited
						q.push(itr);
						vis[itr] = 0;
					}
					else if (vis[itr] == 0) {	// if node is already visited then return cycle is present
						return true;
					}
				}
				vis[q.front()] = 1;				// make current node completely visited
				q.pop();						// pop out the current node

			}
			return false;
		}
	}
}


//UN-WEIGHTED GRAPH
/*int main() {

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
	cout << endl << endl;
	// DETECT CYCLE
	cout<<"Cycle is there? "<<bfs(nodes)<< endl;;
}*/
/*
Sample Input
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

//TRAVELLING SALESMEN PROBLEM 
void tsp(int graph[][4], vector<bool>& v, int currPos,
	int n, int count, int cost, int& ans)
{
	if (count == n && graph[currPos][0]) {
		ans = min(ans, cost + graph[currPos][0]);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!v[i] && graph[currPos][i]) {

			// Mark as visited 
			v[i] = true;
			tsp(graph, v, i, n, count + 1,
				cost + graph[currPos][i], ans);

			// Mark ith node as unvisited 
			v[i] = false;
		}
	}
};

//WEIGHTED GRAPH
int main()
{
	// n is the number of nodes i.e. V 
	int n = 4;

	int graph[][4] = {
		{ 0, 10, 15, 20 },
		{ 10, 0, 35, 25 },
		{ 15, 35, 0, 30 },
		{ 20, 25, 30, 0 }
	};

	vector<bool> v(n);
	for (int i = 0; i < n; i++)
		v[i] = false;

	v[0] = true;
	int ans = INT_MAX;

	// Find the minimum weight Hamiltonian Cycle 
	tsp(graph, v, 0, n, 1, 0, ans);

	// ans is the minimum weight Hamiltonian Cycle 
	cout << ans;

	return 0;
}
