#include "iostream"
#include "ArraySequence.h"
#include "heap.h"
#include "binary_tree.h"
#include "complex"
#include "tests.h"

#ifndef DAR_H_INTERFACE_H
#define DAR_H_INTERFACE_H

bool operator < (const std::complex<int> &num1, const std::complex<int> &num2) {
    return num1.imag()*num1.imag() + num1.real()*num1.imag() <
            num2.imag()*num2.imag() + num2.real()*num2.imag();
}

bool operator > (const std::complex<int> &num1, const std::complex<int> &num2) {
    return num1.imag()*num1.imag() + num1.real()*num1.imag() >
           num2.imag()*num2.imag() + num2.real()*num2.imag();
}

bool operator <= (const std::complex<int> &num1, const std::complex<int> &num2) {
    return num1.imag()*num1.imag() + num1.real()*num1.imag() <=
           num2.imag()*num2.imag() + num2.real()*num2.imag();
}

bool operator >= (const std::complex<int> &num1, const std::complex<int> &num2) {
    return num1.imag()*num1.imag() + num1.real()*num1.imag() >=
           num2.imag()*num2.imag() + num2.real()*num2.imag();
}

void deleteBinaryTree(int item, ArraySequence<Binary_tree<int>> *BTInt,
                      ArraySequence<Binary_tree<double>> *BTDouble, ArraySequence<Binary_tree<std::complex<int>>> *BTComp);

template<class T>
void deleteTypeBinaryTree(ArraySequence<Binary_tree<T>> *BT);

void testFunc();

void printBinaryTree(int item, ArraySequence<Binary_tree<int>> BTInt,
              ArraySequence<Binary_tree<double>> BTDouble, ArraySequence<Binary_tree<std::complex<int>>> BTComp);

template<class T>
void printTypeBinaryTree(ArraySequence<Binary_tree<T>> *BT);


void printArr(int item, Binary_tree<int> BTInt,
              Binary_tree<double> BTDouble, Binary_tree<std::complex<int>> BTComp);

template<class T>
void printTypeArr(Binary_tree<T> BT);


void readBinaryTree(int item, ArraySequence<Binary_tree<int>> *BTInt,
                    ArraySequence<Binary_tree<double>> *BTDouble, ArraySequence<Binary_tree<std::complex<int>>> *BTComp);
template<class T>
Binary_tree<T> readTypeBinaryTree(int count);

void OperationWithBinaryTree(int item, ArraySequence<Binary_tree<int>> *BTInt,
                             ArraySequence<Binary_tree<double>> *BTDouble, ArraySequence<Binary_tree<std::complex<int>>> *BTComp);
template<class T>
void OperationWithTypeBinaryTree(ArraySequence<Binary_tree<T>> *BTs);




void deleteBinaryHeap(int item, ArraySequence<Binary_heap<int>> *BHInt,
                      ArraySequence<Binary_heap<double>> *BHDouble, ArraySequence<Binary_heap<std::complex<int>>> *BHComp);

template<class T>
void deleteTypeBinaryHeap(ArraySequence<Binary_heap<T>> *BH);

//void testFunc();

void printBinaryHeap(int item, ArraySequence<Binary_heap<int>> BHInt,
                     ArraySequence<Binary_heap<double>> BHDouble, ArraySequence<Binary_heap<std::complex<int>>> BHComp);

template<class T>
void printTypeBinaryHeap(ArraySequence<Binary_heap<T>> *BH);


void printArrH(int item, Binary_heap<int> BHInt,
              Binary_heap<double> BHDouble, Binary_heap<std::complex<int>> BHComp);

template<class T>
void printTypeArrH(Binary_heap<T> BH);


void readBinaryHeap(int item, ArraySequence<Binary_heap<int>> *BHInt,
                    ArraySequence<Binary_heap<double>> *BHDouble, ArraySequence<Binary_heap<std::complex<int>>> *BHComp);
template<class T>
Binary_heap<T> readTypeBinaryHeap(int count);


void OperationWithBinaryHeap(int item, ArraySequence<Binary_heap<int>> *BHInt,
                             ArraySequence<Binary_heap<double>> *BHDouble, ArraySequence<Binary_heap<std::complex<int>>> *BHComp);
