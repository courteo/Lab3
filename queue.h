#ifndef LAB3_QUEUE_H
#define LAB3_QUEUE_H
#include "binary_tree.h"


template <class T>
class Queue {
private:
    Binary_tree<T> queue;
public:
    Queue(){
        queue = Binary_tree<T>();
    }

    Queue(const queue &others){
        queue = Binary_tree<T>(others.queue);
    }

    Queue<T> search(T el){
        auto newqueue = Queue<T>();
        newqueue.queue.get_head() = this->queue.search(el);
        return newqueue;
    }


    void Insert(T el){
        queue.Insert(el);
    }

    void Delete(T el){
        queue.Delete(el);
    }

    void map(T k){
        queue.In_order_map(queue.get_head(), k);
    }

    T reduce(T k){
        T res = queue.In_order_reduce(queue.get_head(), k);
        return res;
    }

    Queue<T> where(){
        queue = queue.Where_Pre_O();
        return this;
    }

    Queue<T> getSubQueue(T el){
        auto newqueue = queue<T>();
        newqueue.queue.get_head() = this->queue.get_subtree(el);
        return newqueue;
    }
};


#endif //LAB3_QUEUE_H
