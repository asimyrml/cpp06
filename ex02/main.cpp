#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    std::srand(std::time(NULL));

    Base* obj = generate();

    identify(obj);
    identify(*obj);

    delete obj;
    return 0;
}
