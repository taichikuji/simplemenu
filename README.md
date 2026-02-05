# SimpleMenu 🎮

A minimalistic, practical, lean and efficient menu to enhance handheld gaming devices.

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

This fork is specifically configured for the **Powkiddy V90** and **Bittboy v3.5** handheld gaming devices. Both devices share the same hardware architecture (Allwinner F1C100s ARM processor) and run MiyooCFW firmware, making them binary-compatible.

---

## Building SimpleMenu for Powkiddy V90 and Bittboy v3.5

### Understanding the Hardware

Both the Powkiddy V90 and Bittboy v3.5 devices:
- Use the **Allwinner F1C100s** ARM-based processor (not MIPS)
- Run **MiyooCFW** firmware
- Use the **same compiled binary** - no separate builds needed
- Differ only in **button mappings** due to form factor differences (V90 is clamshell, Bittboy is candybar)

### Prerequisites

To build SimpleMenu, you'll need:

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
   - The compiled binary will be in `output/simplemenu`
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
   - This fork (`taichikuji/simplemenu`) already includes V90-specific button mappings in `config.ini`
   - The clamshell form factor requires different button assignments compared to Bittboy
   - Special attention to d-pad and shoulder button mappings

3. **Test on hardware:**
   - Insert SD card into Powkiddy V90
   - Navigate to SimpleMenu in the apps folder
   - **Important:** Test all buttons, especially:
     - D-pad (up, down, left, right)
     - Shoulder buttons (L1, R1)
     - Face buttons (A, B, X, Y)
     - Start/Select buttons

---

## Device Comparison

| Feature | Powkiddy V90 | Bittboy v3.5 |
|---------|-------------|--------------|
| **Architecture** | ARM (Allwinner F1C100s) | ARM (Allwinner F1C100s) |
| **Firmware** | MiyooCFW | MiyooCFW |
| **Binary** | `output/simplemenu` | `output/simplemenu` |
| **Build Command** | `make PLATFORM=BITTBOY` | `make PLATFORM=BITTBOY` |
| **Form Factor** | Clamshell (GBA SP style) | Candybar |
| **Config File** | Modified button mappings | Default button mappings |
| **Deployment Path** | `apps/simplemenu/` on SD card → `/mnt/apps/simplemenu/` on device | `apps/simplemenu/` on SD card → `/mnt/apps/simplemenu/` on device |

---

## Development Workflow

### Working with Upstream

This fork is based on [fgl82/simplemenu](https://github.com/fgl82/simplemenu). For general development:

1. **Feature development:**
   - Contribute features to upstream `fgl82/simplemenu`
   - Keep this fork focused on V90-specific configurations

2. **Testing on V90:**
   - Use this fork's pre-configured `config.ini` for V90 testing
   - Validate button mappings work correctly on clamshell form factor

3. **Syncing changes:**
   - Regularly merge upstream changes
   - Preserve V90-specific button configurations

### Build Script

For quick builds, you can use the provided build script:

```bash
cd simplemenu/output
./make_bittboy.sh
```

This script automatically:
- Cleans previous builds
- Compiles with PLATFORM=BITTBOY
- Copies binary to mounted device (if configured)

---

## Troubleshooting

### Buttons don't respond on Powkiddy V90

**Symptom:** Buttons work inconsistently or not at all on V90

**Solution:**
- Verify you're using the V90-specific `config.ini` from this fork
- The V90's clamshell design requires different button mappings
- Check `/mnt/apps/simplemenu/config/config.ini` on the device (or `apps/simplemenu/config/config.ini` on your SD card)
- Compare with `configs/bittboy/config/config.ini` in this repository

### Binary won't run on device

**Symptom:** SimpleMenu doesn't launch or crashes immediately

**Solution:**
- Ensure you're using MiyooCFW firmware (not stock firmware)
- Verify the binary was compiled with the correct toolchain
- Check file permissions: `chmod +x simplemenu`
- Try rebuilding: `make clean && make PLATFORM=BITTBOY`

### Compile errors

**Symptom:** Build fails with "command not found" or linker errors

**Solution:**
- Verify ARM toolchain is installed: `which arm-buildroot-linux-musleabi-gcc`
- Add toolchain to PATH: `export PATH=/opt/bittboy-toolchain/bin:$PATH`
- Install required libraries: SDL, SDL_image, SDL_ttf, etc.
- Check Makefile for correct toolchain path

### Wrong architecture error

**Symptom:** Binary compiled for wrong architecture (e.g., MIPS instead of ARM)

**Solution:**
- Both V90 and Bittboy are ARM-based (Allwinner F1C100s)
- Use `PLATFORM=BITTBOY` not `PLATFORM=RFW` or other MIPS platforms
- Verify toolchain: `arm-buildroot-linux-musleabi-gcc --version`

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
