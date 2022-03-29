#include "page.hpp"
namespace ariel {
class Notebook{
    private:
        unsigned int _totalPages;
        std::vector<page> _page;
        bool validPage(int page){return(page<=_totalPages);}
    public:
        void show(int page);
        void write(int page, int row, int column, ariel::Direction dir,const std::string & str);        ///V
        std::string read(int page, int row, int column, ariel::Direction dir,int len);                  ///V
        void erase(int page,int row, int column, ariel::Direction dir,int len);                         ///V
        page getPage(int numPage);                                                                             ///V
        void setPage(int numPage);                                                                             ///V
        Notebook();
};
}
