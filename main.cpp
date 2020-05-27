#include <iostream>
#include "order.cpp"
#include <stdlib.h>

using namespace std;

///2 ecrane, un ecran = client  si celalalt ii ala dupa tesghia

void client_interface(){
    cout<<"INTERFATA CLIENT"<<endl;
    cout<<"1.Pune-te la coada"<<endl;
    cout<<"2.Vezi coada"<<endl;
    cout<<"Scrie 1 sau 2 pentru a selecta optiunea"<<endl;

    int choice;
    cin>>choice;
    system("CLS");
    OrderQueue order;

    if (choice==1){
        order.create_from_file();
        cout<<"Intodu numele"<<endl;
        char nume[30];

        cin>>nume;
        order.add(nume);
        system("CLS");
    }

    else{
        order.create_from_file();
        order.show();
        system("PAUSE");
        system("CLS");
    }
}

void seller_interface(){
    cout<<"INTERFATA SELLER"<<endl;
    cout<<"1.Elimina primul din coada"<<endl;
    cout<<"2.Vezi coada"<<endl;
    cout<<"Scrie 1 sau 2 pentru a selecta optiunea"<<endl;
    int choice;
    cin>>choice;
    system("CLS");
    OrderQueue order;

    if (choice==1){
        order.create_from_file();
        order.remove_first();
        system("CLS");
    }

    else{
        order.create_from_file();
        order.show();
        system("PAUSE");
        system("CLS");
    }
}



int main()
{
    cout<<"1.Client"<<endl<<"2.Seller"<<endl;
    cout<<"Scrie 1 sau 2 pentru a selecta optiunea"<<endl;
    int choice;
    cin>>choice;
    system("CLS");
    if(choice==1)
        while(true)
            client_interface();
    else if(choice==2)
        while(true)
            seller_interface();
    else
        cout<<"Optiune gresita, programul va iesi!";

    return 0;
}
