/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
//Rule: The latest node is around tail, the earliest node is around head.
#include<unordered_map>
struct node{
    int _key ;
    int _value ;
    struct node* next = nullptr;
    struct node* prev = nullptr;
    node()=default;
     node(int key, int value):_key(key), _value(value),next(nullptr),prev(nullptr){}   
    void set_value(const int& other){_value = other;}
    // ~node()=default;
};
class LRUCache {
private:

    int _capacity;
    int _size;
    node* _head;
    node* _tail;
    std::unordered_map<int, node*> map;
public:
    LRUCache(int capacity): _capacity(capacity), _size(0){
        _head = new node();
        _tail = new node();
        _head->next = _tail;
        _tail->prev = _head;
    }   

    // ~LRUCache(){
    //     reset();
    //     delete _head;
    //     delete _tail;
    // }
    
    int get(int key) {
        if(map.count(key) == 0){
            return -1;//key not found
        }
        node* curNode = map[key];
        shiftToTail(curNode);    
        return curNode->_value;
    }
    
    void put(int key, int value) {
        if(!map.count(key)){
            node* latestCreated = new node(key,value);
            map[key]=latestCreated;
            insertAtTail(latestCreated);
            if(_size > _capacity){
               removeNextToHead();
            }
        }
        else{//key exists
            node* latestAccess = map[key];
            latestAccess->set_value(value);
            shiftToTail(latestAccess);
        }
    }

    //Equivalent to remove current node then insert at tail
    void shiftToTail(node* cur){//the latest node
        if(cur == _head || cur == _tail ||cur == nullptr){return;}
        if(cur->next == _tail){return ;}
        unlinkNode(cur);
        insertAtTail(cur);     
    }
    void removeNextToHead(){
        if(_head->next == _tail){return;}
        node* tmp = _head->next;
        unlinkNode(tmp);
        freeNode(tmp);
    }
    void unlinkNode(node* cur){
        if(cur == nullptr){return;}
        if(cur == _head || cur == _tail){return;}
        node* front = cur->prev;
        node* back  = cur->next;
        front->next = back;
        back->prev  = front;
        _size--;

    }

    void freeNode(node* cur){//only after unlinked
        map.erase(cur->_key);
        cur->prev = nullptr;
        cur->next = nullptr;
        // delete cur;
    }

    void insertAtTail(node* cur){
        if(cur == nullptr){return ;}
        node* front = _tail->prev;
        _tail->prev = cur;
        front->next = cur;
        cur->next   = _tail;
        cur->prev   = front;
        _size++;
    }

    // void reset(){
    //     map.clear();
    //     while(_head->next != _tail){
    //         removeNextToHead();
    //     }
    // }
};
