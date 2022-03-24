#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int T, a[1001] = {0}, b[1001] = {0}, m, n;
int cal = 0;

unsigned long long ans = 0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<int> va, vb;
    va.reserve(n);
    vb.reserve(m);

    for (int i = 0; i < n; ++i) {
        cal = 0;
        for (int j = i; j < n; ++j) {
            cal += a[j];
            va.push_back(cal);
        }
    }

    for (int i = 0; i < m; ++i) {
        cal = 0;
        for (int j = i; j < m; ++j) {
            cal += b[j];
            vb.push_back(cal);
        }
    }

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    for (int i = 0; i < va.size(); ++i) {
        int h = upper_bound(vb.begin(), vb.end(), T-va[i]) - vb.begin();
        int l = lower_bound(vb.begin(), vb.end(), T-va[i]) - vb.begin();

        ans += h-l;
    }

    cout << ans;

    return 0;
}
