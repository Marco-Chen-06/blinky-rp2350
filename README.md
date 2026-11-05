# blinky-rp2350
personal reference for blinking an led with half bare metal pico sdk

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
#### Flash: `gdb -ex flash`
#### Debug: `gdb -ex debug`
