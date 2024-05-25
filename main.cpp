#include <iostream>
#include "dynamic_array.hpp"
#include "hashmap.hpp"
#include "queue.hpp"
#include "binary_search_tree.hpp"

void test_list(){
    std::cout << "LIST TEST START" << std::endl;
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
    std::cout << "LIST TEST END" << std::endl;
}

void test_hashmap(){
    std::cout << "HASHMAP TEST START" << std::endl;
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
    std::cout << "HASHMAP TEST END" << std::endl;
}

void test_queue(){
    std::cout << "QUEUE TEST START" << std::endl;
    Queue<int> my_queue;
    my_queue.push_back(3);
    my_queue.push_back(6);
    my_queue.push_back(34);
    my_queue.push_back(11);

    std::cout << my_queue.back() << std::endl << my_queue.front() << std::endl;
    std::cout << my_queue.pop_front() << std::endl;

    std::cout << "Size: " << my_queue.get_size() << " Capacity: " << my_queue.get_capacity() << std::endl;
    
    std::cout << my_queue.front() << std::endl;
    std::cout << "QUEUE TEST END" << std::endl;
}

void test_bst(){
    std::cout << "BINRARY SEARCH TREE TEST START" << std::endl;
    BST tree;
    tree.add_node(12); //               12
    tree.add_node(4);  //              /   |
    tree.add_node(3);  //            4      19         (cant use backslash bc it comments out next line)
    tree.add_node(11); //           /  |   
    tree.add_node(19); //         3    11  


    

    auto lst = tree.get_elements_in_order();
    for(size_t i = 0; i < lst.get_size(); i++){
        std::cout << lst[i] << " " << std::endl;
    }
    tree.remove_node(4);
    node* node = tree.get_node(12);
    std::cout << "Node " << node->data << std::endl;
    if(node->left == nullptr){
        std::cout << "LEFT : NULL" << std::endl;
    }else{
        std::cout << "LEFT : " << node->left->data << std::endl;
    }

    if(node->right == nullptr){
        std::cout << "RIGHT : NULL" << std::endl;
    }else{
        std::cout << "RIGHT : " << node->right->data << std::endl;
    }
    std::cout << "--------------------" << std::endl;
    auto list = tree.get_elements_in_order();
    for(size_t i = 0; i < list.get_size(); i++){
        std::cout << list[i] << " " << std::endl;
    }
 
    std::cout << "BINRARY SEARCH TREE TEST END" << std::endl;
}
int main(void){
    
    test_list(); 
    test_hashmap();
    test_queue();
    test_bst();
    return 0;
}