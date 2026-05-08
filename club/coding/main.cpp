#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int ans=0;

	cin >> n;

	for (int i=1; i<=n; i++)
	{
		if (n % i == 0)
		{
			ans++;
		}
	}

	if (ans <= 2)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 2 << endl;
	}
	return (0);
}