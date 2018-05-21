#include <stdio.h>
#include <malloc.h>

#define MAX 100

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
    struct node *p;
}NODE;

NODE* search_node( NODE *, int);
void insert_node( NODE **, int);
void delete_node( NODE **, int);
void display_node( NODE *);

int main( void)
{
    NODE *root  = NULL;

    insert_node( &root, 50);
    insert_node( &root, 30);
    insert_node( &root, 70);
    insert_node( &root, 25);
    insert_node( &root, 40);
    insert_node( &root, 60);
    insert_node( &root, 80);
    insert_node( &root, 15);
    insert_node( &root, 35);
    insert_node( &root, 45);

    delete_node( &root, 30);
    delete_node( &root, 50);

    display_node( root);
    return 0;
}

/*
    search_node( NODE *, int)
    find the node that has the key.
*/
NODE* search_node( NODE *t, int key)
{
    while( t != NULL && t->key != key)
    {
        if( t->key > key)
        {
            t   = t->left;
        }
        else
        {
            t   = t->right;
        }
    }

    return t;
}

/*
    insert_node( NODE **, int)
    Insert the key in the tree.
*/
void insert_node( NODE **t, int key)
{
    NODE *n     = (NODE *)malloc(sizeof(NODE));
    NODE *temp  = *t; // temporary node.

    n->key  = key;
    n->p    = NULL;
    n->left = NULL;
    n->right= NULL;

    // if there is not any node.
    if( temp == NULL)
    {
        *t  = n;

        return;
    }

    // find the position that new node will be inserted.
    while( temp != NULL)
    {
        n->p    = temp;

        if( temp->key > key)
        {
            temp    = temp->left;
        }
        else
        {
            temp    = temp->right;
        }
    }

    // insert new node in the tree.
    if( (n->p)->key > key)
    {
        (n->p)->left = n;
    }
    else
    {
        (n->p)->right = n;
    }

}

/*
    delete_node( NODE **, int)
    After finding the key that you want,
    remove that from the tree.
*/
void delete_node( NODE **t, int key)
{
    NODE *temp  = NULL;
    NODE *p     = NULL;

    // find the node that has the key.
    temp    = search_node( *t, key);

    // if there is not key.
    if( temp == NULL)
    {
        printf("Can't find the key!\n");

        return;
    }

    // if the node that has the key don't have children.
    if( temp->left == NULL && temp->right == NULL)
    {
        if( temp == *t)
        {
            *t  = NULL;
        }
        else if( (temp->p)->key > key)
        {
            (temp->p)->left = NULL;
        }
        else
        {
            (temp->p)->right= NULL;
        }

        free(temp);
    }
    // if the node don't have a left child.
    else if( temp->left == NULL)
    {
        temp->key   = (temp->right)->key;

        delete_node( &(temp->right), (temp->right)->key);
    }
    // if the node don't have a right child.
    else if( temp->right == NULL)
    {
        temp->key   = (temp->left)->key;

        delete_node( &(temp->left), (temp->left)->key);
    }
    else // if the node have children.
    {
        p   = temp;

        temp    = temp->right;

        while(temp->left != NULL)
        {
            temp    = temp->left;
        }

        p->key  = temp->key;

        delete_node( &(p->right), temp->key);
    }
}

/*
    display_node( NODE *)
    display all nodes in the tree by depth first search(DFS).
*/
void display_node( NODE *t)
{
    if( t == NULL)
    {
        return;
    }

    printf("NODE [%d] > ", t->key);

    if( t->left != NULL)
    {
        printf("LEFT [%d] ", (t->left)->key);
    }
    if( t->right != NULL)
    {
        printf("RIGHT [%d]", (t->right)->key);
    }
    printf("\n");

    if( t->left)
    {
        display_node( t->left);
    }
    if( t->right)
    {
        display_node( t->right);
    }
}
