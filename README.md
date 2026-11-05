# blinky-rp2350
personal reference for blinking an led with half bare metal pico sdk

### Building
```mkdir build
cd build
make
make flash```

### Debugging
`sudo openocd`

#### Flash:
`gdb -ex flash`

#### Debug:
`gdb -ex Debug`
