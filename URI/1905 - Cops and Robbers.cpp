#include <iostream>
#include <cstring>
using namespace std;

int yard[6][6];

void run(int x, int y){
    if(x < 0 || x >= 5 || y < 0 || y >= 5)
        return;
    if(yard[x][y] == 1 || yard[x][y] == 2)
        return;

    yard[x][y] = 2;

    run(x + 1, y); run(x - 1, y);
    run(x, y + 1); run(x, y - 1);
}

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin.ignore();

        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                cin >> yard[j][k];

        run(0, 0);

        (yard[4][4] == 2 || yard[3][4] == 2 || yard[4][3] == 2) ? cout << "COPS\n" : cout << "ROBBERS\n"; 
    }
    return 0;
}
