#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
void strreverse(char* begin, char* end) {
	
	char aux;
	
	while(end>begin)
	
		aux=*end, *end--=*begin, *begin++=aux;
	
}
	
void itoa(int value, char* str, int base) {
	
	static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	
	char* wstr=str;
	
	int sign;
	
	div_t res;
	


	
	// Validate base
	
	if (base<2 || base>35){ *wstr='\0'; return; }
	

	
	// Take care of sign
	
	if ((sign=value) < 0) value = -value;
	


	
	// Conversion. Number is reversed.
	
	do {
	
		res = div(value,base);
	
		*wstr++ = num[res.rem];
	
	}while(value=res.quot);
	
	if(sign<0) *wstr++='-';
	
	*wstr='\0';
	


	
	// Reverse string
	
	strreverse(str,wstr-1);
	
}
// FunciÃ³n principal
int main(int argc, char **argv)
{
    if(argc > 1){
        // Primer paso, definir variables
        int fd, fd2, longitud_cliente, puerto;
        puerto = atoi(argv[1]);

        // Se necesitan dos estructuras del tipo sockaddr
        // La primera guarda info del server
        // La segunda del cliente
        struct sockaddr_in server;
        struct sockaddr_in client;

        // Configuracion del servidor
        server.sin_family = AF_INET;         // Familia TCP/IP
        server.sin_port = htons(puerto);     // Puerto
        server.sin_addr.s_addr = INADDR_ANY; // Cualquier cliente puede conectarse
        bzero(&(server.sin_zero), 8);        // Funcion que rellena con 0's

        // Paso 2, definicion de socket
        if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            perror("Error de apertura de socket");
            exit(-1);
        }

        // Paso 3, avisar al sistema que se creo un socket
        if (bind(fd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
        {
            printf("error en bind() \n");
            exit(-1);
        }

        // Paso 4, establecer el socket en modo escucha
        if (listen(fd, 5) == -1)
        {
            printf("error en listen()\n");
            exit(-1);
        }
        printf("\n Se creo el socket\n");
        // Paso5, aceptar conexiones
        while (1)
        {
            longitud_cliente = sizeof(struct sockaddr_in);
            /* A continuaciÃ³n la llamada a accept() */
            if ((fd2 = accept(fd, (struct sockaddr *)&client, &longitud_cliente)) == -1)
            {
                printf("error en accept()\n");
                exit(-1);
            }
            
            printf("\nSe conectó un cliente\n");

            // send(fd2, "Bienvenido a mi servidor.\n", 26, 0);
            // we should change to the following lines instead
            char * buffer = (char *) calloc(100, sizeof(char));
            recv(fd2, buffer, 100, 0);
            printf("\nEl cliente envio %s\n", buffer);
            int dato=atoi(buffer) +1;
            // strcpy(buffer,""); //strcpy functions as a buffer cleaner, the reason is all buffers do not work the same way
            // the string buffer is cleaned by the operating system meanwhile, the buffer that storages an amount is cleaned
            // by the coder
            // itoa(buffer,dato,10); //integer to array
            itoa(dato,buffer,10);
            // snprintf(buffer,dato,10);
            send(fd2, buffer, 100, 0);
            free(buffer);

            close(fd2); /* cierra fd2 */
        }
        close(fd);
    }
    else{
        printf("NO se ingreso el puerto por parametro\n");
    }
    return 0;
}
	
// /**
	
//  * Ansi C "itoa" based on Kernighan & Ritchie's "Ansi C":
	
//  */
	
// void strreverse(char* begin, char* end) {
	
// 	char aux;
	
// 	while(end>begin)
	
// 		aux=*end, *end--=*begin, *begin++=aux;
	
// }
	
// void itoa(int value, char* str, int base) {
	
// 	static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	
// 	char* wstr=str;
	
// 	int sign;
	


	
// 	// Validate base
	
// 	if (base<2 || base>35){ *wstr='\0'; return; }
	

	
// 	// Take care of sign
	
// 	if ((sign=value) < 0) value = -value;
	


	
// 	// Conversion. Number is reversed.
	
// 	do *wstr++ = num[value%base]; while(value/=base);
	
// 	if(sign<0) *wstr++='-';
	
// 	*wstr='\0';
	

	
// 	// Reverse string

	
// 	strreverse(str,wstr-1);
	
// }
	
	
	
/**
	
 * Ansi C "itoa" based on Kernighan & Ritchie's "Ansi C"

	
 * with slight modification to optimize for specific architecture:
	
 */
	