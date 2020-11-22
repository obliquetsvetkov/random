# random
stuff hacked together for barebones functionality.

Fan controller:
Blower style GPU wouldn't spin fan. 12V and Gnd pins removed from JST and hardwired to PSU; PWM wired to TeensyLC; Tacho is left on the gpu for monitoring purposes. TeensyLC powered via internal USB for further programming. 

Python script collects GPU sensor data and sends it over serial at a preset interval. Requires OpenHardwareMonitor 0.9.5; script is in the same folder. 
Arduino sketch sets fan curve as soon as temp is available on serial port.
batch file runs script headless; sits in Startup folder. 
