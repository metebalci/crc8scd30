# Description

[![Build Status](https://travis-ci.com/metebalci/crc8scd30.svg?branch=master)](https://travis-ci.com/metebalci/crc8scd30)

This repo contains the CRC algorithm used in I2C interface of Sensirion SCD30 Sensor Module.

https://www.sensirion.com/en/environmental-sensors/carbon-dioxide-sensors-co2/


# Specification

SCD30 Interface Description gives the following properties:

| Preceding Command | Value               |
|-------------------|---------------------|
| Name              | CRC-8               |
| Protected Data    | read data           |
| Width             | 8 bits              |
| Polynomial        | 0x31 (x8+x5+x4+1)   |
| Initialization    | 0xFF                |
| Reflect Input     | false               |
| Reflect Output    | false               |
| Final XOR         | 0x00                |
| Example           | CRC(0xBEEF) = 0x92  |

Although they use the same polynomial, this algorithm is different than the more common CRC-8/MAXIM-DOW algorithm where there are many more sample implementations. This one is called "CRC-8/NRSC-5" in http://reveng.sourceforge.net/crc-catalogue/all.htm .

source: https://www.sensirion.com/fileadmin/user_upload/customers/sensirion/Dokumente/9.5_CO2/Sensirion_CO2_Sensors_SCD30_Interface_Description.pdf

# Source Code

Original crc8scd30.c and .h files are generated using the crcany project: https://github.com/madler/crcany

with this command:

```
echo "width=8 poly=0x31 init=0xff refin=false refout=false xorout=0x00 check=0xf7 residue=0x00 name=scd30" | ./crcgen
```

Then, I modified these files, removed the parts that are not related to SCD30 and changed the types. They conform to c11. 

You need only these two files (crc8scd30.c and .h) in your project. See test.c for test vectors.
