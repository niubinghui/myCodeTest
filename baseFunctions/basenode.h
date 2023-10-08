/* *********************
 * Filename: basenode.h
 * Function: define some base function of list nodes
 * Encoding: UTF-8
 ********************* */
#ifndef __BASE_FUNCTION_BASE_NODE_H__
#define __BASE_FUNCTION_BASE_NODE_H__

#define __TRY_BASE_FUNCTION_BASENODE__

typedef struct _basic_node_t bnode_t;

/*
 * 区分链表、图、树结构
 */
typedef struct _basic_list_t blist_t;
typedef struct _basic_graph_t bgraph_t;
typedef struct _basic_tree_t btree_t;

/* 双向链表，需要两个指针分别指向链表两端 */
struct _basic_list_t {
    /* 指向所在的node结点 */
    struct _basic_node_t * lnode_bnode;

    blist_t * lnode_head;
    blist_t * lnode_front;
    blist_t * lnode_next;
};

int list_insert_node_front(blist_t *, blist_t *);
int list_insert_node_next(blist_t *, blist_t *);
int list_delete_node(blist_t *);
int list_exist_circle(blist_t *);
int list_list_length(blist_t *);

/* 图结构，需要两个链表，前序节点及后序节点 */
struct _basic_graph_t {
    /* 指向所在的node结点 */
    struct _basic_node_t * gnode_bnode;

    unsigned int gnode_front_num;
    unsigned int gnode_next_num;
    blist_t * gnode_front;
    blist_t * gnode_next;
};

/* 树结构，记录父节点，子节点，若为多叉树结构，需要链表记录子节点 */
typedef struct _basic_binary_tree_t {
    btree_t * lchild;
    btree_t * rchild;
} btree_binary_t;

typedef struct _basic_normal_tree_t {
    btree_t * child;
    btree_t * next;
} btree_normal_t;

struct _basic_tree_t {
    /* 指向所在的node结点 */
    struct _basic_node_t * tnode_bnode;

    btree_t * tnode_root;
    btree_t * tnode_parent;
    union _tnode_child {
        btree_binary_t tnode_binary;
        btree_normal_t tnode_normal;
    } tnode_child;
};

struct _basic_node_t {
    unsigned int    bnode_type:4;
    unsigned int    bnode_reserve:28;

    unsigned int    bnode_length;
    unsigned int    bnode_size;

    /* 会按照8字节进行字节对齐 */
    union _bnode_pointer {
        blist_t bnode_list;
        bgraph_t bnode_graph;
        btree_t bnode_tree;
    } bnode_pointer;
};

#define NODE_HEAD_LENGTH    sizeof(basic_node_t)

#endif