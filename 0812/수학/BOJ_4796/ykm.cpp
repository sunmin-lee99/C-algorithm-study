#include <iostream>
using namespace std;

int main(void){
    int L, P, V, i=1;
    while(true){
        cin >> L >> P >> V;
        if(L==0 && P==0 && V==0){break;}
        long long vac = (V/P)*L;
        if(V%P<L) vac+=V%P;
        else vac+=L;
        cout << "Case "<<i++<<": "<< vac <<'\n';
    }
    return 0;
}
