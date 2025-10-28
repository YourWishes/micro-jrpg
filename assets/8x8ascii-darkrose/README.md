This is a simple 32x32 bitmap font I made as a byproduct of messing about with Xlib. Because of its a power of 2 sizing, it should be able to be resized easily, even if you're writting your own render.

font.png is a screenshot of the output of my rendering text using font.c.
font.zip contains font.c, which is just a C array of 64bit unsigned integers, these are the original bitmaps for the 8x8 font which I resized 4x to get font.png.

Note the font.c is licensed GPLv3 or later only, the font.png is also licensed GPLv2 and CC-BY-SA.
Copyright/Attribution Notice: 
To satisfy CC-BY-SA's attribution clause, just give a link back to OGA.

# Original URL: https://opengameart.org/content/8x8-ascii-bitmap-font-with-c-source