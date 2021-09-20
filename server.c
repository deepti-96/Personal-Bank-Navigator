#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h> 
#include  <sys/socket.h>
#include<netinet/in.h>
void main()
{//Decleration
	int listenfd,connfd,n,size=0;
	struct sockaddr_in servaddr,clientaddr;
	char sendBuff[3000];
    int numrv;
	//char sbuff[150]="Helo Client: A msg from Server!";
 
	//Socket
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	if(listenfd == -1)
	{
		perror("\nSocket is not created\n");
	}
	else
	{
		printf("\nSocket is created\n");
	}
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(3848);
	//bind
	if(bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) == -1)
	{
		perror("Bind Unsccessful\n");
	}
	else
	{
		printf("Bind Successful\n");
	}
	//listen
	listen(listenfd,9);
	//accept
	size = sizeof(struct sockaddr_in);
 
	connfd = accept(listenfd,(struct sockaddr *)&clientaddr, &size);
 
        int choice ;
       FILE *fp = fopen("rspuram.txt","rb");
       
        if(fp==NULL)
        {
            printf("File open error");
           // return 1;
        }
        FILE *ft = fopen("gandhipuram.txt","rb");
        if(fp==NULL)
        {
            printf("File open error");
           // return 1;
        }
        FILE *fc = fopen("peelamedu.txt","rb");
        if(fp==NULL)
        {
            printf("File open error");
           // return 1;
        }
 
 
 
 
 
           /* First read file in chunks of 256 bytes */
             n=read(connfd,&choice,sizeof(int));
             printf("\n choice is %d",choice);
 
 
             switch(choice)
             {
                 case 1: printf("\nBANKS available near RS PURAM are::");
                  unsigned char buff[3000]={0};
            int nread = fread(buff,1,3000,fp);
            //printf("Bytes read %d \n", nread);
 
            /* If read was success, send data. */
            if(nread > 0)
            {
                printf("Sending \n");
                //printf("%s",buff);
                write(connfd, buff, nread);
 
            }
		fclose("shivajinagar.txt");
 
 
                          break;
           case 2: printf("\t BANKS AVAILABE NEAR GANDHIPURAM ARE");
                   unsigned char buff1[3000]={0};
            int nread1 = fread(buff1,1,3000,ft);
            printf("\tBytes read %d \n", nread1);
 
            /* If read was success, send data. */
            if(nread1 > 0)
            {
                printf("\nSending \n");
                //printf("%s",buff1);
                write(connfd, buff1, nread1);
            }
 
		fclose("shivajichowk.txt");
       
                          break;
           case 3: printf("\nBANKS AVAILABLE NEAR PEELAMEDU ARE");
                   unsigned char buff2[3000]={0};
                   int nread2= fread(buff2,1,3000,fc);
              // printf("Bytes read %d \n", nread2);
 
            /* If read was success, send data. */
            if(nread2 > 0)
            {
                printf("\nSending \n");
                printf("%s",buff2);
                write(connfd, buff2, nread2);
            }
 
		fclose("bhartiya.txt");
      
 
                          break;
 
                 case 4:  close(connfd);
                           sleep(1);
                           close(listenfd);
 
                           break;
                 default: printf("enter proper choice");
 
             }
        
	}
