# Building from Source

So you want to build this from the source code? Here is how you do it, nice and simple.

## Prerequisites

You need the right tools for the job.

1.  **The Toolchain**: You need the specific compiler for Bittboy/V90.
    -   Download: [toolchain.7z](https://drive.google.com/file/d/1Zp6elbB3r4Hq7G7FKXNtBZMTz0H93RiY/view?usp=sharing)
    -   Extract it so the binaries live in: `/opt/bittboy-toolchain/bin/` being the compiler `arm-buildroot-linux-musleabi-gcc`.

2.  **The Code**: You are already here.

3.  **The Libraries**: You need `libopk`.
    -   Inside the `simplemenu` directory (where the `Makefile` is), run:
        ```bash
        git clone https://github.com/pcercuei/libopk.git libopk
        ```

## Build Steps

Go to the `simplemenu` directory (where the `Makefile` is) and run:

```bash
# Clean the kitchen first
make clean

# Cook the binary
make PLATFORM=BITTBOY
```

## Serving (Output)

Once the linking is complete, your fresh binary is ready at:

`../output/simplemenu`

Enjoy!
