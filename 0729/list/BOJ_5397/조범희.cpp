#include <iostream>
#include <list>
using namespace std;

int main(){    
    int T; cin >> T;


    for(int t = 0; t < T; t++){
        list<char> keys;
        list<char>::iterator iter = keys.begin();

        string tmp; cin >> tmp;

        for(char a : tmp){
            if(a == '<'){
                if(iter != keys.begin()){
                    iter--;
                }
            }else if(a == '>'){
                if(iter != keys.end()){
                    iter++;
                }
            }else if (a == '-') {
                if(iter != keys.begin()){
                    iter = keys.erase(--iter);
                }
            }else{
                keys.insert(iter, a);
            }
        }
        for(char a : keys){
            cout << a;
        }
    cout << '\n';
    }
}
