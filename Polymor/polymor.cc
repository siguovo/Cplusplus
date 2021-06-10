#include <iostream>
#include <vector>
using namespace std;


class Animal
{
public:
    //vfptr  ---->  virtual function pointer  
    virtual void speak()
    {
        cout << "Animal speak" << endl;
    }
};
class Cat : public Animal 
{
public:
    void speak()
    {
        cout << "Cat speak" << endl;
    }
};
class Dog : public Animal 
{
public:
    void speak()
    {
        cout << "Dog speak" << endl;
    }
};

void doSpeak(Animal &animal)
{
    animal.speak();
}




void test01()
{
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}

void test02()
{ 
    cout << "sizeof(Animal) = " << sizeof(Animal) << endl;
    cout << "sizeof(Cat) = " << sizeof(Cat) << endl;
//    cout << "sizeof(Dog) = " << sizeof(Dog) << endl;
    
}


int main()
{
    //test01();
    test02();

    return 0;
}



