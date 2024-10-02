u1100
=====

Partial emulator for some Sperry Univac 1100 Series mainframe...  I was
originally intending to target the 1100/80, but it contains complications
I don't want to deal with right now (most notably Univac 494 mode,
which would pretty much require building a second emulator inside of
the 1100 emulator).  I'd still eventually like to get there, but it's
probably better to start with something less ambitious.  The 1100/60 was
considered, but I can't find complete documentation on it (in particular,
the interaction of the processor with the System Support Processor -
I would not consider emulating the SSP per se, but would have to emulate
its observable functionality).  The 1100/40 (a/k/a Univac 1110, at least
for emulation purposes) would be a lot more reasonable, and there is
pretty complete documentation, but it too has a complication I don't
want to deal with right now (Univac 1107 addressing compatbility mode).
So that pretty much leaves the 1100/20 (1108), and 1100/10 (1106) -
almost entirely the same computer, except the 1100/10 is just a
half-speed version of the 1100/20.  This was a little simpler
than I had really wanted (for example, you can only base one bank
at a time) - but I realize that that simplicity makes it a much more
reasonable place to start (and it's not like I have an OS that would
run on any of these emulation targets anyway...).  So that's what
I think I'm going to do.  The emulation target may change (or the
emulator may expand to support multiple emulation targets) in the
future.  But this is OK for now.

This work is just beginning - there's not much to see here (yet!)

(Yes, I know this repo has been sitting here, unpopulated, for
several years.  I wish this were not the case...  My primary issue with
making any progress on this is, I have nothing to run on it - so even
if I were to implement something, I have no way to even guess if it's
working or not.  I do have a hobbyist distribution [directly from
Unisys and everything] of OS2200, but I do not know if it will run
on the 1100/80 configuration I want to target with this project.  If
I can someday find an old OS1100 or EXEC-8 boot tape, I'm much more
likely to make progress on this....)

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
way to do disk I/O (assuming it ever gets that far along), as
well as a very basic cross-assembler (to be able to assemble
1100 binaries on Linux)...

At least for the moment, I'm not going to be processing external pull
requests or external code contributions.  Any pull request submitted
right now is just going to sit for a while until the code is more
fully fleshed out, and then may have to be rejected if it can't
be merged into the codebase cleanly at that point, or if I've already
implmented the functionality in the pull request.  So probably best
to just hang on to those for a little while.  I fully intend to be open
to that in the future - I just want to at least get a foundation built
before I pull outside changes into it.  However, if someone were to
be feeling very enthusiastic about making some kind of code contribution,
rather than trying to work on the emulator itself, there are some
external standalone utilities that are needed, that I would
gratefully accept pull requests to add.  What's currently needed
can be found in the Issues section of this repo - in particular,
[issue #2](https://github.com/patbarron/u1100/issues/2) and
[issue #3](https://github.com/patbarron/u1100/issues/3) are going to need to be done pretty early
on in the project lifecycle, and as standalone utilities,
these items would not really need to be "merged" into anything
(since they'd be their own thing).
