#include "Notebook.hpp"

void valid_pos(int page, int row, int column){
    if(page<0 || row < 0 || column < 0  || column > Linelen-1){
        throw std::runtime_error ("the number is not good");
    }
}
namespace ariel{
Notebook::Notebook(){
    this->_totalPages =0;
    this->_page.push_back(page(0));
}

void Notebook::write(int spage, int srow, int scolumn, ariel::Direction dir,const std::string & str){
        try{
            valid_pos(spage,srow,scolumn);
            setPage(spage);
            unsigned int page = (unsigned int) spage;
            unsigned int row =(unsigned int) srow;
            unsigned int column =(unsigned int) scolumn;
            this->_page.at(page).write(row,column,dir,str);}
        catch(std::exception&){
            throw std::runtime_error ("can't write on this conditions");
        }
}

void Notebook::erase(int spage,int srow, int scolumn, ariel::Direction dir,int slen){
        try{
            valid_pos(spage,srow, scolumn);
            setPage(spage);
            if(slen <0){throw std::runtime_error ("the length is negative");}
            unsigned int page = (unsigned int) spage;
            unsigned int row =(unsigned int) srow;
            unsigned int column =(unsigned int) scolumn;
            unsigned int len =(unsigned int) slen;
            this->_page.at(page).erase(row,column,dir,len);
        }
        catch(std::exception&){
            throw std::runtime_error ("can't earse on this conditions");
        }
}

std::string Notebook::read(int spage, int srow, int scolumn, ariel::Direction dir,int len){
        try{
            valid_pos(spage,srow,scolumn);
            if(len<0){throw std::runtime_error("the length is negative number");}
            setPage(spage);
            unsigned int page = (unsigned int) spage;
            unsigned int row =(unsigned int) srow;
            unsigned int column =(unsigned int) scolumn;
            return this->_page.at(page).read(row,column,dir,(unsigned int) len);
        }
        catch(std::exception&){
            throw std::runtime_error ("can't read on this conditions");
}
}

void Notebook::show(int page){
        try {
            setPage(page);
            this->_page.at((unsigned int)page).show();
        }
        catch(std::exception&){
            throw std::runtime_error ("can't earse on this conditions");
    }
}



page Notebook::getPage(int numPage){
    if(validPage(numPage)){
        return this->_page.at((unsigned int) numPage);
    }
    throw std::runtime_error ("there is no such page yet");
}



void Notebook::setPage(int numPage){
    if(numPage < 0){
        throw std::runtime_error ("there is alot of empty paper before, use them!");
    }
    while(_totalPages<numPage){
        this->_totalPages+=1;
        this->_page.push_back(page(this->_totalPages));
    }
}
}


