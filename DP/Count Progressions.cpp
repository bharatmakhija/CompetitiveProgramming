/*

John has a sequence of numbers with him. He is interested in finding out the number of subsequences of his sequence that are arithmetic progressions.

A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. For example,
 the sequence {4,6,9} is a subsequence of {4,5,6,7,8,9} obtained after removal of elements 5,7,8. The relation of one sequence being the subsequence of another is a preorder.

Arithmetic Progression: A sequence is an arithmetic progression if the difference between consecutive elements is constant. If the initial term of arithmetic progression
 is b[1] and the common difference is D then: b[n] = b[1] + (n-1)*D

Note that empty sequence or a single element sequence are arithmetic progressions.

Input Format
The first line of the input is an integer , total number of elements in the sequence. Each of the next  lines contains a single integer representing an element of
 the sequence.
 
 Output Format

Let A be the number of subsequences that are arithmetic progressions. Print the value of A modulo 1000000009 (10^9?+?9).


*/



#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

const int N = (int) 2e5 + 10;
const int P = (int) 1e9 + 9;
int n, a[N], dp[N];

int main() {
	
	#define LOCAL
    #ifdef LOCAL
        freopen("Data.in", "r", stdin);
        freopen("Data.out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
     cout <<" P is " << P << endl;
     cout <<" N is " << N << endl;
     
    int ans = 0;  // here 1 is for the empty set and 200*n is substracted because 
	cout << " Initially ans is " << ans << endl;
    for (int d = -100; d <= 100; ++d) {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; ++i) {
            int p = a[i] - d;
            cout << "p becomes " << p << endl;
            if (1 <= p && p <= 100) 
			{
			  dp[a[i]] = (dp[a[i]] + dp[p]) % P;
			  cout << "reaches in if" << endl;
		    }
            dp[a[i]] = (dp[a[i]] + 1) % P;
        }
        
        cout << "for d == " << d << endl;
        for (int i = 1; i <= 10; ++i)
		cout << dp[i] << " ";
		cout << endl; 
        for (int i = 1; i <= 100; ++i) ans = (dp[i] + ans) % P;
        cout << "ans becomes " << ans << endl;
    }

    cout << ans - 200*n + 1;
    return 0;
}

