This is a very brief timeline of the history of the Univac 1100 series.  This has been
done elsewhere, much better than I could ever possibly do it, you'll find links to
other sources at the end of this document.  I present this here just to give an
idea of what features there are in other models (besides the model this software
emulates), and what challenges those other models present that led me to settle
on the 1100/20 as the emulation target for this emulator.

In this timeline, I only consider the 1100 series.  The later Unisys
2200 series systems are basically the same architecture (though
faster, higher throughput, and with some new features and instructions),
but for my own personal sense of nostalgia, my interest drops off at
about the time of the last 1100 series system.

| Date | Model | Notable Features | Integer add time | FP divide time |
|------|-------|------------------|------------------|----------------|
| 1962 | 1107  | No base registers, no guard mode (everything effectively runs in privileged mode all the time), core memory | 4000ns | 26700ns |
| 1964 | 1108  | New addressing system, one I-bank base register, one D-bank base register, guard mode, core memory | 750ns | 8250ns |
| 1965 | 1108 II (1108A) | Enhanced version of 1108, multiprocessor capable (up to three CPUs) | - | - |
| 1969 | 1106 | Cost-reduced version of the 1108A, operates at half the speed, otherwise identical | 1000ns | 11000ns |
| 1972 | 1110 | New segmented addressing system, two I-bank base registers, two D-bank base registers, 1107 addressing compatibility mode, supports up to four CPUs, plated-wire memory and core memory | 300ns | 5200ns |
| 1975 | 1100/20 | Upgraded version of 1108A, MOS memory replaces core memory | 875ns | 8325ns |
| 1975 | 1100/40 | Upgraded version of 1110, supports up to 6 CAUs (processors), TTL memory replaces plated-wire memory, MOS memory replaces core memory | 300ns | 5200ns |
| 1976 | 1100/10 | Upgraded version of 1106, MOS memory replaces core memory | 1125ns | 8825ns |
| 1977 | 1100/80 | Supports up to 4 processors, high-speed cache memory, two I-bank base registers, two D-bank base registers, UNIVAC 494 compatibility mode (non-privileged 494 instructions implemented in hardware, privileged 494 instructions emulated by software [Promega]) | 200ns | 4800ns |
| 1979 | 1100/60 | Replacement for 1108, 1108A, 1106, 1100/10, and 1100/20, multiprocessor-capable (initially capable of using two processors, later up to four processors), loadable microcode, microcode loading and system boot by System Support Processor (SSP), multiple configurations available | - | - |
| 1981 | 1100/70 | Improved version of 1100/60 with denser main memory | - | - |
| 1982 | 1100/90 | Last member of the 1100 series, liquid cooled | - | - |

Integer add times and floating point divide times (when available) presented as a proxy for the overall performance of the system.
Shorter operation times, of course, represent better performance.

The System Support Processor (SSP) for the 1100/60 and 1100/70 was an Intel 8080-based microcomputer system, and
was also marketed as a standalone small business computer as the [Sperry Univac BC/7 Business Computer](https://www.ricomputermuseum.org/collections-gallery/equipment/sperry-univac-bc7-1).

Beginning with the 1100/10 systems, in multiprocessor configurations, the last digit of the model number was the number of processors in the system - for example, a two-processor 1100/60 system would be referred to as 1100/62.

After the introduction of the 1100/90, the "Univac" name was discontinued, and in 1985, the first member of the 2200 series systems
was introduced - the Sperry 2200/100.  In 1986, Sperry merged with Burroughs to form Unisys, and in the same year the Unisys 2200/200
system was introduced.  The 2200 series systems (and later systems using the same processor architecture such as the
Unisys Clearpath Dorado product line) will not be further considered here, other than to mention that the most recent system
using this processor architecture, the Unisys ClearPath Dorado 8300, was introduced in 2015.  The most recent ClearPath Dorado
systems actually use Intel x86-based processors running a version of Linux, and they run 1100/2200 operating systems and applications
under emulation.  While these systems are unlikely to be able to run the old EXEC-8 and OS1100 operating systems, they can still
run (with no changes) most user-mode applications that could have run on the Sperry Univac 1108 system in 1964.  Much like how
current IBM zSeries mainframes could still run most user-mode applications that could have run on the System/360 or System/370.
In mainframe environments, absolute (or almost absolute) backwards compatibility is pretty much non-negotiable.  (A large
exception to this in the Univac 1100 world is that applications for the original 1107 probably won't run on any later 1100 series
system except for the 1110 and 1100/40, because those systems have the 1107 addressing compatibility mode that would be
required.)

For further information, see:

* [The Evolution of the Sperry Univac 1100 Series: A History, Analysis, and Projection, B.R. Borgerson, M.L. Hanson, and P.A. Hartley, Sperry Univac](https://dl.acm.org/doi/pdf/10.1145/359327.359334)
* [Wikipedia: UNIVAC 1100/2200 Series](https://en.wikipedia.org/wiki/UNIVAC_1100/2200_series)
* [Wikipedia: UNIVAC 1100/60](https://en.wikipedia.org/wiki/UNIVAC_1100/60)
* [Bitsavers Univac 1100 document archive](https://bitsavers.org/pdf/univac/1100)
* [Fourmilab Univac Memories document archive](https://www.fourmilab.ch/documents/univac/manuals/)
* [Datapro: UNIVAC 1100 Series](https://bitsavers.org/pdf/univac/1100/datapro/70C-877-11_7812_UNIVAC_1100.pdf)
* [Datapro: Unisys 1100/60](https://bitsavers.org/pdf/univac/1100/datapro/70C-944YT-60_8702_Unisys_1100_60.pdf)