template<class T>
void OperationWithTypeBinaryHeap(ArraySequence<Binary_heap<T>> *BHs);

int get_type();




int get_int() {
    int a;
    std::cin >> a;
    return a;
}
int get_int(int up) {
    int a;
    std::cin >> a;
    if (a > up) {
        std::cout << "Число вне диапозона. Повторите попытку\n";
        return get_int(up);
    }
    return a;
}

int get_int(int down, int up) {
    int a;
    std::cin >> a;
    if (a > up || a < down) {
        std::cout << "Число вне диапозона. Повторите попытку\n";
        return get_int(down, up);
    }
    return a;
}

double get_double() {
    double a;
    std::cin >> a;
    return a;
}

std::complex<int> get_complex() {
    int real = get_int();
    int imag = get_int();
    std::complex<int> a(real, imag);
    return a;
}

std::ostream& operator << (std::ostream& cout, std::complex<int> num) {
    if (num.imag() == 0) return cout << num.real();

    if (num.real() != 0) {
        cout << num.real();
    }

    if (num.imag() > 0) {
        if (num.real() != 0)
            cout << '+';
        if (num.imag() != 1)
            cout << num.imag();
        return cout << 'i';
    }
    else {
        if (num.imag() == -1)
            return cout << "-i";
        return cout << num.imag() << 'i';
    }
}

void interface(){
    ArraySequence<Binary_tree<int>> BTInt;
    ArraySequence<Binary_tree<double>> BTDouble;
    ArraySequence<Binary_tree<std::complex<int>>> BTComp;

    ArraySequence<Binary_heap<int>> BHInt;
    ArraySequence<Binary_heap<double>> BHDouble;
    ArraySequence<Binary_heap<std::complex<int>>> BHComp;
    int item;
    while (true) {
        std::cout << "Choose type:\n"
                  << "\t1 - binary tree\n"
                  << "\t2 - binary heap\n"
                  << "\t0 - exit\n";
        int item0 = get_int(0, 6);
        if (item0 == 0) break;

        if (item0 == 1){
            std::cout << "Choose option:\n"
                      << "\t1 - enter binary tree\n"
                      << "\t2 - choose operation\n"
                      << "\t3 - print all trees\n"
                      << "\t4 - print tree[i]\n"
                      << "\t5 - tests\n"
                      << "\t6 - delete\n"
                      << "\t0 - exit\n";
            item = get_int(0, 6);
            if (item == 0) break;

            int item2 = get_type();
            switch (item) {
                case 1:
                    readBinaryTree(item2, &BTInt, &BTDouble,&BTComp);
                    break;

                case 2:
                    OperationWithBinaryTree(item2, &BTInt, &BTDouble, &BTComp);
                    break;

                case 3:
                    printBinaryTree(item2, BTInt, BTDouble, BTComp);
                    break;
                case 4: {
                    int item3;
                    std::cout << "Enter number of trees\n";
                    if (item2 == 1)
                        item3 =get_int(0, BTInt.get_len());
                    else
                    if (item2 == 2)
                        item3 =get_int(0, BTDouble.get_len());
                    else  item3 =get_int(0, BTComp.get_len());

                    Binary_tree<int> BTInt1;
                    Binary_tree<double> BTDouble1;
                    Binary_tree<std::complex<int>> BTComp1;
                    if (BTInt.get_len() <= item3)
                        if (BTInt.get_len() > 0)
                            BTInt1 = BTInt.get_i(BTInt.get_len() - 1);
                        else
                            BTInt1 = Binary_tree<int>();
                    else
                        BTInt1 = BTInt.get_i(item3);


                    if (BTDouble.get_len() <= item3)
                        if (BTDouble.get_len() > 0)
                            BTDouble1 = BTDouble.get_i(BTDouble.get_len() - 1);
                        else
                            BTDouble1 = Binary_tree<double>();
                    else
                        BTDouble1 = BTDouble.get_i(item3);

                    if (BTComp.get_len() <= item3)
                        if (BTComp.get_len() > 0)
                            BTComp1 = BTComp.get_i(BTComp.get_len() - 1);
                        else
                            BTComp1 = Binary_tree<std::complex<int>>();
                    else
                        BTComp1 = BTComp.get_i(item3);

                    printArr(item2, BTInt1, BTDouble1, BTComp1);
                    break;
                }
                case 5:
                    testFunc();
                    break;
                case 6:
                    deleteBinaryTree(item2, &BTInt, &BTDouble,&BTComp);
                    break;
            }
        }
        else {
            std::cout << "Choose option:\n"
                      << "\t1 - enter binary heap\n"
                      << "\t2 - choose operation\n"
                      << "\t3 - print all heaps\n"
                      << "\t4 - print heap[i]\n"
                      << "\t5 - tests\n"
                      << "\t6 - delete\n"
                      << "\t0 - exit\n";
            item = get_int(0, 6);
            if (item == 0) break;

            int item2 = get_type();
            switch (item) {
                case 1:
                    readBinaryHeap(item2, &BHInt, &BHDouble,&BHComp);
                    break;

                case 2:
                    OperationWithBinaryHeap(item2, &BHInt, &BHDouble, &BHComp);
                    break;

                case 3:
                    printBinaryHeap(item2, BHInt, BHDouble, BHComp);
                    break;
                case 4: {
                    int item3;
                    std::cout << "Enter number of heaps\n";
                    if (item2 == 1)
                        item3 =get_int(0, BHInt.get_len());
                    else
                    if (item2 == 2)
                        item3 =get_int(0, BHDouble.get_len());
                    else  item3 =get_int(0, BHComp.get_len());

                    Binary_heap<int> BHInt1;
                    Binary_heap<double> BHDouble1;
                    Binary_heap<std::complex<int>> BHComp1;
                    if (BHInt.get_len() <= item3)
                        if (BHInt.get_len() > 0)
                            BHInt1 = BHInt.get_i(BHInt.get_len() - 1);
                        else
                            BHInt1 = Binary_heap<int>();
                    else
                        BHInt1 = BHInt.get_i(item3);


                    if (BHDouble.get_len() <= item3)
                        if (BHDouble.get_len() > 0)
                            BHDouble1 = BHDouble.get_i(BHDouble.get_len() - 1);
                        else
                            BHDouble1 = Binary_heap<double>();
                    else
                        BHDouble1 = BHDouble.get_i(item3);

                    if (BHComp.get_len() <= item3)
                        if (BHComp.get_len() > 0)
                            BHComp1 = BHComp.get_i(BHComp.get_len() - 1);
                        else
                            BHComp1 = Binary_heap<std::complex<int>>();
                    else
                        BHComp1 = BHComp.get_i(item3);

                    printArrH(item2, BHInt1, BHDouble1, BHComp1);
                    break;
                }
                case 5:
                    testFunc();
                    break;
                case 6:
                    deleteBinaryTree(item2, &BTInt, &BTDouble,&BTComp);
                    break;
            }
        }

    }

}

