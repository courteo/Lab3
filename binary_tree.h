#ifndef LAB3_BINARY_TREE_H
#define LAB3_BINARY_TREE_H
#include "math.h"

template<class T>
class Binary_tree {
private:
    struct element {
        T data;
        element* left = nullptr;
        element* right = nullptr;
        element* parent = nullptr;
        int id = 0;
        int depth = 1;
    };
    element* head = nullptr;



public:
    class IndexOutOfRange{};



    element* get_head(){
        return head;
    }


    Binary_tree(){
        head = nullptr;
    }


    Binary_tree(const Binary_tree<T> &other){
        this->head = nullptr;

        Pre_order_copy(other.head);
        Pre_order(get_head(), 1);
    }


    ~Binary_tree(){                                                                                                                                                         if(this < 0)
        Delete_all(this->head);
    }

    void Delete_all(element* start){
        auto *temp = start;
        if (temp == nullptr)
            return;
        Delete_all(temp->left);
        Delete_all(temp->right);
        Delete(temp->data);
        head = nullptr;
    }


    std::string In_order_GetStr(element* start,int depth)
    {
        if (depth <= 0)
            throw IndexOutOfRange();

        if (start == nullptr)
            return std::string();

        std::string res;
        res += In_order_GetStr(start->left, depth + 1);
        for(int i = 0;i < depth;i++)
            res += "    ";

        res += std::to_string(start->data);
        res += '\n';
        res += In_order_GetStr(start->right, depth + 1);

        return res;
    }

    std::string Pre_order_GetStr(element* start,int depth)
    {
        if (depth <= 0)
            throw IndexOutOfRange();

        if (start == nullptr)
            return std::string();

        std::string res;
        for(int i = 0;i < depth;i++)
            res += "    ";

        res += std::to_string(start->data);
        res += '\n';
        res += Pre_order_GetStr(start->left, depth + 1);
        res += Pre_order_GetStr(start->right, depth + 1);



        return res;
    }

    void Pre_order_copy(element* start){
        auto *temp = start;
        if (temp == nullptr)
            return;

        this->Insert(temp->data);

        Pre_order_copy(temp->left);
        Pre_order_copy(temp->right);

    }

    element* search(T el){
        auto *temp = head;
        while (true)
        {
            if (temp == nullptr)
                return temp;
            else if (el < temp->data) {
                temp = temp->left;
            }
            else if (el > temp->data){
                temp = temp->right;
            }
            else
                if (el == temp->data)
                    return temp;
        }
    }

    void Insert(T el){
        auto *temp = head;


        if (temp == nullptr){
            temp = new element;
            temp->data = el;
            temp->right = nullptr;
            temp->left = nullptr;
            temp->parent = nullptr;
            temp->depth = 1;
            head = temp;
        }
        else {
            while (true) {
                if (el == temp->data)
                    break;
                else if (el < temp->data) {
                    if (temp->left != nullptr) {
                        temp = temp->left;
                    }
                    else {
                        temp->left = new element;
                        temp->left->data = el;
                        temp->left->depth = 1;
                        temp->left->parent = temp;

                        temp->left->left = nullptr;
                        temp->left->right = nullptr;
                        break;
                    }
                } else if (el > temp->data) {
                    if (temp->right != nullptr) {
                        temp = temp->right;
                    }
                    else {
                        temp->right = new element;
                        temp->right->data = el;
                        temp->right->depth = 1;
                        temp->right->parent = temp;

                        temp->right->left = nullptr;
                        temp->right->right = nullptr;
                        break;
                    }
                }
            }
            Post_order_depth(get_head());
        }
    }

