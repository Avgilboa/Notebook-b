#include "Line.hpp"


    Line::Line(){
    for(unsigned int i=0;i<Linelen;i++){this->line.push_back('_');}
    }

    void Line::write(unsigned int column,const std::string & str){
        isValid(column,str);
        validPos(column,str.length());
        for(unsigned int i = 0;i<str.length();i++){if(std::isprint(str.at(i))==0){ throw std::runtime_error ("this is illigal char"); }}
        for(unsigned int i = 0;i<str.length();i++){
            validCharWrite(column, line.at(column+i));
            line.at(column+i) = str.at(i);
        }
    }
    
    void Line::erase(unsigned int  column,unsigned int len){
        validPos(column,len);
        for(unsigned  int i = 0;i<len;i++){
            line.at(column+i) =  '~';
        }
    }

    std::string Line::read(unsigned int column,unsigned int len){
        //validPos(column,len);
        std::string str;
        for(unsigned int i=column;i<column+len;i++){str+=line.at(i);}
        return str;
    }





    void Line::validCharWrite(unsigned int & column,char write_char){
            if(write_char=='\n' || write_char < ' ' || write_char>'~'){throw std::runtime_error("You can't write in this location!");}
    }
    void Line::validPos(unsigned int & column,unsigned int len){
        if(column+len>Linelen || column< 0){
                throw std::runtime_error ("The writing will eceed the line length");
            }
    }
    void Line::isValid(unsigned int & column,const std::string & str){
        for(unsigned int i=0; i<str.length();i++){
            if(this->line.at(column+i)!='_'){
                throw std::runtime_error("You already write in this place before!");
            }
        }
    }