# random
stuff hacked together for barebones functionality.

27th Jun sketch:
Blower style GPU wouldn't spin fan. 12V and Gnd pins removed from JST and hardwired to PSU; PWM wired to TeensyLC; Tacho is left on the gpu for monitoring purposes. TeensyLC powered via internal USB for further programming. 

TODO: Read GPU temps and communicate to teensy somehow; control fan PWM based on those numbers.
