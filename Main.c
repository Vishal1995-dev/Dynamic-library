#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dlfcn.h>

int main()
{
	void *lib=NULL;
 	
 	//int add(int no1,int no2)
	int (*fptr)(int,int);		//function ptr fptr
	int (*fptr2)(int,int);
	
	int val1=10,val2=11,ret=0;
	
	printf("Linking library....\n");
	
	lib=dlopen("./Library.so",RTLD_LAZY);
	if(lib==NULL)
	{
		printf("Unable to link library\n");
		return-1;
	}
	
	printf("Library linked successfully\n");
	
	printf("Fetching address of add\n");
	
	fptr=dlsym(lib,"add");
	if(fptr==NULL)
	{
		printf("Unable to get address\n");
		return-1;
	}
	
	printf("Address fetched successfully\n");
	
	ret=fptr(val1,val2);
	
	printf("Addition is : %d\n",ret);
	
	printf("Fetching address of mul\n");
	
	fptr2=dlsym(lib,"mul");
	if(fptr2==NULL)
	{
		printf("Unable to get address\n");
		return-1;
	}
	
	printf("Address fetched successfully\n");
	
	ret=fptr2(val1,val2);
	
	printf("Multiplication is : %d\n",ret);
	
	dlclose(lib);
	
	printf("Dynamic library unlinked\n");
	
	return 0;
}
