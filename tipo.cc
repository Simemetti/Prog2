/*
 * tipo.cc
 *
 *  Created on: 20 jul 2022
 *      Author: Simone
 */
#include <cstring>
#include <iostream>

using namespace std;

#include "tipo.h"

/*******************************/
/* DEFINIZIONE MODULO "liste" */
/*******************************/

int compare(tipo_inf a1, tipo_inf a2) {
    if(strcmp(a1.data,a2.data) != 0) 
        return strcmp(a1.data,a2.data);
    return strcmp(a1.orai,a2.orai);
}

void copy(tipo_inf& dest, tipo_inf source) {
    strcpy(dest.data,source.data);
    strcpy(dest.orai,source.orai);
    strcpy(dest.oraf,source.oraf);
    strcpy(dest.descr,source.descr);
}

void print(tipo_inf app) {
    cout<<app.descr<<" il "<<app.data<<" da "<<app.orai<<" fino a "<<app.oraf<<endl;
}