#include <cstdio>
using namespace std;

int main(){
   int n, c, res, step = 500, start = 1;
   int curr = step;
   
   scanf("%d %d", &n, &c);
   if(curr > n) curr = n;
   
   while(true){
       printf("%d %d\n", 1, curr);
       scanf("%d", &res);
       
       if(res){
            printf("%d\n", 2);
            for(int i = start; i <= curr; i++){
                printf("%d %d\n", 1, i);
                scanf("%d", &res);
                if(res){
                    printf("%d\n", 2);
                    printf("%d %d\n", 3, i);
                    break;  
                }
            }
            break;
       }else{
           step--;
           start=curr+1;
           curr = (curr+step > n) ? n : curr+step; 
       }
   }
}