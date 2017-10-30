#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>


int randomNum(){

  int file = open("/dev/random",O_RDONLY);
  int address;
  read(file,&address,sizeof(int));
  
  if (errno) printf("Error is: %s\n", strerror(errno));

  close(file);
  return address;

}


int main(){

  int array[10];
  int counter = 1;
  int i = 0;
  for (;i<10;i++){
    array[i] = randomNum();
    printf("Random number %d: %d",counter,array[i]);
    counter++;
  }

  int file = open("randomNumbers", O_CREAT | O_RDWR, 0644);
  write(file, array,sizeof(array));
  close(file);
  if(errno) printf("Error %d: %s\n", errno, strerror(errno));

  int secondArray[10];
  file = open("randomNumbers",O_RDONLY);
  read(file,secondArray,sizeof(array));
  close(file);
  if(errno) printf("Error %d: %s\n", errno, strerror(errno));

  printf("\n\n");
  i=0;
  counter = 1
  for (;i<10;i++){
    printf("Second random number %d: %d",counter,secondArray[i]);
    counter ++;
  }

}
