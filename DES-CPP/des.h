#ifndef _DES_H_
#define _DES_H_

#include <string>
#include <stdint.h>

/*
* 1. Only support algorithm: DES/ECB/PKCS5Padding, compatible with java, C#.
* 2. Both src and key can be empty string.
* 3. Recommend check Decrypt failure.
* 4. basic DES algorithm from https://github.com/dhuertas/DES/blob/master/des.c
* 5. Wrappered with C++ STL and PKCS5Padding by Leo Xiao (xiaolizhimain@qq.com)
*/
class DES {
public:
    static bool Encrypt(const std::string & src, const std::string & key, std::string & out);
    static bool Decrypt(const std::string & src, const std::string & key, std::string & out);
    static std::string Encrypt(const std::string & src, const std::string & key);
    static std::string Decrypt(const std::string & src, const std::string & key);
    static uint64_t CalcDES(uint64_t input, uint64_t key, char mode);
private:
    static uint64_t ReverseBytes(uint64_t n);
    static std::string TidyKey(const std::string & src);
    static std::string AddPKCS5Padding(const std::string & src);
    static bool RemovePKCS5Padding(const std::string & src, std::string & out);
};

#endif