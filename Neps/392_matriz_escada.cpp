#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
using namespace std;
typedef long long int ll;

int L, C, M[550][550], soma[505];
bool ok;

int main(){_
    cin>>L>>C;
    ok=true;
    for(int i=1;i<=L;i++){
        for(int j=1;j<=C;j++){
            cin>>M[i][j];
            soma[i]+=M[i][j];
        }
    }

    for(int i=1;i<=L;i++){
        for(int j=1;j<=C;j++){
            if(!soma[i]){
                for(int k=i+1;k<=L;k++){
                    if(soma[k]){
                        i=L;
                        j=C;
                        ok=false;
                        break;
                    }
                }
            }
        }
    }


    for(int i=1;i<=L;i++){
        for(int j=1;j<=C;j++){
            if(M[i][j]){
                for(int k=i+1;k<=L;k++){
                    for(int h=1;h<=j;h++){
                        if(M[k][h]){
                            i=L;
                            j=C;
                            k=L;
                            h=j;
                            ok=false;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }

    if(ok)
        cout<<"S"<<endl;
    else
        cout<<"N"<<endl;

    return 0;
}
