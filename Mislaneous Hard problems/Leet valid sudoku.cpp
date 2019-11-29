/*Leet is valid sudoku 

A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
----------------------------------------------------------------------------------------------------------------------------------------------------
so the solution is :

i will check weather a number repeats in a row or colum or in box , if it does return false else true. 

in sudoku of 9X9 ..

there are 9 rows indexed 0 to 8 --> used1
there are 9 cols indexed 0 to 8 -->used2
there are 9 boxes of 3*3 indexed 0 to 8 --> used3

so we will use hashmap for all these 3 . 

so if a number 5 is present in 0th row then used1[0][5] = 1. i.e. used1[currentrow][number] = 1. 
so if number again repeats this will be already 1 and we will catch that sudoku is invalid. 

similarly is for column and for block as well. 

now how will you find a block number corresponding to i and j is by using following formula:


k = i / 3 * 3 + j / 3;   // i is rownumber and j is column number.

here / and * are of same precedence. therefore first division will take place of i/3 and then the result will be multiplied with 3. 

logic is : for first 3 blocks 0 1 and 2
		   block no is decided by j/3........for blocks after that i and j both will be required. 
		   
say for 4th block , i can be 3,4,5 and j can be o ,1,2.
		   
i/3 --> it will give 1 and 1 * 3 will be 3 , j/3 will give 0. it will give 3. .. 3 is index of 4th block ..

its time complexity is o(n^2)
---------------------------------------------------------------------------------------------------------------------------------------------------------
second solution to this is using bit operations:
-------------------------------------------------
----------------------------------------------

*/

bool isValidSudoku(vector<vector<char>>& board) {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;  // k is the block number corresponding to index i and j
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
        
    }
    
bool isValidSudoku(vector<vector<char>>& board) { // bit operation solution 
    vector<short> col(9, 0);
    vector<short> block(9, 0);
    vector<short> row(9, 0);
    for (int i = 0; i < 9; i++)
     for (int j = 0; j < 9; j++) {
         if (board[i][j] != '.') {
             int idx = 1 << (board[i][j] - '0');
             if (row[i] & idx || col[j] & idx || block[i/3 * 3 + j / 3] & idx)
                return false;
            row[i] |= idx;
            col[j] |= idx;
            block[i/3 * 3 + j/3] |= idx;
         }
     }
     return true;      /// even this solution takes 12 ms while ppl have solved it in 6 ms as well. coding is mostly abt how you can efficiently eliminate the costly operations so that it works brilliantly smooth. 
  }    
  
  
