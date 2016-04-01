#ifndef DATA_H
#define DATA_H

#include <boost/array.hpp>
#include <fstream>
#include <qstring.h>
#include <qvector.h>
#include <qdebug.h>

typedef boost::array< double , 2 > state_type;

class Data
{
    public:
        Data();
        void operator() (const state_type &x , const double t)
        {
            std::ofstream f("data.csv", std::ofstream::out | std::ofstream::app);
            f << QString::number(t,'d', 5).toStdString() << ';' << QString::number(x[0],'d', 15).toStdString() << ';' << QString::number(x[1],'d', 15).toStdString() << std::endl;
            f.close();
        }
    private:


        //std::ofstream file;
};

#endif // DATA_H
