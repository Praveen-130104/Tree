/*
    Implemtation of Binary Tree
    -> Preorder Traversal
    -> Inorder Traversal
    -> Postorder traversal
    -> Levelorder Traversal
*/

#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data ;
    Node* left;
    Node* right;

    Node(){
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Tree{
    public:
    Node* root = new Node();
    Tree(){
        root = nullptr;
    }

    void addData(int d){
        Node* nn = new Node();
        nn->data = d;
        if(root == nullptr){
            root = nn;
            return;
        }
        
        Node* current = root;
        Node* parent = nullptr;

        while(current != nullptr){
            parent = current;
            if(d < current->data)  current = current->left;
            else current = current->right;
        }

        if(d < parent->data) parent->left = nn;
        else parent->right = nn;

        return;        
    }

    void preOrder(Node* root){
        if(root == nullptr)return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node* root){
        if(root == nullptr)return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    void postOrder(Node* root){
        if(root == nullptr)return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }

    void levelOrder(){
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            cout<<node->data<<" ";
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
    }
};

int main(){
    
    int n;
    cin>>n;

    Tree bt;
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        bt.addData(a);
    }

    cout<<"Pre-Order Traversal is : ";
    bt.preOrder(bt.root);
    cout<<endl;

    cout<<"In-Order Traversal is : ";
    bt.inOrder(bt.root);
    cout<<endl;

    cout<<"Post-Order Traversal is : ";
    bt.postOrder(bt.root);
    cout<<endl;

    cout<<"Level-Order Traversal is : ";
    bt.levelOrder();
    cout<<endl;
}

/*
    Test Cases:
    n = 7
    elements - 10,5,15,2,7,12,20

    Output:
    Pre-Order Traversal is : 10 5 2 7 15 12 20
    In-Order Traversal is : 2 5 7 10 12 15 20
    Post-Order Traversal is : 2 7 5 12 20 15 10
    Level-Order Traversal is : 10 5 15 2 7 12 20

*/