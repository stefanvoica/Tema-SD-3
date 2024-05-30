#include <bits/stdc++.h>
#define int long long
using namespace std;

struct values {
    int totalSum;
    int prefSum, sufSum;
    int maxSum;
};

void update(vector<values>& aint, int node, int val) {
    aint[node].totalSum = aint[node].maxSum = val;
    aint[node].prefSum = aint[node].sufSum = val;
}

void updateAINT(vector<values>& aint, int left, int right, int node, int pos, int val) {
    if (left == right) {
        update(aint, node, val);
    } else {
        int middle = (left + right) / 2;
        if (pos <= middle) {
            updateAINT(aint, left, middle, node * 2, pos, val);
        } else {
            updateAINT(aint, middle + 1, right, node * 2 + 1, pos, val);
        }

        aint[node].totalSum = aint[node * 2].totalSum + aint[node * 2 + 1].totalSum;
        aint[node].prefSum = max(aint[node * 2].prefSum, aint[node * 2].totalSum + aint[node * 2 + 1].prefSum);
        aint[node].sufSum = max(aint[node * 2 + 1].sufSum, aint[node * 2 + 1].totalSum + aint[node * 2].sufSum);
        aint[node].maxSum = max({aint[node * 2].maxSum,
                                 aint[node * 2 + 1].maxSum,
                                 aint[node * 2].sufSum + aint[node * 2 + 1].prefSum
                                });
    }
}

int sumPrefix, maxim;

void query(vector<values>& aint, int left, int right, int leftQuery, int rightQuery, int node) {
    if (leftQuery <= left && right <= rightQuery) {
        maxim = max({maxim, aint[node].maxSum, sumPrefix + aint[node].prefSum});
        sumPrefix = max(sumPrefix + aint[node].totalSum, aint[node].sufSum);
    } else {
        int middle = (left + right) / 2;
        if (leftQuery <= middle)
            query(aint, left, middle, leftQuery, rightQuery, node * 2);
        if (middle < rightQuery)
            query(aint, middle + 1, right, leftQuery, rightQuery, node * 2 + 1);
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<values> posAINT(4 * n + 1), negAINT(4 * n + 1);
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if (i & 1) {
            updateAINT(posAINT, 1, n, 1, i, val);
            updateAINT(negAINT, 1, n, 1, i, -val);
        } else {
            updateAINT(posAINT, 1, n, 1, i, -val);
            updateAINT(negAINT, 1, n, 1, i, val);
        }
    }

    for (int i = 0; i < q; i += 1) {
        int tip, a, b;
        cin >> tip >> a >> b;
        if (tip == 1) {
            if (a & 1) {
                updateAINT(posAINT, 1, n, 1, a, b);
                updateAINT(negAINT, 1, n, 1, a, -b);
            } else {
                updateAINT(posAINT, 1, n, 1, a, -b);
                updateAINT(negAINT, 1, n, 1, a, b);
            }
        } else {
            maxim = INT_MIN, sumPrefix = 0;
            query(posAINT, 1, n, a, b, 1);

            int temp = maxim;

            maxim = INT_MIN, sumPrefix = 0;
            query(negAINT, 1, n, a, b, 1);

            cout << max(temp, maxim) << '\n';
        }
    }
    return 0;
}
