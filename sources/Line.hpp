#include <iostream>
#include <string>
#include <vector>
//#include <Direction.hpp>
constexpr unsigned int Linelen = 100;
constexpr unsigned int extra_pages = 30;
constexpr unsigned int add_pages = 10;
class Line
{
private:
    std::vector<char> line;
    void isValid(unsigned int & column,const std::string & str);                                 //   X    
    static void validCharWrite(unsigned int & column,char write_char);                                  //   V   
    static void validPos(unsigned int & column,unsigned int len);     
public:
        void write(unsigned int  column,const std::string & str);                                //   v
        std::string read(unsigned int column,unsigned int len);                                                  //   v
        void erase(unsigned int  column,unsigned int len);                                                 //   V
        const std::vector<char> getLine(){return line;}                                        //   V
        const char getchar(unsigned long index){
            if(index>99){
                throw std::runtime_error("out of index");
        }
        return line.at(index);}                                                                    //   V

        Line();                                                                                //   v
};
