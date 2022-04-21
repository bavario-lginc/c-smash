# append
append - Append strings to each other
## Description
```
append([string substring, ...]): string result
```
This command will create a new empty string and add the substring(s) at the end of it.
You can pass one or more substrings to this function.
The end result of it will be returned, so they can be written to a variable.
If no substrings are passed onto the function, an empty string is returned.
## Parameters
### Optional: substring
The string to append to the empty string created by default. 
In future versions, you can also use a variable name instead.
### Optional: ...
You can add as many other substrings as you want. They must be comma-seperated.
## Return Values
### string result
This will return the string that was created by appending all substrings passed onto the function. If no substrings are passed, an empty string will be returned.
## Examples
```
// This will output "Hello World".
myString = append("Hello", " World");
sayvar(myString);

// You can add as many strings as you want:
longString = append("C-Smash", " is", " a", " great", " language!");
sayvar(longString);

// In later versions, you will also be able to use variable names instead of normal strings:
before = "Hello";
saythis("Hmm, I'd like to add some text to that. One sec...");
after = append(before, " World);
```
