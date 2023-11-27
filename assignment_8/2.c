#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
    int data;
    struct BST *left;
    struct BST *right;
}BST;

BST* insert(BST* root, int data) {
    if (root == NULL) {
        root = (BST*)malloc(sizeof(BST));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

BST* create() {
    BST* root = NULL;
    int data;

    while (1) {
        printf("Enter the data (-1 to stop): ");
        scanf("%d", &data);

        if (data == -1)
            break;

        root = insert(root, data);
    }

    return root;
}

void inorder(BST* root) {
    if (root == NULL)
        return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(BST* root) { 
    if (root == NULL)
        return;
    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(BST* root) { 
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int search(BST* root, int data) {
    if (root == NULL)
        return 0;
    if (root->data == data)
        return 1;
    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);

    return 0;

}

int smallest(BST* root) {
    if (root == NULL)
        return -1;
    if (root->left == NULL)
        return root->data;
    return smallest(root->left);
}

int largest(BST* root) {
    if (root == NULL)
        return -1;
    if (root->right == NULL)
        return root->data;
    return largest(root->right);
}

BST* minValueNode(BST* node) {
    BST* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

BST* delete_node(BST* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = delete_node(root->left, data);
    else if (data > root->data)
        root->right = delete_node(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            BST* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BST* temp = root->left;
            free(root);
            return temp;
        }
        BST* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }

    return root;
}
void main(){
    int option,value;
    BST* root=NULL;

    do{
        printf("\n****MAIN MENU****");
        printf("\n 1.Create Binary tree");
        printf("\n 2. In-order Traversal");
        printf("\n 3. Pre-order Traversal");
        printf("\n 4. Post-order Traversal");
        printf("\n 5. Search an Element");
        printf("\n 6. Find Smallest Element");
        printf("\n 7. Find Largest Element");
        printf("\n 8. Deletion of Tree");
        printf("\n 9. Quit");
        printf("\n Enter your option");
        scanf("%d",&option);
        switch(option){
            case 1:root=create();
                    break;
            case 2:inorder(root);
                    break;
            case 3:preorder(root);  
                    break;
            case 4:postorder(root); 
                    break;
            case 5:printf("Enter the element to be searched");
                    scanf("%d",&value);
                    if(search(root,value)==1)
                        printf("Element found");
                    else
                        printf("Element not found");
                    break;
            case 6:value=smallest(root);
                    if(value==-1)
                        printf("Tree is empty");
                    else
                        printf("Smallest element is %d",value);
                    break;

            case 7:value=largest(root); 
                    if(value==-1)
                        printf("Tree is empty");
                    else
                        printf("Largest element is %d",value);
                    break;
            case 8:
                    printf("Enter the element to be deleted");
                    scanf("%d",&value);
                    root=delete_node(root,value);
                    break;
        }
    }
    while(option!=9);
}