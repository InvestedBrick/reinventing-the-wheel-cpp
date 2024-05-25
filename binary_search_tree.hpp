#pragma once
#include <stdexcept>
#include "dynamic_array.hpp"
struct node{
    int data;
    node* left;
    node* right;
};
class BST{
private:

    node* root;

    node* make_node(int data) {
        node* new_node = new node();
        new_node->data = data;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node;
    }

    node* get_parent(node* child){
        if(root == nullptr){
            throw std::runtime_error("No Root found");
            return nullptr;
        }
        if(child == nullptr || child == root){
            throw std::runtime_error("Invalid Child");
            return nullptr;
        }
        
        node* current_node = root;
        while(current_node != nullptr){
            if(current_node->left == child|| current_node->right == child){
                return current_node;
            }else{
                current_node = child->data < current_node->data ? current_node->left : current_node->right;
            }
        }
        return nullptr;
    }

    int get_smallest_key(node* ptr){
        if(root == nullptr){
            throw std::runtime_error("No Root found");
        }

        while(ptr->left != nullptr){
            ptr = ptr->left;
        }
        return ptr->data;
    }

    
public:
    
    void remove_subtree(node* ptr){
        if(ptr == nullptr){
            return;
        }

        if(ptr != root){
            node* parent = get_parent(ptr);
            if(parent != nullptr){
                if (parent->left == ptr) {
                    parent->left = nullptr;
                } else if (parent->right == ptr) {
                    parent->right = nullptr;
                }
            }
        }

        List<node*> nodes;
        nodes.append(ptr);
        while(!nodes.empty()){
            node* current_node = nodes.pop();
            
            if(current_node->left != nullptr){
                nodes.append(current_node->left);
            }
            if(current_node->right != nullptr){
                nodes.append(current_node->right);
            }
            delete current_node;
            
        }
    }
    void remove_subtree(int data){
        remove_subtree(this->get_node(data));
    }
    BST(){
        root = nullptr;
    }
    ~BST(){
        remove_subtree(root);
        root = nullptr;
    }
    void add_node(int data) {
        std::cout << data << std::endl;
        if (root == nullptr) {
            root = make_node(data);
            //std::cout << "Made Root Node " << data << std::endl; 
            return;
        }

        node* current_node = root;
        //std::cout << "Node " << data << " wants to be created" << std::endl;

        while (true) { 
            if (data < current_node->data) {
                if (current_node->left == nullptr) {
                    current_node->left = make_node(data);
                    //std::cout << "Node " << data << " was created as a left child of Node " << current_node->data<< std::endl;
                    break;
                } else {
                    current_node = current_node->left;

                }
            } else if (data > current_node->data) {
                if (current_node->right == nullptr) {
                    current_node->right = make_node(data);
                    //std::cout << "Node " << data << " was created as a right child of Node " << current_node->data<< std::endl;
                    break;
                } else {
                    current_node = current_node->right;
                }
            } else {
                break;
                //std::cout << "Node " << data << "already existed "<< std::endl;
            }
        }
    }

    node* get_node(int data){
        if(root == nullptr){
            throw std::runtime_error("No Root found");
            return nullptr;
        }

        node* current_node = root;

        while(current_node != nullptr){
            if(data < current_node->data){
                current_node = current_node->left;
            }
            else if(data > current_node->data){
                current_node = current_node->right;
            }
            else{
                return current_node;
            }
        }
        return nullptr; 
    }


    List<int> get_elements_in_order(){
        if(root == nullptr){
            throw std::runtime_error("No Root found");
        }
        List<int> list;
        List<node*> node_stack;
        node* current_node = root;

        while(current_node != nullptr || !node_stack.empty()){
            while(current_node != nullptr){
                node_stack.append(current_node);
                current_node = current_node->left;
            }            
            current_node = node_stack.pop();
            list.append(current_node->data);
            current_node = current_node->right;
        }
        return list;

    }

    void remove_node(node* ptr){
        if(root == nullptr){
            throw std::runtime_error("No Root found");
            return;
        }
        std::cout << "Node " << ptr->data << " wants to get destroyed" << std::endl;
        if(ptr->left == nullptr && ptr->right == nullptr){
            node* parent = get_parent(ptr);
            if(parent != nullptr) {
                if(parent->left == ptr) {
                    parent->left = nullptr;
                } else if(parent->right == ptr) {
                    parent->right = nullptr;
                }
            }else{
                root = nullptr;
            }
            std::cout << "Node " << ptr->data << " has parent node " << parent->data << std::endl;
            std::cout << "Node " << ptr->data << " has no children and gets destroyed" << std::endl;
            delete ptr;
        }
        else if((ptr->left == nullptr && ptr->right != nullptr) || (ptr->left != nullptr && ptr->right == nullptr)){
            node* child = ptr->left == nullptr ? ptr->right : ptr->left;
            node* parent = get_parent(ptr);
            if(parent != nullptr) {
                if(parent->left == ptr) {
                    parent->left = child;
                } else if(parent->right == ptr) {
                    parent->right = child;
                }
            } else {
                root = child;
            }
            delete ptr;
        }
        else if(ptr->left != nullptr && ptr->right != nullptr){
            int smallest_key = get_smallest_key(ptr->right);
            node* to_be_deleted = get_node(smallest_key);
            ptr->data = smallest_key;
            remove_node(to_be_deleted);
        }
    }

    void remove_node(int data){
        remove_node(this->get_node(data));
    }


};

