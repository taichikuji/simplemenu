#!/bin/sh
set -e
echo "Welcome to Taichi's simplemenu deploy script! Initiating..."

# Preparation: clean 'main' partition - delete all macos dot files 
echo "Deleting all macos dot files"
find /mnt/ -name '._*' -exec rm -v {} &> /dev/null \;
echo "Preparation completed"

# Step 0: Copy main.sh to a variable for later use
if [ -f "/mnt/apps/simplemenu/main.sh" ]; then
    echo "Saving main.sh contents from /mnt/apps/simplemenu/"
    cat_main_content=$(cat /mnt/apps/simplemenu/main.sh)
    echo "Step 0 completed"
fi
# Step 1: Create the ".simplemenu" folder
if [ ! -d "/mnt/.simplemenu" ]; then
    echo "Creating .simplemenu on /mnt/"
    mkdir /mnt/.simplemenu
    echo "Step 1 completed"
fi

# Step 2: Copy the contents of "simplemenu" to ".simplemenu"
if [ -d "/mnt/apps/simplemenu" ]; then
    echo "Copying simplemenu config data to /mnt/.simplemenu/"
    cp -r /mnt/apps/simplemenu/config/* /mnt/.simplemenu/
    cp -r /mnt/apps/simplemenu/* /mnt/.simplemenu/
    echo "Removing redundant data from /mnt/.simplemenu/"
    rm -fr /mnt/.simplemenu/config/*
    rm -fr /mnt/.simplemenu/deploy.sh /mnt/.simplemenu/main.sh /mnt/.simplemenu/clean_dot_files.sh
    echo "Step 2 completed"
fi

# Step 3: Copy "autoexec.sh" one folder upwards
if [ -f "/mnt/.simplemenu/scripts/autoexec.sh" ]; then
    echo "Copying autoexec.sh to /mnt/"
    cp /mnt/.simplemenu/scripts/autoexec.sh /mnt/
    echo "Step 3 completed"
fi

# Step 4: Autobooting simplemenu
if [ -f "/etc/main" ]; then
    echo "Changing partition permissions on /"
    mount -o remount,rw,relatime,data=ordered /
    if [ -n "$cat_main_content" ]; then
           echo "$cat_main_content" > /etc/main
           echo "cat_main_content copied to /etc/main"
    fi
    echo "Changing partition permissions back on /"
    mount -o remount,ro,relatime,data=ordered /
    echo "Step 4 completed"
fi

echo "Syncing..."
sync
echo "Shutting down..."
sleep 3
poweroff
exit