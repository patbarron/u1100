u1100
=====

Partial emulator for Sperry Univac 1100/80 mainframe (or possibly some
other, earlier, model - not entirely clear).

This work is just beginning - there's nothing to see here (yet!)

(Yes, I know this repo has been sitting here, unpopulated, for
several years.  I wish this were not the case...  My primary issue with
making any progress on this is, I have nothing to run on it - so even
if I were to implement something, I have no way to even guess if it's
working or not.  I do have a hobbyist distribution [directly from
Unisys and everything] of OS2200, but I do not know if it will run
on the 1100/80 configuration I want to target with this project.  If
I can someday find an old OS1100 IPL tape, I'm much more likely to
make progress on this....)

Update - September 2024...  This long-mothballed project has been on
my mind again recently.  Unisys has stopped distributing OS2200 Express,
and has stopped renewing PS/2200 emulator licenses for existing
users (they were previously only providing license keys that were valid
for a year at a time and thus had to be renewed annually), , so I no
longer have that crutch to lean on...  It's not clear what progress can
be made without some form of OS1100 boot tape image.  There is a small
program that is distributed with David William Nixon's [1100/40 (1110) emulator](https://sites.google.com/view/univacemulators/110040), that could
potentially be used as a test, but it seems like that emulator internally
implements some basic functionality of EXEC-8 that I'm not sure I want
to try to do at this point.  But even just getting an executable
loaded and doing *something* is better than not having anything at all...

I am also planning to put together some tools to maniplulate
disk pack images, so that the emulator will at least have some
way to do disk I/O, assuming it ever gets that far along.
