#ifndef ARTICLE_H
#define ARTICLE_H
#include <QDateTime>
#include <QPair>

class Article
{
public:
    enum class Type {pass,service};
    QString *name;
    double *price;
    int *id;
    QPair<QString,int> *znizki;
    Type *type;
    int *timePeriod;
    Article();
    ~Article();
};

#endif // ARTICLE_H
