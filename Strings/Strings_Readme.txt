toggle characters:
to toggle characters : i.e. from upper case to lowercase and viseversa
if char is in lowecase : 
then substract 'a' and add 'A' to it. 
it will internally convert it to ascii values and do it.
i.e. 
  if s[i] is lowecase
   char(s[i] + 'A' -'a') // we need to typecast this to char and then print. 
   else if uppercase
   char(s[i]-'A'+'a')
   else
   cout << s[i]  // if any other special char or number.
 ---------------------------------------------------------------------------------------------
Leet : Longest substring without repeating characters
See the file: 

-------------------------------------------------------------------------------
Remember: generally in strings common corner cases are 
1. string is null
2. string is single character. 
---------------------------------------------------------------------------------
Leet Zigzagconversion: create vector of string for seperate rows , ie each string of vector represents string of a specific row
in the end merge these together rowwise and return the ans. // this takes extra memory though but has much less timecomplexity. 
-------------------------------------------------------------------------------------

