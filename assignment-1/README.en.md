## Description
The goal of the first assignment - communication between programs using TCP/IP sockets. The program should consist of two parts - a client and a server. A student is free to choose what
kind of application to write - it can be a game, remote calculations, databases, etc. The program can have only a text-based interface. A student can pick an application from the list of
examples or implement an own idea, however programs should not repeat within the subgroup so I should be notified about the chosen application.

Description [in english](README.md)

## Requirements
* The program should be implemented using C/C++.
* The program should have at least minimal requirements - what socket to create/connect to, what host to connect to. 
* Server should not shut down after servicing only one client.
* Client should not shut down after finishing one request (requirement is not mandatory, if it does not make sense for the chosen program).
* Server should be able to support multiple clients.
* The program should be implemented using BSD sockets or Winsock interfaces. Do not use higher abstraction level interfaces. 
* Source code should be tidy, in accordance with objective or structured programming paradigms, with meaningful method, variable names, and comments.

## Examples
* Trip (bus, airplane, etc.) schedules, booking.
* E-shop, food ordering.
* Various databases - people, books, movies - with registration and search.
* Remote calculator
* Fibonacci numbers.
* Notebook.
* Message (mail) server.
* File server.
* Bank operations, ATM (accounts, transactions).
* Remote dictionary (translations).
* Tests/trivia/polls/math problems (questions/answers).
* Word guessing games, hangman.
* Lines.
* Black jack.
* Battle boats.
* Number guessing games (with hints such as higher or lower; with hints such as how many digits are guessed correctly and how many are in a right place)
* Chess, checkers
* Reversi.
* Tic-tac-toe.
* Matches game (who will get the last).
* Yes/No game.
* Network snake game.
* Other games, remote drawings, calculations, etc.

## Links
http://beej.us/guide/bgipc/output/html/multipage/unixsock.html

http://www.linuxhowtos.org/C_C++/socket.htm

https://msdn.microsoft.com/en-us/library/windows/desktop/ms738545(v=vs.85).aspx

http://www.binarytides.com/winsock-socket-programming-tutorial/