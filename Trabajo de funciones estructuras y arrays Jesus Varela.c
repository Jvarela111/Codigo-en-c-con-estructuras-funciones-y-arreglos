#include <stdio.h>
#include <stdlib.h>
#define length 4
#include <string.h>

//Creando las estructuras
struct autor{
    char nombreAutor[30];
    int librosEscritos;
    int edad;
    float estatura;
    char nacionalidad[15];
} autor[length];
struct datos{
    char nombreLibro[30];
    int A_lanzamiento;
    struct autor autorlibros;
    char genero[20];
    int paginas;
} libros[length];

//Prototipo de funciones
void capturar();
void mostrarTodos();
void buscarLibro();
void buscarAutor();
void buscarGenero();
void salir();
void menu();

int main(){
    menu();
    system("PAUSE");
    return 0 ;
}

//Definicion de las funciones
void capturar(){
	
	for(int i=0;i<length;i++){
		int b,c,d = 0;
		fflush(stdin);
		printf("\nIngresa el Nombre del libro #%d: ",i+1);
		scanf("%s",libros[i].nombreLibro);
		printf("Ingresa el a%co de lanzamiento #%d: ",164,i+1);
		scanf("%d",&libros[i].A_lanzamiento);
		fflush(stdin);
		printf("Ingresa el genero del libro #%d: ",i+1);
		scanf("%s",libros[i].genero);
		printf("Ingresa el numero de paginas #%d: ",i+1);
		scanf("%d",&libros[i].paginas);
		fflush(stdin);
		printf("Ingresa el Autor del libro #%d: ",i+1);
		scanf("%s",libros[i].autorlibros.nombreAutor);
		printf("Ingresa la cantidad de libros escritos por el autor %s: ",libros[i].autorlibros.nombreAutor);
		scanf("%d",&libros[i].autorlibros.librosEscritos);
		fflush(stdin);
		printf("Ingresa la edad que tiene o tendria el autor %s: ",libros[i].autorlibros.nombreAutor);
		scanf("%d",&libros[i].autorlibros.edad);
		printf("Ingresa la estatura del autor %s: ",libros[i].autorlibros.nombreAutor);
		scanf("%f",&libros[i].autorlibros.estatura);
		fflush(stdin);
		printf("Ingresa la nacionalidad del autor %s: ",libros[i].autorlibros.nombreAutor);
		gets(libros[i].autorlibros.nacionalidad);
		fflush(stdin);
	}
}

void mostrarTodos(){
	
	if(libros[0].paginas !=0 && libros[0].A_lanzamiento !=0 ){
	printf("Mostrando los datos de los libros\n");
		for(int i=0;i<length;i++){
			printf("_____________________\n");
			printf("Libro: %d\n",i+1);
			printf("Nombre del libro %s\n",libros[i].nombreLibro);
			printf("A%co de lanzamiento: %d\n", 164, libros[i].A_lanzamiento);		
			printf("Genero del libro %s\n",libros[i].genero);
			printf("Cantidad de paginas: %d\n",libros[i].paginas);
			printf("\nNombre del autor %s\n",libros[i].autorlibros.nombreAutor);
			printf("Libros escritos por el autor: %d\n",libros[i].autorlibros.librosEscritos);		
			printf("Edad que tiene o tendria el autor: %d\n",libros[i].autorlibros.edad);
			printf("Estatura del autor: %.2f\n",libros[i].autorlibros.estatura);
			printf("Nacionalidad del autor: %s\n",libros[i].autorlibros.nacionalidad);
		}
	} else if (libros[0].paginas ==0 && libros[0].A_lanzamiento ==0 ){
		printf("\nPrimero debe ingresar correctamente los datos de los libros con la opcion 1\n");
	}
}

void buscarLibro(){
	
	if(libros[0].paginas !=0 && libros[0].A_lanzamiento !=0 ){
		char nombreLibro[30];
		int a = 1;
		printf("_____________________\n");
		printf("Ingresa el nombre del libro a Buscar: ");
		scanf("%s",nombreLibro);
		fflush(stdin);
		printf("\n_____________________\n");
		for(int i=0;i<length;i++){
			a = strcmp(libros[i].nombreLibro, nombreLibro);
			if (a == 0){
				printf("Libro: %d\n",i+1);		
				printf("Nombre del libro: %s\n",libros[i].nombreLibro);
				printf("A%co de lanzamiento: %d\n",164, libros[i].A_lanzamiento);		
				printf("Genero del libro: %s\n",libros[i].genero);
				printf("Cantidad de paginas: %d\n",libros[i].paginas);
				printf("\nNombre del autor: %s\n",libros[i].autorlibros.nombreAutor);
				printf("Libros escritos por el autor: %d\n",libros[i].autorlibros.librosEscritos);		
				printf("Edad que tiene o tendria el autor: %d\n",libros[i].autorlibros.edad);
				printf("Estatura del autor: %.2f\n",libros[i].autorlibros.estatura);
				printf("Nacionalidad del autor: %s\n",libros[i].autorlibros.nacionalidad);
				fflush(stdin);
				}
			}
		if(a==1){
			printf("No hay libros con el nombre: %s\n",nombreLibro);
		}
	} else if (libros[0].paginas ==0 && libros[0].A_lanzamiento ==0 ){
		printf("\nPrimero debe ingresar  correctamente los datos de los libros con la opcion 1\n");
	}
}

