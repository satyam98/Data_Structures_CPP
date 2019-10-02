/******************************************************************************

							  SATYAM PANDEY

*******************************************************************************/

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

//RECURSIVE FUNCTION TO COUNT LEAF NODES IN A TREE
int reccountLeaves(Node* root)
{
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return reccountLeaves(root->left) + reccountLeaves(root->right);
}

//FUNCTION TO COUNT LEAF NODES IN A TREE
int countLeaves(Node* root)
{

	queue<Node*> q;
	Node* temp;
	q.push(root);
	int count = 0;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (!temp->left && !temp->right)
			count++;
		else
		{
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
	return count;
}

//Maximum sum of path from one left node to another
int rootToLeafSum(Node* root, int& ans)
{
	if (root == NULL)
		return 0;
	int ls = rootToLeafSum(root->left, ans);
	int rs = rootToLeafSum(root->right, ans);
	ans = max(ans, ls + rs + root->data);
	return(ls > rs ? ls : rs + root->data);
}
int maxPathSum(struct Node* root)
{
	if (root == NULL) return 0;
	int ans = INT_MIN;
	rootToLeafSum(root, ans);
	return ans;
}

//Height of a tree
int height(Node* node)
{
	if (node == NULL) return 0;
	return max(height(node->left), height(node->right)) + 1;
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

	//COUNT LEAF NODES
	cout << countLeaves(root) << endl;
	//cout << reccountLeaves(root) << endl;

	//MAX SUM FOR PATH ONE LEAF TO ANOTHER
	cout<<maxPathSum(root);

	//HEIGHT OF A TREE
	cout<<height(root);
	

	return 0;
}