#include <iostream>

using namespace std;

int main()
{
    int unEntier(10);
    int *pointer(0);    //!\ TOUJOURS DONNER UNE VALEUR À UN POINTEUR QU'ON DÉCLARE !!!
    pointer = &unEntier;    //&a = l'adresse de a
    cout << "Voici l'adresse du pointer : " << pointer << endl;
    cout << "Voici la valeur du pointer : " << *pointer << endl;

    //Allocation de mémoire : new type
    int *pointer2(0);
    pointer2 = new int;

    *pointer2 = 2;  //on modifie la veleur contenue dans la case mémoire

    delete pointer2;    //on libère la case mémoire
    pointer = 0;        //on indique que le pointer ne pointe plus vers rien (très important)

    return 0;
}