<h1 align="center">
    Snek QR
</h1>

A game of snake that's less than ~2.8 KB, which is the maximum amount of binary data a QR code can hold.

#### Can you fit a game of snake on a QR code?
The answer is **yes**, and `Matt KC` goes through the process in this great video: https://www.youtube.com/watch?v=ExwqNreocpg. You can also read his [post](https://itsmattkc.com/etc/snakeqr/) on this.

#### So what's this project for?
The code or the exact steps used in the video weren't linked, so I wanted to challenge myself to see if I could do it. I've taken a slightly different
approach than what's shown in the video. This project is essentially a guide for anyone else who wants to try this out. This is by no means perfect, and suggestions are welcome.

#### What's different?
I've created a game of snake that's played in the terminal using C and it runs on Windows. Unfortunately the smallest I could get the `exe` was 3 KB, so I resorted to compressing it in a zip file. This doesn't affect the experience too much in my opinion as the game can be played without extracting from the folder, but it does feel like cheating so I'm looking for ways to make it even smaller.

## Tools
These are the tools I used to minimize my file size.

1. TCC- The tiny C compiler
1. UPX- For executable packing
1. qrencode- To generate a QR code
1. zbarcam- To read the QR code
 
## How to run

1. Create an executable: This creates a `.exe` file that's ~4 KB in size.

    ```shell
    tcc -m32/64 snek.c
    ``` 

1. Pack with UPX: This creates a smaller `exe` file that's ~3 KB large.

    ```shell
    upx --ultra-brute snek.exe
    ```

1. Zip the `exe`: Put the `exe` in a compressed zipped folder and name it `snek.zip`. This zipped file is less than 2KB and can fit in a QR code.

1. Create the QR code: You'll need to run this in a linux environment, I used WSL for this purpose.

    ```shell
    qrencode -r snek.zip -8 code.png
    ```

1. Read the QR code:
    Print the code out on a sheet of paper or use your phone. Download the zip file containing `zbarcam` for windows from here: https://itsmattkc.com/etc/snakeqr/zbarcam.zip and unzip the files.

    ```shell
    cd zbarcam
    zbarcam --raw --oneshot -Sbinary > snake.zip
    ```

    Open the zipped folder and run the application to play snake!

#### [The QR code](https://github.com/Aveek-Saha/snek-qr/blob/master/code.png)

## Credits

Credits for this idea and the modified version of `zbarcam` go to [@itsmattkc](https://github.com/itsmattkc)