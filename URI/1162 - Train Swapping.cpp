#include <iostream>
using namespace std;

int main(){
    int t, n, x, temp;
    cin >> t;
    while(t--){
        cin >> n;
        int curr[n+1], def[n+1];
        for(int i = 1; i <= n; i++)
            def[i] = i;
        for(int i = 1; i <= n; i++)
            cin >> curr[i];
        
        int s = 0;
        for(int i = 1; i <= n; i++){
            if(curr[i] != def[i]){
                int idx = i;
                while(def[idx] != curr[i])
                    idx++;
                
                if(idx > i){
                    while(curr[i] != def[i]){
                        temp = def[idx];
                        def[idx] = def[idx-1];
                        def[idx-1] = temp;

                        idx--;
                        s++;
                    }
                }else{
                   while(curr[i] != def[i]){
                        temp = def[idx];
                        def[idx] = def[idx+1];
                        def[idx+1] = temp;

                        idx++;
                        s++;
                    }
                }
            }
        }

        cout << "Optimal train swapping takes " << s << " swaps.\n";
    }
}
