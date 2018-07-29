#include <bits/stdc++.h>
using namespace std;

int longest_common_subsequence(string s1, string s2) 
{
    int l1 = s1.length(), l2 = s2.length();

    // matrix c stores the char count of child string
    int c[l1 + 1][l2 + 1];
    memset(c, 0, sizeof(c));
    
    for (int i = 1; i <= l1; i++) 
    {
        for (int j = 1;j <= l2; j++) 
        {        
            if (s1[i-1] == s2[j-1]) 
                c[i][j] = c[i-1][j-1] + 1;
            
            else 
                c[i][j] = max(c[i][j-1], c[i-1][j]);
        }
    } 
    return c[l1][l2]; 
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int result = longest_common_subsequence(s1, s2);
    cout << result << "\n";
    return 0;
}
