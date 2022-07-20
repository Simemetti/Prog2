/*******************************/
/* HEADER MODULO "tipo" */
/*******************************/

typedef struct appuntamento{
	char data[7];
	char orai[5];
	char oraf[5];
	char descr[51];
} tipo_inf;

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
