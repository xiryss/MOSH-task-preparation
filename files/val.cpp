#include <bits/stdc++.h>
#include"testlib.h"
using namespace std;
vector<int> maxns{ 1,10,20,5000, 200000,200000 };

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	registerValidation(argc, argv);
	int n = inf.readInt(1, 1000, "n");
	ensuref(n % 3==0, "n is not divisible by 3");
	vector<vector<int>> a(n, vector<int> (n));
	inf.readEoln();
    for(int i =0;i< n;++i) {
        for(int j =0;j< n;++j) {
            if(j) inf.readSpace();
            if(i==j) {
                a[i][j] = inf.readInt(0,0, "cost equal");
                continue;
            }
            a[i][j]=inf.readInt(0, 100000, "cost");
        }
        inf.readEoln();
    }
    for(int i =0;i< n;++i) {
        for(int j =0;j< n;++j) {
            ensuref(a[i][j] == a[j][i], "matrix is not symmetrical");
        }
    }
    inf.readEof();
}
