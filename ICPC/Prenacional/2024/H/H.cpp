#include <bits/stdc++.h>
using namespace std;
#define LIMIT_TO_READ 100000
#define input freopen("H.txt", "r", stdin)

typedef long long int lli;

int main(){
    // input;
    char mountainArray[LIMIT_TO_READ];
    scanf("%s",mountainArray);

    lli sum = 0;
    lli biggerNum = -1;
    lli biggerNumPosition = 0;
    for(lli i = 0; i<LIMIT_TO_READ; i++){
        if(mountainArray[i] == '+'){
            sum++;
        }else{
            sum--;
        }
        if(sum>biggerNum){
            biggerNum = sum;
            biggerNumPosition = i + 1;
        }
    }
    printf("%lld\n", biggerNumPosition);
    return 0;
}
