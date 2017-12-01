//Estructura utilizada en las funciones para el manejo de los proveedores
struct Proveedor{
	int id;
	char nombre[10];
	Proveedor *der;
	Proveedor *izq;
	Proveedor *padre;
}proveedor, *pproveedor = &proveedor, *arbol_proveedor = NULL;

int id_proveedor = 0;

//Declaracion de funciones
Proveedor *crear_proveedor(char [], Proveedor *);
void insertar_proveedor(Proveedor *&,char [],Proveedor*);
void listar_proveedor();
void eliminar_proveedor(Proveedor *, int );
Proveedor *minimo_p(Proveedor *);
void reemplazar_p(Proveedor *, Proveedor *);
void destruir_nodo_p(Proveedor *);
void eliminar_nodo_p(Proveedor *);

FILE *datos_proveedores;

//Funcion para crear un nuevo proveedor, en la cual retorna un puntero
Proveedor *crear_proveedor(char nombre_proveedor[], Proveedor *padre){
	Proveedor *nuevo_p = reservar_memoria2;
	id_proveedor++;
	/*datos_proveedores = fopen("datos_proveedores.txt", "rb");
	rewind(datos_proveedores);
	fseek(datos_proveedores, ftell(datos_proveedores)-sizeof(*pproveedor), SEEK_END);
	fread(pproveedor, sizeof(*pproveedor), 1, datos_proveedores);
	*/
	nuevo_p->id = id_proveedor;
	strcpy(nuevo_p->nombre, nombre_proveedor);
	nuevo_p->der = NULL;
	nuevo_p->izq = NULL;
	nuevo_p->padre = padre;
	
	/*datos_proveedores=fopen("datos_proveedores.txt", "a+b");
	if(datos_proveedores == NULL){
		datos_proveedores=fopen("datos_proveedores.txt", "w+b");
	}
	fwrite(pproveedor, sizeof(*pproveedor), 1, datos_proveedores);
	rewind(datos_proveedores);
	fclose(datos_proveedores);*/
	
	return nuevo_p;
}

//Funcion para insertar el nuevo proveedor en el arbol
void insertar_proveedor(Proveedor *&arbol_proveedor, char nombre_proveedor[], Proveedor *padre){
	if(arbol_proveedor == NULL){
		Proveedor *nuevo_p = crear_proveedor(nombre_proveedor, padre);
		arbol_proveedor = nuevo_p;
	}else{
		int valor_raiz = arbol_proveedor->id;
		if(arbol_proveedor->id <= valor_raiz){
			insertar_proveedor(arbol_proveedor->izq, nombre_proveedor, arbol_proveedor);
		}else{
			insertar_proveedor(arbol_proveedor->der, nombre_proveedor, arbol_proveedor);
		}
	}
}

//Funcion para mostrar todos los proveedores
void listar_proveedor(Proveedor *arbol_proveedor, int cont){
	if(arbol_proveedor == NULL){
		return;
	}else{
		listar_proveedor(arbol_proveedor->der, cont+1);
		for(int i=0; i<cont; i++){
			printf(" ");
		}
		printf("%d ", arbol_proveedor->id);
		printf("%s \n", arbol_proveedor->nombre);
		listar_proveedor(arbol_proveedor->izq, cont+1);
	}
	printf("\n");
}

//Funcion para eliminar el nodo proveedor encontrado
void eliminar_proveedor(Proveedor *arbol_proveedor, int n){
	if (arbol_proveedor == NULL){//Si el Arbol esta vacio
		return;
	}else if(n < arbol_proveedor->id){ //Si el valor es menor
		eliminar_proveedor(arbol_proveedor->izq, n);//Busca por la izquierda
	}else if(n > arbol_proveedor->id){ //Si el valor es mayor
		eliminar_proveedor(arbol_proveedor->der, n);//Busca por la derecha
	}else{ //Si ya se encontro el valor
		eliminar_nodo_p(arbol_proveedor);
	}
}

//Funcion para determinar el nodo mas izq posible
Proveedor *minimo_p(Proveedor *arbol_proveedor){	//Si el Arbol esta vacio
	if(arbol_proveedor == NULL){		//Retorna nulo
		return NULL;
	}
	if(arbol_proveedor->izq){			//Si tiene hijo izq
		return minimo_p(arbol_proveedor->izq);//Buscar la parte izq posible
	}else{						//Si no tiene hijo izq
		return arbol_proveedor;	//Retornamos el mismo Nodo
	}
}

//Funcion para reemplazar dos nodos
void reemplazar_p(Proveedor *arbol_proveedor, Proveedor *nuevoNodo){
	if(arbol_proveedor->padre){
		//arbol->padre hay que asignarle el nuevo hijo
		if(arbol_proveedor->id == arbol_proveedor->padre->der->id){
			arbol_proveedor->padre->der = nuevoNodo;
		}else if(arbol_proveedor->id == arbol_proveedor->padre->id){
			arbol_proveedor->padre->izq = nuevoNodo;
	}
}
if(nuevoNodo){
	nuevoNodo->padre = arbol_proveedor->padre;
	}
}

//Funcion para destruir un Nodo
void destruir_nodo_p(Proveedor *nodo){
	nodo->izq = NULL;
	nodo->der = NULL;
	free(nodo);
}

//Funcion para eliminar el Nodo encontrado
void eliminar_nodo_p(Proveedor *nodo_eliminar){
	if(nodo_eliminar->izq && nodo_eliminar->der){
		Proveedor *menor = minimo_p(nodo_eliminar->der);
		nodo_eliminar->id = menor->id;
		strcpy(nodo_eliminar->nombre, menor->nombre);
		eliminar_nodo_p(menor);
	}else if (nodo_eliminar->izq){//Si tiene hijo Izq
		reemplazar_p(nodo_eliminar, nodo_eliminar->izq);
		destruir_nodo_p(nodo_eliminar);
	}else if(nodo_eliminar->der){//Si tiene hijo Der
		reemplazar_p(nodo_eliminar, nodo_eliminar->der);
		destruir_nodo_p(nodo_eliminar);
	}else{//No tiene Hijo
		reemplazar_p(nodo_eliminar, NULL);
		destruir_nodo_p(nodo_eliminar);
	}
}
