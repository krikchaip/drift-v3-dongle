# ⚙️ Windows to Mac OS - Key Table  
Here is a quick guide on what keys on a Windows keyboard equate to on a Mac OS keyboard  

| Windows Keyboard   | Mac OS Keyboard |
|:------------------:|:---------------:|
| Windows Key / GUI  | Command / ⌘    |
| Alternate / Alt    | Option / ⌥     |
| Control / Ctrl     | Ctrl / ⌃       |  

Use this table so you know what keys to set in [ZMK Studio](https://zmk.studio/)  

The ZMK Keycodes for the Modifiers can be found [HERE](https://zmk.dev/docs/keymaps/list-of-keycodes#modifiers)  

---

### The Tilde(~) Key Problem  
> [!CAUTION]
> If this is your first time setting up the keyboard, skip to the Important section below!  
> 
> Sometimes the Tilde(~) key does not work no matter what you try.  
> 
> Open up the Terminal App  
> 
> Copy the code below and paste it in your terminal then press enter, you will likely be prompted to enter your password to execute it.  
> 
> Your Drift Keyboard will probably be disabled now, Restart your Mac/Macbook.  
```
sudo rm /Library/Preferences/com.apple.keyboardtype.plist
```
---

> [!IMPORTANT]
> When you are prompted to setup your keyboard, press "z" for the key next to the LEFT Shift.  
> 
> Then press "/" (forward slash) when prompted to press the key next to the RIGHT Shift.  
> 
> Finally, choose "ANSI (U.S.)"  
> 
> Now your keyboard can type the Tilde(~) key by pressing [SHIFT + ~]  
> 
> If you are still unsure, you can have a look at the [pdf file](https://github.com/Timception/drift-v3-dongle/blob/main/precompiled-firmware/Mac-OS-keys/Setup-Drift-on-Macbook.pdf) listed above.

---  






