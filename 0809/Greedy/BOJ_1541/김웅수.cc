#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string expression;
    cin>>expression;

    vector<int> numbers;
    vector<char> operators;
    
    stringstream ss(expression);
    string temp;
    while (getline(ss, temp, '-')) 
    {
        int sum = 0;
        stringstream part(temp);
        string num;
        while (getline(part, num, '+')) 
        {
            sum += stoi(num);
        }
        numbers.push_back(sum);
    }
    
    int result = numbers[0];
    for (int i=1;i<numbers.size();i++) 
    {
        result -= numbers[i];
    }

    cout<<result<<'\n';
    
    return 0;
}

