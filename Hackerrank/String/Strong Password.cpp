#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
	int n;
	string s;
	string symbols = "!@#$%^&*()-+";
	bool check[] {false, false, false, false};
	
	cin >> n >> s;
	
	int result = 0;
	for(int i = 0; i < n; i++) {
        if(isdigit(s[i])) check[0] = true;
        if(islower(s[i])) check[1] = true;
        if(isupper(s[i])) check[2] = true;
        for(int j = 0; j < symbols.length(); j++) {
        	if(s[i] == symbols[j]) check[3] = true;
         } 
    } 
    
    for (int i = 0 ; i < 4 ; i++) {
    	if(!check[i]) {result++;} 
    } 
    
    if(n < 6){
        cout<<max(6-n, result) ;
     } 
    else cout<<result;
	return 0;
} 
