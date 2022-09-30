#include "mylib.h"

MyLib::MyLib()
{
    // force to load reasources
    Q_INIT_RESOURCE(resources);
}

QString MyLib::message()
{
    QString msg;
    QFile file(":/files/data/test.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream (&file);
        msg = stream.readAll();
        file.close();
    }
    return msg;
}

QString MyLib::test()
{
    QString message = "This is a test message";
    return message;
}
