#include<iostream>
#include <stdio.h>
#include<queue>
#include <stdlib.h>
#include <bitset>

int main(){
    unsigned a = 1;

    //置1
    unsigned mask_3 = 1<<3;
    unsigned mask_6 = 1<<6; 
    a |= (mask_3 | mask_6);
    std::cout << "a (32-bit): " << std::bitset<32>(a) << std::endl;

    //置0
    unsigned mask_3_reverse = ~(1<<3);
    a &= mask_3_reverse;
    std::cout << "a (32-bit): " << std::bitset<32>(a) << std::endl;
}