void buscarAutor(){
	
	if(libros[0].paginas !=0 && libros[0].A_lanzamiento !=0 ){
		char nombreAutor[30];
		int a = 0;
		printf("_____________________\n");
		printf("Ingresa el nombre del autor a Buscar: ");
		scanf("%s",&nombreAutor);
		fflush(stdin);
		printf("\n_____________________\n");
		int b = length;
		for(int i=0;i<b;i++){
			int a = strcmp(libros[i].autorlibros.nombreAutor,nombreAutor);
			if (a == 0){
				b = i; 
			}
		}
		if (a == 0){
			printf("\nAUTOR ENCONTRADO!\n");
			printf("\nNombre del autor: %s\n",libros[b].autorlibros.nombreAutor);
			printf("Libros escritos por el autor: %d\n",libros[b].autorlibros.librosEscritos);		
			printf("Edad que tiene o tendria el autor: %d\n",libros[b].autorlibros.edad);
			printf("Estatura del autor: %.2f\n",libros[b].autorlibros.estatura);
			printf("Nacionalidad del autor: %s\n",libros[b].autorlibros.nacionalidad);
		}
		for(int i=0;i<length;i++){
			a = strcmp(libros[i].autorlibros.nombreAutor,nombreAutor);
			if (a == 0){
				printf("\n_____________________\n");
				printf("\nLibros en registro escritos por el autor: %d\n",i+1);		
				printf("Nombre del libro %s\n",libros[i].nombreLibro);
				printf("A%co de lanzamiento: %d\n",164, libros[i].A_lanzamiento);		
				printf("Genero del libro %s\n",libros[i].genero);
				printf("Cantidad de paginas: %d\n",libros[i].paginas);
				fflush(stdin);
				}
			}
		if(a==1){
			printf("No hay autores registrados con el nombre %s\n",nombreAutor);
		}
	} else if (libros[0].paginas ==0 && libros[0].A_lanzamiento ==0 ){
		printf("\nPrimero debe ingresar correctamente los datos de los libros con la opcion 1\n");
	}
}

void buscarGenero(){
	
	if(libros[0].paginas !=0 && libros[0].A_lanzamiento !=0 ){
		char genero[15];
		int a = 0;
		printf("_____________________\n");
		printf("Ingresa el genero de libros a Buscar: ");
		scanf("%s",&genero);
		printf("\n_____________________\n");
		for(int i=0;i<length;i++){
			a = strcmp(libros[i].genero,genero);
			if (a == 0){
				printf("\nLibro: %d\n",i+1);
				printf("Nombre del libro %s\n",libros[i].nombreLibro);
				printf("A%co de lanzamiento: %d\n",164, libros[i].A_lanzamiento);		
				printf("Genero del libro %s\n",libros[i].genero);
				printf("Cantidad de paginas: %d\n",libros[i].paginas);
				printf("\nNombre del autor %s\n",libros[i].autorlibros.nombreAutor);
				printf("Libros escritos por el autor: %d\n",libros[i].autorlibros.librosEscritos);		
				printf("Edad que tiene o tendria el autor: %d\n",libros[i].autorlibros.edad);
				printf("Estatura del autor: %.2f\n",libros[i].autorlibros.estatura);
				printf("Nacionalidad del autor: %s\n",libros[i].autorlibros.nacionalidad);
				}
			}
		if(a==1){
			printf("No hay libros con el genero %s\n",genero);
		}
	} else if (libros[0].paginas ==0 && libros[0].A_lanzamiento ==0 ){
		printf("\nPrimero debe ingresar correctamente los datos de los libros con la opcion 1\n");
	}
}

void salir(){
	printf("\n(*)Programa finalizado(*)\n\n");
}

void menu(){
 int elec;
    do{
        printf("________________\n");
        printf("Menu de Opciones\n");
        printf("1. Captura de  datos de los libros y autores\n");
        printf("2. Mostrar datos de  todos libros y autores\n");
        printf("3. Buscar libro por nombre\n");
        printf("4. Buscar Autor por nombre\n");
        printf("5. Buscar libro( s ) por genero\n");
        printf("6. Salir del sistema\n");
        printf("Selecione una Opcion: ");
        scanf("%d", &elec);

        switch(elec){

        case 1:
            capturar();
        break;

        case 2:
            mostrarTodos();
        break;

        case 3:
            buscarLibro();
        break;

        case 4:
            buscarAutor();
        break;
        
        case 5:
            buscarGenero();
        break;
        
        case 6:
            salir();
        break;

        default:
            printf("\nOpcion incorrecta\n");
        }

    }while(elec!=6);

}