    void Delete(T el){
        auto *temp = search(el);


        if (temp == nullptr) return;

        if (temp->left == nullptr && temp->right == nullptr) {
            if (temp == head){
                head->data = 0;
                head = nullptr;
                return;
            }
            if (temp->data < temp->parent->data){
                temp->parent->left = nullptr;
            }
            else {
                temp->parent->right = nullptr;
            }

            delete temp;
        }
        else if (temp->left == nullptr) {
            auto *temp1 = temp->right;

            if (temp == head){
                head = temp1;
                head->parent = nullptr;
            }

            if (temp->data < temp->parent->data){
                temp1->parent = temp->parent;
                temp1->parent->left = temp->right;

            }
            else {
                temp1->parent = temp->parent;
                temp1->parent->right = temp->right;

            }



            delete temp;
        }
        else if (temp->right == nullptr){
            auto *temp1 = temp->left;
            if (temp == head){
                head = temp1;
                head->parent = nullptr;
            }

            else if (temp->data < temp->parent->data){
                temp1->parent = temp->parent;
                temp1->parent->left = temp->left;
            }
            else {
                temp1->parent = temp->parent;
                temp1->parent->right = temp->left;
            }



            delete temp;
        }
        else {
            auto *temp1 = temp->right;

            while (temp1->left != nullptr){
                temp1 = temp1->left;
            }
            temp->data = temp1->data;

            if (temp1 != temp->right){


                if (temp1->data < temp1->parent->data){
                    temp1->parent->left = nullptr;
                }
                else {
                    temp1->parent->right = nullptr;
                }
            }
            else {
                temp->right = temp1->right;
                temp1->right->parent = temp;
            }



            delete temp1;
        }
        Post_order_depth(get_head());
        Pre_order(get_head(), 1);
    }


    Binary_tree<T> get_subtree(T el){                                                                                                                                                                                                                                                                // ИЛЬЯС ЛООХ
        element* temp = head;
        auto res = Binary_tree<T>();
        if (temp == nullptr){
            res.head = temp;
            return res;
        }
        while (true)
        {
            if (temp == nullptr){
                res.head = temp;
                return res;
            }

            else if (el < temp->data) {
                temp = temp->left;
            }
            else if (el > temp->data){
                temp = temp->right;
            }
            else
            if (el == temp->data)
                break;
        }
        temp->parent = nullptr;
        res.head = temp;
        Pre_order(res.get_head(), 1);
        return res;
    }

    bool find_subtree(T el){
        auto res = this->get_subtree(el);
        if (res.head != nullptr)
            return 1;
        return 0;
    }


    void Pre_order(element* start, int k) {
        Pre_order(start, k, 0);
    }

    void Pre_order(element* start, int &i, int){
        auto *temp = start;
        if (temp == nullptr)
            return;

        temp->id = i;
        i++;

        Pre_order(temp->left, i, 0);
        Pre_order(temp->right, i, 0);

    }

    void Pre_order_map(element* start, T k) {

        Pre_order_map(start, k, 0);
    }

    void Pre_order_map(element* start, T &i, int) {

        auto *temp = start;
        if (temp == nullptr)
            return;



        temp->data = temp->data * i;

        Pre_order_map(temp->left, i, 0);
        Pre_order_map(temp->right, i, 0);
    }

    void Pre_order_concat(element* tree){

        auto *temp = tree;
        if (temp == nullptr)
            return;


        this->Insert(temp->data);

        Pre_order_concat(temp->left);
        Pre_order_concat(temp->right);
    }



    Binary_tree<T> Where_Pre_O(){
        auto res = Binary_tree<T>();

        Pre_order_where(this->head, res);
        Pre_order(res.get_head(), 1);
        return res;
    }

    void Pre_order_where(element* start, Binary_tree<T> &res){
        auto *temp = start;
        if (temp == nullptr)
            return;

        if (temp->data - 5 != 0)
            res.Insert(temp->data);

        Pre_order_where(temp->left, res);
        Pre_order_where(temp->right, res);
    }

    T reduce_Pre_O(){
        T res = 0;

        Pre_order_reduce(this->head, res);
        return res;
    }

    void Pre_order_reduce(element* start, T &res){
        auto *temp = start;
        if (temp == nullptr)
            return;

        res += temp->data * temp->id;

        Pre_order_reduce(temp->left, res);
        Pre_order_reduce(temp->right, res);
    }

    void upDepth(element* start){
        int dep1, dep2;
        if (start->left == nullptr)
            dep1 = 0;
        else
            dep1 = start->left->depth;

        if (start->right == nullptr)
            dep2 = 0;
        else
            dep2 = start->right->depth;

        if (dep1 > dep2 )
            start->depth = dep1 + 1;
        else
            start->depth = dep2 + 1;
    }

    element* rLeft(element* start) {
        element *res = start->right;

        int q = 0;
        if (start == head)
            q = 1;

        start->right = res->left;
        if (res->left != nullptr)
            res->left->parent = start;

        res->parent = start->parent;
        if (q != 1)
        {
            if (res->data > res->parent->data)
                res->parent->right = res;
            else
                res->parent->left = res;
        }

        res->left = start;
        start->parent = res;


        upDepth(start);
        upDepth(res);
        if (q == 1){
            head = res;
        }
        return res;
    }

