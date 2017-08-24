
#include <stdio.h>
#include<stdlib.h>
int main(void) {

  pid_t pid, sid;
	int fichero;

 
  pid = fork(); //iniciamos el fork
 
	if (pid>0) // Este es el proceso padre
	{
      exit(0);
	}
	if(pid<0){
	  printf("Error en el proceso");
	  exit(0);
	}
	else // Proceso hijo
	
	{
	  umask(0);
	 
	 fichero = open("log_cpu", O_WRONLY|O_CREAT|O_TRUNC, 0600);
	 
	/* validar apertura de fichero */
	if (fichero == -1) {
		perror ("Error al abrir el archivo");
		return -1;
	}
	
	/*Crear el nuevo sid*/
	sid = setsid();
	
	if (sid < 0) {
		perror(" error en SID ");
	}
	
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	  
	  
	  while (1) {
		char *buf=(char *)malloc(100);
		FILE *fp = popen("top -bn2 | grep '%Cpu' | tail -1", "r");
		fread(buf,100,1, fp);
		write (fichero, buf, strlen(buf));
		pclose(fp);
	sleep(1);
	}	
	return -1; //borrar cuando creamos daemon
	}
}
