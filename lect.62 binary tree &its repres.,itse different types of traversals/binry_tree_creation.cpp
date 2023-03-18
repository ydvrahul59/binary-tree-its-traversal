#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    //creating constructor
    node(int d){
        this ->data=d;
        this -> left = NULL;
        this -> right = NULL;

    }
};
node* buildTree(node* root){
    //entering the dat aof root node in fisrt recurion call
    cout << " enter the data of node :"<<endl;
    int data;
    cin>> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    //creating tree by recursion
    cout << "enter data for inserting in left of "<<data<<endl;
    root ->left = buildTree(root ->left);
    cout << "entert data for inserting in right of "<< data<<endl;
    root -> right = buildTree(root ->right);
    return root;


}
// level order traversal
void levelOrderTaversal(node* root){
    // alys ue queue isko bfs bhi bolten hain level order travesal ko
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
       // cout << temp -> data << " ";
        q.pop();

        if (temp == NULL){
            //purana level complete  traverse ho chuka hai
            cout << endl;
            if(!q.empty()){
                // queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp -> data << " ";

           if(temp -> left){
            q.push(temp -> left);

           }
           if(temp -> right){
            q.push(temp -> right);
           }
        }


    }
}
//creating function for inorder
void inorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    //LNR 
    inorder(root -> left); //L for left ko call mari
    cout << root-> data<<" "; // N for node ko print kara diya
    inorder(root -> right); // R for right ko call mari
}
void preorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    //nlr
    cout<<root->data<<" ";
    preorder(root ->left);
    preorder(root->right);
}
void postorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    //lrn
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
/*(build from level order (inout mein level order diya hoga
toh uske base par ek tre buld krnge)*/
void buildFromLevelOrder(node* &root){
    queue<node*>q;
    cout<< " enter data for root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"enter left node for :"<<temp -> data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"enter right node for : "<<temp -> data<<endl;
        int rightData;
        cin>> rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp ->right);
        }
    }
}


int main(){
    //ek root node bna leta hun main mein jo string mein null ke equal hoga
    node* root = NULL;
    //creating a tree

    buildFromLevelOrder(root); //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    levelOrderTaversal(root); 


  /*  root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //level order
    cout<< "printing the level order traversal output "<<endl;
    levelOrderTaversal(root);

    cout<<"inorder traversal is :";
    inorder(root);

    cout<<endl<<"preorder traversal is: ";
    preorder(root);

    cout<<endl<<"postorder traversal is: ";
    postorder(root); */

}
