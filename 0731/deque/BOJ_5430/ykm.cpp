#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T,n;
    cin >> T;
    
    while(T--){
        deque<int> DQ;
        bool flag = true, error = false;
        
        string p;
        cin >> p;
        cin >> n;
        string nums;
        cin >> nums;

        int num=0;
        if(n!=0){
            for(char c:nums){
                if(c=='['){continue;}
                if('0'<c && c<='9'){
                    num *= 10;
                    num += c-'0';
                }else if(c=='0'){ // 주의
                    num*=10;
                }else{
                    DQ.push_back(num);
                    num=0;
                }
            }
        }
        
        for(int i = 0; i<p.size(); i++){
            if(p[i]=='R'){
                flag=!flag;
            }else if(p[i]=='D'){
                if(DQ.empty()){
                    cout<<"error\n";
                    error=true;
                    break;
                }
                if(flag){DQ.pop_front();}
                else{DQ.pop_back();}
            }
        }
        if(!error){
            cout << '[';
            while(!DQ.empty()){
                if(flag){
                    cout << DQ.front();
                    DQ.pop_front();
                }else{
                    cout << DQ.back();
                    DQ.pop_back();
                }
                if(!DQ.empty()){cout << ',';}
            }
            cout << "]\n";
        }
    }
}
