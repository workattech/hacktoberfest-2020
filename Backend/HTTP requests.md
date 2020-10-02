# HTTP METHODS

HTTP has a set of request methods to indicate the desired action to be performed for a given resource. Although they can be nouns as well, HTTP methods are sometimes called HTTP verbs. All of the methods share some common features like they are safe, idempotent and cacheable.

Following are the most commonly used HTTP methods:



> GET

The GET method is used to request data from a specified source.

* GET requests remain in the browser history.
* GET should **never** be used while requesting sensitive information.
* GET requests should only be used to request data and modify it. 



> POST

The POST method is used send data to a server eg. while filling a form.

* POST requests are never cached.
* POST requests are not stored in the browser history.
* POST request do not have any data length restrictions



> PUT

The PUT method is used to update data on a server.

* Main difference between POST and PUT is PUT requests are idempotent i.e. calling the same request more than once will have the same result.



> HEAD

The HEAD method is almost identical to GET, the only difference is that HEAD doesn't have response body.



> DELETE

This method is used to delete data from the server.



> OPTIONS 

The options method describes the communication options for the target resource.

