# saythis
saythis - Output a string
## Description
```
saythis(string stringToOutput): void
```
Outputs a string to the open command prompt, with an additional newline.
Its argument is a *single* string, to output multiple strings, multiple `saythis` statements are required.
`saythis` can also be written without parentheses, making it look like `saythis "Hello World"`.

Since Version 0.2, you can escape the string using \. The following formats are available:
- `\a`: Play a short alert sound.
- `\b`: Backspace
- `\e`: Escape characters that would otherwise just be printed out.
- `\f`: Indicate to a printer that it should print the content after on a new page.
- `\n`: Write a new line.
- `\r`: Carriage Return
- `\t`: Write a tab, just like when the Tab key is pressed.
- `\v`: Write a vertical tab.
## Parameters
### stringToOutput
The string to output. Integers will also be converted to strings when specified.

**Note**: This function cannot be used to output values of variables. To output variables, use `sayvar()` instead.
## Return Values
Nothing.
## Examples
```
saythis "We don't need those parentheses.";

// You can use escaping since Version 0.2!
saythis("Hello\nWorld"); // This will put Hello and World onto two different lines
saythis("\aDid you hear that?"); // This will play an alert sound.
saythis("\e[34mThis text is now blue!"); // [34m stands for the color blue.

// Integers are converted to strings when passed onto the function. The example below outputs "3".
saythis(3);

// To output variables, use the sayvar() function as shown below:
test = "Foo Bar";
sayvar(test); // Outputs "Foo Bar"
```
