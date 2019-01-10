Dvorak OSX US with Umlauts
==========================

This is my version of a dvorak layout fulfilling my special requirements. I
doubt that someone will use this layout like I do, but it still might be an 
interesting example layout. 

My special requirements
-----------------------
First of all I am from Germany, so occasionally (for example when I write mail
in german), I need those pesky german umlauts (here they are: äöüß). But most of
the time I am programming and don't really need them. In fact I am bound to the 
US layout during that time, because we are doing xtreme programming and I
usually pair with non-germans. (When you pair, you have two programmers, two
keyboards, two mice, and everything connected to _one_ computer. One guy is
typing, the other one is watching and after a while you switch roles.)

So my requirements for the keymap of the ergodox are:
* dvorak layout
* US layout setting on the computer
* still able to access the german umlauts in an easy way (with US layout active)
* must work on osx (we only use macs)
* must allow easy access to special characters needed for programming
* must allow cursor movement (mouse movement is a plus)
* should indicate the layer I am on visually

My keymap
---------
The keymap contains 6 layers:
0) The base layer contains the dvorak layout. I switched the keycaps of my
keyboard according to this layout and every key that is printed on the keycap is
matching with this layout. I am also using the cool feature that the keyboard is
able to distinguish between holding and tapping a key. So this keymap allows me
to access all usual shortcuts without even leaving the main row.
1) The layer with all the special characters for easy access. It also contains
the uppercase version of the german umlauts. And it contains the usual function
keys F1-F10.
2) This layer contains the mouse movements. I move and click with the right
hand, with the left hand I have the modifiers and accelerators. It also contains
function keys F11-F24.
3) This layer contains cursor movements. Same here, left is modifiers and right
hand is movement.
4) Multimedia keys and shortcuts.
5) Color settings for the backlight color.

Backlight color
---------------
I changed the backlight color behaviour a bit. I wanted to let the backlight
switch the color, when I am in a special layer (excluding the base layer and the
color layer). So whenever you press and hold one of the layer switching keys,
the backlight switches to a solid color. When you release the key, the keyboard
continues to show, what color was set for the base layer (which you can control
from the color layer).

