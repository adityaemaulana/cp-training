#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    int n,r,i=0;
    string s;
    
    cin>>n>>s>>r;
    r = r % 26;
    
    while(i < s.length()){
        if(s[i]>=97 && s[i]<=122){
            n = (int) s[i] + r;
            if(n > 122) s[i] = 96 + (n - 122);
            else s[i]+=r;
        }
        
        if(s[i]>=65 && s[i]<=90){
            n = (int) s[i] + r;
            if(n > 90) s[i] = 64 + (n - 90);
            else s[i]+=r;
        }
        i++;
    }
    
    cout<<s;
}