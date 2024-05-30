#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sol = 0;

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n), st(n), dr(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[i] <= a[stk.back()]) {
            stk.pop_back();
        }
        if (stk.empty())
            st[i] = 0;
        else
            st[i] = stk.back() + 1;
        stk.push_back(i);
    }
    stk.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && a[i] < a[stk.back()]) {
            stk.pop_back();
        }
        if (stk.empty())
            dr[i] = n - 1;
        else
            dr[i] = stk.back() - 1;
        stk.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        for (int l = st[i]; l <= i; l++) {
            sol += max(0, min(dr[i], 2 * i - 1 - l) - i + 1);
        }
    }
    cout << sol << "\n";
    return 0;
}
