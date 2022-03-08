#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int T, len;
string str;

bool isPalindrome(int len, string str){
    stack<char> st;
    bool flag = true;

    for (int j = 0; j < len/2; ++j) {
        st.push(str[j]);
    }
    for (int j = len-len/2; j < len; ++j) {
        if(!st.empty() && st.top() == str[j])
            st.pop();
        else {
            flag = false;
            break;
        }
    }

    return flag;
}

bool isPseudoPalindrome(int len, string str){
    stack<char> st1, st2;
    string revstr(str.rbegin(), str.rend());

    for (int j = 0; j < len/2; ++j) {
        st1.push(str[j]);
        st2.push(revstr[j]);
    }

    int diffChar = 0;
    for (int j = (len-1)/2; j < len; ++j) {
        if(!st1.empty() && st1.top() == str[j])
            st1.pop();
        else if(st1.empty()){
            if(j == len-1 && !diffChar) return true;
        }
        else if(!diffChar)
            diffChar++;
        else{
            diffChar++;
            break;
        }
    }
    if(diffChar == 1) return true;


    diffChar = 0;
    for (int j = (len-1)/2; j < len; ++j) {
        if(!st2.empty() && st2.top() == revstr[j])
            st2.pop();
        else if(st2.empty()){
            if(j == len-1 && !diffChar) return true;
        }
        else if(!diffChar)
            diffChar++;
        else {
            diffChar++;
            break;
        }
    }

    return diffChar==1;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; ++i) {
        stack<char> st, extra;
        cin >> str;
        len = str.length();

        if(isPalindrome(len, str))
            cout << "0\n";
        else if(isPseudoPalindrome(len, str))
            cout << "1\n";
        else
            cout << "2\n";
    }

    return 0;
}
