#include <iostream>
using namespace std;

struct node{
    int key;
    node *left, *right;    
};

struct node* newNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key){
    if(node == NULL) return newNode(key);

    if(key < node->key)
        node-> left = insert(node->left, key);
    else if(key > node->key)
        node-> right = insert(node->right, key);
    
    return node;
}

void pre(struct node *root){
    if(root != NULL){
        cout << " " << root->key;
        pre(root->left);
        pre(root->right);
    }
}

void post(struct node *root){
    if(root != NULL){
        post(root->left);
        post(root->right);
        cout << " " << root->key;
    }
}

void inOrder(struct node *root){
    if(root != NULL){ 
        inOrder(root->left);
        cout << " " << root->key;
        inOrder(root->right);
    }
}

int main(){
    int t, n, x;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n >> x; n--;
        struct node *root = NULL;
        root = insert(root, x);

        while(n--){
            cin >> x;
            insert(root, x);
        }

        cout << "Case " << i << ":\n";
        cout << "Pre.:"; pre(root); cout << endl;
        cout << "In..:"; inOrder(root); cout << endl;
        cout << "Post:"; post(root); cout << endl;

        if(i > 0)
            cout << endl;
    }
}
