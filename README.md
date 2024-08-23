# minitalk
<div align = "center">

<img src = "https://www.vangproperties.com/media/3830/42lisboa.jpg?preset=imageWithTextInsideText" alt = "42 lisbon img">

</div>

## About
Minitalk is a small data exchange program that leverages UNIX signals to facilitate communication between two processes: a client and a server. The aim is to send a string from the client to the server, and displays it in the terminal.

## Mandatory
- [x] Create two executable files: client and server;
- [x] The Client  takes two parameters: PID and string to sendo;
- [x] The clinent must send the string passed as a parameter to the server;
- [x]  Server has to display the string quickly;
- [x] Your server should be able to receive strings from several clients;
- [x] We can only use SIGUSR1 and SIGUSR2 signals.

##Bonus 
- [ ]  Add reception acknowledgement system.
- [x] Support Unicode characters.