#include <stdlib.h>
#include <string.h>

#include "bistree.h"

static void destroy_right(BisTree * tree, BiTreeNode *node);

/*****************************************************************************
 * -----------------------------rotate_left--------------------------------- *
 ****************************************************************************/
static void rotate_left(BiTreeNode **node) {
    BiTreeNode *left,
               *granchild;

    left = bitree_left(*node);


    if(((AvlNode *)bitree_data(left))->factor == AVL_LFT_HEAVY) {
        /*****************************************************************************
        * Perform an LL rotation.                                                    *
        *****************************************************************************/
        bitree_left(*node) = bitree_right(left);
        bitree_right(left) = *node;
        ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
        ((AvlNode *)bitree_data(left))->factor = AVL_BALANCED;
        *node = left;
    } else {
        /*****************************************************************************
        * Perform an LR rotation.                                                    *
        *****************************************************************************/
        granchild = bitree_right(left);
        bitree_right(left) = bitree_left(granchild);
        bitree_left(granchild) = left;
        bitree_left(*node) = bitree_right(granchild);
        bitree_right(granchild) = *node;

        switch (((AvlNode *)bitree_data(granchild))->factor){
            case AVL_LFT_HEAVY:
                ((AvlNode *)bitree_data(*node))->factor = AVL_RGT_HEAVY;
                ((AvlNode *)bitree_data(left))->factor = AVL_BALANCED;
                break;
            case AVL_BALANCED: 
                ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
                ((AvlNode *)bitree_data(left))->factor = AVL_BALANCED;
                break;
            case AVL_RGT_HEAVY:
                ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
                ((AvlNode *)bitree_data(left))->factor = AVL_LFT_HEAVY;
                break;
        }

        ((AvlNode *)bitree_data(granchild))->factor = AVL_BALANCED;
        *node = granchild;
    }

    return;
}