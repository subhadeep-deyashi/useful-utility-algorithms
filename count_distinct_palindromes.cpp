// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the count 
// of distinct palindromic sub-strings 
// of the given string s 
int palindromeSubStrs(string s) 
{ 

	// To store the positions of 
	// palindromic sub-strings 
	int dp[s.size()][s.size()]; 
	int st, end, i, j, len; 

	// Map to store the sub-strings 
	map<string, bool> m; 
	for (i = 0; i < s.size(); i++) { 

		// Sub-strings of length 1 are palindromes 
		dp[i][i] = 1; 

		// Store continuous palindromic sub-strings 
		m[string(s.begin() + i, s.begin() + i + 1)] = 1; 
	} 

	// Store palindromes of size 2 
	for (i = 0; i < s.size() - 1; i++) { 
		if (s[i] == s[i + 1]) { 
			dp[i][i + 1] = 1; 
			m[string(s.begin() + i, s.begin() + i + 2)] = 1; 
		} 

		// If str[i...(i+1)] is not a palindromic 
		// then set dp[i][i + 1] = 0 
		else { 
			dp[i][i + 1] = 0; 
		} 
	} 

	// Find palindromic sub-strings of length>=3 
	for (len = 3; len <= s.size(); len++) { 
		for (st = 0; st <= s.size() - len; st++) { 

			// End of palindromic substring 
			end = st + len - 1; 

			// If s[start] == s[end] and 
			// dp[start+1][end-1] is already palindrome 
			// then s[start....end] is also a palindrome 
			if (s[st] == s[end] && dp[st + 1][end - 1]) { 

				// Set dp[start][end] = 1 
				dp[st][end] = 1; 
				m[string(s.begin() + st, s.begin() + end + 1)] = 1; 
			} 

			// Not a palindrome 
			else
				dp[st][end] = 0; 
		} 
	} 

	// Return the count of distinct palindromes 
	return m.size(); 
} 

// Driver code 
int main() 
{ 
	string s = "abaaa"; 
	cout << palindromeSubStrs(s); 

	return 0; 
} 
