//
// Created by jonas on 06/02/2025.
//


#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int val;
    struct Element* left_ancestor;
    struct Element* right_ancestor;
} Element;

void add_element(Element* tree, int val);
Element* create_element(int val, Element* left, Element* right);
void print_tree(Element* tree);
void print_tree_recursive(Element* tree);

int main_4_14() {
    int val = 17;
    int min = -12;
    int max = 27;

    Element tree = {val, NULL, NULL};

    for (int i = min; i <= max; i++) {
        if (i == val) continue;
        add_element(&tree, i);
    }

    print_tree(&tree);

    return 0;
}


void add_element(Element* tree, int val) {
    if (val > tree->val) {
        if (tree->right_ancestor == NULL) {
            tree->right_ancestor = create_element(val, NULL, NULL);
        }
        else {
            add_element(tree->right_ancestor, val);
        }
    }
    else if (val < tree->val) {
        if (tree->left_ancestor == NULL) {
            tree->left_ancestor = create_element(val, NULL, NULL);
        }
        else {
            add_element(tree->left_ancestor, val);
        }
    }
    // Im Falle der Gleichen Zahl -> kein Einfügen möglich, Set nicht list (Oder wie Luca einfach immer rechts / immer links einfügen)
}

Element* create_element(int val, Element* left, Element* right) {
    Element* e = malloc(sizeof(Element));
    e->val = val;
    e->left_ancestor = left;
    e->right_ancestor = right;

    return e;
}


void print_tree(Element* tree) {
    printf("Tree: ");
    print_tree_recursive(tree);
    printf("\n");
}

void print_tree_recursive(Element* tree) {
    if (tree == NULL)
        return;

    print_tree_recursive(tree->left_ancestor);
    printf("%i ", tree->val);
    print_tree_recursive(tree->right_ancestor);
}
