#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

// Basit bir struct, serializer'ı test etmek için kullanılacak
struct Data
{
    int age;
    std::string name;
};

class Serializer
{
private:
    // Nesne oluşturulamaz, kopyalanamaz
    Serializer();
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
    ~Serializer();

public:
    static uintptr_t serialize(Data *ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
