#!/bin/bash
sudo dd if=$1 of=$2  bs=1k count=512 seek=2

sync
