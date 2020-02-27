#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Subarray with given sums
void Subarraywithgivensum()
{
	int tc;
	cin >> tc;
	while (tc--) {
		int size, num;
		cin >> size >> num;
		int arr[100];
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
		int st = 0, en = 0;
		int sum = 0;
		int flag = 0;
		for (int i = 0; i < size; i++) {
			if (sum < num) {
				sum += arr[i];
				en = i;
			}
			if (sum > num) {
				while (st <= en && sum > num)
				{
					sum -= arr[st];
					st++;
				}
			}
			if (sum == num) {
				flag = 1;
				break;
			}
		}
		if (flag)
			cout << st + 1 << " " << en + 1 << endl;
		else
			cout << -1 << endl;
	}
}
// Missing number in array
void missingnumber() {
	int tc;
	cin >> tc;
	while (tc--) {
		int s;
		cin >> s;
		int arr[100];
		for (int i = 0; i < s - 1; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + s - 1);
		for (int i = 0; i < s; i++) {
			int x = (i + 1 ^ arr[i]);
			if (x != 0) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
}

// contiguous sub-array with maximum sum
void kadanealgo() {
	int tc;
	cin >> tc;
	while (tc--) {
		int size;
		cin >> size;
		int local_max = 0;
		int global_max = INT_MIN;
		for (int i = 0; i < size; i++) {
			int num;
			cin >> num;
			local_max = max(num, num + local_max);
			if (local_max > global_max) global_max = local_max;
		}
		cout << global_max << endl;
	}
}

//Count the triplets
int findtriplets(int set[], int size) {
	if (size < 3) {
		return -1;
	}
	int count = 0;
	for (int i = size - 1; i >= 2; i--) {
		int ini = 0, fin = i - 1, sum = 0;
		while (ini < fin) {
			sum = set[ini] + set[fin];
			if (sum == set[i]) {
				count++;
				ini++;
				fin--;
			}
			else if (sum > set[i]) {
				fin--;
			}
			else {
				ini++;
			}
		}
	}
	if (count)
		return count;
	else
		return -1;
}
void triplets() {
	int tc;
	cin >> tc;
	while (tc--) {
		int size;
		cin >> size;
		int set[100];
		for (int i = 0; i < size; i++) {
			cin >> set[i];
		}
		sort(set, set + size);
		cout << findtriplets(set, size) << endl;
	}
}
int main() {
	//Subarraywithgivensum();	//Subarray with given sum
	//missingnumber();		// Missing number in array
	//kadanealgo();			// contiguous sub-array with maximum sum
	//triplets();				//Count the triplets
	return 0;
}