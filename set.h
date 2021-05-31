
#ifndef LAB3_SET_H
#define LAB3_SET_H
#include "binary_tree.h"

template<class T>
class Set {
private:
    Binary_tree<T> set;
public:

    Set(){
        set = Binary_tree<T>();
    }

    Set(const Set &others){
        set = Binary_tree<T>(others.set);
    }

    Set<T> search(T el){
        auto newSet = Set<T>();
        newSet.set.get_head() = this->set.search(el);
        return newSet;
    }


    void Insert(T el){
        set.Insert(el);
    }

    void Delete(T el){
        set.Delete(el);
    }

    void map(T k){
        set.In_order_map(set.get_head(), k);
    }

    T reduce(T k){
        T res = set.In_order_reduce(set.get_head(), k);
        return res;
    }

    Set<T> where(){
        auto newSet = Set<T>();
        newSet.set.get_head() = this->set.Where_Pre_O();
        return newSet;
    }

    Set<T> getSubSet(T el){
        auto newSet = Set<T>();
        newSet.set.get_head() = this->set.get_subtree(el);
        return newSet;
    }
};
#endif //LAB3_SET_H
