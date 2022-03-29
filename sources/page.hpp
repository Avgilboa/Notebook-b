#include "Line.hpp"
#include "Direction.hpp"

class page{
    private:
        unsigned int numPage;
        std::vector<Line> lines;
        int numLines;

        bool setLine(unsigned int numLine);
        void addLines();
        Line getLine(int numLine) {return lines.at((unsigned long) numLines);}
        unsigned int getNumPage(){return numPage;} 
    public:

        void write(unsigned int  row, unsigned int column, ariel::Direction dir,const std::string & str);        ///V
        std::string read(unsigned int row,unsigned int column, ariel::Direction dir,unsigned int len);               ///V
        void erase(unsigned int row, unsigned int column, ariel::Direction dir,unsigned int len);                        ///V
        void show();                                                                          ///V



        page(unsigned int numpage);                                                                    ///V

        //void validPage(int numsPage);                                                         ///
};