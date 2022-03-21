#include <iostream>
#include <cmath>

using namespace std;

long long X, Y, l, r, mid, wr, nwr, ans = 0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X >> Y;

    wr = Y*100 / X;

    l = 1;
    r = X;

    if(wr >= 99){
        cout << -1;
    }
    else{
        while(l <= r){
            mid = (l+r)/2;

            nwr = (Y+mid)*100 / (X + mid);
            if(nwr < wr+1) {
                l = mid+1;
            } else{
                ans = mid;
                r = mid-1;
            }
        }

        cout << ans;
    }
    return 0;
}
