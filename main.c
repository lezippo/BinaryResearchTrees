// DELIVERY 1
// AUTHORS: LUIGI EMANUELE ZIPPO AND PIETRO PELUSO

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

    // STRUCTURES


    
// Definition of the tree structure
    
typedef struct tree* tree_pointer;

struct tree{

    int key;                // content of the node
    tree_pointer dx;        // pointer to the right child
    tree_pointer sx;        // pointer to the left child

    };
    
//*******************************************************************************************
    
    // FUNCTIONS
    
tree_pointer ABR_create () {
    
    // create empty tree
    //
    // input:
    //
    // output: pointer to the root of the newly created tree
    
    tree_pointer T=NULL;
    return T;
}

//---------------------------------------------------------------------------------------------
    
tree_pointer ABR_insert (tree_pointer T, int key) {
    
    // insertion of a node in the tree
    //
    // input: tree_pointer T = pointer to the tree to which the node is to be added
    //                  key = content of the node to be added
    //
    // output: pointer to the modified tree
    
    if (T!=NULL) {
        
        if(key>T->key) {
            // if the key of T is less than key, I need to add to the right, so I recursively call the function on the right subtree
            T->dx=ABR_insert(T->dx, key);
        }
        
        else if (key<T->key) {
            // if the key of T is greater than key, I need to add to the left, so I recursively call the function on the left subtree
            T->sx=ABR_insert(T->sx, key);
        }
        
    }
    
    else {
        
        // if the tree is empty, I insert the node as the root
        T=(tree_pointer)malloc(sizeof(struct tree));
        T->sx=NULL;
        T->dx=NULL;
        T->key=key;
    }
    
    
    return T;
    
}

//---------------------------------------------------------------------------------------------

    // printing functions

void inorder (tree_pointer T) {
    
    // print in symmetric order:
    //
    // input: tree to print
    //
    // output:

    // check: if the node is empty the function closes. So, recursively,
    // when I reach a leaf I stop
    if (T==NULL){
        
        return;
    }
    
    else {
            inorder(T->sx);
            printf("%d |", T->key);
            inorder(T->dx);
        }
    }

//---------------------------------------------------------------------------------------------
    
void preOrder (tree_pointer T) {
    
    // print in preorder:
    //
    // input: tree to print
    //
    // output:

    // check: if the node is empty the function closes. So, recursively,
    // when I reach a leaf I stop
    if (T==NULL){
        return;
    }
        
    else {
        printf("%d |", T->key);
        preOrder(T->sx);
        preOrder(T->dx);
    }
    
}

//---------------------------------------------------------------------------------------------

void postOrder (tree_pointer T) {
    
    // print in postorder:
    //
    // input: tree to print
    //
    // output:
    
    if (T==NULL){
        
        // check: if the node is empty the function closes. So, recursively,
        // when I reach a leaf I stop
        return;
    }
    
    else {
        postOrder(T->sx);
        postOrder(T->dx);
        printf("%d |", T->key);
    }
}


//---------------------------------------------------------------------------------------------

tree_pointer delete_min(tree_pointer P, tree_pointer T) {
    
    // auxiliary function of delete_root: find the minimum key of a subtree to replace the key of the root that you want to delete in delete_root. In this way the properties of binary search tree are maintained
    //
    // input: tree_pointer P: parent pointer of T
    //       tree_pointer T: pointer to the root of the tree whose minimum is to be found
    //
    // output: tree_pointer pointing to the node containing the minimum
    
    if (P == NULL || T == NULL) {
        
        // tree check
        return NULL;
    }
    
    if(T->sx != NULL){
        // if T has a left child the minimum will definitely be there, so we launch the function on the left subtree and return it
        return delete_min(T,T->sx) ;
    }
    
    // this way we traverse the tree always going left. Once we get to a node without left children, the previous if doesn't trigger anymore. Now, therefore, we have reached a minimum node but it could be a leaf or have only a right child
    
    // there are two possible cases
    
    // CASE 1: T is left child of P
    if(T == P->sx){
        
        // update the left child field of P, without overwriting any field of T
        P->sx=T->dx;
        
    }
    
    // CASE 2: T is right child of P
    else{
        
        // analogous
        P->dx=T->dx;
        
    }
    
    return T;
    
}


//---------------------------------------------------------------------------------------------

