/*
 * @Author: FrankTudor
 * @Date: 2022-06-08 22:55:08
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * 36/36 cases passed (92 ms)
 * Your runtime beats 96.62 % of cpp submissions
 * Your memory usage beats 25.25 % of cpp submissions (57.5 MB)
 * @LastEditTime: 2022-06-09 17:56:45
 */
/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */
#include<iostream>
using namespace std;
// @lc code=start


struct Node {
    int key;
    int value;
    struct Node * next = nullptr;
    Node()=default;
    Node(int KEY, int VALUE):key(KEY), value(VALUE), next(nullptr){}
};


class MyHashMap {
public:
    MyHashMap() {
        size = 0;
        buckets = new Node[capacity];
    }
    ~MyHashMap(){
        delete [] buckets;
    }
    
    void put(int key, int value) {
        int index = key % capacity;
        Node* active_node = &buckets[index];
        while(active_node-> next != nullptr && active_node->next->key != key){//The first node is the bound
            active_node = active_node->next;
        }
        if(active_node->next != nullptr){
            active_node->next->value = value;
        }else{
            Node* node_to_add = new Node(key, value);
            active_node->next = node_to_add;
            size++;
        }
        
        if(size >= capacity * HASHMAP_LOAD_FACTOR){
            expand();
        }

    }
    
    int get(int key) {
        int index = key % capacity;
        Node* active_node = &buckets[index];

        while(active_node->next != nullptr && active_node->next->key != key){
            active_node = active_node->next;
        }   
        if(active_node->next != nullptr){
            return active_node->next->value;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % capacity;
        Node* active_node =  &buckets[index];
        
        while(active_node->next != nullptr && active_node->next->key != key){
            active_node = active_node->next;
        }
        if(active_node->next != nullptr){
            Node* node = active_node->next->next;
            delete active_node->next;
            active_node->next = node;
            size--;
        }
        
    }

    void expand(){
        int previous_capacity = capacity;
        capacity <<= 1;
        Node* old_buckets = buckets;
        Node* new_buckets = new Node[capacity];
        buckets = new_buckets;
        for(size_t i = 0; i < previous_capacity; i++){
            Node* tmp = &old_buckets[i];
            while(tmp->next != nullptr){
                put(tmp->next->key, tmp->next->value);
                tmp = tmp->next;
            }
        }
        delete [] old_buckets;
    }
    // void print(){
    //     for(int i = 0; i < capacity; i++){
    //         printf("%d)>:", i);
    //         Node* node = &buckets[i];
    //         while(node->next != nullptr){
    //             printf("<%d, %d>, ", node->next->key, node->next->value);
    //             node = node->next;
    //         }
    //         printf("\n");
    //     }
    // }
private:
    size_t capacity = 128;
    static constexpr float HASHMAP_LOAD_FACTOR = 0.5;
    Node *buckets = nullptr;
    size_t size;
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
