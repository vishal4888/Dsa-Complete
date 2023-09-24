#include<iostream>
using namespace std;
#include<vector>
#include<queue>


class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* buildTree(Node* root){

    cout<<"Enter the data : " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for the Left Child of : " << data << endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for the Right child of : " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void LevelOrderTraversal(Node* root){

    queue<Node* > q;

    //Push THe Root in the queue
    q.push(root);
    //first level complete push kar diya fir null push karo
    q.push(NULL);

    //traverse the queue till not empty

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<< endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{

            cout<< temp->data << " ";

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void preOrder(Node* root){

    if(root == NULL){
        return ;
    }

    cout<< root->data << " ";

    preOrder(root->left);

    preOrder(root->right);

}

void inOrder(Node* root){

    if(root == NULL){
        return;
    }

    inOrder(root->left);

    cout<< root->data << " ";

    inOrder(root->right);
}

void postOrder(Node* root){

    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);

    cout<< root->data << " ";
}


Node* buildFromLevelOrder(Node* root){

    queue<Node*> q;

    cout<<"Enter the data for the root : " <<endl;

    int data;

    cin >> data;

    root = new Node(data);

    q.push(root);


    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        cout<< "Enter left Node For : " << root->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<< "Enter right Node For : " << root->data << endl;

        int rightData;

        cin >> rightData;

        if(rightData != -1){
            temp->right = new Node(rightData);

            q.push(temp->right);
        }


    }
}




int main(){

    Node* root = NULL;

    root = buildTree(root);

    //1 3 7 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"Printing the Level Order : " << endl;

    LevelOrderTraversal(root);

    






    return 0;
}

