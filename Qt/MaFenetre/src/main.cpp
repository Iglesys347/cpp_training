#include <QApplication>
#include "MaFenetre.h"
 
 
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
 
    //MaFenetre fenetre;
    MaFenetre fenetre(1280,720);
    fenetre.show();
 
    return app.exec();
}