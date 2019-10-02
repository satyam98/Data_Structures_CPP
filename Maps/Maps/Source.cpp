/******************************************************************************

							  SATYAM PANDEY

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = { 2,2,5,50,1 };
	map<int, int> mp;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (mp.count(arr[i])) {
			mp[arr[i]]++;
		}
		else {
			mp.insert({ arr[i],1 });
		}
	}
	//pair<int,int> p={INT_MAX,INT_MAX};
	int num = INT_MAX;
	int count = INT_MAX;
	for (auto itr = mp.rbegin(); itr != mp.rend(); ++itr) {
		cout << itr->first << " " << itr->second << endl;
		if (itr->second < count) {
			num = itr->first;
			count = itr->second;
		}
	}
	cout << num;

	return 0;
}
