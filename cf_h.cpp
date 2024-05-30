#include <bits/stdc++.h>
using namespace std;
const int dim = 200006;
int v[dim], m1[dim], m2[dim];

struct trie {
    trie* kids[2];
    trie() {
        kids[0] = nullptr;
        kids[1] = nullptr;
    }
};
trie* root = new trie();

void insert(int num) {
    trie* node = root;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node->kids[bit])
            node->kids[bit] = new trie();
        node = node->kids[bit];
    }
}

int getMaxXOR(int num) {
    trie* node = root;
    int maxXOR = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int oppositeBit = 1 - bit;
        if (node->kids[oppositeBit] != nullptr) {
            maxXOR = maxXOR | (1 << i);
            node = node->kids[oppositeBit];
        } else {
            node = node->kids[bit];
        }
    }
    return maxXOR;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i <= n - 2; i++)
        insert(v[i]);

    //Calculam maxime pe prefixe
    m1[n-1] = max(v[n], v[n - 1]);
    m2[n-1] = min(v[n], v[n - 1]);
    for (int i = n - 2; i >= 1; i--)
        if (v[i] > m1[i + 1]) {
            m1[i] = v[i];
            m2[i] = m1[i + 1];
        }
        else if (v[i] > m2[i + 1]) {
            m1[i] = m1[i + 1];
            m2[i] = v[i];
        }
        else {
            m1[i] = m1[i + 1];
            m2[i] = m2[i + 1];
        }

    long long sol = 0;
    insert(v[1]);
    for (int i = 2; i <= n; i++) {
        sol = max(sol, getMaxXOR(v[i]) * 1LL * (m1[i] +  m2[i]));
        insert(v[i]);
    }
    cout << sol << endl;
    return 0;
}
