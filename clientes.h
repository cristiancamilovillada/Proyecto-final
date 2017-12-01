struct Nodo
{
	int id_cliente;
	int puntos_acumu;
	char cedula[20];
	char nombre[20];
	char apellido[20];
	char telefono[20];
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

//Prototipos de las funciones
Nodo *crearNodoClientes(char[],char [],char[],char[],Nodo *);
void insertarNodo(Nodo *&,char[],char[],char[],char[],Nodo *);
void inOrden(Nodo *);
void busqueda_cliente(Nodo *,int );
void editar_cliente(Nodo *,int);
void eliminar_cliente(Nodo *,int );
Nodo *minimo(Nodo *);
void reemplazar_Nodo(Nodo *,Nodo *);
void destruirNodo(Nodo *);
void eliminarNodo(Nodo *);

int id_Cliente=0;
Nodo*arbol=NULL;

//Funcion para crear el nodo cliente, la cual retorna un puntero
Nodo *crearNodoClientes(char cedula[],char nombre[],char apellido[],char telefono[],Nodo *padre)
{
	Nodo *nuevo_nodo= reservar_memoria;
	id_Cliente++;
	nuevo_nodo->id_cliente=id_Cliente;
	strcpy(nuevo_nodo->cedula,cedula);
	strcpy(nuevo_nodo->nombre,nombre);
	strcpy(nuevo_nodo->apellido,apellido);
	strcpy(nuevo_nodo->telefono,telefono);
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	nuevo_nodo->padre=padre;

	return nuevo_nodo;
}

//Funcion para insertar el nodo clientes en el arbol
void insertarNodo(Nodo *&arbol,char cedula[],char nombre[],char apellido[],char telefono[],Nodo *padre)
{
	
	if(arbol==NULL)
	{
		Nodo *nuevo_nodo = crearNodoClientes(cedula,nombre,apellido,telefono,padre);
		arbol=nuevo_nodo;
	}
	else
	{	
		int valorRaiz = arbol->id_cliente;
		if(id_Cliente<valorRaiz)
		{
			insertarNodo(arbol->izq,cedula,nombre,apellido,telefono,arbol);
		}
		else
		{
			insertarNodo(arbol->der,cedula,nombre,apellido,telefono,arbol);
		}
	}
}

//Funcion para listar los clientes en inOrden
void inOrden(Nodo *arbol){
	if(arbol == NULL){//Si el Arbol esta vacio
		return;
	}else{
		printf("ID:%d CC:%s NOMBRE:%s APELLIDO:%s TELEFONO:%s \n",arbol->id_cliente,arbol->cedula,arbol->nombre,arbol->apellido,arbol->telefono);
		//printf("CC:%s\n",arbol->cedula);
		//printf("NOMBRE:%s\n",arbol->nombre);
		//printf("APELLIDO:%s\n",arbol->apellido);
		//printf("TELEFONO:%s\n",arbol->telefono);
		inOrden(arbol->der);
	}
}

//Funcion para buscar los clientes 
void busqueda_cliente(Nodo *arbol,int id_buscador)
{
	if(arbol==NULL)
	{
		printf("el id ingresado no esta en nuestro sistema");
	}
	else if (arbol->id_cliente==id_buscador)
	{
		printf("ID:%d CC:%s NOMBRE:%s APELLIDO:%s TELEFONO:%s \n",arbol->id_cliente,arbol->cedula,arbol->nombre,arbol->apellido,arbol->telefono);
			
	}
	else
	{
		return busqueda_cliente(arbol->der,id_buscador);
	}

}

//Funcion para editar los clientes
void editar_cliente(Nodo *arbol,int id_buscador)
{
	if(arbol==NULL)
	{
		printf("el id ingresado no esta en nuestro sistema");
	}
	else if (arbol->id_cliente==id_buscador)
	{
		int opc=0;
		do
		{
			printf("1. editar cedula\n");
			printf("2. editar nombre \n");
			printf("3. editar apellido\n");
			printf("4. editar telefono\n");
			printf("seleccione una opcion:  ");
			scanf("%d",&opc);
			switch(opc)
			{
				case 1:
				{	
					
					char nueva_cedula[20];
					printf(" editar cedula\n");
					printf("CC:%s\n",arbol->cedula);
					printf("ingrese la nueva cedula: ");
					getchar();
					scanf("%[^\n]",nueva_cedula);
					strcpy(arbol->cedula,nueva_cedula);
					break;
				}
				case 2:
				{
					char nuevo_nombre[20];
					printf("editar nombre\n");
					printf("NOMBRE:%s\n",arbol->nombre);
					printf("ingrese el nuevo nombre: ");
					getchar();
					scanf("%[^\n]",nuevo_nombre);
					strcpy(arbol->nombre,nuevo_nombre);
					break;
				}
				case 3:
				{
					char nuevo_apellido[20];
					printf("editar apellido\n");
					printf("APELLIDO:%s\n",arbol->apellido );
					printf("ingrese el nuevo apellido: ");
					getchar();
					scanf("%[^\n]",nuevo_apellido);
					strcpy(arbol->apellido,nuevo_apellido);
					break;
				}
				case 4:
				{
					char nuevo_telefono[20];
					printf("editar telefono\n");
					printf("TELEFONO:%s\n",arbol->telefono  );
					printf("ingrese el nuevo numero de telefono: ");
					getchar();
					scanf("%[^\n]",nuevo_telefono);
					strcpy(arbol->telefono,nuevo_telefono);
				}
				case 0:
				{
					break;
				}
				default:
				{
					printf("opcion invalida");
					break;
				}
			}
		}while(opc!=0);
		inOrden(arbol);	
		
	}
	else
	{
		return editar_cliente(arbol->der,id_buscador);
	}

}

//Funcion para eliminar un cliente
void eliminar_cliente(Nodo *arbol,int id_buscador)
{
	if(arbol==NULL)
	{
		return;
	}
	else if(id_buscador>arbol->id_cliente)
	{
		eliminar_cliente(arbol->der,id_buscador);
	}
	else
	{
		eliminarNodo(arbol);
	}
}

//Funcion para eliminar el Nodo cliente encontrado
void eliminarNodo(Nodo *nodoeliminar)
{
	if(nodoeliminar->izq && nodoeliminar->der)
	{
		Nodo *menor=minimo(nodoeliminar->der);
		nodoeliminar->id_cliente=menor->id_cliente;
		strcpy(nodoeliminar->cedula,menor->cedula);
		strcpy(nodoeliminar->nombre,menor->nombre);
		strcpy(nodoeliminar->apellido,menor->apellido);
		strcpy(nodoeliminar->telefono,menor->telefono);
		eliminarNodo(menor);
	}
	else if(nodoeliminar->der)
	{
		reemplazar_Nodo(nodoeliminar,nodoeliminar->der);
		destruirNodo(nodoeliminar);
	}
	else
	{
		reemplazar_Nodo(nodoeliminar,NULL);
		destruirNodo(nodoeliminar);

	}
} 

//Funcion para determinar el nodo mas a la izq posible
Nodo *minimo(Nodo *arbol)
{
	if(arbol==NULL)
	{

		return NULL;
	}
	if(arbol->izq)
	{
		return minimo(arbol->izq);
	}
	else
	{
		return arbol;
	}
}

//Funcion para reemplazar el nodo
void reemplazar_Nodo(Nodo *arbol,Nodo *nuevoNodo)
{
	if(arbol->padre)
	{
		if(arbol->id_cliente==arbol->padre->der->id_cliente)
		{
			arbol->padre->der=nuevoNodo;
		}
	}
	if(nuevoNodo)
	{
		nuevoNodo->padre=arbol->padre;
	}

}

//Funcion para destruir un Nodo (liberar la memoria)
void destruirNodo(Nodo *Nodo)
{
	Nodo->izq=NULL;
	Nodo->der=NULL;
	free(Nodo);
	
}

