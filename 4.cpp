#include<bits/stdc++.h>
using namespace std;

int ans(char str[])
{
    int n = strlen(str);

	int m[n][n];
	memset(m, 0, sizeof(m));

	bool s[n][n];
	memset(s, false , sizeof(s));

	for (int i= 0; i< n; i++)
		s[i][i] = true;

	for (int i=0; i<n-1; i++)
	{
		if (str[i] == str[i+1])
		{
			s[i][i+1] = true;
			m[i][i+1] = 1 ;
		}
	}

	for (int x=2 ; x<n; x++)
	{
		for (int i=0; i<n-x; i++)
		{
			int j = x + i;

			if (str[i] == str[j] && s[i+1][j-1] )
				s[i][j] = true;

			if (s[i][j] == true)
				m[i][j] = m[i][j-1] + m[i+1][j] + 1 - m[i+1][j-1];
			else
				m[i][j] = m[i][j-1] + m[i+1][j] - m[i+1][j-1];
		}
	}

	return m[0][n-1]+n;
}


int main()
{
	char str[] = "aaa";
    cout << ans(str) << endl;
	return 0;
}
