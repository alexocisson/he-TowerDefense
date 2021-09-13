#include <mainmenu.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu s;
    s.show();
    return a.exec();
}