tree_pointer delete_root(tree_pointer T){
    
    // auxiliary function of ABR_delete: delete the root of a tree
    //
    // input: tree_pointer T = tree from which you want to delete the root
    //
    // output: tree_pointer pointing to the modified tree
    
    if (T == NULL) {
        
        // tree check
        return NULL;
    }
        
        // CASE 1: T has both left and right child. Look for the minimum in the right subtree (analogously you could look for the maximum of the left subtree), replace the key of the node to be deleted with that of the minimum, and deallocate the minimum node
        
        if(T->dx != NULL && T->sx != NULL){
            tree_pointer min = delete_min(T,T->dx);
            T->key = min->key;
            free(min);
            
            return T;
            
        }
    
            // CASE 2: T has only one child or is a leaf (the previous if doesn't trigger).
            tree_pointer new_root;
    
            // enter the if if T is a leaf or has only right child
            if (T->sx == NULL) {
                
                // put the right child (possibly NULL) in newroot
                new_root = T->dx;
            }
    
            // enter the else if T has only left child
            else {
                
                // put the left child in newroot
                new_root = T->sx;
                free(T);
                
            }
            
    return new_root;
        
    }

//---------------------------------------------------------------------------------------------

tree_pointer ABR_delete(tree_pointer T, int key) {
    
    // delete element in the tree with specific key
    //
    // input: tree_pointer T: pointer to the root of the tree from which an element is to be deleted
    //              int key: key of the element to be deleted
    //
    // output: tree_pointer pointing to the modified tree
    
        if(T == NULL) {
            
            // if the tree is empty it surely does not contain the key (recursively, if we reach a leaf the function stops)
            return NULL;
            
        }
        
        if(T->key > key) {
            
            // if the key of T is greater than key the node containing key will be on the left, so I recursively call the function on the left subtree of T
            T->sx= ABR_delete(T->sx,key);
        }
    
        else if (T->key < key){
            
            // if the key of T is less than key the node containing key will be on the right, so I recursively call the function on the right subtree of T
            T->dx = ABR_delete(T->dx, key);
        }
    
        else {
            
            // if the key of T is exactly equal to key then I have to delete it, so I call delete_root
            T = delete_root(T);
        }
    
        return T;
    
    }

//---------------------------------------------------------------------------------------------

tree_pointer ABR_destroy_key(tree_pointer T,int k) {
    
    // delete subtree
    //
    // input: tree_pointer T = pointer to the root of the tree from which to delete the subtree
    //                int k = key of the root of the subtree to be deleted
    //
    // output: tree_pointer pointing to the deleted subtree
    
    tree_pointer temp=NULL;
    
    if (T) {
        
        if (T->key==k) {
            
            // if I immediately find the key then I recursively call the function on the left and right subtrees of T
            
            if (T->sx)
                ABR_destroy_key(T->sx, (T->sx)->key);
            
            if (T->dx)
                ABR_destroy_key(T->dx, (T->dx)->key);
            
            free(T);
        }
        
        else {
            
            // if the key of T is less than k the node containing k will be on the right, so I recursively call the function on the right subtree, save the output in a temporary variable
            if (k>T->key)
                temp=ABR_destroy_key(T->dx, k);
            
            // if the key of T is greater than k the node containing k will be on the left, so I recursively call the function on the left subtree, save the output in a temporary variable
            else if (k<T->key)
                temp=ABR_destroy_key(T->sx, k);
            
            // compare, iteration by iteration, the subtree saved in temp
            if (T->dx==temp)
                T->dx=NULL;
            
            else if (T->sx==temp)
                T->sx=NULL;
            
            return temp;
        }
    }
    
    return T;
}

//---------------------------------------------------------------------------------------------

void ABR_destroy (tree_pointer T) {
    
    // destroy entire tree
    //
    // input: tree_pointer T = pointer to the tree to deallocate
    //
    // output:
    
    if (T==NULL){

        // if the tree is already NULL do nothing
        return;

    }
    
    else {
        
        // if the tree is not NULL call ABR_destroy_key on the root
        ABR_destroy_key(T, T->key);
        return;
    }
    
}

//---------------------------------------------------------------------------------------------

