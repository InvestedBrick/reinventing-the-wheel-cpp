#include <iostream>
#include "dynamic_array.hpp"
#include "hashmap.hpp"

struct test{
    int x;
};
void list_test(){
    List<int> my_list;
    my_list.append(4);
    my_list.append(2);
    my_list.append(5);
    my_list.append(343);
    my_list.append(42);
    for (size_t i = 0; i < my_list.get_size(); i++){
        std::cout << my_list[i] << std::endl;
    }
    std::cout << "Size: " << my_list.get_size() << " Capacity: " << my_list.get_capacity() << std::endl;
    my_list.shrink_to_fit();
    std::cout << "Size: " << my_list.get_size() << " Capacity: " << my_list.get_capacity() << std::endl;

    my_list.pop();
    std::cout << "Size: " << my_list.get_size() << " Capacity: " << my_list.get_capacity() << std::endl;
    for (size_t i = 0; i < my_list.get_size(); i++){
        std::cout << my_list[i] << std::endl;
    }
    my_list.erase(1);
    std::cout << "--------------------" << std::endl;
    for (size_t i = 0; i < my_list.get_size(); i++){
        std::cout << my_list[i] << std::endl;
    }
}

void test_hashmap(){
    static_hashmap<std::string,int> map("",10);
    map.insert("test",3);
    std::cout << map.retrieve("test") << std::endl;
    map.insert("test",4);
    std::cout << map["test"] << std::endl;
    map.remove("test");
    std::cout << map.retrieve("test") << std::endl;
    map.insert("Hello World", 23);
    map.insert("Hello World",map.retrieve("Hello World") + 1);
    std::cout << map["Hello World"] << std::endl;
    std::cout << "Finished" << std::endl;
}


int main(void){
    
    //list_test(); 
    test_hashmap();

    return 0;
}