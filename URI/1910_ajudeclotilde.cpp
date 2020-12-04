#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vii vector< pair<long long,long long> >
typedef long long ll;

int O, D, K, i, V[100010];
int inter, S1, S2, S3, S4, S5;

int main(){_


    while(cin>>O>>D>>K){
        if(O==0 && D==0 && K==0)
            return 0;

        memset(V, -1,sizeof(V));

        queue<int> Q;

        for(i=0;i<K;i++){
            cin>>inter;
            V[inter]=0;
        }

        V[O]=0;
        V[0]=0;
        Q.push(O);

        while(true){
            if(Q.empty())
                break;

            inter=Q.front();
            Q.pop();

            if(inter+1<=100000 && V[inter+1]==-1)
                S1=inter+1;
            else
                S1=0;

            if(inter-1>0 && V[inter-1]==-1)
                S2=inter-1;
            else
                S2=0;

            if(inter*2<=100000 && V[inter*2]==-1)
                S3=inter*2;
            else
                S3=0;

            if(inter*3<=100000 && V[inter*3]==-1)
                S4=inter*3;
            else
                S4=0;

            if(inter%2==0 && V[inter/2]==-1)
                S5=inter/2;
            else
                S5=0;

            if(V[S1]==-1 && S1!=O){
                V[S1]=1+V[inter];
                if(S1==D)
                    break;
                Q.push(S1);
            }
            if(V[S2]==-1 && S2!=O){
                V[S2]=1+V[inter];
                if(S2==D)
                    break;
                Q.push(S2);
            }
            if(V[S3]==-1 && S3!=O){
                V[S3]=1+V[inter];
                if(S3==D)
                    break;
                Q.push(S3);
            }
            if(V[S4]==-1 && S4!=O){
                V[S4]=1+V[inter];
                if(S4==D)
                    break;
                Q.push(S4);
            }
            if(V[S5]==-1 && S5!=O){
                V[S5]=1+V[inter];
                if(S5==D)
                    break;
                Q.push(S5);
            }
        }

            cout<<V[D]<<endl;

    }



    return 0;

}
