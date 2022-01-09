#ifndef WPOINTA_H
#define WPOINTA_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct wptst {
    char name[20];
    int number;
    int age;
};

int wpointa_test(void);
int phenkan(struct wptst **wp);

#endif