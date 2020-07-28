#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QDateTime>
#include "basket.h"
#include "article.h"

class Customer
{
public:
    enum class State{active,inactive,suspended};
    QDateTime *dateOfRegistration = new QDateTime;
    QDateTime *dateLastActive = new QDateTime;
    QString *photoPath = new QString;
    QString *name = new QString;
    QString *surname = new QString;
    QString *email = new QString;
    Basket *customersBasket;
    Basket *debts;
    State *state;

    Customer();
    bool addCustomer();
    bool removeCustomer();
    bool updateDb();
    bool addToBasket(Article*);
    bool suspendCustomer();
    bool unsuspendCustomer();
    ~Customer();

};

#endif // CUSTOMER_H
