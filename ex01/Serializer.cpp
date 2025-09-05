#include "Serializer.hpp"

// Private constructor & destructor
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &) {}
Serializer &Serializer::operator=(const Serializer &) { return *this; }
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{
    // reinterpret_cast ile pointer -> integer dönüşümü
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    // reinterpret_cast ile integer -> pointer dönüşümü
    return reinterpret_cast<Data*>(raw);
}
