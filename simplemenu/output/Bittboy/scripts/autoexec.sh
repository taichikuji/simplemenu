#!/bin/sh
if [ -d "/mnt/.simplemenu" ]; then
  echo "Cleaning .simplemenu folder"
  find /mnt/.simplemenu -name '._*' -exec rm -v {} \;
fi
cd /mnt/apps/simplemenu
./simplemenu
