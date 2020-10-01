# Object Oriented Programming

## What is an Object
Object Oriented Programming is a programming style that is intended to make thinking about programming closer to thinking about the real world.
In programming, objects are independent units, and each has its own identity, just as objects in the real world do.

### Objects
An object might contain other objects but they’re still different objects.
Objects also have characteristics that are used to describe them. For example, a car can be red or blue, a mug can be full or empty, and so on. These characteristics are also called attributes. An attribute describes the current state of an object.
Objects can have multiple attributes (the mug can be empty, red and large).

In the real world, each object behaves in its own way. The car moves, the phone rings, and so on.
The same applies to objects – behavior is specific to the object’s type.

In programming, an object is self-contained, with its own identity. It is separate from other objects.
Each object has its own attributes, which describe its current state. Each exhibits its own behavior, which demonstrates what they can do.
In computing, objects aren’t always representative of physical items.
For example, a programming object can represent a date, a time, a bank account. A bank account is not tangible; you can’t see it or touch it, but it’s still a well-defined object – it has its own identity, attributes, and behavior.


## What is a Class
Objects are created using classes, which are actually the focal point of OOP.
The class describes what the object will be, but is separate from the object itself.
In other words, a class can be described as an object’s blueprint, description, or definition.
You can use the same class as a blueprint for creating multiple different objects. For example, in preparation to creating a new building, the architect creates a blueprint, which is used as a basis for actually building the structure. That same blueprint can be used to create multiple buildings.
Programming works in the same fashion. We first define a class, which becomes the blueprint for creating objects.
Each class has a name, and describes attributes and behavior.
In programming, the term type is used to refer to a class name: We’re creating an object of a particular type.

### Methods
Method is another term for a class’ behavior. A method is basically a function that belongs to a class.

### A Class Example
For example, if we are creating a banking program, we can give our class the following characteristics:
Name: BankAccount
Attributes: accountNumber, balance, dateOpened
Behavior: open(), close(), deposit()
The class specifies that each object should have the defined attributes and behavior. However, it doesn’t specify what the actual data is; it only provides a definition.
Once we’ve written the class, we can move on to create objects that are based on that class.
Each object is called an instance of a class. The process of creating objects is called instantiation.


## Abstraction
Data abstraction is the concept of providing only essential information to the outside world. It’s a process of representing essential features without including implementation details.
A good real-world example is a book: When you hear the term book, you don’t know the exact specifics, i.e.: the page count, the color, the size, but you understand the idea of a book – the abstraction of the book.

Abstraction means, that we can have an idea or a concept that is completely separate from any specific instance.
It is one of the fundamental building blocks of object oriented programming.
For example, when you use cout, you’re actually using the cout object of the class ostream. This streams data to result in standard output.


## Encapsulation
Part of the meaning of the word encapsulation is the idea of “surrounding” an entity, not just to keep what’s inside together, but also to protect it.
In object orientation, encapsulation means more than simply combining attributes and behavior together within a class; it also means restricting access to the inner workings of that class.
The key principle here is that an object only reveals what the other application components require to effectively run the application. All else is kept out of view.

For example, if we take our BankAccount class, we do not want some other part of our program to reach in and change the balance of any object, without going through the deposit() or withdraw() behaviors.
We should hide that attribute, control access to it, so it is accessible only by the object itself.
This way, the balance cannot be directly changed from outside of the object and is accessible only using its methods.
This is also known as “black boxing”, which refers to closing the inner working zones of the object, except of the pieces that we want to make public.
This allows us to change attributes and implementation of methods without altering the overall program. For example, we can come back later and change the data type of the balance attribute.


## Access Specifiers
Access specifiers are used to set access levels to particular members of the class.
The three levels of access specifiers are public, protected, and private.
A public member is accessible from outside the class, and anywhere within the scope of the class object.

### Private
A private member cannot be accessed, or even viewed, from outside the class; it can be accessed only from within the class.
A public member function may be used to access the private members.

## Constructors
Class constructors are special member functions of a class. They are executed whenever new objects are created within that class.
The constructor’s name is identical to that of the class. It has no return type, not even void.

Constructors can be very useful for setting initial values for certain member variables.
A default constructor has no parameters. However, when needed, parameters can be added to a constructor. This makes it possible to assign an initial value to an object when it’s created.

## Destructors
Remember constructors? They’re special member functions that are automatically called when an object is created.
Destructors are special functions, as well. They’re called when an object is destroyed or deleted.


## Friend Functions
Normally, private members of a class cannot be accessed from outside of that class.
However, declaring a non-member function as a friend of a class allows it to access the class’ private members. This is accomplished by including a declaration of this external function within the class, and preceding it with the keyword friend.
Typical use cases of friend functions are operations that are conducted between two different classes accessing private members of both.

### This
Every object in C++ has access to its own address through an important pointer called the this pointer.
Inside a member function this may be used to refer to the invoking object.

## Operator Overloading
Overloaded operators are functions, defined by the keyword operator followed by the symbol for the operator being defined.
An overloaded operator is similar to other functions in that it has a return type and a parameter list.


## Inheritance
Inheritance is one of the most important concepts of object-oriented programming.
Inheritance allows us to define a class based on another class. This facilitates greater ease in creating and maintaining an application.
The class whose properties are inherited by another class is called the Base class. The class which inherits the properties is called the Derived class. For example, the Daughter class (derived) can be inherited from the Mother class (base).
The derived class inherits all feature from the base class, and can have its own additional features.

### Type of Inheritance
*Public Inheritance:* public members of the base class become public members of the derived class and protected members of the base class become protected members of the derived class. A base class's private members are never accessible directly from a derived class, but can be accessed through calls to the public and protected members of the base class.

*Protected Inheritance:* public and protected members of the base class become protected members of the derived class.

*Private Inheritance:* public and protected members of the base class become private members of the derived class.

### Constructors
The base class constructor is called first.
### Destructors
The derived class destructor is called first.


## Polymorphism
The word polymorphism means “having many forms”.
Typically, polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.
C++ polymorphism means that a call to a member function will cause a different implementation to be executed depending on the type of object that invokes the function.