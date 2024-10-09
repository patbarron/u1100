# Design Notes

These are some rough design notes, intended mainly for my own reference.
Putting them in the project repo to preserve them.

## Emulation Target and Supported Devices

The system being emulated is the Sperry Univac 1100/20 (basically
the same as the 1108) with either 131K words or 524K words of storage..

I need to figure out what was supplied as an operator console with
the 1100/20.  I know the 1108 used the 4009 Display Console.  Not sure
if it's the same on the 1100/20.

## CPU execution main loop

A general (pseudocode) description of the instruction execution loop.

```
   while (CPU not halted) do
      Update day clock if required
      if (interrupt is pending)
          dispatch interrupt
          break to next CPU cycle after interrupt return
      if P (current program counter) matches breakpoint register
           do whatever breakpoint processing does
      fetch instruction from P
      decode current instruction
      find instruction in instruction dispatch table
      if (instruction doesn't exist)
          queue up invalid instruction interrupt through location 241
          break to next CPU cycle
      if (privileged instruction in guard mode)
          queue up guard mode interrupt through location 243
          break to next CPU cycle
      execute instruction via instruction dispatch table (may cause
        its own storage limits or breakpoint interrupt)
      increment P
      go to top of loop
```

## Breakpoint Interrupts

The 1100/20 manual doesn't say what happens when we do something
that matches the breakpoint register (unless the OCR for that section
has failed and my search of the PDF manual for this is broken).
The 1100/80 manual says that system generates an interrupt through
location 231.  On the 1100/20, that location is for RTC interrupts.
Not sure if it's handled the same as on the 1100/80.  The book just
says there is a breakpoint register, though I can't find any
instructions that do anything with it.  I wonder if this is strictly
a front-panel thing?

## System Bootstrap

How does an 1100/20 boot up?  How does the EXEC get loaded?  Does
the emulator need to find it in the MFD and load it?

I found a document (I don't recall which document at this point) that
said that the first 2000 words of the boot drive contain bootstrap
information (I guess beyond what's in the normal disk label, as
described in the Installation Reference Manual and the Data Structures
Programmer Reference).  What's in that?
