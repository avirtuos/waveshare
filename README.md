# Waveshare 7.5 Inch E-Ink

This repository is a collection of documentation, tutorials, and examples for the <a href='https://www.amazon.com/gp/product/B075YP81JR'>Waveshare 7.5inch 3-collor E-Ink Display</a>

![alt tag](https://github.com/avirtuos/waveshare/blob/master/docs/img/waveshare-e-ink.jpg?raw=true)

## Software Setup

The most frustrating part of this well made piece of hardware was finding instructions for how to set it up. The info on the manufacturer site has many typos, broken links, or worse... copies of files for the black/white screen which don't work for the 3-color screen.

### Install WiringPI Library

You can find detailed instructions at the <a href='https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/'>maintainer's site</a> or directly below:

```bash
sudo apt-get install git-core
sudo apt-get update
sudo apt-get upgrade
git clone git://git.drogon.net/wiringPi
cd wiringPi
git pull origin
./build.sh
```

### Install BCM2835 Library

You can find detailed instructions at the <a href='http://www.airspayce.com/mikem/bcm2835/'>maintainer's site</a> or directly below:

```bash
install bcm library - 
wget https://www.waveshare.com/w/upload/d/d8/Bcm2835-1.45.tar.gz
tar xzvf Bcm2835-1.45.tar.gz
./configure
make
sudo make check
sudo make install
```

### Install RPi.GPIO

```bash
sudo apt-get install python-rpi.gpio python3-rpi.gpio
```
### Install SMbus

```bash
sudo apt-get install python-smbus python3-smbus python-dev python3-dev
```

### Install Python-Serial

```bash
sudo apt-get install python-serial python3-serial
```

### Install SPI-Dev

```bash
wget https://pypi.python.org/packages/36/83/73748b6e1819b57d8e1df8090200195cdae33aaa22a49a91ded16785eedd/spidev-3.2.tar.gz
tar xzvf spidev-3.2.tar.gz
cd spidev-3.2
sudo python setup.py install
```

### Install Misc Items

```bash
sudo apt-get install python-imaging
sudo apt-get install fonts-freefont-ttf
```

## Hardware Wiring
| Waveshare        | RPi        |
| ------------- |:-------------:|
| 3.3v     | 3.3v |
|GND|	GND|
|DIN	|MOSI|
|CLK	|SCLK|
|CS	|CE0/CS0|
|DC	25 |(GPIO)|
|RST	|17 (GPIO)|
|BUSY	|24 (GPIO)|