int get_type() {
    std::cout << "Enter number to operate with certain data type: \n"
         << "\t1: int\n"
         << "\t2: double\n"
         << "\t3: complex<int>\n"
         << "\t0: exit\n"
         << ": ";
    return get_int(0, 3);
}


void readBinaryTree(int item, ArraySequence<Binary_tree<int>> *BTInt,
                    ArraySequence<Binary_tree<double>> *BTDouble, ArraySequence<Binary_tree<std::complex<int>>> *BTComp) {
    if (item == 0) return;

    std::cout << "Enter count of elements or -1 to exit: \n";
    int count;
    std::cin >> count;
    while(count < 0) {
        if (count < 0) {
            std::cout << "count can't be less than 0!\n: ";
        }
        std::cin >> count;

        if (count == -1)
            return;
    } ;

    Binary_tree<int> BTInt1;
    Binary_tree<double> BTDouble1;
    Binary_tree<std::complex<int>> BTComp1;
        switch (item) {
            case 1:
                BTInt1 = readTypeBinaryTree<int>(count);
                BTInt->append(BTInt1);
                break;
            case 2:
                BTDouble1 = readTypeBinaryTree<double>(count);
                BTDouble->append(BTDouble1);
                break;
            case 3:
                BTComp1 = readTypeBinaryTree<std::complex<int>>(count);
                BTComp->append(BTComp1);
                break;
            default:
                break;
        }
}


