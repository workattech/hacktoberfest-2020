# How internet works?



## What is internet?

The internet is the network which allows computers, smartphones, smart-watches, smart-televisions, videogame consoles etc. to talk to each other. 
It is the thing which lets you watch your favorite movie on Netflix at 2 AM in the night or lets you send an email to your cousin living half way across the world. 
This is done by a lot of cables, routers, servers, data centers, satellites and Wi-Fi towers, which allow digital signal to travel around the world.



## Who owns the internet?

Internet was made in 1960s by the government of the United States to make a decentralized system to distribute information. 
They installed routers which allowed the flow of information. Since then many private _Internet Service Providers (ISPs)_ have added  their own routers to that network. 
So no completely owns the internet, its as if we asked who owned all the telephone lines!



## How do devices communicate through internet?

Internet uses a system of rules or _protocols_ to send or receive a message. 
These are mainly the Internet Protocol (IP) and, the transport Protocol (TCP). The messages are first split into small fragments called _packets_. 
These packets are sent independent to each other to the receiver which combines them together. The typical size of a packet is usually between 2000 to 3000 characters.



## How is data sent/received?

Data is sent or received in the form of small packets. The internet is made up of a specialized network of computers called routers. 
Each router knows how to move packets from source to destination. A packet may travel through many routers before reaching to the receiver.



## What is the work of Internet Protocol(IP)?

IP has the task of delivering packets from source to the destination. It's first task it to break the data into packets. Each packet has two components, a header and a payload. 
It keeps track of packets by assigning an _IP address_ in the packet's header - a designated place to hold packet's _metadata_ - before before sending them.
Finally it is also responsible for _reassembly_.



## What is the work of TCP?

TCP provides reliable, ordered, and error-checked delivery of a stream of octets between applications running of IP networks. 
It is a stateless protocol which means that after a communication is done, the whole process will start afresh. 
If some of the packets are lost in the transmission, TCP makes sure to re-transmit them.


