/* ******************************************************************
 * LISTA - pruebas_alumno.c                                         *
 * AYUDANTE: MILENA MARCHESE										*
 * PADRÓN: 101741 													*
 * NOMBRE: GABRIELA ELIZABETH MÉNDEZ GUTIÉRREZ						*
 * ******************************************************************/
#include "lista.h"
#include "testing.h"

#include <stdio.h>
#include <stdlib.h>

#define VOLUMEN 1000

void pruebas_lista_estado_inicial(){
	printf("Pruebas estado inicial:\n");
	
	//Creo una lista
	lista_t* lista = lista_crear();
	print_test("lista crear",lista!=NULL);
	
	//Comprobar estado de lista recién creada.
	print_test("lista recién creada está vacía",lista_esta_vacia(lista));
	print_test("lista recién creada ver primero inválido",lista_ver_primero(lista)==NULL);
	print_test("lista recién creada ver último inválido",lista_ver_ultimo(lista)==NULL);
	print_test("lista recién creada, borrar primero inválido",lista_borrar_primero(lista)==NULL);
	
	//Destruir lista sin función de destrucción
	lista_destruir(lista,NULL);
	print_test("lista destruir",true);
}

void pruebas_lista_algunos_elementos(){
	printf("Pruebas algunos elementos:\n");
	
	//Creo una lista
	lista_t* lista = lista_crear();
	print_test("lista crear",lista!=NULL);
	//Prueba insertar algunos elementos.
	int valor1 = 1;
	int valor2 = 2;
	int valor3 = 3;
	
	printf("\nPruebas insertar primero:\n");
	print_test("lista insertar primero",lista_insertar_primero(lista,&valor1));
	print_test("lista ver primero es valor correcto",lista_ver_primero(lista)==&valor1);
	print_test("lista insertar primero",lista_insertar_primero(lista,&valor2));
	print_test("lista ver primero es valor correcto",lista_ver_primero(lista)==&valor2);
	print_test("lista insertar primero",lista_insertar_primero(lista,&valor3));
	print_test("lista ver primero es valor correcto",lista_ver_primero(lista)==&valor3);
	print_test("lista ver último es valor correcto",lista_ver_ultimo(lista)==&valor1);
	print_test("lista largo = 3",lista_largo(lista)==3);
	//Lista: 3-2-1
	
	printf("\nPruebas insertar último:\n");
	int valor4 = 4;
	int valor5 = 5;
	int valor6 = 6;
	print_test("lista insertar último",lista_insertar_ultimo(lista,&valor4));
	print_test("lista ver último es valor correcto",lista_ver_ultimo(lista)==&valor4);
	print_test("lista insertar último",lista_insertar_ultimo(lista,&valor5));
	print_test("lista ver último es valor correcto",lista_ver_ultimo(lista)==&valor5);
	print_test("lista insertar último",lista_insertar_ultimo(lista,&valor6));
	print_test("lista ver último es valor correcto",lista_ver_ultimo(lista)==&valor6);
	print_test("lista largo = 6",lista_largo(lista)==6);
	//Lista: 3-2-1-4-5-6
	
	//Prueba borrar elementos.
	printf("\nPruebas borrar primero:\n");
	print_test("lista borrar primero retorna valor correcto",lista_borrar_primero(lista)==&valor3);
	//Lista: 2-1-4-5-6
	print_test("lista ver primero es valor correcto",lista_ver_primero(lista)==&valor2);
	print_test("lista borrar primero retorna valor correcto",lista_borrar_primero(lista)==&valor2);
	//Lista: 1-4-5-6
	print_test("lista ver primero es valor correcto",lista_ver_primero(lista)==&valor1);
	print_test("lista borrar primero retorna valor correcto",lista_borrar_primero(lista)==&valor1);
	//Lista: 4-5-6
	print_test("lista ver primero es valor correcto",lista_ver_primero(lista)==&valor4);
	print_test("lista largo = 3",lista_largo(lista)==3);
	print_test("lista borrar primero retorna valor correcto",lista_borrar_primero(lista)==&valor4);
	//Lista: 5-6
	print_test("lista ver primero es valor correcto",lista_ver_primero(lista)==&valor5);
	print_test("lista borrar primero retorna valor correcto",lista_borrar_primero(lista)==&valor5);
	//Lista: 6
	print_test("lista ver primero es valor correcto",lista_ver_primero(lista)==&valor6);
	print_test("lista borrar primero retorna valor correcto",lista_borrar_primero(lista)==&valor6);
	//Lista:
	print_test("lista está vacía",lista_esta_vacia(lista));
	
	lista_destruir(lista,NULL);
	print_test("lista destruir",true);
}

