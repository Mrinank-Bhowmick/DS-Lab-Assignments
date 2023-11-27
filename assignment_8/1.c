#include <stdio.h>
#include <stdlib.h>

typedef struct BT{
    struct BT* left;
    int data;
    struct BT* right;
} BT;

BT* create(){
    BT* root;
    printf("Enter the data: ");
    int data;
    scanf("%d",&data);
    root=malloc(sizeof(BT));
    root->data=data;
    
    if(data == -1){
        free(root); //
        return NULL;
    }

    printf("Enter data for inserting in left of %d\n",data);
    root->left=create();
    printf("Enter data for inserting in right of %d\n",data);
    root->right=create();

    return root;
}

void inorder(BT* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(BT* root){
    if(root == NULL){
        return;
    }

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(BT* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int search(BT* node, int key)
{
    if (node == NULL)
        return 0;
 
    if (node->data == key)
        return 1;
 
    int res1 = search(node->left, key);
    if(res1) return 1; 
 
    int res2 = search(node->right, key);
 
    return res2;
}


int smallest(BT* root){
    
    int minimum = root->data;

    if(root->left != NULL){
        int leftmin = smallest(root->left);
        minimum = (leftmin < minimum ? leftmin : minimum);  
    }
    if(root->right != NULL){
        int rightmin = smallest(root->right);
        minimum = (rightmin < minimum ? rightmin : minimum);  
    }

    return minimum;
}

int largest(BT* root){
    
    int maximum = root->data;

    if(root->left != NULL){
        int leftmax = largest(root->left);
        maximum = (leftmax > maximum ? leftmax : maximum);  
    }
    if(root->right != NULL){
        int rightmax = largest(root->right);
        maximum = (rightmax > maximum ? rightmax : maximum);  
    }

    return maximum;
}

Node* delete_node(Node* root) {
    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    if (root->left != NULL && root->right == NULL) {
        Node* temp = root->left;
        free(root);
        return temp;
    }

    if (root->right != NULL && root->left == NULL) {
        Node* temp = root->right;
        free(root);
        return temp;
    }

    if (root->right != NULL && root->left != NULL) {
        Node* temp = root->right;
        Node* prev = root;
        while (temp->left != NULL) {
            prev = temp;
            temp = temp->left;
        }

        root->data = temp->data;

        if (prev == root)
            prev->right = temp->right;
        else
            prev->left = temp->right;

        free(temp);
    }

    return root;
}



void main()
{
 int option,value;
  BT* root=NULL;

 do
 {
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

        switch(option)
        {

           case 1:      
               root=create();
               break;


           case 2:
               inorder(root);
               break;

           case 3:

               preorder(root);
               break;

           case 4:

               postorder(root);
               break;

            case 5:
                printf("Enter the element to be searched: ");
                scanf("%d",&value);
                if(search(root,value)){
                    printf("Element found \n");
                }
                else{
                    printf("Not found\n");
                }
                break;
            
            case 6:
                printf("The smallest number is : %d\n",smallest(root));
                break;
            
            case 7:
                printf("The largest number is : %d\n",largest(root));
                break;
            case 8:
                printf("Choose which node to delete\n");
                int data;
                scanf("%d",&data);
                root=delete_node(root,data);
          
        }
    
    }while(option !=9);
     
}
