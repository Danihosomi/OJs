#include <iostream>
#include <algorithm>
using namespace std;

struct pais{
    int id, o, p, b;
};

int medalha(pais a, pais d){
            if(a.o!=d.o)
            return a.o>d.o;
            if(a.p!=d.p)
            return a.p>d.p;
            if(a.b!=d.b)
            return a.b>d.b;

            return a.id<d.id;
}




int main(){
    int N, M, i, K, E, J;
    pais V[150];
    cin>>N>>M;

    for(i=1;i<=N;i++){
        V[i].id=i;
        V[i].o=V[i].p=V[i].b=0;
    }

    for(i=0;i<M;i++){
        cin>>K>>E>>J;
        V[K].o++;
        V[E].p++;
        V[J].b++;
    }

    sort(V+1,V+N+1, medalha);

    for(i=1;i<=N;i++){
        cout<<V[i].id<<" ";
    }

    cout<<endl;


	return 0;
}
