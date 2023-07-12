#!/bin/sh
if find /mnt/.simplemenu -name '._*' -print -quit >/dev/null; then
    find /mnt/.simplemenu -name '._*' -exec rm -v {} \;
fi
cd /mnt/apps/simplemenu
./simplemenu
