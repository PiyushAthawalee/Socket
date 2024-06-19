# Test_project_piyush

Chat Application based on TCP client/server communication:

Chat program, using socket programming in C, where there is a single server and multiple clients.
The server forwards a client's message to all the other clients. The communication between the server and the clients is based on TCP Client/Server Communication and multiplexing.

**Getting Started**

*  Copy the project to a local directory: Clone with SSH

    git@192.168.70.240:csns/test_project_piyush.git

*  Clone with HTTPS

    http://192.168.70.240/csns/test_project_piyush.git

**Platform**

 Linux with GCC compiler

**To Run the project**

 Make a directory:
    
>   $ mkdir newdir 

 Move server and client directory in the newdir.
    
**Server**

  Server folder have following files:
  
     1.  Main File which include the library header and implement the main functionality (main.c)
     2.  Library file whiich contain the 'error' functon and the additional utility function (server_lib.c)
     3.  Library Header File its declear the functions and structure in 'lib.c' file(server_lin.h)
        

**Client**

 Client folder have following files:
       
    1.  Main File (main.c)  
    2.  Library file (client_lib.c)
    3.  Library Header File(client_lin.h)


**Installation:**

 To install the GCC compiler from Ubuntu repositories: 

1. Update the Ubuntu package repository using the following command: 

> $ sudo apt update 


2. Install the build-essential package:

> $ sudo apt installbuild-essential 


3. Use the following command to check the GCC version:

> $ gcc --version 

**Compilation**

 1.Run Makefile to compile the main.c and server_lib.c programm for server:
    
>   $ make server

 2.Run Makefile to compile the main.c and client_lib.c programm for client:
   
>   $ make client


    
**Running the Application**

1. Start the Server: 
   To start the server, run the following command :

> $ ./server <port_no> 
   
   Replace ‘<port_no>’ with the desired port number(eg. 5353).

2. Start the Client:
   To start the client, run the following command in a separate terminal for each client: 

>   $ ./client <server_ip> <port_no> 
   
   Replace ‘server_ip’ with the address of the server eg. ‘127.0.0.1’ for local host and ‘<port_no>’ with the port number the server is running on.

