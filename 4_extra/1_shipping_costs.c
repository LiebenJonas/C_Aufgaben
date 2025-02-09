//
// Created by jonas on 08.02.2025.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Liste (Order) erstellen:
typedef enum Item_Type { UNKNOWN, O1, O2, O3, O4, O5, O6 } Item_Type;

typedef struct Item {
    Item_Type item;
    char *name;
    double price;
} Item;

typedef struct Order_Node {
    Item item;
    int count;
    struct Order_Node *next;
} Order_Node;

int equals_items(Item *i1, Item *i2) {
    if (i1 == NULL || i2 == NULL) {
        return i1 == i2;
    }
    return i1->item == i2->item
           && i1->price == i2->price
           && i1->name == i2->name;
}

Order_Node *create_node(Item i, int count, Order_Node *next) {
    Order_Node *ret = malloc(sizeof(Order_Node));
    ret->item = i;
    ret->count = count;
    ret->next = next;

    return ret;
}

void add_item(Order_Node *order, Item i, int count) {
    if (order == NULL)return;

    // wird ein Item einer Liste hinzugefügt, dann gibt es zwei verschiedene Optionen:
    //  1. Exakt dieses Item ist bereits vorhanden -> Anzahl erhöhen
    //  2. Dieses Item ist bisher nicht vorhanden -> hinzufügen

    if (equals_items(&order->item, &i)) {
        // Anzahl erhöhen
        order->count += count;
        return;
    }
    if (order->next == NULL) {
        // Item nicht in der Liste enthalten
        Order_Node *node = create_node(i, count, NULL);
        order->next = node;
        return;
    }
    add_item(order->next, i, count);
}

void remove_last_order_node(Order_Node *list) {
    if (list == NULL || list->next == NULL)return;
    if (list->next->next == NULL) {
        free(list->next);
        list->next = NULL;
        return;
    }
    remove_last_order_node(list->next);
}

void clear_list(Order_Node *list) {
    if (list == NULL)return;
    while (list->next != NULL)
        remove_last_order_node(list);
}

void merge_orders(Order_Node *order1, Order_Node *order2) {
    if (order2 == NULL) return;
    if (order1 == NULL) {
        order1 = order2;
        return;
    }


    while (order2 != NULL) {
        add_item(order1, order2->item, order2->count);
        order2 = order2->next;
    }

    //Liste order2 löschen
    clear_list(order2);
    free(order2);
}

void print_order(Order_Node *order) {
    if (order == NULL)return;

    printf("Position:\tItemname: %s,\tPrice: %.2lf,\tCount: %d,\tTotal: %.2lf\n", order->item.name, order->item.price,
           order->count, order->count * order->item.price);
    if (order->next == NULL) {
        printf("\n");
    }
    print_order(order->next);
}


/*
 *
 *
 *  Bis hier hin: Funktionen der Liste
 *
 *
 */

const Item valid_items[] = {
    {UNKNOWN, "UNKNOWN", -1},
    {O1, "Oszilloskop 1", 349.99},
    {O2, "Oszilloskop 2", 249.99},
    {O3, "Oszilloskop 3", 149.99},
    {O4, "Oszilloskop 4", 49.99},
    {O5, "Oszilloskop 5", 22.99},
    {O6, "Oszilloskop 6", 120.99}
};


int main_4extra_1() {
    Order_Node *order = create_node(valid_items[1], 5, NULL);
    add_item(order, valid_items[1], 5); // -> 10x O1
    add_item(order, valid_items[1], 2); // -> 12x O1

    add_item(order, valid_items[2], 2); // -> 2x O2
    add_item(order, valid_items[2], 1); // -> 3x O2
    add_item(order, valid_items[2], 11); // -> 14x O2

    add_item(order, valid_items[3], 1); // -> 1x O3

    add_item(order, valid_items[5], 1); // -> 1x O5

    add_item(order, valid_items[6], 1); // -> 1x O6

    // Order 2
    Order_Node *order2 = create_node(valid_items[1], 5, NULL);
    add_item(order2, valid_items[1], 1); // -> 10x O1
    add_item(order2, valid_items[1], 3); // -> 12x O1

    add_item(order2, valid_items[2], 2); // -> 2x O2
    add_item(order2, valid_items[2], 1); // -> 3x O2
    add_item(order2, valid_items[2], 21); // -> 14x O2

    add_item(order2, valid_items[3], 4); // -> 1x O3

    add_item(order2, valid_items[5], 2); // -> 1x O5

    add_item(order2, valid_items[6], 9); // -> 1x O6


    printf("Liste 1:\n");
    print_order(order);
    printf("Liste 2:\n");
    print_order(order2);

    merge_orders(order, order2);
    printf("Liste merged:\n");
    print_order(order);
}
