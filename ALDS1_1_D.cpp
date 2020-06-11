#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<utility>
#include<queue>
#include<map>

using namespace std;
const long long int MAX = -1000000000;

int main(){
    int n;
    cin >> n;

    vector<int> r(n);
    for(int i=0;i<n;i++){
        cin >> r[i];
    }

    int minv = r[0];
    int maxv = MAX;

    for(int j=1;j<n;j++){
        maxv = max(r[j] - minv, maxv);
        minv = min(minv, r[j]);
    }

    cout << maxv << endl;
}
