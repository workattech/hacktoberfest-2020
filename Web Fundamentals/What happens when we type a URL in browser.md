# What happens when we type a URL in the browser?

> This article describes how a browser retrieves our favorite website from the Internet using a URL. But before we go any deeper, let's look into some basic networking concepts:

##### Client-Server

The most common way of modelling a network is the Client - Server architecture.
In this architecture, every node is either a Server (provider of services/resources) or Client (consumer of services).
A service is hosted at a particular network port in the server machine. The designated IP and Port Number combination is used to reach the service.
For example, if you start a localhost server at port number `8000`, you can reach it from the browser at `127.0.0.1:8000`.

##### Communication Protocols

Nodes communicate using a two-way messaging technique, where a client sends request messages and the server sends back response messages.
But both parties need to maintain some standards in order to understand and transmit the information properly.
This set of formats and policies are known as protocols. We generally use **HTTP** to transfer hypertext resources at the application level and **TCP** to create a connection between the two nodes at the transport level. The communication flow is as follows:

- Client starts a reliable connection generally using TCP's **3-way handshake** (SYN, SYN-ACK and ACK):
  - Client sends SYN (synchronization) message to check server's availability and to send an initial sequence number, `p`.
  - Receiver also selects a sequence number, `q`. Each side acknowledges the other by incrementing the other sequence number in ACK (acknowledgement). So on receiving SYN, the server responds with SYN-ACK containing `q` and `p+1`.
  - On receiving SYN-ACK, client acknowledges with `q+1` in it's ACK message. This sets the connection for actual data transfer.
- Now at the application level, the client sends a HTTP request to the server. It consists of the HTTP request method, resource path, HTTP version, host name, and headers.
- A server awaits requests and sends back a HTTP response. It consists of HTTP version, Response status code, status message, headers and a body for the fetched web resource.

In our scenario, the browser is the client that makes requests to get a website's contents from it's server. But first let's see what a browser is.

## Web Browser

A browser is a software application that requests information from a host machine, retrieves the content and renders it on the user's device.
It does so with the help of 3 internal components:

- Network stack: Responsible for all network related calls.
- Javascript engine: Compiles and executes javascript code
- Rendering engine: Determines web page layout, parses HTML and displays graphics.

A browser provides us with web resources when we give the correct address of the resource on the network. So let's find out how resources are addressed in the web.

## Addressing

The Uniform Resource Locator (URL) is a string used to identify and locate a web resource. It contains a protocol, domain name and resource path. It may also contain a port number, query parameters and an anchor. The domain name has a hierarchical structure. It contains one or more parts called labels that are dot-separated. The domains/labels are part of a domain name space.

The right-most label of the domain name is the top level. The labels at the left of each label is it's subdomain. For e.g, in case of `www.github.com`, `com` is the top level domain (TLD), `github` is a subdomain of `com` and `www` is a subdomain of `github.com`.

There is another kind of address for web resources. Every node in a network is assigned a unique ID in the form of an IP address. For Internet Protocol version 4 (IPv4), the IP address is a 32-bit number. An IP address is also used to identify and locate a web resource.

The domain name part in the URL actually works as an alias for the IP address of the host machine. Since it's easier to remember `www.google.com` over something like `172.217.166.228`, we generally use domain names for identification in the human world.

But the 32 bit number is more efficient for communication in the network device world. That's why we have the concept of Domain Name System (DNS) that helps browsers and other clients find out the IP addresses from a URL.

## Domain Name System

DNS is a hierarchical system used for translations between URLs and IP addresses. In case of a distributed system of host servers, the URL is translated to the geographically closest available server. It supports the domain name hierarchy. The domain name space is represented as a tree and supported by a distributed database of domain information.

Each node is called a Name Server. The top domain is served by Root Servers. Each domain has at least one assigned name server called Authoritative Name Server to store the domain's information as well as its subdomains' details in the form of DNS records.

A DNS record can be an IP address (A or AAAA record), domain name alias (CNAME record), other name servers (NS record), pointer for reverse DNS lookup i.e, IP Address to domain name (PTR record) etc.

## Hitting a URL in Browser

When a URL is entered, the first task of the browser is to find the IP address from the URL. This is done through DNS Address resolution using a DNS Resolver. The task of the resolver is to keep sending queries until the IP address for the required domain is found. 

This process is initiated by the browser by sending a DNS query to a simple stub resolver present in the OS. The stub resolver looks up in its files to check if the record is available. If it's not found, it queries an actual DNS Resolver that sends out DNS queries till the required IP address is obtained and sent to the browser.

We generally use the DNS resolver of our Internet Service Provider (ISP), which also caches DNS lookups for faster resolutions. If the record is not found, the query is sent to a root server which resolves the TLD (suppose, `tech`), and returns the address of the Name Server for the TLD to the resolver. The resolver then queries TLD's Name server for the next label (`workat`) and so on, till we reach an Authoritative Name Server containing the IP Address (suppose `3.6.162.254` for `www.workat.tech`) or a CNAME record. If a CNAME is obtained, a similar DNS lookup for that domain name is triggered by the browser till we get the actual server IP Address.

In reality, we may not require to reach the Authoritative Name Server to get the address. This is because the browser, the OS, routers and resolvers perform caching on DNS translations to speed-up the resolution process.

After the browser gets the actual IP address, it creates a TCP connection with the server, using the 3-way handshake method. Once a connection is established, the resources are obtained using the request-response method by the browser. After receiving resources, the browser closes the TCP connection by sending a RST (reset or tear down) or FIN (finish) message to the server.

Once the page resources are obtained, the last step for the browser is to process the content using its javascript and layout engines and finally display the page on your screen.

That's the life-story of a URL hit. Hope you enjoyed it!
