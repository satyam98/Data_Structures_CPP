#include<bits/stdc++.h>
using namespace std;

//NODE STRUCTURE
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

//INSERTION INTO BINARY SEARCH TREE
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
// LEVEL ORDER TRAVERSAL
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
	cout << endl;
}
// SEARCHING A DATA
bool Search(Node* root, int data) {
	if (root == NULL) {
		return false;
	}
	if (root->data == data) {
		return true;
	}
	else if (root->data > data) {
		return Search(root->left, data);
	}
	else
	{
		return Search(root->right, data);
	}
	return false;
}
//FIND MINIMUM AND MAXIMUM IN A TREE
void findminmax(Node* root) {
	if (!root) {
		cout << "Invalid Tree"<<endl;
	}
	Node* current = root;
	while (current->left) {
		current = current->left;
	}
	cout << "Minimum = " << current->data << endl;
	current = root;
	while (current->right) {
		current = current->right;
	}
	cout << "Maximum = " << current->data << endl;
}
// MAIN FUNCTION
int main() {
	int num_of_nodes,data;
	cout << "Enter number of nodes" << endl;
	cin >> num_of_nodes;
	Node* root = NULL;
	//INSERTION
	cout << "Insert Elements"<<endl;
	for (int i = 0; i < num_of_nodes; i++) {
		cin >> data;
		root=Insert(root, data);
	}

	//TRAVERSAL
	cout << "Level Order Traversal" << endl;
	LevelOrderTraversal(root);

	//SEARCHING
	cout << "Enter data to search"<<endl;
	cin >> data;
	if (Search(root, data) == true) {
		cout << "Found"<<endl;
	}
	else {
		cout << "Not Found"<<endl;
	}

	//FIND MINIMUM AND MAXIMUM
	cout << "Finding Min and Max" << endl;
	findminmax(root);


	return 0;
}