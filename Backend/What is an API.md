# What is an API?

## Application Programming Interface

> APIs are a set of functions and procedures that allow for the creation of applications that access data and features of other applications, services, or operating systems.

According to *Wikipedia*, good APIs make it easier to develop a computer program by providing all the building blocks, which are then put together by the programmer.

# So, what exactly is an API?
An **application program interface (API)** is a toolset that programmers can use to help them create software. Simply put, an API specifies how software components should interact.

To describe the concept in further detail, you need to comprehend the basics. Let’s start with my favorite analogy of a restaurant menu. When you go to a restaurant to eat, you choose from the selection on the menu. From this point, you convey your choices to the waiter. He/she then takes your choices to the chef, they prepare your meal, and it’s returned to you for a nice meal. From this point, you may ask yourself, do you know what the chef used in your fish or steak? How was it prepared? This back-and-forth analogy serves as a starting point for this explanation.

Why? Because with an API, you really don’t know what’s going on behind the scenes at the restaurant. All you really know is that you gave your food order, it was processed and out came your dinner on a nice plate.

# A real-world example
A real-world example is buying movie tickets online. You go to the movie site, you enter your movie, name and credit card information, and lo-and-behold, you print out your tickets. But what’s going on between entering your information to receiving your ticket? APIs, that’s what!

They are collaborating behind the scenes with other applications. How is this possible you ask? This type of integration is called “seamless” because you never have a clue when a software role is passed from one application to another. 

# Different types of APIs
There isn’t just one type of **API (Application Programming Interface)** but actually, there are four main types of APIs:

- **Open APIs**, aka **Public APIs**, are publicly available to developers and other users with minimal restriction. They may require registration, use of an API Key or OAuth, or maybe completely open. They focus on external users, to access data or services.
- **Partner APIs** are APIs exposed by/to the strategic business partners. They are not available publicly and need specific entitlement to access them. Like open APIs, partner APIs are the tip of the iceberg because they are the most visible ones and are used to communicate beyond the boundaries of the company. They are usually exposed to a public API developer portal that developers can access in self-service mode. While open APIs are completely open, there is an on-boarding process with a specific validation workflow to get access to partner APIs.
- **Internal APIs**, aka **Private APIs**, are hidden from external users and only exposed by internal systems. Internal APIs are not meant for consumption outside of the company but rather for use across different internal development teams for better productivity and reuse of services. A good governance process consists of exposing them to an internal API developer portal that connects to the internal IAM systems to authenticate and authorize users to access the right set of APIs.
- **Composite APIs** combine multiple data or service APIs. They are built using the API orchestration capabilities of an API creation tool. They allow developers to access several endpoints in one call. Composite APIs are useful for example in a micro-services architecture pattern where you need information from several services to perform a single task.

# Data and service APIs
Beyond the difference between an internal, partner, open, and composite APIs, we should mention another approach to categorize APIs:

- **Data APIs** provide **CRUD** access to underlying data sets for various databases or SaaS cloud providers. These APIs are needed to serve some fundamental data coming from SaaS application, with help from SaaS connectors or internal data stores.
- **Internal service APIs** consist of exposing internal services, reflecting parts of internal processes, or some complex actions.
- **External service APIs** are third-party services that can be easily embedded into the existing services of the company to bring additional value.
- **User experience APIs** leverage composite APIs to help app developers provide the right experience for each specific device (desktop, mobile, tablet, VPA, IoT).

# Types of API Protocols
>To leverage these different types of APIs, we must follow certain protocols. A protocol provides defined rules for API calls. It specifies the accepted data types and commands. Let’s take a look at the major types of protocols for APIs:

**1.REST**
**REST (short for Representational State Transfer)** is a web services API. REST APIs are a key part of modern web applications, including Netflix, Uber, Amazon, and many others. For an API to be RESTful, it must adhere to the following rules:

- **Stateless** —A REST API is stateless in nature, Client-Server Architecture
- **Uniform Interface** —A client and server should communicate with one another via HTTP (HyperText Transfer Protocol) using URIs (Unique Resource Identifiers), CRUD (Create, Read, Update, Delete) and JSON (JavaScript Object Notation) conventions.
- **Client-Server** —The client and server should be independent of each other. The changes you make on the server shouldn’t affect the client and vice versa.
Cache—The client should have the ability to cache the responses as this improves the user experience by making them faster and more efficient.
- **Layered** —The API should support a layered architecture, with each layer contributing to a clear hierarchy. Each layer should be loosely coupled and allow for encapsulation.

**2.SOAP**
**SOAP (simple object access protocol)** is a well-established protocol similar to REST in that it’s a type of Web API.

SOAP has been leveraged from the late 1990s. SOAP was the first to standardize the way applications should use network connections to manage services.

But SOAP came with strict rules, rigid standards were too heavy and, in some situations, very resource-intensive. Except for existing on-premise scenarios, most developers now prefer developing in REST over SOAP.

**3.RPC**
An **RPC** is a **remote procedural call** protocol. They are the oldest and simplest types of APIs. The goal of an RPC was for the client to execute code on a server. XML-RPC used XML to encode its calls, while JSON-RPC used JSON for the encoding. Both are simple protocols. Though similar to REST, there are a few key differences. RPC APIs are very tightly coupled, so this makes it difficult to maintain or update them. To make any changes, a new developer would have to go through various RPCs documentation to understand how one change could affect the other.

**APIs** play a key role in the development of any applications. And REST has become the preferred standard for building applications that communicate over the network. REST fully leverages all the standards that power the World Wide Web and is simpler than traditional SOAP-based web services. Unlike RPC, it allows for a loosely coupled layered architecture to maintain easily or update them.