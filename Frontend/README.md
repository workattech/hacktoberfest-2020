# JS - Cheatsheet

## Table of Contents

  1. [Types](#types)
  1. [References](#references)
  1. [Objects](#objects)
  1. [Arrays](#arrays)

## Types

  <a name="types--primitives"></a><a name="1.1"></a>
  - [1.1](#types--primitives) **Primitives**: 

    - `string`
    - `number`
    - `boolean`
    - `null`
    - `undefined`
    - `symbol`
    - `bigint`

    ```javascript
    let str = 'This is the string';
    console.log(typeof(str)); //"string"
    let num = 12; 
    console.log(typeof(num)); //"number"
    let bool_val = true; 
    console.log(typeof(bool_val));//"boolean"
    let a;
    console.log(typeof(a)); //"undefined"
    let sym1 = Symbol();
    console.log(typeof(sym1)); //"symbol"
    let b = null;
    console.log(typeof(b)); //"object"
    ```


  <a name="types--non_premetive"></a><a name="1.2"></a>
  - [1.2](#types--non_premetive)  **Non premetive**: When you access a non-premetive type you work on a reference to its value. Some of them are:

    - `object`
    - `array`
    - `function`

    ```javascript
    const arr1 = [1, 2];
    const arr2 = arr1;

    arr1[0] = 9;

    console.log(arr1[0], arr2[0]); // => 9, 9
    ```



## References

  <a name="references--prefer-const"></a><a name="2.1"></a>
  - [2.1](#references--prefer-const) `const` must be always use for the references; avoid using `var`. eslint: [`prefer-const`](https://eslint.org/docs/rules/prefer-const.html), [`no-const-assign`](https://eslint.org/docs/rules/no-const-assign.html)

    > The question may arise why we should not use var insted of const? Using ```const``` ensures that one can't reassign the references, which may lead to bugs in code.

    ```javascript
    // bad
    var days = ['Mon','Tue','Wed','Thus','Fri','Sat','Sun'];

    // good
    const days = ['Mon','Tue','Wed','Thus','Fri','Sat','Sun'];
    
    ```

  <a name="references--disallow-var"></a><a name="2.2"></a>
  - [2.2](#references--disallow-var) If you have to reassign references, use `let` instead of `var`. eslint: [`no-var`](https://eslint.org/docs/rules/no-var.html)

    > Why should we use `let ` insted of `var`? One of the major reason for using `let` is that it is block-scoped rather than function-scoped like `var`.

    ```javascript
    // bad
    var count = 1;
    if (true) {
      count += 1;
    }

    // good, use the let.
    let count = 1;
    if (true) {
      count += 1;
    }
    ```

  <a name="references--block-scope"></a><a name="2.3"></a>
  - [2.3](#references--block-scope) Note that both `let` and `const` are block-scoped.

    ```javascript
    // const and let only exist in the blocks they are defined in.
    {
      var elem = 2;
      let a = 1;
      const b = 1;
    }
    console.log(elem); // 2
    console.log(a); // ReferenceError
    console.log(b); // ReferenceError
    ```


## Objects

  <a name="objects--no-new"></a><a name="3.1"></a>
  - [3.1](#objects--no-new) Creation of object using `new` keyword is not a good practice

    ```javascript
    // bad
    const obj = new Object();

    // good
    const obj = {};
    ```

  
  <a name="es6-object-shorthand"></a><a name="3.4"></a>
  - [3.2](#es6-object-shorthand) Use object method shorthand. eslint: [`object-shorthand`](https://eslint.org/docs/rules/object-shorthand.html)

    ```javascript
    // bad
    const unit = {
    value: 1,
    addValue: function (value) {
        return unit.value + value;
    },
    };

    // good
    const unit = {
    value: 1,

    addValue(value) {
     return unit.value + value;
     },
    };
    ```

  <a name="es6-object-concise"></a><a name="3.6"></a>
  - [3.3](#es6-object-concise) Use property value shorthand. eslint: [`object-shorthand`](https://eslint.org/docs/rules/object-shorthand.html)

    > Why should we use shorthand? It is shorter and descriptive plus it saves extra effort to write code.

    ```javascript
    // bad
    let id =12;
    let value = 100;
    const atom = {
      id,
      text='This is the sample',
      value,
    };

    // good
    const id =12;
    const value = 100;
    const atom = {
      id,
      value,
      text='This is the sample',
    };
    ```

  <a name="objects--grouped-shorthand"></a><a name="3.7"></a>
  - [3.4](#objects--grouped-shorthand) Group your shorthand properties at the beginning of your object declaration.

    > What is the need to group shorthand properties at the beginning of your object declaration? It’s easier to tell which properties are using the shorthand.

    ```javascript
    
    const id =12;
    const value = 100;

    // bad
     const id =12;
    const value = 100;
    const atom = {
      id,value
    };

    // good
    const atom = {
      id,value
    };
    ```


## Arrays

  <a name="arrays--literals"></a><a name="4.1"></a>
  - [4.1](#arrays--literals) Array Creation

    ```javascript
    // bad
    const arr = new Array();

    // good
    const arr = [];
    ```

  <a name="arrays--push"></a><a name="4.2"></a>
  - [4.2](#arrays--push) Use [Array#push](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/Array/push) instead of direct assignment to add items to an array.

    ```javascript
    const someStack = [];

    // bad
    someStack[someStack.length] = 'abracadabra';

    // good
    someStack.push('abracadabra');
    ```

  <a name="es6-array-spreads"></a><a name="4.3"></a>
  - [4.3](#es6-array-spreads) Use array spreads `...` to copy arrays.

    ```javascript
    // wrong
    itemsCopy = items;
    // it is wrong as we are having the referance of Array only. The elements are not coppied
    // bad
    const len = items.length;
    const itemsCopy = [];
    let i;

    for (i = 0; i < len; i += 1) {
      itemsCopy[i] = items[i];
    }

    // good
    const itemsCopy = [...items];
    ```

  

