procesodaemon: 
	gcc -Wall  taller15.c -o programa
.PHONY: clean
clean:
rm -rf programa log_cpu