    element* rRight(element* start) {
        element *res = start->left;
        int q = 0;
        if (start == head)
            q = 1;

        start->left = res->right;
        if (res->right != nullptr)
            res->right->parent = start;

        res->parent = start->parent;
        if (q != 1)
        {
            if (res->data > res->parent->data)
                res->parent->right = res;
            else
                res->parent->left = res;
        }
        res->right = start;

        start->parent = res;
        upDepth(start);
        upDepth(res);
        if (q == 1){
            head = res;
        }

        return res;
    }


    int getDel(element* temp){
        int dep1, dep2;
        if (temp->left == nullptr)
            dep1 = 0;
        else
            dep1 = temp->left->depth;

        if (temp->right == nullptr)
            dep2 = 0;
        else
            dep2 = temp->right->depth;

        return dep2 - dep1;
    }


    element* Balance_Node(element* temp, int &res){
        int dep1, dep2;
        if (temp->left == nullptr)
            dep1 = 0;
        else
            dep1 = temp->left->depth;

        if (temp->right == nullptr)
            dep2 = 0;
        else
            dep2 = temp->right->depth;

        int del = dep2 - dep1;

        if (del < -1) {
            if (temp->left != nullptr && getDel(temp->left) > 0)
                temp->left = rLeft(temp->left);
            res = 0;
            return rRight(temp);
        }
        if (del > 1) {
            if (temp->right != nullptr && getDel(temp->right) < 0)
                temp->right = rRight(temp->right);
            res = 0;
            return rLeft(temp);
        }
        return temp;
    }

    void All_Balance(){

        while (true){
            int res = 1;
            Balance(this->get_head(), res);
            if (res == 1)
                break;
        }
        Post_order_depth(get_head());
        int k = 1;
    }

    void Balance(element* start, int &res){
        auto *temp = start;
        if (temp == nullptr)
            return;

        if (temp != nullptr)
            Balance(temp->left, res);
        if (temp != nullptr)
            Balance(temp->right, res);
        temp = Balance_Node(temp, res);
        int k =0;
    }


    void Post_order_depth(element* start){
        auto *temp = start;
        if (temp == nullptr)
            return;
        Post_order_depth(temp->left);
        Post_order_depth(temp->right);

        if (temp->left == nullptr && temp->right == nullptr){
            temp->depth = 1;
        }
        else
            upDepth(temp);



    }


    void In_order(element* start, int k) {
        In_order(start, k, 0);
    }

    void In_order(element* start, int &i, int){
        auto *temp = start;
        if (temp == nullptr)
            return;
        In_order(temp->left, i, 0);

        temp->id = i;
        i++;


        In_order(temp->right, i, 0);

    }

    void In_order_map(element* start, T k) {
        In_order_map(start, k, 0);
    }

    void In_order_map(element* start, T &i, int) {

        auto *temp = start;
        if (temp == nullptr)
            return;

        double k;

        k = 8,31;

        In_order_map(temp->left, i,0);


        temp->data = temp->data * i;


        In_order_map(temp->right, i, 0);
    }

    void In_order_concat(element* tree){

        auto *temp = tree;
        if (temp == nullptr)
            return;

        In_order_concat(temp->left);

        this->Insert(temp->data);


        In_order_concat(temp->right);
    }



    Binary_tree<T> Where_In_O(){
        auto res = Binary_tree<T>();

        In_order_where(this->head, res);
        In_order(res.get_head(), 1);
        return res;
    }

    void In_order_where(element* start, Binary_tree<T> &res){
        auto *temp = start;
        if (temp == nullptr)
            return;

        In_order_where(temp->left, res);

        if (temp->data - 5 != 0)
            res.Insert(temp->data);


        In_order_where(temp->right, res);
    }

    T reduce_In_O(){
        T res = 0;

        In_order_reduce(this->head, res);
        return res;
    }

    void In_order_reduce(element* start, T &res){
        auto *temp = start;
        if (temp == nullptr)
            return;

        In_order_reduce(temp->left, res);

        res += temp->data * temp->id;


        In_order_reduce(temp->right, res);
    }

    void print_Tree(element* tree,int level)
    {
        if(tree != nullptr)
        {
            print_Tree(tree->left,level + 1);
            for(int i = 0;i <= level;i++) std::cout<<"   ";
            std::cout << tree->data << std::endl;
            print_Tree(tree->right,level + 1);
        }
    }



};


#endif //LAB3_BINARY_TREE_H