void pruebas_lista_comportamiento_vacia(){
	//Creo una lista.
	lista_t* lista = lista_crear();
	print_test("lista crear",lista!=NULL);
	
	int vector[5];
	//Inserto elementos.
	for(int i=0;i<5;i++){
		vector[i]=i+1;
		lista_insertar_ultimo(lista,&vector[i]);
	}
	//Borro todos los elementos en la lista.
	for(int i=0;i<5;i++){
		lista_borrar_primero(lista);
	}
	
	//Pruebas lista a la que se le borró elementos hasta quedar vacía.
	printf("\nPruebas lista que quedó vacía:\n");
	print_test("lista está vacía",lista_esta_vacia(lista));
	print_test("lista ver primero inválido",lista_ver_primero(lista)==NULL);
	print_test("lista ver último inválido",lista_ver_ultimo(lista)==NULL);
	print_test("lista borrar primero inválido",lista_borrar_primero(lista)==NULL);
	
	//Prueba comportamiento lista vacía igual a lista recién creada.
	int* valora = malloc(sizeof(int));
	int* valorb = malloc(sizeof(int));
	int* valorc = malloc(sizeof(int));
	*valora = 1;
	*valorb = 2;
	*valorc = 3;
	
	print_test("lista insertar primero",lista_insertar_primero(lista,valora));
	print_test("lista no está vacía",!lista_esta_vacia(lista));
	print_test("lista ver primero es valor correcto",lista_ver_primero(lista)==valora);
	print_test("lista insertar primero",lista_insertar_primero(lista,valorb));
	print_test("lista ver primero es valor correcto",lista_ver_primero(lista)==valorb);
	print_test("lista insertar último",lista_insertar_ultimo(lista,valorc));
	print_test("lista ver ultimo es valor correcto",lista_ver_ultimo(lista)==valorc);
	print_test("lista borrar primero",lista_borrar_primero(lista)==valorb);
	free(valorb);
	
	//Destruir lista con elementos con función de destrucción
	lista_destruir(lista,free);
	print_test("lista destruir",true);
}

void pruebas_lista_NULL(){
	printf("\nPruebas lista NULL:\n");
	//Creo una pila
	lista_t* lista = lista_crear();
	print_test("lista crear",lista!=NULL);
	
	//encolar NULL es válido.
	print_test("lista insertar NULL último",lista_insertar_ultimo(lista,NULL));
	print_test("lista no está vacía",!lista_esta_vacia(lista));
	print_test("lista ver primero = NULL",lista_ver_primero(lista)==NULL);
	int valor = 2;
	print_test("lista insertar valor no nulo",lista_insertar_ultimo(lista,&valor));
	print_test("lista borrar primero = NULL",lista_borrar_primero(lista)==NULL);
	print_test("lista borrar primero",lista_borrar_primero(lista)==&valor);
	print_test("lista2 está vacía",lista_esta_vacia(lista));
	print_test("lista2 borrar primero inválido",lista_borrar_primero(lista)==NULL);
	
	lista_destruir(lista,NULL);
	print_test("lista destruir",true);	
}

void pruebas_lista_volumen(){
	printf("\nPruebas lista volumen:\n");
	
	//Creo una lista
	lista_t* lista = lista_crear();
	print_test("lista crear",lista!=NULL);
	
	//Creo un vector de elementos.
	int vector[VOLUMEN];
	for(int i=0;i<1000;i++){
		vector[i]=i+1;
		lista_insertar_ultimo(lista,&vector[i]);
		
	}
	printf("lista insertar 1000 elementos");
	print_test("lista largo = 1000",lista_largo(lista)==1000);
	
	//Desencolar 1000 elementos.
	bool ok = true;
	for(int i = 0;i<1000;i++){
		int* valor = &vector[i];
		int* primero = &vector[i+1];
		if(lista_borrar_primero(lista)!=valor)ok=false;
		if(!lista_esta_vacia(lista)&&lista_ver_primero(lista)!=primero)ok=false;
	}
	
	print_test("lista borrar todos los elementos",ok);
	print_test("lista está vacía",lista_esta_vacia(lista));
	print_test("lista ver primero inválido",lista_ver_primero(lista)==NULL);
	print_test("lista ver último inválido",lista_ver_ultimo(lista)==NULL);
	print_test("lista borrar primero inválido",lista_borrar_primero(lista)==NULL);
	
	//Destruir lista.
	lista_destruir(lista,NULL);
	print_test("lista destruir",true);
}

