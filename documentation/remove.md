# remove
remove - Remove every occurence of the substring in a string
## Description
```
remove(string haystack, string needle): string result
```
This command will remove every occurence of needle in the haystack and return the result.
## Parameters
### haystack
A string in which the substring will be found and removed.
In future versions, you will also be able to use a variable name instead.
### needle
A string that will be searched for in the haystack. If it is found, it will be removed from the string.
## Return Values
### string result
This will return the string that was created by removing the substrings from the original string passed onto the function.
## Examples
```
withGarbage = "Hellogarbage Worgarbageld";
withoutGarbage = remove("Hellogarbage Worgarbageld", "garbage"); // This removes the word 'garbage' from this string.
sayvar(withGarbage); // Outputs 'Hellogarbage Worgarbageld'
sayvar(withoutGarbage); // Outputs 'Hello World'
```
