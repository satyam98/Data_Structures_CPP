#include<bits/stdc++.h>
using namespace std;
struct Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int x) {
		data = x;
		left = right = NULL;
	}
};
Node* getnewnode(int data) {
	Node* newnode = new Node(data);
	return newnode;
}
Node* Insert(Node* root, int data) {
	if (root == NULL) {
		return getnewnode(data);
	}
	else if (data < root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}
void LevelOrderTraversal(Node* root) {
	if (root == NULL) {
		return;
	}
	queue<Node*>Q;
	Q.push(root);
	while (!Q.empty()) {
		Node* current = Q.front();
		cout << current->data<< " ";
		Q.pop();
		if(current->left)Q.push(current->left);
		if(current->right)Q.push(current->right);
	}
}

int main() {
	int num_of_nodes,data;
	cout << "Enter number of nodes" << endl;
	cin >> num_of_nodes;
	Node* root = NULL;
	for (int i = 0; i < num_of_nodes; i++) {
		cin >> data;
		root=Insert(root, data);
	}
	LevelOrderTraversal(root);
	return 0;
}