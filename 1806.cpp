#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long N, S, psum, psum_idx;
long long ar[100001] = {0}, ans = 100002;
int l, r;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        cin >> ar[i];
    }

    l = 0;
    r = 0;
    psum = ar[0];

    while(r < N && l <= r){
        if(psum >= S){
            psum_idx = r-l+1;
            if(psum_idx < ans)
                ans = psum_idx;
            l++;
            psum -= ar[l-1];
        }
        else{
            r++;
            psum += ar[r];
        }
    }
    
    if(ans == 100002) ans = 0;
    cout << ans;

    return 0;
}
