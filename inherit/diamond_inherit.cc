#include <iostream>
using namespace std;

class Animal{
public:
    int m_Age;
};

class Sheep : public Animal{};

class Tuo : public Animal{};

class SheepTuo : public Sheep ,public Tuo{};






int main()
{

    return 0;
}
