#include "page.hpp"

page::page(unsigned int numPage){
    //validPage(numPage);           ////the page not already exsist and do not have more then 10 empty pages before.
    this->numPage = numPage;
    this->numLines =-1;
    addLines();
}

void page::write(unsigned int  row, unsigned int column, ariel::Direction dir,const std::string & str){
    if(setLine(row)){
            for(unsigned int i=1; i<str.length();i++){
                if(str.at(i)=='~' || 0==std::isprint(str.at(i))){throw std::runtime_error("this char is not printable");}
            }
        if(dir==ariel::Direction::Horizontal){this->lines.at(row).write(column,str);}
        if(dir==ariel::Direction::Vertical && column >=0 && column <Linelen){
            for(unsigned int i=0;i<str.length();i++){
                std::string s;
                s.push_back(str[i]);
                lines.at(row+i).write(column, s);
                lines.push_back(Line());
                this->numLines++;
                }
        }
    }
}

void page::erase(unsigned int row, unsigned int column, ariel::Direction dir,unsigned int len){
    if(ariel::Direction::Horizontal==dir){
        this->lines.at(row).erase(column, len);}
    if(ariel::Direction::Vertical ==dir){
        if(column>Linelen-1 || column<0){throw std::runtime_error ("this is out of bounds");}
        for(unsigned i=0;i<(unsigned int) len;i++){
            lines.at(row+i).erase(column,1);
            lines.push_back(Line());
            this->numLines++;
        }
    }
}

std::string page::read(unsigned int row,unsigned int column, ariel::Direction dir,unsigned int len){
    if(column<0 && column>Linelen){
        throw std::runtime_error ("there is no colomn!");
    }
    if(ariel::Direction::Horizontal==dir){
        return this->lines.at(row).read(column,len);
    }
    std::string s;
//    if(ariel::Direction::Vertical==dir) {
        
        for(unsigned int i=0; i<len;i++){
            if(row+i >numLines){
                this->lines.push_back(Line());
                this->numLines++;
            }
            s+=lines.at(row+i).getchar(column);
        }
 //   }
    return s;
} 

void page::show(){
    unsigned int start=0;
    unsigned int end=(unsigned int) this->numLines;
        for(unsigned int i=start;i<=end;i++){
            std::cout << lines.at(i).read(0,Linelen) <<std::endl;
        }
} 

bool page::setLine(unsigned int numLine){
    while(this->numLines<numLine){
        addLines();
    }
    return true;
}
 void page::addLines(){
    for(unsigned int i=0;i<add_pages;i++){
        this->lines.push_back(Line());
    }
    numLines+=add_pages;
}