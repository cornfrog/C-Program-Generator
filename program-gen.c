#include <stdio.h>
#include <string.h>	//including this to use strcat()
#include <sys/stat.h>	//including this to create directories with mkdir()

void getFileName();
void getDirName();
void createDir();
void createFile();
void createMakefile();

char fileName[100];
char dirName[100];
char dirPath[100];
char filePath[100];
char Makefile[] = "Makefile";
char MakefilePath[100];

int main(){
	getDirName();
	createDir();
	getFileName();
	createFile();
	createMakefile();
	return 0;
}

void getFileName(){
	printf("Enter File Name: ");
	scanf("%s", fileName);
}

void getDirName(){
	printf("Enter Project Name: ");
	scanf("%s", dirName);
	strcpy(dirPath, dirName);
}

void createDir(){
	/*
		NOTE:
			mkdir('directory-name', mode)
			'status' will be 0 for success and -1 if fails to create directory
	*/
	int status = mkdir(dirName, 0777);
	//if - mkdir was successful print message
	if(status == 0){
		printf("Success - Created Directory: %s\n", dirName);
		strcat(dirPath, "/");	// adding '/' for nesting file in created directory
	}
	//else - print error message
	else{
		printf("Error - Failed to create directory: %s\n", dirName);
	}
}

void createFile(){
	FILE* file;	//file pointer
	//setting file path
	strcpy(filePath, dirPath);
	strcat(filePath, fileName);
	file = fopen(filePath, "w");	//opening file - using "w" to create
	//if cannot create file print error message
	if(file == NULL){
		printf("Error: Could not create %s\n", fileName);
	}
	else{
		printf("Created file: %s\n", fileName);
	}
}

void createMakefile(){
	FILE* file;
	//setting Makefile path
	strcpy(MakefilePath, dirPath);
	strcat(MakefilePath, Makefile);
	file = fopen(MakefilePath, "w");
	if(file == NULL){
		printf("Error: Cannot create Makefile\n");
	}
	else{
		printf("Makefile Created\n");
	}
}
