# count
count - Count the occurences of a substring in a string
## Description
```
count(string haystack, string needle): int result
```
This command will count every occurence of needle in the haystack and return the result.
## Parameters
### haystack
A string in which the substring will be found and counted.
In future versions, you will also be able to use a variable name instead.
### needle
A string that will be searched for in the haystack. Whenever it is found, a 1 is added to the result counter.
## Return Values
### int result
This will return the amount of times that the substring was found in the original string passed onto the function.
## Examples
```
// This script will search for how often the letter 'l' is written in the string 'Hello World':
amount = count("Hello World", "l");
saythis "'Hello World' contains...";
sayvar(amount); // Returns 3
saythis "occurences of the letter 'l'!";

// count() is case-sensitive, so doing the same thing with 'L' returns 0:
newAmount = count("Hello World", "L");
saythis "'Hello World' contains...";
sayvar(newAmount); // Returns 0
saythis "occurences of the letter 'L'!";
```
