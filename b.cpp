#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
int main(){
    cout<<"welcome to binary"<<endl;
    return 0;
}