int ABR_search (tree_pointer T, int k) {
    
    // search element in the tree
    //
    // input: tree_pointer T = pointer to the root of the tree to search in
    //                int k = key to search for
    //
    // output: int 0 = the tree does not contain the searched key
    //         int 1 = the tree contains the searched key

    // if the tree is empty it surely does not contain the key (recursively, if we reach a leaf the function stops)
    if (T==NULL) return 0;
    
    if (T->key==k) return 1;
    
    // if the key of T is greater than k it will be in the left subtree, so I call the function on the left subtree of T
    else if (T->key>k) return ABR_search(T->sx, k);
    
    // if the key of T is less than k it will be in the right subtree, so I call the function on the right subtree of T
    else return ABR_search(T->dx, k);
    
}

//*******************************************************************************************
//*******************************************************************************************
//*******************************************************************************************

int main() {
    
    char risposta[3]="yes";
    int numero;
    int scelta=0;
    tree_pointer root=ABR_create();
    
    printf("Start of the program on Trees.\n");
    
    while (strcmp(risposta,"yes")==0){
    
    printf("Give a number to insert into the tree:\n");
    scanf("%d",&numero);
    root=ABR_insert(root, numero);
    
    printf("Do you want to insert another node? (write yes or no)\n");
    scanf("%s",risposta);
    }
    
    printf("Possible operations on the tree:\n");
    printf("1) Delete an element\n");
    printf("2) Add an element\n");
    printf("3) Search for an element\n");
    printf("4) Print the tree\n");
    printf("5) Delete a subtree\n");
    printf("6) Delete the tree\n");
    printf("0) Close the program\n");
    printf("--------------------------------------------\n");
    printf("CHOICE: ");
    scanf("%d",&scelta);
    
    while (scelta!=0){
    
    if (scelta==1) {
    
    if (root==NULL) printf("\nThe tree is empty\n");
    
    else {
    
    printf("\nInsert element to delete:");
    scanf("%d", &numero);
    root=ABR_delete(root, numero);
    inorder(root);
        
    }
        
    }
        
    //---------------------------------------------------------------------------------------------
    
    if (scelta==2){
    
    printf("\nInsert element to add:");
    scanf("%d", &numero);
    root=ABR_insert(root, numero);
    printf("\nPrint the tree\n");
    inorder(root);
    
    }
    
    //---------------------------------------------------------------------------------------------
    
    if (scelta==3){
    
    if (root==NULL) printf("\nThe tree is empty\n");
    
    else {
    
    printf("\nInsert element to search:");
    scanf("%d", &numero);
    int found=ABR_search(root, numero);
        
        if (found){
            printf("The element is present in the tree");
        }
        
        else {
            printf("The element is not present in the tree");
        }
    }
    }
        
    //---------------------------------------------------------------------------------------------
        
    if (scelta==4){
        
        if (root==NULL) printf("\nThe tree is empty\n");
        
        else {
            printf("Choose the printing order:\n1)Symmetric order\n2)Post order\n3)Pre order\n");
            scanf("%d", &numero);
            if (numero==1){
                printf("\nPrint the tree in Symmetric order\n");
                inorder(root);
            }
            else if (numero==2){
                printf("\nPrint the tree in Post order\n");
                postOrder(root);
            }
            else if (numero==3){
                printf("\nPrint the tree in Pre order\n");
                preOrder(root);
            }
            
            
        }

        }
        
        //---------------------------------------------------------------------------------------------
        
        if (scelta==5) {
            
            if (root==NULL) printf("\nThe tree is empty\n");
            
            else{
                
                printf("\nInsert the root of the subtree to delete:");
                scanf("%d", &numero);
                
                if (numero==root->key){
                    
                    ABR_destroy(root);
                    root=NULL;
                    printf("\nYou emptied the tree\n");
                    
                }
                
                else {
                    
                    ABR_destroy_key(root, numero);
                    printf("\nPrint the tree\n");
                    inorder(root);
                    
                }
            }
        }
        
        //---------------------------------------------------------------------------------------------
        
        if (scelta==6) {
            
            ABR_destroy(root);
            root=NULL;
            printf("The tree has been deleted");
            
        }
        
        //---------------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------------
        
        printf("\n\n--------------------------------------------\n");
        printf("Possible operations on the tree:\n");
        printf("1) Delete an element\n");
        printf("2) Add an element\n");
        printf("3) Search for an element\n");
        printf("4) Print the tree\n");
        printf("5) Delete a subtree\n");
        printf("6) Delete the tree\n");
        printf("0) Close the program\n");
        printf("--------------------------------------------\n");
        printf("CHOICE: ");
        scanf("%d",&scelta);
        
    }
    
   printf("\nEnd of program\n");
   return 0;
    
}
