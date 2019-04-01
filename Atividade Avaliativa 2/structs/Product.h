#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

struct product{
	int code;
    char name[20];
    float price;
};
typedef struct product Product;

#endif // PRODUCT_H_INCLUDED
