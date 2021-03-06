//
//  encryption.cpp
//  RSA
//
//  Created by shuster on 2018/6/3.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#include "bigint.h"
#include "encryption.hpp"
#include "Prime_generator.h"
using namespace std;
using namespace Dodecahedron;

unsigned long long power_module(unsigned long long x, unsigned long long power, unsigned long long mode) {
    unsigned long long temp = x;
    for (int i = 0; i < power - 1; ++i) {
        temp *= x;
        if (temp > mode) {
            temp = temp % mode;
        }
    }
    return temp;
}

void string_to_ints(string str, unsigned long long &temp, size_t len) {
    for (int i = 0; i < len; ++i) {
        temp = temp * 100 + static_cast<int>(str[i]) - 27;
    }
}

int digits(long long n) {
    int cnt = 0;
    while (n != 0) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

void shift(Bigint &x, int digits) {
    for (int i = 0; i < digits; ++i) {
        x *= 10;
    }
}

void encrpte(unsigned int e, unsigned long long n) {
    cout << "Please type in the text you want to encrpte: " << endl;
    string str;
    getline(cin, str);
    int l = digits(n) - 1;
    const  int nums = l / 2;
    Bigint C = 0;
    int length = static_cast<int>(str.length());
    while (length > 0) {
        unsigned long long temp = 0;
        if (length <= nums) {
            string_to_ints(str, temp, str.length());
            temp = power_module(temp, e, n);
            shift(C, 10);
            C += temp;
            length -= nums;
            //For debug
//            cout << str << " " << temp << " " << str.length() << endl;
//            cout << temp << endl;
        } else {
            string_to_ints(str.substr(0, nums), temp, nums);
            temp = power_module(temp, e, n);
            shift(C, 10);
            C += temp;
            str = str.substr(nums, length);
            length -= nums;
            //For debug
//            cout << str.substr(0, nums) << " " << temp << " " << nums << endl;
//            cout << temp << endl;
        }
    }
    cout << "Your encrypted code is as follows: " << endl;
    cout << C << endl;
}

void encrpte(void) {
    unsigned int e;
    unsigned long long n;
    cout << "Please type in the text you want to encrpte: " << endl;
    string str;
    getline(cin, str);
    cout << "Please type in the public keys" << endl;
    cin >> e >> n;
    int l = digits(n) - 1;
    const  int nums = l / 2;
    Bigint C = 0;
    int length = static_cast<int>(str.length());
    while (length > 0) {
        unsigned long long temp = 0;
        if (length <= nums) {
            string_to_ints(str, temp, str.length());
            temp = power_module(temp, e, n);
            shift(C, 10);
            C += temp;
            length -= nums;
            //For debug
//            cout << str << " " << temp << " " << str.length() << endl;
//            cout << temp << endl;
        } else {
            string_to_ints(str.substr(0, nums), temp, nums);
            temp = power_module(temp, e, n);
            shift(C, 10);
            C += temp;
            str = str.substr(nums, length);
            length -= nums;
            //For debug
//            cout << str.substr(0, nums) << " " << temp << " " << nums << endl;
//            cout << temp << endl;
        }
    }
    cout << "Your encrypted code is as follows: " << endl;
    cout << C << endl;
}

