# SimpleMenu

An alternative launcher over stock, made to be simple.

## About SimpleMenu

- <span style="color:red">**S**</span>impleMenu
- <span style="color:red">**I**</span>s (a)
- <span style="color:red">**M**</span>inimalistic 
- <span style="color:red">**P**</span>ractical
- <span style="color:red">**L**</span>ean (and)
- <span style="color:red">**E**</span>fficient 
- <span style="color:red">**M**</span>enu (to)
- <span style="color:red">**E**</span>nhance
- <span style="color:red">**N**</span>ew Bittboys'
- <span style="color:red">**U**</span>sability 

---

See [SECURITY.md](SECURITY.md) for details on security improvements and [CONTRIBUTING.md](CONTRIBUTING.md) for development guidelines.

---

## Building SimpleMenu for Powkiddy V90 and Bittboy v3.5

As this fork, based on [fgl82/simplemenu](https://github.com/fgl82/simplemenu), targets Powkiddy v90, most of the work was done targetting that specific layout, and hardware.

However, as Bittboy v3.5 is quite similar, only changing the layout ( binary built stays the same ), both are supported.

### Prerequisites

To build SimpleMenu for development, you'll need:

- **Linux environment** (or WSL on Windows)
- **ARM toolchain**: `arm-linux-musleabi-gcc` or `arm-buildroot-linux-musleabi-gcc`
  - For Bittboy toolchain: `/opt/bittboy-toolchain/bin/arm-buildroot-linux-musleabi-gcc`
- **Git** for repository management
- **Make** build tool

### Build Steps

1. **Clone the repository:**
   ```bash
   git clone https://github.com/taichikuji/simplemenu.git
   cd simplemenu/simplemenu
   ```

2. **Compile for Bittboy/V90 (MiyooCFW):**
   ```bash
   make clean
   make PLATFORM=BITTBOY
   ```

3. **Build output:**
   - The compiled binary will be at `output/simplemenu`
   - The deployment files (binary + configs + resources) are pre-organized in `output/Bittboy/`
   - This single binary works on both Powkiddy V90 and Bittboy v3.5

---

## Deployment Instructions

### For Bittboy v3.5

1. **Copy files to SD card:**
   ```bash
   # Mount your SD card (e.g., /media/sdcard), then:
   cp -r output/Bittboy/* /media/sdcard/apps/simplemenu/
   ```
   - Replace `/media/sdcard/` with your SD card's mount point on your computer
   - Copy the contents to the `apps/simplemenu/` directory on the SD card
   - When running on the device, this will be accessible at `/mnt/apps/simplemenu/`

2. **Configuration:**
   - Default `config.ini` works out-of-the-box for Bittboy v3.5
   - No button mapping changes required

3. **Test on hardware:**
   - Insert SD card into Bittboy
   - Navigate to SimpleMenu in the apps folder
   - Test all buttons and functionality

### For Powkiddy V90

1. **Copy files to SD card:**
   ```bash
   # Mount your SD card (e.g., /media/sdcard), then:
   cp -r output/Bittboy/* /media/sdcard/apps/simplemenu/
   ```
   - Replace `/media/sdcard/` with your SD card's mount point on your computer
   - Copy the contents to the `apps/simplemenu/` directory on the SD card
   - When running on the device, this will be accessible at `/mnt/apps/simplemenu/`

2. **Configuration:**
   - This fork (`taichikuji/simplemenu`) includes button mappings optimized for both devices
   - The config files are in `output/Bittboy/config/config.ini` (pre-deployment) and will be at `/mnt/apps/simplemenu/config/config.ini` on the device
   - The clamshell form factor of the V90 may require button mapping adjustments compared to the candybar Bittboy
   - If buttons don't work correctly, you may need to edit the button key codes in `config.ini` (see Troubleshooting section)

3. **Test on hardware:**
   - Insert SD card into Powkiddy V90
   - Navigate to SimpleMenu in the apps folder
   - **Important:** Test all buttons, especially:
     - D-pad (up, down, left, right)
     - Shoulder buttons (L1, R1)
     - Face buttons (A, B, X, Y)
     - Start/Select buttons

---

## Development Workflow

### Build Script

For quick builds, you can use the provided build script:

```bash
# From the repository root:
cd simplemenu/simplemenu/output
./make_bittboy.sh
```

This script automatically:
- Cleans previous builds
- Compiles with PLATFORM=BITTBOY
- Copies binary to mounted device (if configured in the script)

### Testing

Run the test suite to verify code quality:

```bash
cd tests
./run_tests.sh
```

For unit tests:

```bash
cd tests
gcc -o test_string_utils test_string_utils.c ../simplemenu/src/logic/string_utils.c -I../simplemenu/src/headers
./test_string_utils
```

See [tests/README.md](tests/README.md) for more information.

### Code Quality Tools

Before submitting changes, run static analysis:

```bash
# cppcheck
cppcheck --enable=all --inconclusive simplemenu/src/

# clang-tidy (if available)
clang-tidy simplemenu/src/logic/*.c -- -I simplemenu/src/headers
```

Check for memory leaks with Valgrind:

```bash
valgrind --leak-check=full ./simplemenu
```

---

## Contributing

We welcome contributions! Please see [CONTRIBUTING.md](CONTRIBUTING.md) for:
- Coding standards and best practices
- Security guidelines
- How to submit pull requests
- Areas needing improvement

---

## Troubleshooting

Go to [simplemenu's wiki](https://github.com/taichikuji/simplemenu/wiki) for additional information about this.

---

## Credits

### People who provided technical assistance so this launcher could exist

- **Gameblabla/Sauce:** https://github.com/gameblabla
- **James O' Farrell:** https://github.com/jamesofarrell
- **TriforceX:** https://github.com/TriForceX
- **Vamastah/Szymor:** https://github.com/szymor
- **Pingflood:** https://github.com/pingflood

### People who provided excellent suggestions

- **Dancero643:** https://www.youtube.com/channel/UCM_EKCNx0qwGC7CCOBjhyLg
- **MADX**

---

## License

### Code License

This project is licensed under the GNU General Public License v3.0.

https://www.gnu.org/licenses/gpl-3.0.en.html

### Artwork License

Creative Commons CC BY-NC-SA 3.0

https://creativecommons.org/licenses/by-nc-sa/3.0/

**Logo Attribution:** Logos from https://github.com/rxbrad/es-theme-gbz35
