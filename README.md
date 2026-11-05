# blinky-rp2350
blink an LED using 2-pico openocd setup

## Building
```
mkdir build
cd build
cmake ..
make
```
## How to Use
### In one terminal:
`sudo openocd`

### In second terminal:
#### Flash: 
`gdb -ex flash`

#### Debug: 
`gdb -ex debug`

