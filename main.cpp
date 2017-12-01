/*
** PROYECTO FINAL EDII
** PRESENTADO POR:
** CRISTIAN CAMILO VILLADA GRANADA - STEVEN FLOREZ HERNANDEZ
** INGENIERIA DE SISTEMAS
** SEMESTRE III
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo))
#define reservar_memoria2 (Proveedor*)malloc(sizeof(Proveedor))
#include "clientes.h"
#include "proveedores.h"

#include "menu.h"

int main () {
	menu();
	return 0;
}
