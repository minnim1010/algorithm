#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, C;
unsigned long long x[200000];
unsigned long long ans = 0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    sort(x, x+N);

    unsigned long long left = 1, right = x[N-1];

    while (left <= right){
        int cnt = 1;
        int idx = 0;
        unsigned long long mid = (left+right)/2;
        for (int i = 0; i < N; ++i) {
            unsigned long long gap = x[i]-x[idx];
            if(gap >= mid){
                cnt++;
                idx = i;
            }
        }
        if(cnt < C){
            right = mid-1;
        }
        else {
            ans = mid;
            left = mid+1;
        }
    }

    cout << ans;

    return 0;
}
