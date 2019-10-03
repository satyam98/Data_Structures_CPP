#include<bits/stdc++.h>
#include <unordered_map> 
using namespace std;

//FUNCTION TO REVERSE WORDS IN A GIVEN STRING
void ReverseWordsInAGivenString(string str) {
	vector<string> v;
	string word = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '.') {
			v.push_back(word);
			word = "";
		}
		else {
			word = word + str[i];
		}
	}
	v.push_back(word);
	for (int i = v.size() - 1; i >= 0; i--) {
		if (i != 0) {
			cout << v[i] << ".";
		}
		else {
			cout << v[i];
		}
	}
	cout << endl;

}

//FUNCTION TO PRINT PERMUTATIONS USING STL
void PrintPermutations(string str) {
	sort(str.begin(), str.end());
	do {
		cout << str << " ";
	} while (next_permutation(str.begin(), str.end()));
	cout << endl;
}

//FUNCTION TO FIND LARGEST PALINDROME IN A STRING (USING DYNAMIC PROGRAMMING)
void LargestPalindrome(string str) {
	int i, j, k, start = 0, maxPalindrome = 0, cstart, cend, length;
	const unsigned int size = str.length();
	bool dparr[100][100];
	memset(dparr, 0, sizeof(dparr));
	maxPalindrome = 1;
	for (i = 0; i < size; i++) {
		dparr[i][i] = true;
	}
	start = 0;
	for (i = 0; i < size - 1; i++) {
		if (str[i] == str[i + 1]) {
			dparr[i][i + 1] = true;
			if (maxPalindrome < 2) {
				maxPalindrome = 2;
				start = i;
			}
		}
	}
	for (k = 3; k <= size; k++) {
		for (i = 0; i < size - k + 1; i++) {
			j = i + k - 1;
			if (dparr[i + 1][j - 1] && str[i] == str[j]) {
				dparr[i][j] = true;

				if (k > maxPalindrome) {
					start = i;
					maxPalindrome = k;
				}
			}
		}
	}
	for (i = start; i <= start + maxPalindrome - 1; ++i)
		cout << str[i];
}

//FUNCTION TO REMOVE DUPLICATES IN A STRING
string RemoveDup(string str) {
	string temp;
	int i = 0;
	while (i < str.size()) {
		if (str[i] == str[i + 1]) {
			while (str[i] == str[i + 1]) {
				i++;
			}
		}
		else {
			temp.push_back(str[i]);
		}
		i++;
	}
	return temp;
	/*if (temp == str) {
		return str;
	}
	else {
		return RecursiveRemoveDup(temp);
	}*/
}

// RECURSIVE FUNCTION TO FIND MINIMUM NUMBER OF INSERTION IN A STRING TO MAKE IT PALINDROME
int findPalinMinInsertions(string str, int l, int h)
{
	// Base Cases 
	if (l > h) return INT_MAX;
	if (l == h) return 0;
	if (l == h - 1) return (str[l] == str[h]) ? 0 : 1;

	// Check if the first and last characters are same. On the basis of the comparison result, decide which subrpoblem(s) to call 
	return (str[l] == str[h]) ? findPalinMinInsertions(str, l + 1, h - 1) : min(findPalinMinInsertions(str, l, h - 1),findPalinMinInsertions(str, l + 1, h)) + 1;
}

// FUNCTION TO CHECK IF A STRING IS BALANCED (USING STACK)
string isBalanced(string s) {
	stack<char> stk;
	char x;
	int size = s.length();
	for (int i = 0; i < size; i++) {
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
			stk.push(s[i]);
			continue;
		}
		if (stk.empty()) {
			return "not balanced";
		}
		else {

			switch (s[i]) {
			case '}':   x = stk.top();
				stk.pop();
				if (x == '[' || x == '(') return "not balanced";
				break;
			case ']':   x = stk.top();
				stk.pop();
				if (x == '{' || x == '(') return "not balanced";
				break;
			case ')':   x = stk.top();
				stk.pop();
				if (x == '[' || x == '{') return "not balanced";
				break;
			}
		}

	}
	if (stk.empty()) {
		return "balanced";
	}
	else {
		return "not balanced";
	}
}

//FUNCTION FOR FINDING ANAGRAMS IN A VECTOR OF STRINGS
void findanagram(unordered_map<string, vector<string>>& store) {
	for (auto itr = store.begin(); itr != store.end(); itr++) {
		vector<string> temp = itr->second;
		if (temp.size() > 1) {
			for (int i = 0; i < temp.size(); i++) {
				cout << temp[i] << " ";
			}
			cout << endl;
		}
	}
	
}
void storeinmap(vector<string> &ana) {
	unordered_map<string, vector<string> > store;
	for (int i = 0; i < ana.size(); i++) {
		string temp=ana[i];
		sort(temp.begin(), temp.end());
		if (store.find(temp) == store.end()) {
			vector<string> temp_vec;
			temp_vec.push_back(ana[i]);
			store.insert({ temp,temp_vec });
		}
		else {
			vector<string> temp_vec = store[temp];
			temp_vec.push_back(ana[i]);
			store[temp] = temp_vec;
		}
	}
	findanagram(store);
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		string str;
		cin >> str;
		//ReverseWordsInAGivenString(str);
		//PrintPermutations(str);
		//LargestPalindrome(str);
		//str = RemoveDup(str); cout << str << endl;
		//cout << findPalinMinInsertions(str, 0, str.size()- 1);
		//cout << isBalanced(str) << endl;
		/*if (str == "anagram") {
			vector<string> arr;
			cout << "No of strings" << endl;
			int size;
			cin >> size;
			string ana;
			for (int i = 0; i < size; i++) {
				cin >> ana;
				arr.push_back(ana);
			}
			storeinmap(arr);
		}*/
	}
	
	return 0;
}