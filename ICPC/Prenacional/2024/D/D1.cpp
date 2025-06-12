#include <bits/stdc++.h>
using namespace std;

#define input freopen("D.txt", "r", stdin)
#define show(x) cout << #x << " = " << x << endl
#define show2(x,y) cout << #x<<" = "<<x<<", " <<#y<<" =" <<y<< endl
#define show3(x,y,z) cout << #x<<" = "<<x<<", " <<#y<<" = " <<y<< ", " <<#z<<" = " <<z<< endl

typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main(){
   // input;
    
    lli n,x,y,res[100001];
    scanf("%d",&n);
    memset(res,-1,sizeof res);
    while (n--) {
        scanf("%d", &x);
        if(x==1){
            printf("1 complicado\n");
        }
        else{
        if(res[x]==-1){
            res[x]=1;
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    if(i!=(x/i)){
                        res[x]+=(x/i);
                    }
                    res[x] += i;
                }
            }
        }
        if(res[x]==x){
            printf("%lld perfecto\n",x);
        }
        else{
            y=x;
            x=res[x];
            if(res[x]==-1) {
                res[x]=1;
                for(int i=2;i*i<=x;i++){
                    if(x%i==0){
                        if(i!=(x/i)){
                            res[x]+=(x/i);
                        }
                        res[x] += i;
                    }
                }
            }
            if(y==res[x]){
                printf("%lld romantico",y);
                if(x>y){
                    printf(" abuntante");
                }
                printf("\n");
            }
            else {if(x>y){
                    printf("%lld abuntante\n",y);
                }
            else{
                printf("%lld complicado\n",y);
            }}
        }     
    }
    
    }
    
    return 0;
}