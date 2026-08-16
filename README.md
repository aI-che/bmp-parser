# BMP Parser

A simple C program for parsing 24-bit BMP image files.

## Features

* Reads BMP files in binary mode
* Validates BMP file format
* Extracts image width and height
* Detects bits per pixel
* Locates pixel data
* Supports 24-bit BMP files

## How It Works

The program loads a BMP file into memory and parses its header information.

It checks the BMP signature, extracts the image dimensions and color depth, and locates the beginning of the pixel data.

Parsed information is stored in a `ParsedFile` structure containing:

* Width
* Height
* Bits per pixel
* Pixel data

## Input

The program currently reads:

```text
test.bmp
```

Only 24-bit BMP files are supported.

## Requirements

* C compiler (GCC recommended)
* Standard C library

No external libraries are required.

## Technologies

* C
* Binary File I/O
* BMP File Format
* Dynamic Memory Allocation

## License

MIT License