void pruebas_lista_iter_externo_insertar(){
	printf("\nPruebas Iterador Externo insertar:\n");
	//Creo una lista y le inserto elementos.
	lista_t* lista = lista_crear();
	print_test("lista crear",lista!=NULL);
	
	int vector[10];
	// [1,2,3,4,5,6,7,8,9,10]
	// Lista: 1-2-3-4-5
	for(int i=0;i<10;i++){
		vector[i]=i+1;
		if(i<5)lista_insertar_ultimo(lista,&vector[i]);
	}
	
	//Creo un interador externo.
	lista_iter_t* iter = lista_iter_crear(lista);
	print_test("iterador crear",iter!=NULL);
	
	//Pruebas al principio.
	print_test("Iter ver actual es el primer elem",lista_iter_ver_actual(iter)==lista_ver_primero(lista));
	printf("Pruebas insertar elementos con iterador:\n");
	print_test("Insertar en la posición inicial del iterador",lista_iter_insertar(iter,&vector[5]));
	print_test("lista ver primero se actualizó",lista_ver_primero(lista)==&vector[5]);
	print_test("Iter ver actual es el primer elem",lista_iter_ver_actual(iter)==lista_ver_primero(lista));
	// Lista: 6-1-2-3-4-5
	
	//Pruebas al medio.
	print_test("Iter avanzar",lista_iter_avanzar(iter));
	print_test("Iter ver actual es el elem correcto",lista_iter_ver_actual(iter)==&vector[0]);
	print_test("Iter avanzar",lista_iter_avanzar(iter));
	print_test("Iter ver actual es el elem correcto",lista_iter_ver_actual(iter)==&vector[1]);
	print_test("Iter insertar al medio",lista_iter_insertar(iter,&vector[6]));
	print_test("Iter ver actual es el elem correcto",lista_iter_ver_actual(iter)==&vector[6]);
	lista_iter_t* iter2 = lista_iter_crear(lista);
	print_test("Iter2 crear",iter2!=NULL);
	print_test("Iter2 avanzar",lista_iter_avanzar(iter2));
	print_test("Iter2 avanzar",lista_iter_avanzar(iter2));
	print_test("Iter2 ver actual corresponde al elem insertado por Iter correcto",lista_iter_ver_actual(iter2)==&vector[6]);
	lista_iter_destruir(iter2);
	print_test("Iter2 destruir",true);
	// Lista: 6-1-7-2-3-4-5
	
	//Pruebas al final.
	print_test("Iter avanzar",lista_iter_avanzar(iter));
	print_test("Iter avanzar",lista_iter_avanzar(iter));
	print_test("Iter avanzar",lista_iter_avanzar(iter));
	print_test("Iter avanzar",lista_iter_avanzar(iter));
	print_test("Iter ver actual es el último elemento",lista_iter_ver_actual(iter)==lista_ver_ultimo(lista));
	print_test("Iter insertar en la última pos",lista_iter_insertar(iter,&vector[7]));
	print_test("El último en la lista es el correcto",&vector[4]==lista_ver_ultimo(lista));
	// Lista: 6-1-7-2-3-4-8-5
	print_test("Iter avanzar",lista_iter_avanzar(iter));
	print_test("Iter avanzar",lista_iter_avanzar(iter));
	print_test("Iter avanzar inválido",!lista_iter_avanzar(iter));
	print_test("Iter está al final",lista_iter_al_final(iter));
	print_test("Iter insertar al final",lista_iter_insertar(iter,&vector[8]));
	print_test("Insertar al final equivale a insertar último",lista_iter_ver_actual(iter)==lista_ver_ultimo(lista));
	// Lista: 6-1-7-2-3-4-8-5-9
	print_test("Iter avanzar",lista_iter_avanzar(iter));
	print_test("Iter está al final",lista_iter_al_final(iter));
	print_test("Iter avanzar inválido",!lista_iter_avanzar(iter));
	
	lista_iter_destruir(iter);
	print_test("Iter destruir",true);
	lista_destruir(lista,NULL);
	print_test("Lista destruir",true);
}

