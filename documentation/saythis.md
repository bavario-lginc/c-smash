# saythis
saythis - Output a string
## Description
```
saythis(string stringToOutput): void
```
Outputs a string to the open command prompt, with an additional newline.
Currently, formatting the string is not possible, but it will be added in version 0.2.
Its argument is a *single* string, to output multiple strings, multiple `saythis` statements are required.
`saythis` can also be written without parentheses, making it look like `saythis "Hello World"`.
## Parameters
### stringToOutput
The string to output. Integers will also be converted to strings when specified.

**Note**: This function cannot be used to output values of variables. To output variables, use `sayvar()` instead.
## Return Values
Nothing.
## Examples
```
saythis "We don't need those parentheses.";

// When using saythis(), a newline is added; the example below outputs "hello" and "world" on seperate lines.
saythis("Hello");
saythis("World");

// Integers are converted to strings when passed onto the function. The example below outputs "3".
saythis(3);

// To output variables, use the sayvar() function as shown below:
test = "Foo Bar";
sayvar(test); // Outputs "Foo Bar"
```
