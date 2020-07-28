#ifndef BASKET_H
#define BASKET_H
#include <QDateTime>
#include <boughtarticle.h>
class Basket
{
public:

    int* idCounter;
    std::tuple<int*,QString*,QString*,QDateTime*,double*,QDateTime*,QDateTime*,int*> basket;

    Basket();
    bool addToBasket(BoughtArticle*);
    bool removeFromBasket(BoughtArticle*);
    ~Basket();

};

#endif // BASKET_H
