/*Name of program:- Binary Search Tree
Coder:-Dhiraj Gardi
Email:- dhiraj.21920116@viit.ac.in
*/
//Header files
#include <stdio.h>
#include <conio.h>

struct Node *insert(struct Node *node, int data);
struct Node *newNode(int data);
void delete (struct Node *node, int data);
void preOrder(struct Node *node);
void inOrder(struct Node *node);
void push(struct Node *node);
struct Node *pop();

void preorder(struct Node *node);
void postorder(struct Node *node);
void inorder(struct Node *node);

struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node *root = NULL, *stack[50];
int top = 0;

void main()
{
    int choice, data;
    while (1)
    {
        puts("1. Insert");
        puts("2. Delete");
        puts("3. Inorder Display");
        puts("4. Preorder Display");
        puts("5. Postorder Dsplay");
        printf("Enter Your Choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter data: \t");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter the element to be deleted:\n");
            scanf("%d\n", &data);
            delete (root, data);
            break;
        case 3:
            printInorder(root);
            break;
        case 4:
            printPreorder(root);
            break;
        case 5:
            printPostorder(root);
            break;
        }
    }
}

struct Node *insert(struct Node *node, int data)
{
    if (node == NULL)
    {
        node = newNode(data);
        return node;
    }
    else
    {
        if (data > node->data)
        {
            node->right = insert(node->right, data);
        }
        else
        {
            node->left = insert(node->left, data);
        }
    }
    printf("%u\n", node);
    return node;
}

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    return node;
}

void delete (struct Node *node, int data)
{
    struct Node *prev = node, *curr = node;
    int found = 0;
    if (node == NULL)
    {
        printf("Empty Tree");
    }
    while (curr)
    {
        if (curr->data == data)
        {
            found = 1;
            break;
        }
        else
        {
            prev = curr;

            if (curr->data < data)
            {

                curr = curr->right;
            }
            else
            {

                curr = curr->left;
            }
        }
    }

    if (!found)
    {
        printf("Element not found");
        return;
    }
    //Delete element having no child
    if (curr->left == NULL && curr->right == NULL)
    {
        if (prev->data < data)
        {
            prev->right = NULL;
        }
        else
        {
            prev->left = NULL;
        }
        free(curr);
        return node;
    }
    //Delete element having one child
    else if (curr->right == NULL && curr->left != NULL || curr->right != NULL && curr->left == NULL)
    {
        if (curr->right == NULL && curr->left != NULL)
        {
            if (prev->left == curr)
            {
                prev->left = curr->left;
            }
            else
            {
                prev->right = curr->left;
            }
        }
        else
        {
            if (prev->left == curr)
            {
                prev->left = curr->right;
            }
            else
            {
                prev->right = curr->right;
            }
        }
        return node;
    }
    //Delete element having two child(delete small element in right sub tree)
    else
    {
        struct Node *t1 = curr->right;
        if (t1->right == NULL && t1->left == NULL)
        {
            curr->data = t1->data;
            curr->right == NULL;
            free(t1);
        }
        else
        {
            if (t1->right != NULL && t1->left == NULL)
            {
                curr->data = t1->data;
                curr->right = t1->right;
                t1->right = NULL;
                free(t1);
            }
            else
            {
                struct Node *t2 = t1->left;
                while (t2->left)
                {
                    t1 = t2;
                    t2 = t2->left;
                }
                curr->data = t2->data;
                t1->left = NULL;
                free(t2);
            }
        }
    }
}

void printInorder()
{
    if (root)
    {
        inorder(root);
    }
    else
    {
        printf("Empty BST");
    }
}
void inorder(struct Node *node)
{
    if (node->left != NULL)
    {
        inorder(node->left);
    }
    printf("%d\t", node->data);

    if (node->right)
    {
        inorder(node->right);
    }
}
void printPreorder()
{
    if (root)
    {
        preorder(root);
    }
    else
        printf("BST is empty");
}
void preorder(struct Node *node)
{
    printf("%d\t", node->data);
    if (node->left)
        preorder(node->left);
    if (node->right)
        preorder(node->right);
}
void printPostorder()
{
    if (root)
    {
        postorder(root);
    }
    else
        printf("BST is empty");
}
void postorder(struct Node *node)
{
    if (node->left)
        postorder(node->left);
    if (node->right)
        postorder(node->right);
    printf("%d\t", node->data);
}
