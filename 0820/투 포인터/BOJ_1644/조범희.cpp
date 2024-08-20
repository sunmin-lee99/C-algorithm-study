#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> primeNumbers;
int prefix[1000000];

void Eratostenes(int N){
    bool check[4000001];

    memset(check, false, sizeof check);
    check[1] = true;
    for(int i = 2; i * i <= N; i++){
        if(check[i] == false){
            for(int j = i*i; j <= N; j += i){
                check[j] = true;
            }
        }
    }
    for(int i = 2; i <= N; i++){
        if(!check[i]){
            primeNumbers.push_back(i);
        }
    }
}

void makePrefix(){
    prefix[0] = 0;
    
    for(int i = 1; i <= primeNumbers.size(); i++){
        prefix[i] = primeNumbers[i - 1] + prefix[i - 1];
    }
}

int solution(int N){
    int answer = 0;
    int lo = 0; int hi = 1;
    while(hi <= primeNumbers.size()){
        int value = prefix[hi] - prefix[lo];

        if(value == N){
            answer++;
            lo++;
            hi++;
        }else if(value < N){
            hi++;
        }else if(value > N){
            lo++;    
        }
    }

    return answer;
}

int main(){
    int N; cin >> N;

    Eratostenes(N);
    makePrefix();
    cout << solution(N) << '\n';
}
