#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
Node* buildtree(const vector<int>& preorder,int& idx){
    idx++;
     if(preorder[idx]==-1) return NULL;
    Node* root=new Node(preorder[idx]);
    root->left=buildtree(preorder,idx);
    root->right=buildtree(preorder,idx);
    return root;
}
void preOrder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

    return;
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelOrder(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
            if(curr==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        cout<<curr->data<<" ";

        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    
}
int height(Node* root){
    if(root==NULL) return 0;

    int heileft=height(root->left);
    int heiright=height(root->right);

     return max(heileft,heiright)+1;
}
int count(Node* root){
    if(root==NULL) return 0;

    int leftcount=count(root->left);
    int rightcount=count(root->right);

    return leftcount+rightcount+1;
}
int sum(Node* root){
    if(root==NULL) return 0;

    int leftsum=sum(root->left);
    int rightsum=sum(root->right);

    return leftsum+rightsum+(root->data);
}
bool isavailable(Node* root, int value){
    if(root == NULL) return false;

    if(root->data == value)
        return true;

    return isavailable(root->left, value) ||
           isavailable(root->right, value);
}
int countLeaf(Node* root) {
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}
bool isSameTree(Node* p, Node* q){
    if(p==NULL||q==NULL){
        return p==q;
    }

    return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right)&&(p->data==q->data);
}
bool isSubtree(Node* root, Node* subRoot) {
    if(root==NULL||subRoot==NULL) return root==subRoot;

    if(root->data==subRoot->data&&isSameTree(root,subRoot)){
            return true;  
    }
    return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
}
class Solution {
public:
    int ans = 0;

    int height(Node* root) {
        if(root == NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        ans = max(ans, left + right);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(Node* root) {
        height(root);
        return ans;
    }
};
void topView(Node* root){
    if(root==NULL) return;
    queue<pair<Node* ,int>>Q;
    map<int,int>m;
    Q.emplace(root,0);
    while(!Q.empty()){
        Node* curr=  Q.front().first;
        int currHD=Q.front().second;

        Q.pop();

        if(m.find(currHD)==m.end()){
            m[currHD]=curr->data;
        }

        if(curr->left!=NULL){
            Q.emplace(curr->left,currHD-1);
        }

        if(curr->right!=NULL){
            Q.emplace(curr->right,currHD+1);
        }
    }
    
    for(auto it:m){
        cout<<it.second<<" ";
    }

    return;

}
void kthLevel(Node* root,int k){
    if(root==NULL) return;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    kthLevel(root->left,k-1);
    kthLevel(root->right,k-1);
}
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root==NULL) return NULL;
    if(root==p||root==q){
        return root;
    }
    Node* leftLCA=lowestCommonAncestor(root->left,p,q);
    Node* rightLCA=lowestCommonAncestor(root->right,p,q);

    if(leftLCA && rightLCA){
        return root;
    }
    else if(rightLCA!=NULL){
        return rightLCA;
    }
    else{
        return leftLCA;
    }
}
Node* buildtree(vector<int>& preorder,vector<int>& inorder,int preidx,int left,int right){

}
Node* buildTree(vector<int>& preorder,vector<int>& inorder){

}
int sumTree(Node* root){
    if(root==NULL) return 0;

   
    int leftsum=sumTree(root->left);
    int rightsum=sumTree(root->right);

     if(root!=NULL){
        root->data+=(leftsum+rightsum);
    }

    return root->data;
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int idx=-1;
    Node* root = buildtree(preorder,idx);
   // preOrder(root);
   // cout<<"\n";
   // inorder(root);
   //  cout<<"\n";
   //  postorder(root);
   //  cout<<"\n";
    // levelOrder(root);

    // cout<<height(root)<<endl;
    // cout<<count(root)<<endl;
    // cout<<sum(root)<<endl;

    // cout<<isavailable(root,4)<<endl;

   // cout<<countLeaf(root)<<endl;
  // topView(root);
  kthLevel(root,2);
    return 0;
}