void OperationWithBinaryTree(int item, ArraySequence<Binary_tree<int>> *BTInt,
                             ArraySequence<Binary_tree<double>> *BTDouble, ArraySequence<Binary_tree<std::complex<int>>> *BTComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            OperationWithTypeBinaryTree<int>(BTInt);
            break;
        case 2:
            OperationWithTypeBinaryTree<double>(BTDouble);
            break;
        case 3:
            OperationWithTypeBinaryTree<std::complex<int>>(BTComp);
            break;
    }
}

template<class T>
void OperationWithTypeBinaryTree(ArraySequence<Binary_tree<T>> *BTs){
    if (BTs->get_len() == 0){
        std::cout << "Binary tree doesnt exist\n";
        return;
    }

    while (true){
        auto length = BTs->get_len();
        std::cout << "You have " << length << " binary trees\n"
                  << "\t - negative number for exit\n"
                  << "\t - index of binary tree\n"
                  << "\t - number bigger than length for print all binary trees\n";
        int item1 = get_int();
        if (item1 < 0) break;

        if (item1 >= length){
            printTypeBinaryTree(BTs);
            continue;
        }
        Binary_tree<T> BT;
        BT = BTs->get_i(item1);

        std::cout << "What operation do you want to choose:\n"
                  << "\t0: exit\n"
                  << "\t1: Insert element\n"
                  << "\t2: Search element\n"
                  << "\t3: Delete element\n"
                  << "\t4: getSubtree\n"
                  << "\t5: findsubtree\n"
                  << "\t6: balance tree\n"
                  << "\t7: Choose order\n";
        int item = get_int(0, 7);

        if (item == 0) break;

        Binary_tree<T> subtree;

        if (item >= 1 && item <= 3){
            T element;
            std::cout << "Enter element:\n";
            std::cin >> element;

            if (item == 1){
                BT.Insert(element);
            }

            if (item == 2){
                BT.search(element);
            }
             if (item == 3){
                 BT.Delete(element);
             }
                BTs->append(BT);
        }
        else if (item == 4 || item == 5){
            std::cout << "Enter head of subtree: \n";

            T el;
            std::cin >> el;

            if (item == 4){
                auto res = BT.get_subtree(el);
                BTs->append(res);
            }
            if (item == 5){
                if (BT.find_subtree(el) == 1){
                    std::cout << "subtree was found\n";
                }
                else
                    std::cout << "subtree wasn't found\n";
            }
        }
        else if (item == 6){
            BT.All_Balance();
            BTs->append(BT);
        }
        else{
            std::cout << "Choose order or -1 to exit: \n"
                      << "\t1: In-order\n"
                      << "\t2: Pre-order\n";
            int item1 = get_int(-1, 2);

            if (item1 == -1)
                return;

            if (item1 == 1){
                std::cout << "Choose operation: \n"
                          << "\t0: exit\n"
                          << "\t1: Reduce\n"
                          << "\t2: map\n"
                          << "\t3: Where\n"
                          << "\t4: concat\n";
                int item2 = get_int(0, 4);

                if (item2 == -1)
                    return;

                if (item2 == 1){
                    std::cout << BT.reduce_In_O() << "\n";
                }
                else if (item2 == 2){
                    std::cout << "Enter value\n";
                    double val;
                    std::cin >> val;
                    BT.In_order_map(BT.get_head(), val);
                    BTs->append(BT);
                }
                else if (item2 == 3){
                    auto res = BT.Where_In_O();
                    BTs->append(res);
                }
                else {
                    Binary_tree<T> tree;

                    std::cout << "Enter count of elements or -1 to exit: \n";
                    int count;
                    std::cin >> count;
                    while(count < 0) {
                        if (count < 0) {
                            std::cout << "count can't be less than 0!\n: ";
                        }
                        std::cin >> count;

                        if (count == -1)
                            return;
                    }

                    for (int i = 0; i < count; i++){
                        T el;
                        std::cin >> el;
                        tree.Insert(el);
                    }

                    BT.In_order_concat(tree.get_head());
                    BTs->append(BT);
                }

            }
            else{
                std::cout << "Choose operation: \n"
                          << "\t0: exit\n"
                          << "\t1: Reduce\n"
                          << "\t2: map\n"
                          << "\t3: Where\n"
                          << "\t4: concat\n";
                int item2 = get_int(0, 4);

                if (item2 == -1)
                    return;

                if (item2 == 1){
                    std::cout << BT.reduce_Pre_O() << "\n";
                }
                else if (item2 == 2){
                    std::cout << "Enter value\n";
                    T val;
                    std::cin >> val;
                    BT.Pre_order_map(BT.get_head(), val);
                    BTs->append(BT);
                }
                else if (item2 == 3){
                    BTs->append(BT.Where_Pre_O());
                }
                else {
                    Binary_tree<T> tree;

                    std::cout << "Enter count of elements or -1 to exit: \n";
                    int count;
                    std::cin >> count;
                    while(count < 0) {
                        if (count < 0) {
                            std::cout << "count can't be less than 0!\n: ";
                        }
                        std::cin >> count;

                        if (count == -1)
                            return;
                    }

                    for (int i = 0; i < count; i++){
                        T el;
                        std::cin >> el;
                        tree.Insert(el);
                    }

                    BT.Pre_order_concat(tree.get_head());
                    BTs->append(BT);
                }
            }

        }
    }
}

