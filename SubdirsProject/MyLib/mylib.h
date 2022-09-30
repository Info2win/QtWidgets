#ifndef MYLIB_H
#define MYLIB_H

#include "MyLib_global.h"
#include <QString>
#include <QFile>
#include <QTextStream>

class MYLIB_EXPORT MyLib
{
public:
    MyLib();
    QString message();
    QString test();
};

#endif // MYLIB_H
