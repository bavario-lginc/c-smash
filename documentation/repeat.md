# repeat
repeat - Repeat the string x amount of times.
## Description
```
repeat(string original, int amount): string result
```
This command will repeat the original string as often as is specified through the amount.
The output of this function can then be passed onto a variable.
## Parameters
### original
A string which will be repeated a certain amount of times.
In future versions, you will also be able to use a variable name instead.
### amount
An integer that stands for the amount of times that the string will be repeated.
If this parameter is 0, an empty string is returned. Likewise, if this parameter is 1, the original string will be returned without any changes.
## Return Values
### string result
This will return the string that was created by repeating the original string passed onto the function.
## Examples
```
once = "Hello World";
twice = repeat("Hello World ", 2); // This repeats the word 'Hello World ' twice.
thrice = repeat("Hello World ", 3); // This repeats the word 'Hello World ' three times.
sayvar(once); // Outputs 'Hello World'
sayvar(twice); // Outputs 'Hello World Hello World'
sayvar(thrice); // Outputs 'Hello World Hello World Hello World'
```
