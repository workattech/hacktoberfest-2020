# HTTP METHODS

### What are HTTP METHODS?

HTTP has a set of request methods to indicate the desired action to be performed for a given resource. Although they can be nouns as well, HTTP methods are sometimes called HTTP verbs. All of the methods share some common features like they are safe, idempotent and cacheable.


### Following are the most commonly used HTTP methods:

> GET

The GET method is used to request data from a specified source. These requests remain in the browser history.These should **never** be used while requesting sensitive information. These requests should only be used to request data and modify it. These are one of the most important requests in HTTP when we want to fetch some data from a server or a website.


> POST

The POST method is used send data to a server eg. while filling a form. These requests are never cached.requests are not stored in the browser history. These requests do not have any data length restrictions. These requests are very important when we want to send some data to a server/website.


> PUT

The PUT method is used to update data on a server.Main difference between POST and PUT is PUT requests are idempotent i.e. calling the same request more than once will have the same result. These requests are not as important as POST and GET beacuse with some tweaking they can do perform its functionality as well.


> HEAD

The HEAD method is almost identical to GET, the only difference is that HEAD doesn't have response body.


> DELETE

This method is used to delete data from the server. This is one the the important reqeusts beacause only this requests allows the functionality of deleting the previously stored data on a server.


> OPTIONS 

The options method describes the communication options for the target resource.

