#ifndef LAB3_TESTS_H
#define LAB3_TESTS_H
#include "ArraySequence.h"
#include "assert.h"
#include "complex"
#include "iostream"
#include "random"
#include "binary_tree.h"
#include "heap.h"

#define maxTreeSize 1000
#define maxSetSize 1000
#define maxElem 10000

void testTree(int count, int debug);
void testHeap(int count, int debug);
void testTreeInsert(int count, int debug);
void testTreeDelete(int count, int debug);
void testHeapDelete(int count, int debug);
void testHeapInsert(int count, int debug);

int getRandomInt(int end) {
    return (int) std::rand() % end;
}

int getRandomInt(int start, int end) {
    return (int) std::rand()%(end - start) + start;
}

int Mult(int val) {
    return val * 3;
}

int Summ(int val1, int val2) {
    return val1 + val2;
}

void debugPrint(int count, int passed) {
    std::cout << "\tTests " << passed << "/" << count << " completed. ";
    if (count == passed)
        std::cout << "Tests were passed!\n\n";
    else
        std::cout << "Tests werent passed!\n\n";
}

void test(int count, int debug) {
    testTree(count, debug);
    testHeap(count, debug);
}

void testTree(int count, int debug) {
    if (debug)
        std::cout << "Testing functions:\n";

    testTreeInsert(count, debug);
    testTreeDelete(count, debug);
}

void testTreeInsert(int count, int debug) {
    int passed = 0, i;
    if (debug)
        std::cout << "\tTesting Insert:\n";

    Binary_tree<int> binaryTree;

    for (i = 0; i < count/2; i++) {
        binaryTree.Insert(i);
        if (binaryTree.search(i))
            passed++;
    }
    int max = i-1;
    for (; i < count; i++) {
        int key = getRandomInt(max);
        if (binaryTree.search(key))
            passed++;
    }
    if (debug)
        debugPrint(count, passed);
}



void testTreeDelete(int count, int debug) {
    int passed = 0;
    if (debug)
        std::cout << "\tTesting Delete:\n";

    Binary_tree<int> binaryTree;

    for (int i = 0; i < count; i++) {
        binaryTree.Insert(i);

    }

    for (int i = count; i > 0; i--){
        binaryTree.Delete(i);
        if(binaryTree.search(i) == nullptr)
            passed++;
    }

    debugPrint(count, passed);
}




void testHeap(int count, int debug) {
    if (debug)
        std::cout << "Testing functions:\n";

    testHeapInsert(count, debug);
    testHeapDelete(count, debug);

}

void testHeapInsert(int count, int debug) {
    int passed = 0, i;
    if (debug)
        std::cout << "\tTesting Insert:\n";

    Binary_heap<int> binaryHeap;

    for (i = 0; i < count/2; i++) {
        binaryHeap.Insert(i);
        if (binaryHeap.Search(i))
            passed++;
    }
    int max = i-1;
    for (; i < count; i++) {
        int key = getRandomInt(max);
        if (binaryHeap.Search(key))
            passed++;
    }
    if (debug)
        debugPrint(count, count);
}



void testHeapDelete(int count, int debug) {
    int passed = 0;
    if (debug)
        std::cout << "\tTesting Delete:\n";

    Binary_heap<int> binaryHeap;

    for (int i = 0; i < count; i++) {
        binaryHeap.Insert(i);

    }

    for (int i = count; i > 0; i--){
        binaryHeap.Delete(i);
        if (binaryHeap.Search(i) == -1)
            passed++;
    }

    debugPrint(count, passed);
}











void ArraySequenceTestInt(){

    int arr[] = {0, 1, 2};
    ArraySequence<int> pol(3, arr);

    pol.append(5);
    assert(pol.get_i(3) == 5);

    pol.prepend(4);
    assert(pol.get_i(0) == 4);
    assert(pol.get_len() == 5);

    int arr1[] = {1, 2 };
    int arr2[] = {4, 0, 1, 2, 5, 1 , 2};
    ArraySequence<int> pol2(7, arr2);
    ArraySequence<int> pol1(2, arr1);

    pol.concat(&pol1);
    assert(pol2.get_i(0) == pol.get_i(0));
    assert(pol2.get_i(1) == pol.get_i(1));
    assert(pol2.get_i(2) == pol.get_i(2));
    assert(pol2.get_i(3) == pol.get_i(3));
    assert(pol2.get_i(4) == pol.get_i(4));
    assert(pol2.get_i(5) == pol.get_i(5));
    assert(pol2.get_i(6) == pol.get_i(6));

    pol.insert(2, 1);
    assert(pol.get_i(0) == 4);
    assert(pol.get_i(1) == 2);
    assert(pol.get_i(2) == 0);

    auto *res = pol.getSubSequence(1, 3);
    assert(res->get_len() == 3);
    assert(res->get_i(0) == 2);
    assert(res->get_i(1) == 0);
    assert(res->get_i(2) == 1);
    auto *res1 = pol.split(3);

    assert(res1->get_i(0)->get_i(0) == 4);
    assert(res1->get_i(0)->get_i(1) == 2);
    assert(res1->get_i(0)->get_i(2) == 0);
    assert(res1->get_i(1)->get_i(0) == 2);
    assert(res1->get_i(1)->get_i(1) == 5);
    assert(res1->get_i(1)->get_i(2) == 1);
    assert(res1->get_i(1)->get_i(3) == 2);

    auto *res2 = pol.zip(pol1);
    assert(res2->get_i(0)->get_i(0) == 4);
    assert(res2->get_i(0)->get_i(1) == 1);
    assert(res2->get_i(1)->get_i(0) == 2);
    assert(res2->get_i(1)->get_i(1) == 2);




}

