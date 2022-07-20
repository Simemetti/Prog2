/*
 * tipo.cc
 *
 *  Created on: 20 jul 2022
 *      Author: Simone
 */

#include "lista.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/**
 * funzione agenda che carica in una lista un nuovo evento
 *
 * carica nella lista passata e ne modifica il contentuto aggiungendo
 * il nuovo evento.
 * controllando prima se per quella data e ora ha gia un altro impegno
 *
 * @param l Lista della aggenda passata per parametro
 * @param app un evento da inserire
 */
void agenda (lista &l, tipo_inf app){
	if(search(l,app) == NULL) 
        l = insert_elem(l,new_elem(app));
    else cout<<"Orario occupato"<<endl;
}

/**
 * funzione che stampa una lista di appuntamenti
 * 
 * @param l lista che viene stampata
 */
void stampa(lista l) {
    lista tmp = l;
    while(tmp != NULL) {
        print(head(tmp));
        tmp = tail(tmp);
    }
}

/**
 * funzione che legge la lista di appuntamenti contenuta nel file "agenda.txt"
 * 
 * @return lista ottenuta
 */
lista read_file() {
    lista apps = NULL;

    ifstream file("agenda.txt");
    appuntamento app;

    while(file >> app.data >> app.orai >> app.oraf) {
        file.ignore();
        file.getline(app.descr,sizeof(app.descr));
        agenda(apps,app);
    }

    return apps;
}

/**
 * funzione che stampa quanti appuntamenti precedono e seguono un certo appuntamento, nello stesso giorno
 * 
 * @param agenda lista degli appuntamenti
 * @param app appuntamento in questione
 */
void quanti(lista agenda, appuntamento app) {
    int pre = 0;
    int post = 0;
    
    while(agenda != NULL) {
        if(strcmp(head(agenda).data,app.data) == 0) {
            if(strcmp(head(agenda).orai,app.oraf)>0){
                post++;
            }else if(strcmp(head(agenda).orai,app.oraf)<0){
                pre++;
            }
        }
        agenda = tail(agenda);
    }

    cout<<"Prima: "<<pre<<" Dopo: "<<post<<endl;
}

int main() {
    lista apps = read_file();
    stampa(apps);
    cout<<endl;
    appuntamento app;
    cout<<"Inserire appuntamento"<<endl;
    cin>>app.data>>app.orai>>app.oraf;
    quanti(apps,app);
}

