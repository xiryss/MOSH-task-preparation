#include <bits/stdc++.h>
#include"testlib.h"
using namespace std;
vector<int> maxns{1,100,2000,400000};
 
map<string, string> params;
 
long long get(string name, long long def = 0) {
	if (params.count(name)) {
		return stoll(params[name]);
	}
	else {
		return def;
	}
}
vector<int> par;
int fin(int v)
{
    return (v==par[v] ?v:par[v]=fin(par[v]));
}
void make(int v)
{
    par[v]=v;
}
vector<vector<int>> g;
int cntr=0;
vector<int> value;
void dfs(int v, int p) {
    value[v] = ++cntr;
    for(int i:g[v]) 
    {
        if(i!=p)
        {
            dfs(i,v);
        }
    }
}
void unite(int a, int b)
{
    a=fin(a), b=fin(b);
    if(a!=b)
    {
        par[b]=a;
    }
}

void genxy(int x, int y, vector<vector<int>> &a) {
    int w = rnd.next(1, 100000);
    a[x][y] = a[y][x] = w;
}
int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	registerGen(argc, argv, 1);
	for (int i = 1; i < argc; i++) {
		string s = string(argv[i]);
		if (s.find("=") != string::npos) {
			auto pos = s.find("=");
			params[s.substr(0, pos)] = s.substr(pos + 1);
		}
		else {
			params[s] = "";
		}
	}
	string mode = params["mode"];
	auto mem = get("zeros",-1);
	int n = get("n", -1);
	if (n == -1) {
	    n = rnd.next(1, 333) * 3;
	}
	if (mode == "random") {
	    vector<vector<int>> a(n, vector<int> (n));
	    for (int i=0 ;i< n;++i) {
	        for(int j =i + 1;j< n;++j) {
	            if(mem == 0) {
	                if(rnd.next(0,5) <= 3) {
	                    a[i][j]= a[j][i]  =0;
	                    continue;
	                }
	            }
	            a[i][j] = a[j][i] = rnd.next(0, 100'000);
	        }
	    }
	    cout<< n<< endl;
	    for (int i =0 ; i< n;++i) {
	        for(int j =0 ;j< n;++j) {
	            cout<<a[i][j];
	            if(j < n-1) {
	                cout<<' ';
	            }
	        }
	        cout<<endl;
	    }
	    return 0;
	}
    else if(mode == "triangles") {
        vector<int> perm(n);
        iota(perm.begin(), perm.end(),0);
        shuffle(perm.begin(), perm.end());
	    vector<vector<int>> a(n, vector<int> (n));
        for(int i = 0;i< n;i+=3) {
            genxy(perm[i], perm[i+1], a);
            genxy(perm[i], perm[i+2], a);
            genxy(perm[i+1], perm[i+2], a);
        }
        
	    cout<< n<< endl;
	    for (int i =0 ; i< n;++i) {
	        for(int j =0 ;j< n;++j) {
	            cout<<a[i][j];
	            if(j < n-1) {
	                cout<<' ';
	            }
	        }
	        cout<<endl;
	    }
    }
    else if(mode == "smallcomp") {
        
        vector<int> perm(n);
        iota(perm.begin(), perm.end(),0);
        shuffle(perm.begin(), perm.end());
	    vector<vector<int>> a(n, vector<int> (n));
        for(int i =0 ;i< n;) {
            int sz;
            if( i + 14 >= n-1) {
                sz = n- i;
            }
            else {
                sz = rnd.next(1,6) * 3;
            }
            for(int j =0;j< sz;++j) {
                for(int x= j+1;x<sz;++x) {
                    int w = rnd.next(1,100'001);
                    a[perm[j + i]][perm[x + i]] = w;
                    a[perm[x+i]][perm[j+i]]=w;
                }
            }
            i += sz;
        }
	    cout<< n<< endl;
	    for (int i =0 ; i< n;++i) {
	        for(int j =0 ;j< n;++j) {
	            cout<<a[i][j];
	            if(j < n-1) {
	                cout<<' ';
	            }
	        }
	        cout<<endl;
	    }
    }
    else if(mode == "bigcomp") {
        vector<int> perm(n);
        iota(perm.begin(), perm.end(),0);
        shuffle(perm.begin(), perm.end());
	    vector<vector<int>> a(n, vector<int> (n));
        for(int i =0 ;i< n;) {
            int sz;
            if( i + 40*3 - 1 >= n-1) {
                sz = n- i;
            }
            else {
                sz = rnd.next(20,40) * 3;
            }
            for(int j =0;j< sz;++j) {
                for(int x= j+1;x<sz;++x) {
                    int w = rnd.next(1,100'000);
                    a[perm[j + i]][perm[x + i]] = w;
                    a[perm[x+i]][perm[j+i]]=w;
                }
            }
            i += sz;
        }
	    cout<< n<< endl;
	    for (int i =0 ; i< n;++i) {
	        for(int j =0 ;j< n;++j) {
	            cout<<a[i][j];
	            if(j < n-1) {
	                cout<<' ';
	            }
	        }
	        cout<<endl;
	    }
    }
}
