Pair of Amicable numbers: 
here it requires to find the sum of all the divisors of a number. to do this 
1. 1 is always the divisor so sum = 1(initialise)
2. consider all numbers from 2 to its sqareroot (i.e. sqrt(num))
3. in these numbers(say loop of i from 2 to sqrt(num)), any number if completely divides
   num i.e.(if num % i == 0 ) then include that number is a divisor.
   now another number on other side of sqareroot will also be a divisor 
   for ex: 
   for 100--> sqrt is 10
   2 is a divisor --> 100/2 = 50 is also a divisor
   4 is a divisor --> 100/4 = 25 is also a divisor
   
   so we also need to include (num/i) BUT NOT ALL num/i. 
   ex:
   
    for num = 4 --> sqrt = 2;
	
	2 is divisor and 4/2 is also a divisor which is 2 again. 
	so number get repeated. so condition to include becomes 
	
	if (num/i != i) then include num/i else not 
4. by this logic keep adding i and num/i and done!! this is also a way to find all divisors of a 
   number.

--------------------------------------------------------------------------------------------
 Leet median of 2 sorted arrays:
 create a vector of int and insert both vectors in it. 
 sort them using sort function --> sort(nums.begin(),nums.end())
 median can be a decimal value so store it in double variable. 
 double ans;
        int n = nums.size();
        if(n % 2 == 1 ) // odd
        ans = nums[(n-1)/2];
        else
        ans = double(nums[n/2] + nums[(n/2)-1])/2;
----------------------------------------------------------------------------------------------
Leet reverse Integer: 
only thing to consider is this if (res > INT_MAX/10 || res < INT_MIN/10) overflow condition
---------------------------------------------------------------------------------------------
 Leet max water container:
 in this we have vertical lines of different heights on x axis at difference of 1 on x axis. 
 ex: (0,a0) (1,a1) .. are points, there are line from these point to x axis.
we want to find container with max water possible. 

what we need: Area of container should be maximum. 
 Area  = min(height of both sides height)* horziontal_distance 
 
   |  
   |   |  for this maxwater = 2*2 = 4
   |___|
   
   |
   |   | 
   |   |    |
   |___|____|   --> 10, 12, 6 are the heights , 2, 6 are horizontal distance
                     3 containers are possible --> 10,12 will give 10*2 --> 20
													12,6 will give  6*6 --> 36
													10,6 will give 6*(2+6) --> 48 (max)
													
	point is horziontal_distance also makes a difference. we need to focus on maximizing the area.see que how to do it. 
----------------------------------------------------------------------------------------------------------------------------------
	