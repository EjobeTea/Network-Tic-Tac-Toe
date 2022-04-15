# Network-Tic-Tac-Toe #

This lab consists of a UDP protocol to implement a client and server system for gameplay.

Arbitrary monitor ports between two raspberry pis consisted of port 4096 for the server and port 4097 for the client.

## How to compile and run ##
| Command            | Explanation
| -------------------|:-------------:|
| gcc -o t3 t3.c udp.c    | Compiles the program
| ./t3 REMOTE_IP ROLE     | Run this to have the role assignment 
| ./t3 192.168.1.x accept | Server will accept the invite
| ./t3 192.168.1.y invite | Client will send out the invite

Note: Since this game relies on IPv4 addresses, you have to verify your device's IP address after every hardware start up. Others will need the address to connect to your computer.
