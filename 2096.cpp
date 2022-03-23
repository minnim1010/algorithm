#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int maxdp[3], mindp[3], dp[3];
int ar[3];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < 3; ++i) {
        cin >> maxdp[i];
        mindp[i] = maxdp[i];
    }


    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> ar[j];
        }

        dp[0] = max(maxdp[0], maxdp[1]);
        dp[1] = max(dp[0],maxdp[2]);
        dp[2] = max(maxdp[1], maxdp[2]);

        for (int j = 0; j < 3; ++j) {
            maxdp[j] = ar[j] + dp[j];
        }

        dp[0] = min(mindp[0], mindp[1]);
        dp[1] = min(dp[0],mindp[2]);
        dp[2] = min(mindp[1], mindp[2]);

        for (int j = 0; j < 3; ++j) {
            mindp[j] = ar[j] + dp[j];
        }
    }

    cout << *max_element(maxdp, maxdp+3) << ' ' << *min_element(mindp, mindp+3);

    return 0;
}