void pruebas_lista_iter_externo_borrar(){
	
	printf("\nPruebas iter externo borrar:\n");
	//Creo una lista y le inserto elementos.
	lista_t* lista = lista_crear();
	print_test("lista crear",lista!=NULL);
	int vector[10];
	for(int i=0;i<10;i++){
		vector[i]=i+1;
		lista_insertar_ultimo(lista,&vector[i]);
	}
	// Lista: 1-2-3-4-5-6-7-8-9-10

	lista_iter_t* iter3 = lista_iter_crear(lista);
	print_test("Iter3 crear",iter3!=NULL);
	print_test("Borrar iter en posición inicial",lista_iter_borrar(iter3));
	print_test("Primer elemento de la lista es el correcto",lista_ver_primero(lista)==&vector[1]);
	//Lista: 2-3-4-5-6-7-8-9-10
	print_test("Iter avanzar",lista_iter_avanzar(iter3));
	print_test("Iter avanzar",lista_iter_avanzar(iter3));
	print_test("Iter avanzar",lista_iter_avanzar(iter3));
	print_test("Iter borrar actual",lista_iter_borrar(iter3));
	//Lista: 2-3-4-6-7-8-9-10
	print_test("Iter ver actual",lista_iter_ver_actual(iter3)==&vector[5]);
	lista_iter_t* iter4 = lista_iter_crear(lista);
	print_test("Iter4 crear",iter4!=NULL);
	print_test("Iter4 avanzar",lista_iter_avanzar(iter4));
	print_test("Iter4 avanzar",lista_iter_avanzar(iter4));
	print_test("Iter4 avanzar",lista_iter_avanzar(iter4));
	print_test("Comprobar que Iter eliminó el elemento correcto",lista_iter_ver_actual(iter4)==&vector[5]);
	lista_iter_destruir(iter4);
	print_test("Iter4 destruir",true);
	
	//Borrar el último elemento con el iterador.
	print_test("Iter avanzar",lista_iter_avanzar(iter3));
	print_test("Iter avanzar",lista_iter_avanzar(iter3));
	print_test("Iter avanzar",lista_iter_avanzar(iter3));
	print_test("Iter avanzar",lista_iter_avanzar(iter3));
	print_test("Iter ver actual es el último elemento",lista_iter_ver_actual(iter3)==lista_ver_ultimo(lista));
	print_test("Iter borrar actual",lista_iter_borrar(iter3));
	//Lista: 2-3-4-6-7-8-9
	print_test("Último elemento de la lista es el correcto",lista_ver_ultimo(lista)==&vector[8]);
	print_test("Iter avanzar inválido",!lista_iter_avanzar(iter3));
	print_test("Iter está al final",lista_iter_al_final(iter3));
	print_test("Borrar cuando iter está al final es inválido",lista_iter_borrar(iter3)==NULL);
	
	lista_iter_destruir(iter3);
	print_test("Iter destruir",true);
	lista_destruir(lista,NULL);
	print_test("Lista destruir",true);
}

bool sumar_todos(void* dato,void* extra){
	*(int*)extra+= *(int*)dato;
	return true;
}

bool duplicar_primeros5(void* dato,void*extra){
	int* pos = extra;
	if(*pos>4){
		return false;
	}
	*(int*)dato *= 2;
	*pos +=1;
	return true;
}

void pruebas_lista_iter_interno(){
	printf("\nPruebas iterador interno:\n");
	//Creo una lista y le inserto elementos.
	lista_t* lista = lista_crear();
	print_test("lista crear",lista!=NULL);
	
	int vector[10];
	// [1,2,3,4,5,6,7,8,9,10]
	for(int i=0;i<10;i++){
		vector[i]=i+1;
	}
	// Lista: 1-2-3-4-5
	for(int i=0;i<10;i++){
		lista_insertar_ultimo(lista,&vector[i]);
	}
	int suma = 0;
	lista_iterar(lista,sumar_todos,&suma);
	print_test("Prueba iterar sin corte, sumar todos",suma==55);
	int pos = 0;
	lista_iterar(lista,duplicar_primeros5,&pos);
	print_test("Prueba iterar con corte, duplicar primeros 5",pos==5);
	bool ok=true;
	for(int i=0;i<5;i++){
		int valor = (i+1)*2;
		if(vector[i]!= valor) ok = false;
	}
	print_test("Se duplicaron efectivamente",ok);
	lista_destruir(lista,NULL);
}

void pruebas_lista_alumno(){
	pruebas_lista_estado_inicial();
	pruebas_lista_algunos_elementos();
	pruebas_lista_comportamiento_vacia();
	pruebas_lista_NULL();
	pruebas_lista_volumen();
	pruebas_lista_iter_interno();
	pruebas_lista_iter_externo_insertar();
	pruebas_lista_iter_externo_borrar();
}
	
	
	
