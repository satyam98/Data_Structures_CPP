#include<bits/stdc++.h>
#include<unordered_map>
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
}
//OR
string removeDupSTLMap(string s) {
	string output;
	map<char, bool> mp;
	int size = s.length();
	for (int i = 0; i < size; i++) {
		if (mp.find(s[i]) == mp.end()) {
			mp.insert({ s[i],true });
			output = output + s[i];
		}
	}
	return output;
}

// RECURSIVE FUNCTION TO FIND MINIMUM NUMBER OF INSERTION IN A STRING TO MAKE IT PALINDROME (USING RECURSION ONLY)
int findPalinMinInsertions(string str, int l, int h)
{
	// Base Cases 
	if (l > h) return INT_MAX;
	if (l == h) return 0;
	if (l == h - 1) return (str[l] == str[h]) ? 0 : 1;

	// Check if the first and last characters are same. On the basis of the comparison result, decide which subrpoblem(s) to call 
	return (str[l] == str[h]) ? findPalinMinInsertions(str, l + 1, h - 1) : min(findPalinMinInsertions(str, l, h - 1),findPalinMinInsertions(str, l + 1, h)) + 1;
}
// RECURSIVE FUNCTION TO FIND MINIMUM NUMBER OF INSERTION IN A STRING TO MAKE IT PALINDROME (USING RECURSION WITH DP
int findPalinMinInsDP(map<string, int>& map, string s, int l, int h) {
	if (l > h) return INT_MAX;
	if (l == h) return 0;
	if (l == h - 1) return (s[h] == s[l]) ? 0 : 1;
	//using dynamic programming
	if (map.find(s) == map.end())
		map[s.substr(l + 1, h - l - 1)] = findPalinMinInsDP(map, s, l + 1, h - 1);
	if (map.find(s.substr(l, h - l)) == map.end())
		map[s.substr(l, h - l)] = findPalinMinInsDP(map, s, l, h - 1);
	if (map.find(s.substr(l + 1, h - l)) == map.end())
		map[s.substr(l + 1, h - l)] = findPalinMinInsDP(map, s, l + 1, h);
	return (s[h] == s[l]) ? map[s.substr(l + 1, h - l - 1)] : (1 + min(map[s.substr(l, h - l)], map[s.substr(l + 1, h - l)]));
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

//FUNCTIONS TO FIND NUMBER OF POSSIBLE PARTITION IN A STRING WITH M ELEMENTS HAVING SAME FREQUENCY
int countWays(string str)
{
/*QUESTION EXPLANATION 
Input: str = “aabbccaa”, m = 2
Output : 2
The string has length 8, so there are 7 positions available to perform the partition.
i.e.a | a | b | b | c | c | a | a
Only two partitions are possible which satisfy the given constraints.
aab | bccaa – On the left half of the separator, ‘a’ has frequency 2 and ‘b’ has frequency 1
which is same as that of the right half.
aabbc | caa – On the left half of the separator, ‘a’ has frequency 2 and ‘c’ has frequency 1
which is same as that of the right half.

Input: str = “aabbaa”, m = 2
Output : 1
*/
	int m;
	cin >> m;
	// Hashset to store unique characters 
	// in the given string 
	set<char> s;
	for (int i = 0; i < str.length(); i++)
		s.insert(str[i]);

	// To store the number of ways 
	// to partition the string 
	int result = 0;

	for (int i = 1; i < str.length(); i++)
	{
		// Hashmaps to store frequency of characters 
		// of both the partitions 
		map<char, int> first_map, second_map;

		// Iterate in the first partition 
		for (int j = 0; j < i; j++) {

			// If character already exists in the hashmap 
			// then increase it's frequency 
			first_map[str[j]]++;
		}

		// Iterate in the second partition 
		for (int k = 0; k < str.length(); k++)

			// If character already exists in the hashmap 
			// then increase it's frequency 
			second_map[str[k]]++;

		// Iterator for HashSet 
		set<char>::iterator itr = s.begin();

		// To store the count of characters that have 
		// equal frequencies in both the partitions 
		int total_count = 0;
		while (++itr != s.end())
		{
			// first_count and second_count keeps track 
			// of the frequencies of each character 
			int first_count = 0, second_count = 0;
			char ch = *(itr);

			// Frequency of the character 
			// in the first partition 
			if (first_map.find(ch) != first_map.end())
				first_count = first_map[ch];

			// Frequency of the character 
			// in the second partition 
			if (second_map.find(ch) != second_map.end())
				second_count = second_map[ch];

			// Check if frequency is same  
			// in both the partitions 
			if (first_count == second_count &&
				first_count != 0)
				total_count += 1;
		}

		// Check if the condition is satisfied 
		// for the current partition 
		if (total_count >= m)
			result += 1;
	}
	return result;
}

int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--) {
		string str;
		getline(cin, str);
		//ReverseWordsInAGivenString(str);
		//PrintPermutations(str);
		//LargestPalindrome(str);
		//str = RemoveDup(str); cout << str << endl;
		//cout << removeDupSTLMap(str);
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
		//cout<<findPalinMinInsertions(str, 0, str.length()-1);
		map<string, int>map;
		cout << findPalinMinInsDP(map, str, 0, str.length() - 1) << endl;
		//cout<<countWays(str);
	}
	
	return 0;
}