# Snek QR

Create a game of snake thats less than ~2.8 KB, which is the maximum amount of binary data a QR code can hold.

#### Can you fit a game of snake on a QR code?
The answer is **yes**, and `Matt KC` goes through the process in this great video: https://www.youtube.com/watch?v=ExwqNreocpg.

#### So what's this project for?
The code or the exact steps used in the video weren't linked, so I wanted to chalenge myself to see if I could do it. I've taken a slightly different
aproach than what's shown in the video. This project is esentially a guide for anyone else who want's to try this out. This is by no means perfect, and suggestions are welcome.

#### What's different?
I've created a game of snake that's played in the terminal using C and it runs on Windows. Unfortunately smallest I could get the `exe` was 3 KB, so I resorted to compressing it in a zip file. This doesn't affect the experience too much in my opinion as the game can be played without extracting from the folder, but it does feel like cheating so I'm looking for ways to make it even smaller.

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

1. Zip the `exe`

    Put the `exe` in a compressed zipped folder and name it `snek.zip`. This zipped file is less than 2KB and can fit in a QR code.

1. Create the QR code

    ```shell
    qrencode -r snek.zip -8 code.png
    ```

    You'll need to run this in a linux environment, I used WSL for this purpose.

1. Read the QR code

    Print the code out on a sheet of paper or use your phone. Download the zip file containing `zbarcam` for windows from here: https://itsmattkc.com/etc/snakeqr/zbarcam.zip and unzip the files.

    ```shell
    cd zbarcam
    zbarcam --raw --oneshot -Sbinary > snake.zip
    ```

    Open the zipped folder and run the application to play snake!


## Credits

Credits for this idea and the modified version of `zbarcam` go to @itsmattkc