# input
input - Wait for the user to input a string, then continue the program.
## Description
```
input([string MessageToOutput]): string result
```
This command will stop the program and wait for the user to input a string.
Code execution will resume after the user presses Enter. The string the user wrote will then be returned and can be passed on to a variable.
You can also write a message to output before the user input, in parentheses. This is not required, however.
## Parameters
### Optional: MessageToOutput
The string to output before the user is prompted to input something. The string is followed up by an automatic newline.
## Return Values
### string result
This command will always return a string of what the user entered before pressing Enter. If they pressed Enter right away, an empty string is returned.
## Examples
```
// This forces the user to input something.
input("How old are you?");

// However, the result of this will go nowhere, so if you want to use the value, add a variable, like so:
age = input("How old are you?");

// Now we can use the info of what the user typed:
age = input("How old are you?");
saythis("You typed:");
sayvar(age);
```
