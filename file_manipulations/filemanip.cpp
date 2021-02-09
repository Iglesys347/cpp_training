#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string const fileName("files/fichier.txt");
    ofstream flux(fileName.c_str());    //créé un fichier (remplca tout fichier de même nom) 
    if(flux)
    {
        flux << "Bonjour," << endl;
        flux << "J'écris dans ce fichier de manière opportune" << endl;
        int valeur(10);
        flux << "J'ai envie d'écrire un nombre : " << valeur << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    ofstream flux2("files/file1.txt", ios::app);    //app=append, on ouvre le fichier sans le supprimer
    if(flux2)
    {
        flux2 << endl << "J'ai été ajouté au fichier sans le supprimer !" << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    //On va maintenant lire des fichiers :
    ifstream fluxLecture("files/file1.txt");    //ouverture en mode lecture
    if (fluxLecture)
    {
        // Lecture ligne par ligne :
        string ligne;
        while(getline(fluxLecture, ligne))  //lecture de la ligne; getline renvoie aussi un booléen vrai si on peut continuer de lire, faux sinon
        {
            cout << ligne << endl;
        }

        // Lecture mot par mot :
        string mot;
        fluxLecture >> mot;  //lecture du premier mot
        fluxLecture.ignore();   //pour puvroir combiner get line et >>

        // Lecture caractère par caractère : 
        char a;
        fluxLecture.get(a);

        // Position du curseur dans le fichier
        int pos = fluxLecture.tellg();  //donne la position dans le fichier (tellp pour in ofstream)
        fluxLecture.seekg(10, ios::beg);    //place le curser 10 caractères après le début du fichier
        // On utilisera seekp pour un ofstream ; le deuxième paramètre peut prendre 3 valeurs :
                                                // ios::beg = début du fichier
                                                // ios::end = fin
                                                // ios::cur = position actuelle

        // Taille du fichier :
        fluxLecture.seekg(0, ios::end); //on se met à la fin
        int taille;
        taille = fluxLecture.tellg();   //on récupère la position = taille
        cout << "Le fichier fait :" << taille << endl;

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    
    /*
    flux2.close();  //ferme le fichier (pas nécéssaire il se ferme tout seul)
    flux2.open("files/file1");    //ouvre le flux
    */
    return 0;
}