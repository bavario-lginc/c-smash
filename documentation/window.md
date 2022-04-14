# window
window - Open a message box.
## Description
```
window(const TYPE, string title, string description): void
```
Opens a new message box with a different type. This can either be an info, question, warning or error dialog.
You also have to provide a title and description.

Currently, there is no way to adjust the buttons order, it will always be "Yes", "No", "Cancel". This will be adjustable in version 0.2.
On top of that, version 0.2 will output an integer that equates to the button the user pressed.
## Parameters
### TYPE
A constant that can either be `INFO`, `QUESTION`, `WARNING` or `ERROR`. This determines the icon shown on the dialog.
**Note:** Question is a legacy feature, and should not be used anymore.
### title
A non-optional string that will be written at the top of the message box.
### description
A non-optional string that will be written below the title in the message box.
## Return Values
Currently nothing, will return an int in the future.
## Examples
```
window(INFO, "Welcome to this C-Smash program!", "This is a great message.")

// Displaying a question dialog works, but it is not recommended.
window(QUESTION, "Notepad: C-Smash edition", "Are you sure you want to quit without saving?")

// Changing the type of message box will also change the sound that will play!
window(WARNING, "Delete File?", "Are you sure you want to delete this file? This can't be reverted.")

// In the future, you'll be able to obtain the button that the user clicked, like so:
buttonPressed = window(ERROR, "An Error occured", "An unknown error occured. Would you like to restart the program?")
// As of right now, this is not possible however.
```
## Attachments
![grafik](https://user-images.githubusercontent.com/35093969/163441508-fbdea8f9-a324-4f72-83ba-86bbb24e0ec2.png)
![grafik](https://user-images.githubusercontent.com/35093969/163441529-665c52f5-b721-4f85-ae16-065ecfb0da7f.png)
![grafik](https://user-images.githubusercontent.com/35093969/163441557-5e7b787e-3395-4ef8-b021-9f7b8aed0886.png)
![grafik](https://user-images.githubusercontent.com/35093969/163441663-39604fc7-0818-4ae1-ab1d-9d5424d75d75.png)
