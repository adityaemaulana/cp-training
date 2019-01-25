#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<char> vc;
vector<vc> grid;
vc hieroglyph{'W', 'A', 'K', 'J', 'S', 'D'};
vector<string> hextobin{"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110", "1111"};
vector<int> x{1, 0, -1, 0},  y{0, -1, 0, 1};

void fill(int i , int j, int r, int c, char ch){
    if(i < 0 || i == r || j == c || j < 0)
        return;
    if(grid[i][j] != ch)
        return;

    grid[i][j] = '.';
    for(size_t p = 0; p < x.size(); p++){
       fill(i + x[p], j + y[p], r, c, ch); 
    }
}

void fillBackground(int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(i == 0 || i == r-1 || j == 0 || j == c-1){
               fill(i, j, r, c, '0');
            }
        }
    }
}

bool searchHieroglyph(int r, int c, pair<int, int>& pos){
    bool found = false;
    int i, j;

    for(i = 0 ; i < r; i++){
        if(found) break;
        for(j = 0; j < c; j++){
            if(grid[i][j] == '1'){
                pos = make_pair(i, j);
                found = true;
                break;
            }
        }
    }
    
    return found;
}

int main(){
    int col, row, cases = 0;
    char ch;

    while(cin >> row >> col){
        cases++;

        if(!col && !row)
            break;

        grid.clear();
        grid.assign(row, vc());

        // Input
        for(int i = 0; i < row; i++){
            for(int j = 0 ; j < col; j++){
                cin >> ch;
                string val = isalpha(ch) ? hextobin[10+(ch-97)] : hextobin[ch-48];
                for(auto &x : val){
                    grid[i].push_back(x);
                }
            }
        }

        // Size of column increased because hex to binary conversion
        col *= 4;

        // Fill background for differintiating hieroglyph and background
        fillBackground(row, col);

        pair<int, int> hgPos;
        vc result;
        while(searchHieroglyph(row, col, hgPos) == true){
            int i = hgPos.first, j = hgPos.second;
            // Fill Hieroglpyh Outline
            fill(i, j, row, col, '1');
            

            // Count Hieroglyph's holes
            int count = 0;
            for(i = 0; i < row; i++){
                for(j = 0; j < col; j++){
                    if(grid[i][j] == '0' && i > 0 && i < row-1 && j > 0 && j < col-1){
                        if(grid[i-1][j] == '.' ||
                        grid[i+1][j] == '.' ||
                        grid[i][j-1] == '.' ||
                        grid[i][j+1] == '.'){
                            count++;
                            fill(i, j, row, col, '0');
                        }
                    }
                }
            }
            
            result.push_back(hieroglyph[count]);
        }
        
        sort(result.begin(), result.end());
        string stringresult(result.begin(), result.end());
        cout << "Case " << cases << ": " << stringresult << endl;
    }
}