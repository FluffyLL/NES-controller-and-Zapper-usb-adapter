# NES gamepad controller and Zapper Light gun usb adapter
Digispark ATtiny85 based NES gamepad controller and Zapper Light gun to usb adapter

When powered on the code checks if a controller or a light gun is connected, if you switch which is connected you need to power off and on again the board, when using a controller you can press select+a or select+b to use 2 extra inputs
the ligh gun works best when setting your screen brightness high, or/and low ambient light

#To use the light gun in emulators
neslcdmod ips patch is required, ligh gun games usually require to configure player2 port
In FCEUmm(RetroArch):
in retroarch configure trigger and aux.A buttons, load FCEUmm and set Zapper mode: Sequential Targets Light gun
In FCEUX:
https://github.com/r57zone/Zapper-Light-Gun-PC#configuring-fceux

#Assembly and programming
I used an attiny85 board, whith this firmware https://github.com/ArminJo/micronucleus-firmware
i had to dissable the reset pin to get enough I/O pins so i set the attiny fuses with an ISP programmer to
Low fuse: 0xe1
High fuse: 0x5d
Extended fuse: 0xfe
Any failure in this step will require a high voltage programmer to fix it (transistor as a switch connected to 12v)

After this you can upload the code normally, these are the connections to the board:
pin0 = controller data/light gun trigger
pin1 = controller latch
pin2 = controller clock
pin3 = USB+
pin4 = USB-
pin5 = Light signal
and you are ready, enjoy your adapter

#Extras
Check this schematic if you want to build the light gun yourself:
URL
Check this SteamInput config to quickly setup the adapter:
URL

#Links
Original idea that ended up becoming this project: https://github.com/r57zone/Zapper-Light-Gun-PC
related, uses an arduino board and has snes support: https://github.com/mooware/arduino-nes-snes-usb

LCDMOD page: https://neslcdmod.com/
Interesting video about r57zone version: https://www.youtube.com/watch?v=zikiFYUYBj0

Controller and light gun inner workings data:
https://tresi.github.io/nes/
https://www.nesdev.org/wiki/Zapper
https://www.nesdev.org/wiki/Standard_controller
