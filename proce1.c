#include <sys/types.h>
#include <sys/stat.h>


#define ETH_LOCATION "/sys/class/net/enp0s3/address"
#define WIFI_LOCATION	"/sys/class/net/enp0s8/address"
#include <stdio.h>
int main()
{
   	char usr_choice, *buff;
	FILE *file_ptr;
   	printf("Enter your choice !!\n1. Ethernet \n2. WIFI \n");
   	scanf("%c", &usr_choice);
	if (usr_choice == '1') {
		printf("Entered character is %c \n", usr_choice);
		file_ptr = popen("cat "ETH_LOCATION" ","r");
		if(file_ptr == NULL) return -1;
	}
	else if(usr_choice == '2') {
		printf("Entered character is %c \n", usr_choice);
		file_ptr = popen("cat "WIFI_LOCATION" ","r");
		if(file_ptr == NULL) return -1;
	}		
	else {
		printf("invalid choice %c \n", usr_choice);
		return -1;
	}
	
	fscanf(file_ptr, "%s", buff);
	fclose(file_ptr);
	mkfifo ("./fifo",0666);
	file_ptr = fopen("./fifo","w");	
	fprintf(file_ptr, "%s", buff);
	fclose(file_ptr);
	return 0;
}
