/*
** FUNCIION MENU, CON TODOS LOS SUBMENUS
** Y LA IMPLEMENTACION DE LAS FUNCIONES NECESARIAS
*/

void menu();

void menu()
{	
	int opc=1,idClientes=0;

	while(opc!=0)
	{
		printf("Minutos El RUSSO\n");
		printf("1. Venta\n");
		printf("2. Crear\n");
		printf("3. Listar\n");
		printf("4. Buscar\n");
		printf("5. Editar\n");
		printf("6. Eliminar\n");
		printf("0. Salir \n");
		printf("Seleccione una opcion:  ");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:{
				
				break;
			}
			case 2:{
				int opc=1;
				while(opc!=0)
				{
					printf("CREAR\n");
					printf("1. Crear cliente\n");
					printf("2. Crear proveedor\n");
					printf("0. salir\n");
					printf("Seleccione una opcion:  ");
					scanf("%d",&opc);
					switch(opc)
					{
						case 1:
						{
							int puntos;
							char cedula[20],nombre[20],apellido[20],telefono[20];
							printf("CREAR CLIENTE\n");
							fflush(stdin);
							printf("Ingrese la cedula: ");
							getchar();
							scanf("%[^\n]",cedula);
							fflush(stdin);
							printf("Ingrese nombre:  ");
							getchar();
							scanf("%[^\n]",nombre);
							fflush(stdin);
							printf("Ingrese apellido:  ");
							getchar();
							scanf("%[^\n]",apellido);
							fflush(stdin);
							printf("Ingrese el telefono: ");
							getchar();
							scanf("%[^\n]",telefono);
							//printf("\ningrese los puntos: ");
							//getchar();
							//scanf("%d",puntos);
							insertarNodo(arbol,cedula,nombre,apellido,telefono,NULL);
							break;
						}
						case 2:
						{
							char nombre_proveedor[10];
							printf("CREAR PROVEEDOR\n");
							fflush(stdin);
							printf("Ingrese el nombre del proveedor: ");
							getchar();
							scanf("%[^\n]",nombre_proveedor);
							insertar_proveedor(arbol_proveedor, nombre_proveedor, NULL);
							break;
						}
						case 0:
						{
							break;
						}
						default:
						{
							printf("opcion invalida\n");
							break;
						}
					}
				}
				break;
			}
			case 3:
			{
				int opc=1;
				while(opc!=0)
				{
					printf("LISTAR\n");
					printf("1. Clientes\n");
					printf("2. Proveedores\n");
					printf("3. Facturas\n");
					printf("0. Salir\n");
					printf("Seleccione una opcion:  ");
					scanf("%d",&opc);
					switch(opc)
					{
						case 1:
						{
							printf("LISTAR CLIENTES\n");
							inOrden(arbol);
							break;
						}
						case 2:
						{
							int cont = 0;
							printf("LISTAR LOS PROVEEDORES\n");
							listar_proveedor(arbol_proveedor, cont);
							break;
						}
						case 3:
						{
							break;
						}
						case 0:
						{
							break;
						}
						default:
						{
							printf("Opcion Invalida\n");
							break;
						}
					}
				}
				break;
			}
			case 4:
			{
				int opc=1;
				while(opc!=0)
				{
					printf("BUSCAR\n");
					printf("1. Clientes\n");
					printf("2. Facturas\n");
					printf("0. Salir\n");
					printf("seleccione una opcion:  ");
					scanf("%d",&opc);
					switch(opc)
					{
						case 1:
						{
							int id_buscador;
							printf("BUSCAR CLIENTES\n");
							inOrden(arbol);
							printf("\nIngrese el id del cliente a buscar: ");
							scanf("%d",&id_buscador);
							busqueda_cliente(arbol,id_buscador);
							break;
						}
						case 2:
						{
							break;
						}
						case 0:
						{
							break;
						}
						default:
						{
							printf("Opcion Invalida\n");
							break;
						}
					}
				}
				break;
			}
			case 5:
			{
				int opc=1;
				while(opc!=0)
				{
					printf("EDITAR\n");
					printf("1. Clientes\n");
					printf("2. Facturas\n");
					printf("3. Proveedores\n");
					printf("0. Salir\n");
					printf("Seleccione una opcion:  ");
					scanf("%d",&opc);
					switch(opc)
					{
						case 1:
						{	
							int id_buscador;
							printf("EDITAR CLIENTES\n");
							printf("ingrese el id del cliente a buscar: ");
							scanf("%d",&id_buscador);
							editar_cliente(arbol,id_buscador);
							break;
						}
						case 2:
						{
							break;
						}
						case 3:
						{
							break;
						}
						case 0:
						{
							break;
						}
						default:
						{
							printf("opcion invalida\n");
							break;
						}
					}
				}
				break;
			}
			case 6:
			{
				int opc=1;
				while(opc!=0)
				{
					printf("ELIMINAR\n");
					printf("1. Clientes\n");
					printf("2. Proveedores\n");
					printf("3. Facturas\n");
					printf("seleccione una opcion:  ");
					scanf("%d",&opc);
					switch(opc)
					{
						case 1:
						{
							int id_buscador;
							printf("ELIMINAR CLIENTES\n");
							printf("ingrese el id del cliente a buscar: ");
							scanf("%d",&id_buscador);
							eliminar_cliente(arbol,id_buscador);
							break;
						}
						case 2:
						{
							int n;
							printf("ELIMINAR PROVEEDOR\n");
							printf("Digite el id del proveedor a eliminar: ");
							scanf("%d", n);
							eliminar_proveedor(arbol_proveedor, n);
							break;
						}
						case 3:
						{
							break;
						}
						case 0:
						{
							break;
						}
						default:
						{
							printf("Opcion Invalida\n");
							break;
						}
					}
				}
				
				break;
			}
			case 0:
			{
				break;
			}
			default:
			{
				printf("Opcion Invalida\n");
				break;
			}
		}
	}
}
