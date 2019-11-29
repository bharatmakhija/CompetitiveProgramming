First lets understand how bit manipulation work. 
or you need to understand how binary value changes as decimal value changes.

for ex: (Decimal) --> (Binary)
			3			011	
			6			0110
			12			01100
			24			011000 

As you can see as we multiply decimal value by two a 0 gets added at the end of binary.In other words i can say binary value "011" keeps shifting to left adding 0's on 
its right side. this is called left shift operation. 
similary if you keep diving by 2, it keeps shifting to right. called rightshift operation. 
----------------------------------------------------------------------------------------------
there can be two reasons for integer overflow::
 two cases may cause overflow:

divisor = 0;
dividend = INT_MIN and divisor = -1 (because abs(INT_MIN) = INT_MAX + 1)
---------------------------------------------------------------------------------------------------