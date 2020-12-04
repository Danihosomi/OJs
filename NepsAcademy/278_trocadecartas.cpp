#include <bits/stdc++.h>
using namespace std;

int main(){
    set <int> X;
    set <int> Y;
    int i, A, C, T, soma=0;

    cin>>A>>C;
    for(i=0;i<A;i++){
        cin>>T;
        X.insert(T);
    }
    for(i=0;i<C;i++){
        cin>>T;
        Y.insert(T);
    }
    T=0;
    for (set<int>::iterator it=X.begin(); it!=X.end(); ++it){
            if(Y.find(*it)==Y.end())
                soma++;
    }
    for (set<int>::iterator it=Y.begin(); it!=Y.end(); ++it){
            if(X.find(*it)==X.end())
                T++;
    }

    if(T>soma)
        cout<<soma<<endl;
    else
        cout<<T<<endl;

    return 0;

}
