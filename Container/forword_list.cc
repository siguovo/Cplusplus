#include<iostream>
#include<forward_list>
#include<algorithm>
#include<functional>


void test01()
{
    std::forward_list<int>fl1;
    fl1.push_front(1);
    fl1.push_front(2);
    fl1.push_front(3);
    fl1.push_front(4);
    fl1.push_front(5);
    fl1.push_front(6);
    fl1.push_front(7);
    fl1.pop_front();
    std::for_each(fl1.begin(),fl1.end(),[](const int a){ std::cout << a << " ";});
    std::cout << std::endl;
    std::cout << "dm" << std::endl;
    fl1.sort();
    std::for_each(fl1.begin(),fl1.end(),[](const int a){ std::cout << a << " ";});
    std::cout << std::endl;
    fl1.push_front(2);
    fl1.insert_after(fl1.begin(),0);
    std::for_each(fl1.begin(),fl1.end(),[](const int a){ std::cout << a << " ";});
    std::cout << std::endl;
}




int main()
{
    test01();
  
    return 0;
}
