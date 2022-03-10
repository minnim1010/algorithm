#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

string str, ans;
int isInTag = 0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    str.reserve(100000);
    ans.reserve(100000);
    getline(cin, str);

    int len = str.length();
    int begin = 0, end = 0;
    for (int i = 0; i < len; ++i) {
        if(str[i] == '<'){
            if(str[i-1] != '>'){
                end = i-1;
                for (int j = end; j >= begin; --j)
                    ans.push_back(str[j]);
            }
            isInTag = 1;
            ans.push_back(str[i]);
        }
        else if(str[i] == '>') {
            isInTag = 0;
            ans.push_back(str[i]);
        }
        else{
            if(isInTag)
                ans.push_back(str[i]);
            else{
                if(str[i] == ' ' || str[i] == '<' || i == len-1) {
                    end = i;
                    if(str[i] == ' ' || str[i] == '<')
                        end -= 1;
                    for (int j = end; j >= begin; --j)
                        ans.push_back(str[j]);
                    if(str[i] == ' ')
                        ans.push_back(' ');
                }
                else if(!i || str[i-1] == ' ' || str[i-1] == '>'){
                    begin = i;
                }
            }
        }
    }

    cout << ans;


    return 0;
}
