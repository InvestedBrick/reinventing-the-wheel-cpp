#include <iostream>
#include "dynamic_array.hpp"

void list_test(List<int> my_list){
    
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
}

int main(void){
    List<int> my_list;
    list_test(my_list);
    return 0;
}