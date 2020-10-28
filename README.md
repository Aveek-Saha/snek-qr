# Snek QR

Trying to create a game of snake thats less than ~2.8 KB, which is the maximum amount of binary data a QR code can hold.

#### Can you fit a game of snake on a QR code?
The answer is yes, and `Matt KC` goes through the process in this great video: https://www.youtube.com/watch?v=ExwqNreocpg.

#### So what's this project for?
The code or the exact steps used in the video weren't linked, so I wanted to chalenge myself to see if I could do it. I've taken a slightly different
aproach than what's shown in the video. This project is esentially a guide for anyone else who want's to try this out. This is by no means perfect, and suggestions are welcome.

## Tools
These are the tools I used to minimize my file size.

1. TCC- The tiny C compiler
1. UPX- For executable packing
1. qrencode- To generate a QR code
1. zbarcam- To read the QR code

## How to run

1. Create an executable

    ```shell
    tcc -m32/64 snek.c
    ```
    This creates a `.exe` file that's ~4 KB in size.

1. Pack with UPX

    ```shell
    upx --ultra-brute snek.exe
    ```
    This creates a smaller `exe` file that's ~3 KB large.
