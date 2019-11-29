Leet longestpalindrome substring:
in this we create d 2D boolean array say matrix of lenXlen where len is size of string. 
now
 matrix[i][j] = true represents there is a palindromic sequence from index j to index i 
 in the string or substring(j, i-j+1) is a palindrome where i-j+1 is its length. 

so for every case when i= j i.e. a single character string i.e.  matrix[i][i] = true;
we keep storing the length and starting index j. everytime the length of current palindrom 
exceed maxlength , starting index and maxlength are updated.
------------------------------------------------------------------------------------------------

 