void printBinaryTree(int item, ArraySequence<Binary_tree<int>> BTInt,
              ArraySequence<Binary_tree<double>> BTDouble, ArraySequence<Binary_tree<std::complex<int>>> BTComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            printTypeBinaryTree<int>(&BTInt);
            break;
        case 2:
            printTypeBinaryTree<double>(&BTDouble);
            break;
        case 3:
            printTypeBinaryTree<std::complex<int>>(&BTComp);
            break;
    }
}


void printArr(int item, Binary_tree<int> BTInt,
              Binary_tree<double> BTDouble, Binary_tree<std::complex<int>> BTComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            printTypeArr<int>(BTInt);
            break;
        case 2:
            printTypeArr<double>(BTDouble);
            break;
        case 3:
            printTypeArr<std::complex<int>>(BTComp);
            break;
    }
}

template<class T>
void printTypeBinaryTree(ArraySequence<Binary_tree<T>> *BT){

    //BT.print_Tree(BT.get_head(), 1);

    for (int i = 0; i < BT->get_len(); i++) {
        std::cout << '(';
               BT->get_i(i).print_Tree(BT->get_i(i).get_head(), 1);
               //std::cout << polynomial->get_i(i).get_i(j) << ", ";
           std::cout << "\b\b), \n";

    }
    std::cout << "\n";

}

template<class T>
void printTypeArr(Binary_tree<T> BT){
    if (BT.get_head() != nullptr)
        BT.print_Tree(BT.get_head(), 1);
    else
        std::cout << "tree doesnt exist\n";
    /*
    for (int i = 0; i < polynomial.get_len(); i++) {
        std::cout << polynomial.get_i(i) << " ";
    }
    std::cout << "\n";
    */
}

template<class T>
Binary_tree<T> readTypeBinaryTree(int count) {
    std::cout << "Enter the elements:\n";
    auto tree = Binary_tree<T>();
    for (int i = 0; i < count; i++) {
        T item;
        std::cin >> item;

        tree.Insert(item);
    }
    return tree;
}

void deleteBinaryTree(int item, ArraySequence<Binary_tree<int>> *BTInt,
                             ArraySequence<Binary_tree<double>> *BTDouble, ArraySequence<Binary_tree<std::complex<int>>> *BTComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            deleteTypeBinaryTree<int>(BTInt);
            break;
        case 2:
            deleteTypeBinaryTree<double>(BTDouble);
            break;
        case 3:
            deleteTypeBinaryTree<std::complex<int>>(BTComp);
            break;
    }
}


template<class T>
void deleteTypeBinaryTree(ArraySequence<Binary_tree<T>> *BT){
    if (BT->get_len() == 0){
        std::cout << " tree doesnt exist\n";
        return;
    }

    while (true){
        int length = BT->get_len();
        if (length == 0){
            std::cout<< " tree doesnt exist\n";
            break;
        }

        std::cout << "You have " << length << " trees\n"
                  << "\t - negative number for exit\n"
                  << "\t - index of tree\n"
                  << "\t - number bigger than length for print all trees\n";
        int item1 = get_int();
        if (item1 < 0) break;

        if (item1 >= length){
            printTypeBinaryTree(BT);
            continue;
        }

        std::cout << "Choose operation:\n"
                  << "\t-1:  return to choosing index\n"
                  << "\t0: delete\n";

        int item2 = get_int(-1,0);

        if (item2 == -1) continue;

        if (item2 == 0){
            std::cout << "Do you really want to delete BT[" << item1 <<"]?"
                      << "\t0 - no\n"
                      << "\t1 - yes\n";
            int item3 = get_int(0, 1);
            if (item3 == 1) {
                BT->pop(item1);
            }
            continue;
        }
    }
}



