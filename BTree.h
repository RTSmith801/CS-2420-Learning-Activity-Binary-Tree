/**
 * @file: BTree.h
 * @assignment_name: 06 Learning Activity: Binary Tree
 * @author: Rick Smith (rickysmith@mail.weber.edu)
 * @date: 02/02/2023
 * @brief: Demonstrate the implementation of a Binary Tree.
 *
 */

#ifndef INC_06_LEARNING_ACTIVITY_BINARY_TREE_BTREE_H
#define INC_06_LEARNING_ACTIVITY_BINARY_TREE_BTREE_H

template <class Type>
struct Node{
    Type item;
    Node <Type> *left;
    Node <Type> *right;
};


template <class Type>
class BTree{

public:

    BTree(); //Constructor: Creates an empty tree
    BTree(const BTree<Type>&); //Constructor: Creates a copy of a tree
    BTree<Type> operator=(const BTree<Type>&); //Overloaded assignment operator. Copies the BTree
    ~BTree(); //Dest     void preOrder(); //Displays a pre-order traversal of the tree
    void insert(Type item); //Inserts a node into the tree
    void preOrder(); //Displays a pre-order traversal of the tree
    void inOrder(); //Displays an in-order traversal of the tree
    void postOrder(); //Displays a post-order traversal of the tree
    int nodeCount(); //Calculates the number of items in the tree

protected:
    Node<Type> *root; //pointer to top of tree.

private:
    //helper methods for recurrsion
    void copyTree(Node<Type> *curr);
    void destroy(Node<Type> *curr);
    void insert(Type item, Node<Type> *curr);
    void preOrder(Node<Type> *curr);
    void inOrder(Node<Type> *curr);
    void postOrder(Node<Type> *curr);
    int nodeCount(Node<Type> *curr);
};

template <class Type>
BTree<Type>::BTree(){
    root = nullptr;
}

template <class Type>
BTree<Type>::BTree(const BTree<Type>&b){
    copyTree(b.root);
}

template <class Type>
BTree<Type> BTree<Type>::operator=(const BTree<Type>&b){
    copytree(b.root);
    return *this;
}

template <class Type>
void BTree<Type>::copyTree (Node<Type>*curr) {
    if(curr){
        insert(curr->item);
        copyTree(curr->left);
        copyTree(curr->right);
    }
}

template <class Type>
BTree<Type>::~BTree(){
    destroy(root);
}

template <class Type>
void BTree<Type>::destroy(Node<Type> * curr){
    if(curr != nullptr){
        destroy(curr->left);
        destroy(curr->right);
        delete curr;
    }
}

template <class Type>
void BTree<Type>::insert(Type item){
    //if empty tree
    if(root == nullptr){
        root = new Node<Type>;
        root->item = item;
        root->left = nullptr;
        root->right = nullptr;
    }
    else{
        insert(item, root);
    }
}

template <class Type>
void BTree<Type>::insert(Type item, Node<Type> * curr){
    if(item < curr->item){
        if(curr->left == nullptr){
            auto tmp = new Node<Type>;
            tmp->item = item;
            tmp->left = nullptr;
            tmp->right = nullptr;
            curr->left = tmp;
        }
        else{
            insert(item, curr->left);
        }//ends inner if
    }//ends outer if
    else{ //item > curr->item
        if(curr->right == nullptr) {
            auto tmp = new Node<Type>;
            tmp->item = item;
            tmp->left = nullptr;
            tmp->right = nullptr;
            curr->right = tmp;
        }
        else{
            insert(item, curr->right);
        }//ends inner if
    }
}//ends insert

template <class Type>
void BTree<Type>::preOrder() {
    std::cout << "Pre Order: ";
    preOrder(root);
}

template <class Type>
void BTree<Type>::preOrder(Node<Type> *curr) {
    if(curr){
        std::cout << curr->item << " ";
        preOrder(curr->left);
        preOrder(curr->right);
    }
}

template <class Type>
void BTree<Type>::inOrder() {
    std::cout << "In Order: ";
    inOrder(root);
}

template <class Type>
void BTree<Type>::inOrder(Node<Type> *curr) {
    if(curr) {
        inOrder(curr->left);
        std::cout << curr->item << " ";
        inOrder(curr->right);
    }
}

template <class Type>
void BTree<Type>::postOrder() {
    std::cout << "Post Order: ";
    postOrder(root);
}

template <class Type>
void BTree<Type>::postOrder(Node<Type> *curr) {
    if(curr) {
        postOrder(curr->left);
        postOrder(curr->right);
        std::cout << curr->item << " ";
    }
}

template <class Type>
int BTree<Type>::nodeCount(){
    return nodeCount(root);
}

template <class Type>
int BTree<Type>::nodeCount(Node<Type> *curr){
    if(curr){
        return 1 + nodeCount(curr->left) + nodeCount(curr->right);
    }
    return 0;
}


#endif //INC_06_LEARNING_ACTIVITY_BINARY_TREE_BTREE_H
