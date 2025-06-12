#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)

using namespace std;
typedef long long ll;
typedef multiset<int,greater<int>> ms;

int main(){
    input;
    int n,k,l;
    cin>>n;
    int a[n],b[n];

    for (int i = 0; i < n; i++)
        cin>>a[i];
    for (int i = 0; i < n; i++)
        cin>>b[i];

    cin>>k>>l;

    
    ll sumaK=0, sumaL=0;
    ms sumados, no_sumados;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++){
        sumaK+=a[i];
        pq.push(b[i]);
    }
    
    for (int i = 0; i < l; i++)
    {
        int cabeza = pq.top();
        sumaL += cabeza;
        sumados.insert(cabeza);
        pq.pop();
    }

    for (int i = 0; i < k-l; i++)
    {
        no_sumados.insert(pq.top());
        pq.pop();
    }

    ll sumaMax = sumaK+sumaL;
    
    for (int i = 0; i < k; i++)
    {
        int in = n-i-1;
        int out = k-i-1;

        sumaK+=a[in];
        sumaK-=a[out];

        //add
        ms::iterator last = next(sumados.end(),-1);
        if (b[in]>*last)
        {
            sumaL+=b[in];
            sumados.insert(b[in]);
            sumaL-=*last;
            no_sumados.insert(*last);
            sumados.erase(last);
        } else {
            no_sumados.insert(b[in]);
        }

        //remove
        last = next(sumados.end(),-1);
        ms::iterator first = no_sumados.begin();
        if (b[out]<*last)
        {
            no_sumados.erase(no_sumados.find(b[out]));
        } else {
            sumaL-=b[out];
            sumados.erase(sumados.find(b[out]));
            sumaL+=*first;
            sumados.insert(*first);
            no_sumados.erase(first);
        }
        
        sumaMax = max(sumaMax,sumaK+sumaL);
    }
    
    cout<<sumaMax<<endl;

    return 0;
}