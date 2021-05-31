#ifndef LAB3_HEAP_H
#define LAB3_HEAP_H
#include "ArraySequence.h"

template <class T>
class Binary_heap {
private:
    ArraySequence<T> heap;
    int size = 0;
    void set_size(int newSize){
        size = newSize;
    }
public:
    class IndexOutOfRange{};

    int get_size(){
        return size;
    }



    T Get_i(int i){
        return heap.get_i(i);
    }

    Binary_heap(){
        heap = ArraySequence<T>();
        set_size(0);
    }

    Binary_heap(const Binary_heap<T> &array){
        heap = array.heap;
        set_size(array.size);
    }



    void Insert(T item){
        heap.append(item);
        if (get_size() == 0){
            set_size(get_size() + 1);
            return;
        }

        set_size(get_size() + 1);

        int i = get_size() - 1;
        int parent = (i - 1) / 2;

        while(parent >= 0 && i > 0){
            if (heap.get_i(i) < heap.get_i(parent)){
                T temp = heap.get_i(i );
                heap.set_i(i, heap.get_i(parent));
                heap.set_i(parent, temp);
            }
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    int Search(T item){
        for (int i = 0; i < get_size(); i++) {
            if (heap.get_i(i) == item) {
                return i;
            }
        }
        return -1;
    }



    void Delete(T item){
        int i = Search(item);
        int q = 0;
        if (i != -1){
            if (i == get_size() - 1)
                q = 1;

            T temp1 = heap.get_i(i);
            heap.set_i(i, heap.get_i(get_size() - 1));
            heap.set_i(get_size() - 1, temp1);
            //heap.get_i(i) = heap.get_i(get_size() - 1);
            //heap.get_i(get_size() - 1) = temp1;
            set_size(get_size() - 1);

            if (q == 0){
                while (2 * i + 1 < get_size()) {
                    int left = 2 * i + 1;
                    int right = 2 * i + 2;
                    int j = right;

                    if (right < get_size() && heap.get_i(right) > heap.get_i(left)) {
                        j = left;
                    }

                    if (heap.get_i(i) <= heap.get_i(j)) {
                        break;
                    }
                    T temp = heap.get_i(i);
                    heap.set_i(i, heap.get_i(j));
                    heap.set_i(j, temp);
                    i = j;
                }
            }
        }

    }

    Binary_heap<T> getSubTree(T el){
        int k = this->Search(el);

        if (k != -1){
            auto newHeap = Binary_heap<T>();
            newHeap.Insert(el);

            for (int i = k + 1; i < size; i++){
                int temp = 0;

                int t = i;

                while (t >= k){
                    if (t == k){
                        temp = 1;
                        break;
                    }
                    t = (t - 1)/2;
                }



                if (temp == 1){
                    newHeap.Insert(this->heap.get_i(i));

                }
            }

            return newHeap;
        }
        else {
            auto heap111 = Binary_heap<T>();
            return heap111;
        }

    }



    int findSubTree(Binary_heap<T> heap){
        if (heap.get_size() > this->get_size())
            return 0;

        int temp1 = 0;
        for (int i = 0; i < heap.get_size(); i++){
            temp1 *= Search(heap.heap.get_i(i));
        }

        return temp1;
    }


    int getDepth(){
        int depth = 0;
        int i = size;
        if (i == 0)
            return 0;

        while (i > 0){
            i = (i- 1) / 2;
            depth++;
        }

        return depth;
    }

    int getParentsCount(int i){
        int parents = 0;
        if (i == 0)
            return 0;

        while (i > 0){
            i = (i- 1) / 2;
            parents++;
        }

        return parents;
    }


    void print_heap(Binary_heap<T> heapt){
        int depth = heapt.getDepth();
        int currdep = -2;

        for (int i = 0; i < heapt.get_size(); i++){
            int parents = heapt.getParentsCount(i);
            if (parents > currdep){
                if (currdep == -2)
                    currdep = parents;
                else{
                    std::cout << "\n";
                    currdep = parents;
                }
            }

            int temp = 1;
            for (int j = 0; j < depth - parents; j++)
                temp *= 2;

            for (int jj = 0; jj < temp; jj++)
                std::cout << "  ";

            std::cout << heapt.Get_i(i);
        }

        std::cout<< "\n";
    }

};

#endif //LAB3_HEAP_H
