#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <iostream>
#include <string>
#include <algorithm>

#include "des.h"
#include "base64.h"

using namespace std;

void test1() {
    uint64_t src = 123456789L;
    uint64_t key = 201806015L;

    printf("src: %lld\n%016llx\n", src, src);
    printf("key: %lld\n%016llx\n", key, key);

    uint64_t enc = DES::CalcDES(src, key, 'e');
    printf("enc: %lld\n%016llx\n", enc, enc);

    uint64_t dec = DES::CalcDES(enc, key, 'd');
    printf("dec: %lld\n%016llx\n", dec, dec);
}

void test2(const string src, const string key) {
    cout << "==========" << endl;
    string enc;
    bool ok1 = DES::Encrypt(src, key, enc);
    string enc2;
    bool ok2 = Base64::Encode(enc, enc2);
    cout << "key : " << key << endl;
    cout << "src : " << src << endl;
    cout << "enc : " << enc2 << endl;
    cout << boolalpha << "ok1 : " << ok1 << endl;
    cout << boolalpha << "ok2 : " << ok2 << endl;

    string enc3;
    bool ok3 = Base64::Decode(enc2, enc3);
    string dec;
    bool ok4 = DES::Decrypt(enc3, key, dec);
    cout << "dec : " << dec << endl;
    cout << boolalpha << "ok3 : " << ok3 << endl;
    cout << boolalpha << "ok4 : " << ok4 << endl;
    cout << "==========" << endl;
}

void test2() {
    test2(u8"infodba222244444444555込込", "Mq1ZLIqSbYxmo6QZ");
    test2(u8"infodba", "Mq1ZLIqSbYxmo6QZ");
    test2(u8"infodba222244444444555込込", "Mq1ZL");
    test2(u8"", "Mq1ZLIqSbYxmo6QZ");
    test2(u8"", "");
}

int main(int argc, const char * argv[]) {
    test1();
    test2();    
}