# stringpow
stringpow - Repeat every letter in a string x amount of times.
## Description
```
stringpow(string original, int amount): string result
```
This command will repeat every letter in a string as often as is specified through the amount. 
The output of this function can then be passed onto a variable.
## Parameters
### original
A string of which every letter will be repeated a certain amount of times.
In future versions, you will also be able to use a variable name instead.
### amount
An integer that stands for the amount of times that every letter of a string will be repeated.
If this parameter is 0, an empty string is returned. Likewise, if this parameter is 1, the original string will be returned without any changes.
## Return Values
### string result
This will return the string that was created by repeating every letter in the original string passed onto the function.
## Examples
```
once = "Hello World";
twice = stringpow("Hello World ", 2); // This repeats every letter of the word 'Hello World ' twice.
thrice = stringpow("Hello World ", 3); // This repeats every letter of the word 'Hello World ' three times.
sayvar(once); // Outputs 'Hello World'
sayvar(twice); // Outputs 'HHeelllloo  WWoorrlldd'
sayvar(thrice); // Outputs 'HHHeeellllllooo   WWWooorrrlllddd'
```
