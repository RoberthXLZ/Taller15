
#include <stdio.h>
 
int main() {
	int pid;
 
	pid = fork();
 
	if (pid>0) // Este es el proceso padre
	{
      exit(0);
	}
	if(pid<0){
	  printf("Error en el proceso");
	  //strerror(errno);
	  exit(0);
	}
	else // Proceso hijo
	{
	  umask(0);
	  
	}
}
