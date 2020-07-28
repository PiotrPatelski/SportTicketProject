#ifndef TRANSANCTION_MENU_H
#define TRANSANCTION_MENU_H
#include <vector>
#include "article.h"
#include "customer.h"
///////////////////////////////////////////////////////////////////
//KLASA ZAWIERAJĄCA SPIS PRODUKTÓW/USŁUG DOSTĘPNYCH DO SPRZEDARZY//
///////////////////////////////////////////////////////////////////

class Transanction_Menu
{
public:

    std::vector<Article>* articles;

    Transanction_Menu();
    bool Add_Article();
    bool Remove_Article();
    bool Add_To_Basket(Article*,Customer*);
    bool Update_DB();
    Article* Fetch_From_DB();
    ~Transanction_Menu();
};

#endif // TRANSANCTION_MENU_H
