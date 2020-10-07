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

#### Example : 
```java
//A Simple Java program to demonstrate method overloading in java
class Addition  
{ 
  int add(int i, int j) //first add() function takes int values
  {
  	return i+j;
  }
  float add(float f1, float f2) //second add() function takes float values
  { 
 	 return f1+f2;
  }
  double add(double d1, double d2) //third add() function takes double values
  { 
  	return d1+d2;
  }
} 
class AddOperation
{
 public static void main(String args[]) 
 {
	Addition Obj=new Addition();
	System.out.println(Obj.add(1,2));			//method with same name
	System.out.println(Obj.add(2.5f,4.6f));			//but with change in
	System.out.println(Obj.add(1.5,2));			//type of argument
 }
}
```
#### Output : 

```
3
7.1
3.5
```


#### 2. Run Time Polymorphism – Method Overriding

In a class hierarchy, when a method in a sub class has the same name and the same signature as a method in its super class, then the method in the sub class  is said to override the method in the super class. 

> In method overriding, which method will be called , is checked at runtime. So it is called __runtime polymorphism or dynamic binding.__ 

#### Example : 
```java
// A Simple Java program to demonstrate method overriding in java

class Parent	// The Base Class
{
    void show() 
	{
	System.out.println("Parent's show() method"); 
	}
}

class Child extends Parent 	// The Inherited class
{
    void show() 	//method in inherited class overriding the method in base class
	{ 
	System.out.println("Child's show() method");
	}
}
 
// Driver class
class Main
{
    public static void main(String[] args)
    {
        
	Parent obj1 = new Parent();		        // A Parent type reference refers to a Parent object, 
        obj1.show();					// therefore Parent's show() method is called.
 
        Parent obj2 = new Child();			// A Parent type reference refers to a Child object, 
        obj2.show();					// therefore Child's show() method is called.
    }
}
```

#### Output : 

```
Parent's show() method
Child's show() method
```
