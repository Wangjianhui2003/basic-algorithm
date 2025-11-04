#include<iostream>
#include<numeric>
using namespace std;

// 辗转相除法
int gcd1(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(int argc, char const *argv[]){
    cout<<gcd1(2117,3139)<<endl;
}


int gcd2(int a,int b){
    while(b != 0){
        int temp = b;
        b = b % a;
        a = temp;
    }
    return a;
}
