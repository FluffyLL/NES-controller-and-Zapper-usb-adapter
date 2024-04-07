# NES gamepad controller and Zapper Light Gun usb adapter
Digispark ATtiny85 based NES gamepad controller and Zapper Light gun to usb adapter

When powered on the code checks if a controller or a light gun is connected, if you switch which is connected you need to power off and on again the board, when using a controller you can press select+a or select+b to use 2 extra inputs, the ligh gun works best when setting your screen brightness high, or/and low ambient light<br>

# To use the light gun in emulators
LCDMOD ips patch is required, light gun games usually require to configure player2 port<br>
* In FCEUmm(RetroArch):<br>
  - in retroarch configure trigger and aux.A buttons, load FCEUmm and set Zapper mode: Sequential Targets light gun<br>
* In FCEUX:<br>
  - https://github.com/r57zone/Zapper-Light-Gun-PC#configuring-fceux<br>

# Assembly and programming
I used an attiny85 board, whith this firmware https://github.com/ArminJo/micronucleus-firmware<br>
i had to dissable the reset pin to get enough I/O pins so i set the attiny fuses with an ISP programmer to<br>
```
Low fuse: 0xe1
High fuse: 0x5d
Extended fuse: 0xfe
```
Any failure in setting the fuses will require a high voltage programmer to fix it (transistor as a switch connected to 12v)<br>
After this you can upload the code normally through the usb port, these are the connections to the board:<br>
```
pin0 = controller data/light gun trigger
pin1 = controller latch
pin2 = controller clock
pin3 = USB+
pin4 = USB-
pin5 = Light signal
```
and you are ready, enjoy your adapter<br>

# Extras
Check this schematic if you want to build the light gun yourself:<br>
<a href=MyLighGunSchematic.png>MyLighGunSchematic.png</a><br>
Check this SteamInput config to quickly set up the adapter on steam:<br>
<a href=SteamInputConfig.txt>SteamInputConfig.txt</a><br>

# Links
Original idea that ended up becoming this project: https://github.com/r57zone/Zapper-Light-Gun-PC<br>
related, uses an arduino board and has snes support: https://github.com/mooware/arduino-nes-snes-usb<br>
<br>
LCDMOD page: https://neslcdmod.com/<br>
Interesting video about r57zone version: https://www.youtube.com/watch?v=zikiFYUYBj0<br>
<br>
Controller and light gun inner workings data:<br>
https://tresi.github.io/nes/<br>
https://www.nesdev.org/wiki/Zapper<br>
https://www.nesdev.org/wiki/Standard_controller<br>
