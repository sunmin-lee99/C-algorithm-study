#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char Delimiter){
    istringstream iss(str);
    string buffer;

    vector<string> result;
    while(getline(iss, buffer, Delimiter)){
        result.push_back(buffer);
    }
    return result;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);

    string eq;cin >> eq;
    vector<string> eq_=split(eq,'-');
    int output=0;
    for(int i=0; i<eq_.size();i++){
        int sum=0;
        vector<string> eq__=split(eq_[i],'+');
        for(auto s:eq__){
            sum += stoi(s);
        }
        if(i==0) output=sum;
        else output-=sum;
    }
    cout <<output;
    return 0;
}
