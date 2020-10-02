# What happens when we type a URL in the browser?

Have you ever noticed the **http://** attached to the URL string when you type in the address of a website? That is one of the most widely used protocols called **hyper text transfer protocol** to communicate via internet. **HTTP** are a set of rules by which you - a client - communicate to a server - say, *workat.tech*. 

Its easier for us to remember websites by their names like *workat.tech* but to a computer a hostname isn't of much use. So, to pin-point the exact address of the server where wewant to send our request a mediator called a domain name server or **DNS server** is used. When we type in a URL, a DNS server goes to work and starts to translate the name of the website into its IP address. It does this by sending a *query* to several servers, each of which translate a different part of the URL, and finally we get the exact address where we want to send our request. 

Now that we have the IP address, a **request-response cycle** begins. Say that you want to read about some topic on workat.tech, so you will type that URL in your search bar, 
now behind the scenes a **HTTP request** is send by your browser to the servers of workat.tech and if all goes well a connection is established between you two. The server will 
process the information which you asked and will send back a **HTTP response** with your **HTML page** in its response body. It will also send a **status code 200** if everything 
worked exactly the way we wanted and if you sent a bad request there is a chance that you can get the infamous **404 not found error**.

You might have also noticed **https://** with URLs of some websites (and a little lock icon). The "s" stands for secure. This was made to increase protection and security against
hackers. Hackers can hack the DNS server and configure it in such a way that all the requests which you send go to their IP instead. This can have disastrous consequences. 
Imagine if you entered your credit card details and they went to a wrong IP! 

To prevent this, there is something called the **SSH/TLS protocol** or the **handshake protocol**. In this protocol, every request you send is encrypted with a 2-way key - a
public key and a private key. If both of the keys match a handshake occurs and only then a connection gets established. Every website with https has a SSH certificate. Your 
browser first sends a *hello* message to the server and the server responds with its SSH certificate. If the certificate is valid and both the keys match you can communicate with 
the server without any worry else an error occurs and the connection doesn't get established.

