#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x) & (-x))
using namespace std;
typedef long long int ll;

int N, resp1, resp2, V[5], V1[5], X, Y;

int main(){_
    cin>>N;

    while(N--){
        X=Y=0;

        for(int i=1;i<=3;i++){
            cin>>V[i];
            if(V[i]==11)
                V[i]=12;

            else if(V[i]==12)
                V[i]=11;

            else if(V[i]<=3)
                V[i]+=13;
        }
        for(int i=1;i<=3;i++){
            cin>>V1[i];
            if(V1[i]==11)
                V1[i]=12;

            else if(V1[i]==12)
                V1[i]=11;

            else if(V1[i]<=3)
                V1[i]+=13;
        }
        for(int i=1;i<=3;i++){
            if(V[i]>=V1[i])
                X++;
            else
                Y++;
        }

        if(X>=Y)
            resp1++;
        else
            resp2++;
    }

    cout<<resp1<<" "<<resp2;

	return 0;
}

