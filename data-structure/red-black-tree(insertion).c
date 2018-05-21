#include <stdio.h>

void create_nilnode(ROOT *r)
{
    r->nil  = (NODE*)malloc(sizeof(NODE));
    (r->nil)->clr = BLACK;
    r->r    = r->nil;
}

void left_rotate(ROOT *r, NODE *x)
{
    NODE *temp;
    temp = x->right;
    // turn temp's left subtree into x's right subtree
    x->right = temp->left;

    if(temp->left != r->nil) {
        (temp->left)->p = x;
    }

    temp->p = x->p; // link x's parent to temp

    if( x->p == r->nil)
    {
        r->r = temp;
    }
    else if( x == (x->p)->left)
    {
        (x->p)->left = temp;
    }
    else
    {
        (x->p)->right = temp;
    }

    temp->left = x; // put x on temp's left
    x->p = temp;
}

void right_rotate( ROOT *r, NODE *y)
{
    NODE *temp;

    temp = y->left;
    // turn temp's right subtree into y's left subtree
    y->left = temp->right;

    if( temp->right != r->nil)
    {
        (temp->right)->p = y;
    }

    temp->p = y->p; // link y's parent to temp

    if( y->p == r->nil)
    {
        r->r    = temp;
    }
    else if( y == (y->p)->left)
    {
        (y->p)->left    = temp;
    }
    else
    {
        (y->p)->right   = temp;
    }

    temp->right = y; // put y on temp's right
    y->p        = temp;
}

void insert_node( ROOT *r, int key)
{
    NODE *n     = (NODE *)malloc(sizeof(NODE));
    NODE *temp  = r->r;
    NODE *p     = r->nil;

    n->left     = r->nil;
    n->right    = r->nil;
    n->clr      = RED;
    n->key      = key;

    // find the position that new node can be inserted.
    while( temp != r->nil)
    {
        p   = temp;

        if( key > temp->key)
        {
            temp    = temp->right;
        }
        else
        {
            temp    = temp->left;
        }
    }

    n->p    = p; // link new node to p

    if( p == r->nil)
    {
        r->r    = n;
    }
    else if( key > p->key)
    {
        p->right    = n;
    }
    else
    {
        p->left     = n;
    }

    insert_fixup( r, n);
}

void insert_fixup( ROOT *r, NODE *x)
{
    NODE *u = NULL;;

    while( (x->p)->clr == RED)
    {
        if( x->p == (x->p->p)->left)
        {
            u   = (x->p->p)->right;

            // process property 4 of the red-black properties.
            if( u->clr == RED)
            {
                (x->p)->clr = BLACK;
                u->clr      = BLACK;

                (x->p->p)->clr  = RED;

                x   = (x->p->p);
            }
            // process property 5
            else
            {
                if( x == (x->p)->right)
                {
                    x   = (x->p);

                    left_rotate( r, x);
                }

                (x->p)->clr     = BLACK;
                (x->p->p)->clr  = RED;

                right_rotate( r, (x->p->p));
            }
        }
        else
        {
            u   = (x->p->p)->left;

            // process property 4 of the red-black properties.
            if( u->clr == RED)
            {
                (x->p)->clr = BLACK;
                u->clr      = BLACK;

                (x->p->p)->clr  = RED;

                x   = (x->p->p);
            }
            // process property 5
            else
            {
                if( x == (x->p)->left)
                {
                    x   = (x->p);

                    right_rotate( r, x);
                }

                (x->p)->clr     = BLACK;
                (x->p->p)->clr  = RED;

                left_rotate( r, (x->p->p));
            }
        }
    }

    // correct the lone violation of property 2.
    (r->r)->clr = BLACK;
}