void readBinaryHeap(int item, ArraySequence<Binary_heap<int>> *BHInt,
                    ArraySequence<Binary_heap<double>> *BHDouble, ArraySequence<Binary_heap<std::complex<int>>> *BHComp) {
    if (item == 0) return;

    std::cout << "Enter count of elements or -1 to exit: \n";
    int count;
    std::cin >> count;
    while(count < 0) {
        if (count < 0) {
            std::cout << "count can't be less than 0!\n: ";
        }
        std::cin >> count;

        if (count == -1)
            return;
    } ;

    Binary_heap<int> BHInt1;
    Binary_heap<double> BHDouble1;
    Binary_heap<std::complex<int>> BHComp1;
    switch (item) {
        case 1:
            BHInt1 = readTypeBinaryHeap<int>(count);
            BHInt->append(BHInt1);
            break;
        case 2:
            BHDouble1 = readTypeBinaryHeap<double>(count);
            BHDouble->append(BHDouble1);
            break;
        case 3:
            BHComp1 = readTypeBinaryHeap<std::complex<int>>(count);
            BHComp->append(BHComp1);
            break;
        default:
            break;
    }
}




void OperationWithBinaryHeap(int item, ArraySequence<Binary_heap<int>> *BHInt,
                             ArraySequence<Binary_heap<double>> *BHDouble, ArraySequence<Binary_heap<std::complex<int>>> *BHComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            OperationWithTypeBinaryHeap<int>(BHInt);
            break;
        case 2:
            OperationWithTypeBinaryHeap<double>(BHDouble);
            break;
        case 3:
            OperationWithTypeBinaryHeap<std::complex<int>>(BHComp);
            break;
    }
}

template<class T>
void OperationWithTypeBinaryHeap(ArraySequence<Binary_heap<T>> *BHs){

    if (BHs->get_len() == 0){
        std::cout << "Binary heap doesnt exist\n";
        return;
    }

    while (true){
        auto length = BHs->get_len();
        std::cout << "You have " << length << " binary heaps\n"
                  << "\t - negative number for exit\n"
                  << "\t - index of binary heap\n"
                  << "\t - number bigger than length for print all binary heaps\n";
        int item1 = get_int();
        if (item1 < 0) break;

        if (item1 >= length){
            printTypeBinaryHeap(BHs);
            continue;
        }
        Binary_heap<T> BH;
        BH = BHs->get_i(item1);

        std::cout << "What operation do you want to choose:\n"
                  << "\t0: exit\n"
                  << "\t1: Insert element\n"
                  << "\t2: Search element\n"
                  << "\t3: Delete element\n"
                  << "\t4: getSubtree\n"
                  << "\t5: findsubtree\n";
        int item = get_int(0, 5);

        if (item == 0) break;

        Binary_heap<T> subtree;

        if (item >= 1 && item <= 3){
            T element;
            std::cout << "Enter element:\n";
            std::cin >> element;

            if (item == 1){
                BH.Insert(element);
            }

            if (item == 2){
                BH.Search(element);
            }
            if (item == 3){
                BH.Delete(element);
            }
            BHs->append(BH);
        }
        else if (item == 4 || item == 5){
            std::cout << "Enter head of subtree: \n";

            T el;
            std::cin >> el;

            if (item == 4){
                auto res = BH.getSubTree(el);
                BHs->append(res);
            }
            if (item == 5){

                std::cout << "Enter count of elements or -1 to exit: \n";
                int count;
                std::cin >> count;
                while(count < 0) {
                    if (count < 0) {
                        std::cout << "count can't be less than 0!\n: ";
                    }
                    std::cin >> count;

                    if (count == -1)
                        return;
                }
                auto newHeap = Binary_heap<T>();
                for (int i = 0; i < count; i++){
                    T ell;
                    std::cin >> ell;
                    newHeap.Insert(ell);
                }


                if (BH.findSubTree(newHeap) == 1){
                    std::cout << "subtree was found\n";
                }
                else
                    std::cout << "subtree wasn't found\n";
            }
        }

    }
}

