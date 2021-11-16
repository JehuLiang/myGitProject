#!/bin/bash
sudo dd if=led.imx of=/dev/sdb bs=1k count=512 seek=2

sync
