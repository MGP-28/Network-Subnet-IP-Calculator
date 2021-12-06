#include <stdio.h>
#include <math.h>

void subnet_size_to_IP(int subnet_size){
  int cont=0;
    while(subnet_size-8>0){
      subnet_size=subnet_size-8;
      cont++;
    }
    for(int i=0; i<cont; i++){
      printf("255.");
    }
  //calculate subnet number where network ends and host IPs begin
      int sum=0, power=7;
      for(int i=0; i<subnet_size; i++){
        sum+=pow(2,power);
        power--;
      }
    //fills the zeros after, if needed, to complete a 4 number IP
      printf("%d", sum);
      for(int i=cont; i<3; i++){
        printf(".0");
      }
}

int main(void) {
  int loop=1;
  printf("########## SUBNET IP CALCULATOR ##########\n");
  do{

//read program choice
    int choice=0;
    do{
      printf("\n\nCalculate by subnet size (1) or computers slots (2)? ");
      scanf("%d",&choice);
      if(choice >2 || choice <1)
          printf("----- Invalid -----\n");
    }while(choice >2 || choice <1);
    int subnet_size=0, hosts=0;

//program 1 -> size of network to subnet IP
    if(choice==1){
  //read subnet size number   
      do{
        printf("Subnet size: /");
        scanf("%d", &subnet_size);
        if(subnet_size<1 || subnet_size>32)
          printf("----- Invalid -----\n");
          if(subnet_size==31 || subnet_size==32)
            printf("Subnet will be calculated but it's an unusable network!!!\n");
      }while(subnet_size<1 || subnet_size>32);
      hosts=pow(2,32-subnet_size)-2;
      printf("Maximum number of hosts per network: %d\n",hosts);
      printf("Network jump: %d\n",hosts+2);
    }

//program 2 -> number of hosts to subnet IP
    else{
      do{
  //read host needed number
        printf("Number of hosts per network: ");
        scanf("%d", &hosts);
        if(hosts<1 || hosts>pow(2,31))
          printf("----- Invalid -----\n");
      }while(hosts<1 || hosts>pow(2,31));
      hosts+=2; //+network and broadcast
  //Find how many 0s of the subnet the hosts will need
      int power=0, jump=0;
      while(pow(2,power)<hosts){
        power++;
      }
  //Calculate subnet size number
      subnet_size=32-power;
      printf("Subnet size: /%d\n", subnet_size);
      jump=pow(2,power);
      printf("Network jump: %d (2^%d)\n",jump, power);
    }

//Run subnet to IP function
    subnet_size_to_IP(subnet_size);

  }while(loop==1);//Loops program
  return 0;
}