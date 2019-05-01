/*
 * =====================================================================================
 *
 *       Filename:  linkedlist.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/25/2015 09:25:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdio>
using namespace std;
struct node{
    int value;
    node *next;
};
void initList(struct node *n, int v){
    n->value = v;
    n->next = 0;
}
void pushBack(struct node **n, struct node *a){
//    cout << " *n:" << (*n) << endl;
    if(!(*n)){
        *n = a;
        return;
    } else pushBack(&((*n)->next), a);
}
void push(struct node **n, struct node *a){
//    printf("before: %d\n", (*n)->value);
    a->next = *n;
    *n = a;
//    cout << (*n)->value << " " << (*n)->next->value << endl;
    return;
}
struct node *popFront(struct node **n){
    struct node *front = *n;
    *n = (*n)->next;
    return front;
}
struct node *popEnd(struct node **n){
//    cout << " " << (*n)->value << endl;
    if(!(*n)) return 0;
    if(!((*n)->next->next)) {
        node *end = (*n)->next;
        (*n)->next = 0;
        return end;
    }
    else return popEnd(&((*n)->next));
}
struct node *findNode(struct node *n, int v){
    if(!n) return 0;
    struct node *temp = n;
    while(temp->value != v){
        temp = temp->next;
        if(temp == 0) break;
    }
    return temp;
}
void insertAfter(struct node **n, struct node *a, int v){
    struct node *targetNode = findNode(*n, v);
    if(!targetNode) return;
    a->next = targetNode->next;
    targetNode->next = a;
    return;
}
void deleteNode(struct node **n, int v){
    if(!(*n)) return;
    if((*n)->value == v){
       *n = (*n)->next;
       return;
    }
    if((*n)->next && (*n)->next->value == v){
        (*n)->next = (*n)->next->next;
        return;
    }
    if((*n)->next) deleteNode(&((*n)->next), v);
    return;
}
void printList(struct node *n){
    struct node *temp = n;
    while(temp){
        int v = temp->value;
        printf("%d",v);
        printf("\n");
        temp = temp->next;
    }
}
int main(){
    struct node *root;
    root = new node;
    initList(root, 3);
    struct node *one;
    one = new node;
    initList(one, 1);
    struct node *two;
    two = new node;
    initList(two, 2);
    struct node *four;
    four = new node;
    initList(four, 4);
    cout << four << endl;
    printList(root);
//    struct node **test = &root;
//    struct node **test2 = &((*test)->next);
//    cout << (*test2);
//    cout << "fuck\n";
    cout << "Push 4, pushback 1, pushback 2\n";
    push(&root, four);
    pushBack(&root, one);
    pushBack(&root, two);
    printList(root);
    cout << "Insert 9 after 2\n";
    struct node *nine;
    nine = new node;
    initList(nine, 9);
    insertAfter(&root, nine, 2); 
    printList(root); 
    cout << "Pop end \n";
    struct node *end = popEnd(&root);
    cout << end->value << endl;
    cout << "New list: \n";
    printList(root);
    cout << "Push 5\n";
    struct node *five = new node;
    initList(five, 5);
    push(&root, five);
    printList(root);
    cout << "Pop front\n";
    struct node *front = popFront(&root);
    cout << front->value << endl;
    cout << "New list\n";
    printList(root);
    cout << "Delete 2\n";
    deleteNode(&root, 2);
    printList(root);
    cout << "Delete 4\n";
    deleteNode(&root, 4);
    printList(root);
    cout << "Delete 3\n";
    deleteNode(&root, 3);
    printList(root);
    cout << "Delete 1\n";
    deleteNode(&root, 1);
    printList(root);
}

