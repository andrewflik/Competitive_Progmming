/*
    Author - Devesh
    Problem - PRINT (SPOJ) (Harder Version of PRIME1) -> Just set the upper bound to sqrt(INT_MAX)
    Time Complexity - O((R−L+1)loglog(R)+R−−√loglogR−−√)
*/
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
// Stores Primes till sqrt(INT_MAX)
vector<bool> v(46346);
vector<int> primes;
void sieve(){
	fill(v.begin(), v.end(), true);
	// Genrate Pre-Primes
	for(int i=2; i<=46345; i++){
		if(v[i]){
			primes.push_back(i);
			for(int j=i+i; j<=46345; j+=i)
				v[j] = false;
		}
	}
}
void solve(int l, int r){
	vector<bool> p(r-l+1, true);
	for(int i: primes)
		for(ll j = max(i+i, (l+i-1)/i*i); j <= r; j+=i)
			p[j-l] = false;
	if(l == 1)
		p[0] = false;
	//for(auto x: p)
	//	cout << x << endl;
	for(int i=l, j=0; j<=r-l; i++, j++)
		if(p[j])
			cout << i << endl;
	cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	int t;
	cin >> t;
	while(t--){
		int l, r;
		cin >> l >> r;
		solve(l, r);
	}
}