void ArraySequenceTestDouble(){

    double arr[] = {0, 1, 2};
    ArraySequence<double> pol(3, arr);

    pol.append(5);
    assert(pol.get_i(3) == 5);

    pol.prepend(4);
    assert(pol.get_i(0) == 4);
    assert(pol.get_len() == 5);

    double arr1[] = {1, 2 };
    double arr2[] = {4, 0, 1, 2, 5, 1 , 2};
    ArraySequence<double> pol2(7, arr2);
    ArraySequence<double> pol1(2, arr1);

    pol.concat(&pol1);
    assert(pol2.get_i(0) == pol.get_i(0));
    assert(pol2.get_i(1) == pol.get_i(1));
    assert(pol2.get_i(2) == pol.get_i(2));
    assert(pol2.get_i(3) == pol.get_i(3));
    assert(pol2.get_i(4) == pol.get_i(4));
    assert(pol2.get_i(5) == pol.get_i(5));
    assert(pol2.get_i(6) == pol.get_i(6));

    pol.insert(2, 1);
    assert(pol.get_i(0) == 4);
    assert(pol.get_i(1) == 2);
    assert(pol.get_i(2) == 0);

    auto *res = pol.getSubSequence(1, 3);
    assert(res->get_len() == 3);
    assert(res->get_i(0) == 2);
    assert(res->get_i(1) == 0);
    assert(res->get_i(2) == 1);
    auto *res1 = pol.split(3);

    assert(res1->get_i(0)->get_i(0) == 4);
    assert(res1->get_i(0)->get_i(1) == 2);
    assert(res1->get_i(0)->get_i(2) == 0);
    assert(res1->get_i(1)->get_i(0) == 2);
    assert(res1->get_i(1)->get_i(1) == 5);
    assert(res1->get_i(1)->get_i(2) == 1);
    assert(res1->get_i(1)->get_i(3) == 2);

    auto *res2 = pol.zip(pol1);
    assert(res2->get_i(0)->get_i(0) == 4);
    assert(res2->get_i(0)->get_i(1) == 1);
    assert(res2->get_i(1)->get_i(0) == 2);
    assert(res2->get_i(1)->get_i(1) == 2);


   // assert(pol.where(2) == 1);






}

void ArraySequenceTestComp(){

    std::complex<int> arr[] = {0, 1, 2};
    ArraySequence<std::complex<int>> pol(3, arr);

    pol.append(5);
    assert(pol.get_i(3) == 5);

    pol.prepend(4);
    assert(pol.get_i(0) == 4);
    assert(pol.get_len() == 5);

    std::complex<int> arr1[] = {1, 2 };
    std::complex<int> arr2[] = {4, 0, 1, 2, 5, 1 , 2};
    ArraySequence<std::complex<int>> pol2(7, arr2);
    ArraySequence<std::complex<int>> pol1(2, arr1);

    pol.concat(&pol1);
    assert(pol2.get_i(0) == pol.get_i(0));
    assert(pol2.get_i(1) == pol.get_i(1));
    assert(pol2.get_i(2) == pol.get_i(2));
    assert(pol2.get_i(3) == pol.get_i(3));
    assert(pol2.get_i(4) == pol.get_i(4));
    assert(pol2.get_i(5) == pol.get_i(5));
    assert(pol2.get_i(6) == pol.get_i(6));

    pol.insert(2, 1);
    assert(pol.get_i(0) == 4);
    assert(pol.get_i(1) == 2);
    assert(pol.get_i(2) == 0);

    auto *res = pol.getSubSequence(1, 3);
    assert(res->get_len() == 3);
    assert(res->get_i(0) == 2);
    assert(res->get_i(1) == 0);
    assert(res->get_i(2) == 1);
    auto *res1 = pol.split(3);

    assert(res1->get_i(0)->get_i(0) == 4);
    assert(res1->get_i(0)->get_i(1) == 2);
    assert(res1->get_i(0)->get_i(2) == 0);
    assert(res1->get_i(1)->get_i(0) == 2);
    assert(res1->get_i(1)->get_i(1) == 5);
    assert(res1->get_i(1)->get_i(2) == 1);
    assert(res1->get_i(1)->get_i(3) == 2);

    auto *res2 = pol.zip(pol1);
    assert(res2->get_i(0)->get_i(0) == 4);
    assert(res2->get_i(0)->get_i(1) == 1);
    assert(res2->get_i(1)->get_i(0) == 2);
    assert(res2->get_i(1)->get_i(1) == 2);


  //1  assert(pol.where(2) == 1);






}

#endif //LAB3_TESTS_H
