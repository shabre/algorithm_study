#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 100002
#define RIGHT 2
#define RIGHT_NOT -2
#define LEFT 1
#define LEFT_NOT -1
using namespace std;

class Node{
private:
    Node *leftChild;
    Node *rightChild;
    int value;
public:
    Node* getLeftChild(){return leftChild;}
    Node* getRightChild(){return rightChild;}
    void setRightChild(int value){this->rightChild = new Node(value);}
    void setLeftChild(int value){this->leftChild = new Node(value);}
    int getValue(){
        return value;
    }
    int getNextNode(int goalValue);
    Node(int value);
};

Node::Node(int value) {
    this->value = value;
}

class Tree{
private:
    Node *firstNodePtr;
    
public:
    void insertNode(int value);
    bool isExistence(int value);
};

int Node::getNextNode(int goalValue) {
    if(this->value > goalValue) {
        if(this->rightChild == NULL) {
            return RIGHT_NOT;
        } else {
            return RIGHT;
        }
    } else {
        if(this->leftChild == NULL) {
            return LEFT_NOT;
        } else {
            return LEFT;
        }
    }
}



void Tree::insertNode(int value) {
    if(firstNodePtr == NULL) {
        firstNodePtr = new Node(value);
    } else {
        Node *nodePtr = firstNodePtr;
        while (true) {
            int next = nodePtr->getNextNode(value);
            if(next == RIGHT) {
                nodePtr = nodePtr->getRightChild();
            } else if(next == LEFT) {
                nodePtr = nodePtr->getLeftChild();
            } else if(next == RIGHT_NOT) {
                nodePtr->setRightChild(value);
                break;
            } else {
                nodePtr->setLeftChild(value);
                break;
            }
        }
    }
}

bool Tree::isExistence(int value) {
    if(firstNodePtr == NULL) {
        return false;
    } else {
        Node *nodePtr = firstNodePtr;
        while (true) {
            if(nodePtr->getValue() == value) {
                return true;
            }
            int next = nodePtr->getNextNode(value);
            if(next == RIGHT) {
                nodePtr = nodePtr->getRightChild();
            } else if(next == LEFT) {
                nodePtr = nodePtr->getLeftChild();
            } else {
                return false;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    bool arr[MAX];
    memset(arr, 0, sizeof(bool)*MAX);
    Tree tree;
    int num =0;
    int input = 0;
    scanf("%d", &num);
    for(int i =0; i< num; i++) {
        scanf("%d", &input);
        tree.insertNode(input);
    }
    scanf("%d", &num);
    for(int i = 0; i<num; i++) {
        scanf("%d", &input);
        if(tree.isExistence(input)) {
            printf("1\n");

        } else {
            printf("0\n");
        }
    }
    return 0;
}
