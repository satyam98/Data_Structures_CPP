#include <bits/stdc++.h>
using namespace std;

// Next larger element
void NxtLE() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long a[n];
        long ans[n];
        long i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        stack<long>s;
        for (i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= a[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = s.top();
            }
            s.push(a[i]);
        }
        for (i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    return 0;
}