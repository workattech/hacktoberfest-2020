# Polymorphism 

In __Object Oriented Programming__ there is a provision by which an operator or a method exhibits different characteristics depending upon the different sets of input provided to it. This feature in Object Oriented Programming is known as polymorphism. The term __‘polymorphism’__ is derived from the two greek words: _poly_ and _morphs_. The word “poly” means __many__ and “morphs” means __forms__. Therefore polymorphism literally means the capacity to take ‘different forms from one’. It is the ability to appear one thing in many forms in which the same operations may behave differently in different classes.

> Polymorphism is broadly used in implementing the concept of inheritance. 

### Example : 
![Polymorphism example image](https://github.com/Dhruv-194/hacktoberfest-2020/blob/Polymorphism/OOP/Polymorphism/Polyworktech.png)

Suppose that our program uses many kinds of shapes, such as Circle, Box etc. So here, we design a super class called Shape. In example, all shapes have a method called Draw(), which is derived from super class Shape. 

## Types of Polymorphism : 

#### 1. Compile Time Polymorphism – Method Overloading 

In Java creating more than one method with same name but with different signature, eg. change in argument list or change in type of argument or change in parameters, when this is the case, the methods are said to be overloaded and the process is referred to as method overloading. 

> In method overloading, which method is called, is checked at compile time. Therefore it is known as __compile time polymorphism or static binding.__ 


#### 2. Run Time Polymorophism – Method Overriding

In a class hierarchy, when a method in a sub class has the same name and the same signature as a method in its super class, then the method in the sub class  is said to override the method in the super class. 

> In method overriding, which method will be called , is checked at runtime. So it is called __runtime polymorphism or dynamic binding.__ 
