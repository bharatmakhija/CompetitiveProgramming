/*
Implement strStr().

Returns the index of the first occurrence of string needle in another string haystack, or -1 if needle is not part of haystack.

*/

int strStr(string haystack, string needle) {
    
    int hl = haystack.length();
    int nl = needle.length();    
    
    if(hl == 0 && nl == 0)
    return 0;
    
    if(nl == 0)
    return 0;
    
	if (h1 < n1) //  ex: bharat is needle, bhar is haystack, n1 = 6, h1 = 4  then no match is possible 
	return 0; 
	    
    for(int i=0; i < haystack.size() ; i++)
    {
        if(haystack[i] == needle[0]) .// if 1st char of both string match
        if( i + nl -1 < hl) //  ex: bharat is needle, abcdef is haystack, n1 = 6, h1 = 6 , when i will be at 1, both b will match now , from here we check the length if current index + len(needle) - 1--> 1 + 6 - 1 gives 6 , 6 is the last index , so if index no. 6 is present in haystack then only check else not. also if first only only didn't match none will match further.   
        {
			if(haystack[i + nl -1] == needle[nl-1]) // checking last char directly 
        	{
            	bool flag = true;
            	int k = i + 1;
            	int num = 1;
            	while(num < nl && flag)
            	{
                	if(haystack[k] != needle[num])
                	flag = false;  // in any case if it doesn't match --> stop checking!!!
                	else
                	{
                    	num++;
                    	k++;
                	}
            	}	
            
            	if(flag)  // if matches fully return the starting index i 
            	return i;
        	}
        }
        else
        return 0; 
    }
    
    return -1;
        
    }