void printBinaryHeap(int item, ArraySequence<Binary_heap<int>> BHInt,
                     ArraySequence<Binary_heap<double>> BHDouble, ArraySequence<Binary_heap<std::complex<int>>> BHComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            printTypeBinaryHeap<int>(&BHInt);
            break;
        case 2:
            printTypeBinaryHeap<double>(&BHDouble);
            break;
        case 3:
            printTypeBinaryHeap<std::complex<int>>(&BHComp);
            break;
    }
}


void printArrH(int item, Binary_heap<int> BHInt,
              Binary_heap<double> BHDouble, Binary_heap<std::complex<int>> BHComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            printTypeArrH<int>(BHInt);
            break;
        case 2:
            printTypeArrH<double>(BHDouble);
            break;
        case 3:
            printTypeArrH<std::complex<int>>(BHComp);
            break;
    }
}

template<class T>
void printTypeBinaryHeap(ArraySequence<Binary_heap<T>> *BH){


    for (int i = 0; i < BH->get_len(); i++) {
        std::cout << '(';
        BH->get_i(i).print_heap(BH->get_i(i));
        //std::cout << polynomial->get_i(i).get_i(j) << ", ";
        std::cout << "\b\b), \n";

    }
    std::cout << "\n";


}

template<class T>
void printTypeArrH(Binary_heap<T> BH){
    BH.print_heap(BH);
}

template<class T>
Binary_heap<T> readTypeBinaryHeap(int count) {
    std::cout << "Enter the elements:\n";
    auto heap = Binary_heap<T>();
    for (int i = 0; i < count; i++) {
        T item;
        std::cin >> item;

        heap.Insert(item);
    }
    return heap;
}

void deleteBinaryHeap(int item, ArraySequence<Binary_heap<int>> *BHInt,
                      ArraySequence<Binary_heap<double>> *BHDouble, ArraySequence<Binary_heap<std::complex<int>>> *BHComp){
    if (item == 0) return;

    switch (item) {
        case 1:
            deleteTypeBinaryHeap<int>(BHInt);
            break;
        case 2:
            deleteTypeBinaryHeap<double>(BHDouble);
            break;
        case 3:
            deleteTypeBinaryHeap<std::complex<int>>(BHComp);
            break;
    }
}


template<class T>
void deleteTypeBinaryHeap(ArraySequence<Binary_heap<T>> *BH){
    if (BH->get_len() == 0){
        std::cout << " heap doesnt exist\n";
        return;
    }

    while (true){
        int length = BH->get_len();
        if (length == 0){
            std::cout<< "heap doesnt exist\n";
            break;
        }

        std::cout << "You have " << length << " heaps\n"
                  << "\t - negative number for exit\n"
                  << "\t - index of heap\n"
                  << "\t - number bigger than length for print all heaps\n";
        int item1 = get_int();
        if (item1 < 0) break;

        if (item1 >= length){
            printTypeBinaryHeap(BH);
            continue;
        }

        std::cout << "Choose operation:\n"
                  << "\t-1:  return to choosing index\n"
                  << "\t0: delete\n";

        int item2 = get_int(-1,0);

        if (item2 == -1) continue;

        if (item2 == 0){
            std::cout << "Do you really want to delete BH[" << item1 <<"]?"
                      << "\t0 - no\n"
                      << "\t1 - yes\n";
            int item3 = get_int(0, 1);
            if (item3 == 1) {
                BH->pop(item1);
            }
            continue;
        }
    }
}



void testFunc() {
    std::cout << "Enter:\n"
                 "\t - positive number for enter iterate tests\n"
                 "\t - 0 or negative number for exit\n";

    int count = get_int();
    if (count <= 0)
        return;
    test(100, 100);
    ArraySequenceTestComp();
    ArraySequenceTestDouble();
    ArraySequenceTestInt();

    std::cout << "Do you want to repeat test?\n"
                 "\t0 - no\n"
                 "\t1 - yes\n: ";
    count = get_int(0, 1);
    if (count == 1)
        testFunc();
}

#endif //DAR_H_INTERFACE_H
