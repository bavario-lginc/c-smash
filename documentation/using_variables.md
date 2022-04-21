# Using Variables in C-Smash
## Declaring a variable
```
name = string value
name = int value
name = bool value
name = array value
```
This creates a new variable named after `name` and assigns either an integer, a string or an array to it. You can also assign the keywords `True` and `False` to it, which will be converted to `0` and `1` respectively.
The variable can then be called by another command later.
## Performing Arithmetic
```
name = int a + int b // Addition
name = int a - int b // Subtraction
name = int a * int b // Multiplication
name = int a / int b // Division
name = int a ^ int b // a to the power of b
name = int a % int b // Remainders of Division
```
These commands allow you to perform certain arithmetic tasks using two integers.
In future versions, these will also be usable on strings.
## Outputting variables
`sayvar(var variable)` outputs the string or integer from a variable.
When used with an array, it will output all of the array's content. You can also choose one entry out of the array by writing `sayvar(array[index])`, see the Examples down below for more information.

This will later be united with `saythis()`.
## Examples
```
// This outputs:
//    I have a message for you:
//    Hello World!
test = "Hello World!";
saythis("I have a message for you:");
sayvar(test);

// You can also assign integers to a variable
anotherTest = 2;
saythis("The minimum age requirement is:")
sayvar(anotherTest);

// Assigning a bool will replace it with 0 or 1:
trueBool = True;
falseBool = False;
sayvar(trueBool); // Outputs 1
sayvar(falseBool); // Outputs 0

// You can even calculate integer values like this:
csmashTest = 4 ^ 2;
saythis("4 to the 2nd power is:");
sayvar(csmashTest);

// Since version 0.2, using arrays is possible:
testArray = <"Hello", "World", "and", "foo", "bar">;
sayvar(testArray); // Outputs: Array: ["Hello","World","and","foo","bar"]
sayvar(testArray[1]); // Outputs: World

// You can also write integers to arrays, like so:
intArray = <13, 3, 58, 25, 98>;
sayvar(testArray); // Outputs: Array: [13,3,58,25,98]
sayvar(testArray[1]); // Outputs: 3
```
