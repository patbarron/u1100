1100 Emulator Tools
===================

This directory contains some little tools to assist with the process of
developing the emulator, and using it.

uimage2strings - This utility reads a disk pack image and dumps it
to stdout treating it as if it's all character data (either 9-bit ASCII
or FIELDATA).  The motivation for doing this is just to be able to
casually peruse a disk image to get an idea of what's in it.  1100
disk packs are formatted to work with 36 bit words, and any computer
you'll be likely to be working on right now is going to have disk drives
that operate on 8-bit bytes.  And the 1100 words actually span across
bytes in the disk image.  So it's impossible to use "normal" troubleshooting
tools (like text editors and hex editors) to do anything with them at all,
because if you look at the image files that way, it all looks like
nonsense.  This utility reformats the contents of the disk pack
image in 8-bit bytes (just like your native filesystem and operating
system expect), so you can peek at it.  Aside from just observation
and learning, there is nothing you can really do with the output of
this program - all you can do with it is look at it.  But sometimes,
that's all you need to do...

