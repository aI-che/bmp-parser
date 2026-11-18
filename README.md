# BMP Parser

A small **C** program that reads a 24-bit BMP file and parses its header with no external libraries.

## What it does

- Checks the BMP signature (`BM`)
- Reads the **width**, **height** and **bits per pixel**
- Finds the pixel data and loads it into a `ParsedFile` struct

## Run

```bash
gcc bmpparse.c -o bmpparse
./bmpparse          # reads test.bmp from the same folder
```

> Only 24-bit BMP files are supported.

## Tech

C · Binary file I/O · Dynamic memory

## License

MIT
