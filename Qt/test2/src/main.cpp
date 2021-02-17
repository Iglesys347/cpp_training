#include <QApplication>
#include <QPushButton>
 
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /*
    QPushButton bouton("Bonjour je suis un bouton");    //création du bouton avec texte
    bouton.setToolTip("Un bouton sur lequel on peut appuyer");  //légende du bouton
    bouton.setFont(QFont("Courier", 20, QFont::Bold, true));    //police "Courier", taille 20, gras et italique
    bouton.setCursor(Qt::PointingHandCursor);   // change le logo de la souris quand on passe sur le bouton
    bouton.setIcon(QIcon("img/risi.png"));  //ajout d'un logo au bouton
    bouton.show();  //affichage du bouton
    */
 
    // Création d'un widget qui servira de fenêtre
    QWidget fenetre;
    fenetre.setFixedSize(300, 150);
 
    // Création du bouton, ayant pour parent la "fenêtre"
    QPushButton bouton("Je suis un bouton !", &fenetre);
    // Personnalisation du bouton
    bouton.setFont(QFont("Comic Sans MS", 14));
    bouton.setCursor(Qt::PointingHandCursor);
    bouton.setIcon(QIcon("img/risi.png"));
    bouton.move(60, 50);    //on déplace le bouton
 
    // Affichage de la fenêtre
    fenetre.show();

    return app.exec();
}
