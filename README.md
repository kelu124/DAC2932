# DAC2932


DAC2932 devboard

## Objective

```
TLDR: Getting a fast DAC board controlled without any FPGA, purely fast, simple, open source hardware (rp2040).

Outputs:
* 2x 40Msps, 12bits signal (I-DACs)
* 4x 1Msps, 12bits (V-DAC) (not really 4x1Msps but good enough description)
```

The [DAC2932 devboard](https://github.com/kelu124/DAC2932) is a simple yet powerful tool for anyone working with high-speed digital-to-analog conversion (DAC). Designed for ease of use, it combines a high dynamic range with low power consumption, making it a great choice for engineers and hobbyists alike.

At its core, the DAC2932 features dual 12-bit DACs capable of delivering up to 40 million samples per second (MSPS), as well as four additional voltage-output DACs operating at around 1 MSPS. The entire setup is controlled by a Raspberry Pi Pico (RP2040), meaning you don’t need any complex FPGA programming. The open-source toolchain makes it accessible and versatile.

You get fast, accurate signal output with minimal hassle, ideal for prototyping or integrating into larger systems. Whether you’re working on emulating ultrasound signals, as I am, or experimenting with other real-time applications, the DAC2932 devboard offers a user-friendly way to get high-speed DAC performance without the headaches of advanced hardware setups. 

## Software

* Everything in `/software/` using classical rp2040 toolchain.

## Hardware


* Everything in `/hardware/` using classical KiCad.

![](/docs/images/view.jpg)

# Also


## License

This work is based on a previous TAPR project, [the echOmods project](https://github.com/kelu124/echomods/), the [un0rick project](https://github.com/kelu124/un0rick) and more recently the gamind-card, pmod-enabled format [pic0rick](https://github.com/kelu124/pic0rick/) family. Its boards are open hardware and software, developped with open-source elements.

Copyright Luc Jonveaux (kelu124@gmail.com) 2024

* The *hardware* is licensed under TAPR Open Hardware License (www.tapr.org/OHL)
* The *software* components are free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
* The *documentation* is licensed under a [Creative Commons Attribution-ShareAlike 3.0 Unported License](http://creativecommons.org/licenses/by-sa/3.0/).


## Disclaimer(s)

This project is distributed WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF MERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A PARTICULAR PURPOSE. 

See the GNU General Public License for more details.
