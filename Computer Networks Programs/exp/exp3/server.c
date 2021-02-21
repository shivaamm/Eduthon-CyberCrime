#include<sys/types.h>
//Data type including system data types and macros
#include<stdio.h> 
#include<sys/socket.h> 
//socket related functions and data types, constants, macros
#include<netinet/in.h> 
//Address family, IPv6 header address family
#include<netdb.h> 
//network dtabase operations
#include<arpa/inet.h> 
//constants, functions, macros related to internet operations.
#include<string.h> 
//string manpulating functions.

int main(int asrgc,char*argv[])
{ 
int bd,sd,ad;   //bind discriptor, socket discriptor, accept discriptor
char buff[1024];
struct sockaddr_in cliaddr,servaddr;  //It declares two uninitialized variables of the type struct sockaddr_in.
socklen_t clilen; 
clilen=sizeof(cliaddr); 
bzero(&servaddr,sizeof(servaddr)); //bzero() function erases the data in the n bytes of the memory starting at the location pointed to by   

           /*Socket address structure*/ 
servaddr.sin_family=AF_INET; //The variable serv_addr is a structure of type struct sockaddr_in.

servaddr.sin_addr.s_addr=htonl(INADDR_ANY);  // This field contains the IP address of the host. For server code, this will always be the IP address of the machine on which the server is running(32 bit) 

servaddr.sin_port=htons(1999); //Set IP address to localhost  (16 bit)

/*TCP socket is created, an Internet socket address structure is filled with wildcard address & server’s well known port*/   
sd=socket(AF_INET,SOCK_STREAM,0); 

          /*Bind function assigns a local protocol address to the socket*/
bd=bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr)); 

/*Listen function specifies the maximum number of connections that kernel should queue for this socket*/
listen(sd,5);  //listen func shows it's server side
printf("Server is running….\n");
 
           /*The server to return the next completed connection from the front of the  
           completed connection Queue calls it*/    
ad=accept(sd,(struct sockaddr*)&cliaddr,&clilen); 
while(1) 
{ 
bzero(&buff,sizeof(buff)); 
            /*Receiving the request message from the client*/
    recv(ad,buff,sizeof(buff),0); 
    printf("Message received is %s\n",buff); 
} 
}
