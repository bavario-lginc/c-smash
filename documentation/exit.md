# exit
exit - Exit out of the program.
## Description
```
exit(): void
```
This command exits out of the program. If you wrote code after this statement, it will not be executed.
`exit` can also be written without parentheses, making it look like `exit;`.
If you opened the interpreter using a command prompt, it will remain open, and only the interpreter will be closed. If you opened the executable itself, it will close the entire window.
## Parameters
None
## Return Values
Nothing
## Examples
```
saythis("Closing the program...");
exit();

// The exit statement can also be written without parentheses:
saythis "Closing the program...";
exit;

// Commands written after exit() aren't executed.
saythis("This will be executed!");
exit();
saythis("This won't be executed!");
```
