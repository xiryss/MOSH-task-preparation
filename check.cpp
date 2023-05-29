#include <bits/stdc++.h>
#include"testlib.h"
using namespace std;
vector<vector<int>> a;
 
map<string, string> params;
 
long long get(string name, long long def = 0) {
	if (params.count(name)) {
		return stoll(params[name]);
	}
	else {
		return def;
	}
}
int n;
long long checkAns(InStream &stream) 
{
    vector<vector<int>> triples;
    map<int,int> cnt;
    for(int i=0; i< n/3;++i) {
        triples.push_back(vector<int> (3));
        for(int j=0;j< 3;++j) {
            triples[i][j] = stream.readInt(1, n, "vertex");
        }
    }
    for(auto i :triples) for(int j:i) ++cnt[j];
    for(int i=1;i<=n;++i) {
        if(cnt[i] != 1) {
            quitf(_wa, "some triples are incorrect");
        }
    }
    long long sum = 0;
    for (auto i : triples) {
        long long prod = 1;
        for(int j=0;j<3;++j) {
            prod *= a[i[j] - 1][i[(j+1) % 3] - 1];
        }
        sum += prod;
    }
    return sum;
    int t= stream.readInt(0,n-1,"t");
    
    return t;
}
double score(long long jury, long long participant) {
    double tmp = (double)participant / jury;
    return 10*tmp *tmp * tmp;
}
int main(int argc, char* argv[]) {
    setName("checking optimal partition");
 
    registerTestlibCmd(argc, argv);
    n = inf.readInt();
    a.resize(n, vector<int> (n));
    for(int i = 0 ;i< n;++i) {
        for(int j =0; j< n;++j) {
            a[i][j] = inf.readInt();
        }
    }
    long long t_ans = checkAns(ans);
    long long t_out = checkAns(ouf);
    if(t_ans < t_out) 
    {
        quitp(10, "Jury's answer is worse, %lld, while participant has %lld", t_ans, t_out);
//        quitf(_fail,"Jury's answer is not optimal: %d operations, participant can do in %d", t_ans, t_out);
    }
    else if(t_out <= t_ans) 
    {
        quitp(score(t_ans, t_out), "Participant's answer is worse, %lld, while jury can do in %lld", t_out, t_ans);
//        quitf(_wa,"Participant's answer is not optimal: %d operations, jury can do in %d", t_out, t_ans);
    }
    else 
    {
         quitf(_ok, "answer is correct");
    }
 
}
