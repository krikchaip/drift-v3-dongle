# Drift Keyboard V3 by Timception (Dongle Version)  

![Drift Keyboard V3 by Timception](https://github.com/Timception/drift-v3-dongle/blob/main/keymap-drawer/DriftJTK-HyperfusenoBG.png)

Firmware for the **Drift Keyboard V3 by Timception** with **ZMK Studio** enabled.  
You can customize your layout directly in [ZMK Studio](https://studio.zmk.dev)  

**Mac users can setup this keyboard** [following this guide](https://github.com/Timception/drift-v3-dongle/tree/main/precompiled-firmware/Mac-OS-keys/)  

---

## ✨ Features
- ✅ Precompiled firmware builds ready to flash  
- ✅ ZMK Studio support (view & change keymaps live) 
- ✅ Simple reset/reflash procedure  

---

## 🔋 Battery Installation  
How to [install batteries](/battery/) and Charging.  

---

## 🔄 Reflashing Instructions

Your keyboard already has firmware installed, you usually don’t need to reflash.  
But if you want to update to the latest build, here’s how to do it:

1. **Download the latest firmware**  
   - Go to the **[precompiled-firmware](https://github.com/Timception/drift-v3-dongle/tree/main/precompiled-firmware)** in this repo.  
   - Download the **firmware .zip file**.  

2. **Unzip the file**  
   - Inside you’ll find multiple `.uf2` files:       
     - `drift_central_dongle.uf2` → Dongle firmware  
     - `drift_left.uf2` → Left half firmware  
     - `drift_right.uf2` → Right half firmware  
	 - `settings_reset-nice_nano_v2-zmk.uf2` → Settings Reset firmware (needed to clean devices before new firmware)  

3. **Reset the dongle**  
   - Plug in your dongle.  
   - Double-click the **reset button** on the dongle.  
   - A new drive should appear on your computer.

4. **Flash the reset firmware**  
   - Drag `settings_reset-nice_nano_v2-zmk.uf2` into the new bootloader drive.  
   - Wait until the dongle reboots.  

5. **Repeat reset step for each keyboard half**  
   - Double-click the reset button on the **left half** → drag `settings_reset-nice_nano_v2-zmk.uf2` into the bootloader drive.  
   - Do the same for the **right half**.  

6. **Flash the NEW dongle firmware**  
   - Plug in the dongle again.  
   - Double-click reset → drag `drift_central_dongle.uf2` into the drive.  
   - Wait for it to finish.  

7. **Flash the left half with new firmware**  
   - Plug in the **left half**.  
   - Double-click reset near the power switch.  
   - Drag `drift_left.uf2` into the bootloader drive.  

8. **Flash the right half with new firmware**  
   - Repeat the same process with the **right half**, using `drift_right.uf2`.  

9. **Reconnect everything**  
   - Unplug the halves.  
   - Plug the dongle back in.  
   - Press the reset button once on each half so they reconnect to the dongle.  

10. ✅ You’re done!  
	- Download [ZMK Studio](https://zmk.studio/download), or
    - Open the [ZMK Studio](https://studio.zmk.dev) app online to see your Drift keyboard.  
    - Now you can view and customize your keys to your hearts content.  
	
11. **Useful Links for further tinkering:**  
	- More information on all the different [keys and keycodes](https://zmk.dev/docs/keymaps/list-of-keycodes)  
	- The original [Drift Keyboard V3](https://github.com/Timception/zmk-config-drift-v3-editor) that uses the more detailed keymapper by [Nick Coutsos](https://nickcoutsos.github.io/keymap-editor/).  

---

## 📸 Keymaps
The default layout is shown here:  

Each layer starting with the default/base:  
![Keymap](https://github.com/Timception/drift-v3-dongle/blob/main/keymap-drawer/drift.svg)  


---

## Acknowledgments & Licensing  

This project makes use of code and ideas from the following repositories:  
- [ZMK Firmware](https://github.com/zmkfirmware) (MIT License) - Zephyr™ Mechanical Keyboard (ZMK) Firmware  
- [leafflat/sai44](https://github.com/leafflat/sai44) (MIT License) – Dongle code reference  
- [caksoylar](https://github.com/caksoylar/keymap-drawer) (MIT License) - Keymap Drawer  
- [badjeff/zmk-behavior-key-press-lip](https://github.com/badjeff/zmk-behavior-key-press-lip) - LIP Key Press Behavior  

All third-party code remains under their original licenses.  

---

- The PCB is not open source, but you could [contact me](https://www.instagram.com/majin.keyboards) if you would like a pair, that would really help me out :)  





