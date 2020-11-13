# Touchless Garbage Can


parts list:

* OLED display (in kit)

* raspberry pi (in kit)

* arduino (in kit)

* [wii fit board (still shipping)](https://www.ebay.com/itm/Wii-Balance-Board-Tested-Working-Good-Condition-Free-Shipping-Wii-Fit-Wii-U-Game/333698817157?hash=item4db1ffdc85%3Ag%3AfbIAAOSwkl5fQ-0x&LH_GD=3&LH_BIN=1)

* [pir motion sensor (delivered)](https://www.digikey.com/en/products/detail/SEN-13285/1568-1207-ND/5673793?itemSeq=343984210)

* [*tentative trash can (will need to determine dimensions of wii fit board)](https://www.amazon.com/PENGKE-Plastic-Garbage-Bathroom-Kitchen/dp/B07RBMC1GQ)


# Plan

* once IR sensor comes in, get arduino to respond to IR sensor (code in PIR/)

* create arm / opening mechanism to attach to a box (or garbage can lid if I can get one soon enough)

* get arduino to open a lid using IR sensor

* once wii fit board comes in, try to find a garbage can with a lid that can fit the balance board

* try to connect wii balance board to raspberry pi and display weight on OLED screen

* connect pi and arduino to open lid as well as display weight info

* set IoT capabilities to control lid, might find a thermometer or use an API to find weather info to maybe control spray

* [Tentative Design](https://photos.app.goo.gl/AR2av9fdCzt5MHhLA)
