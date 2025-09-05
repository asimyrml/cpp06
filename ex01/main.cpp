#include "Serializer.hpp"

int main()
{
    // Dinamik Data objesi
    Data *data = new Data;
    data->name = "Asim";
    data->age = 25;

    std::cout << "Original Data:" << std::endl;
    std::cout << " Name: " << data->name << std::endl;
    std::cout << " Age : " << data->age << std::endl;

    // Serialize & Deserialize
    uintptr_t raw = Serializer::serialize(data);
    Data *restored = Serializer::deserialize(raw);

    std::cout << "\nRestored Data:" << std::endl;
    std::cout << " Name: " << restored->name << std::endl;
    std::cout << " Age : " << restored->age << std::endl;

    delete data;

    return 0;
}
