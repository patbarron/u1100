/* 
 * uimage2strings - reinterpret a UNIVAC 1100 / Unisys 2200 disk pack image
 *    as either ASCII or FIELDATA, by extracting all of the 36 bit words
 *    from the image, assuming they're all either 9-bit ASCII or 6-bit
 *    FIELDATA, and dumping out the 8-bit ASCII equivalent (for 9-bit
 *    ASCII, by just dropping the high order bit of each quarter-word
 *    and writing out the remaining 8 bits assuming it's in ASCII
 *    character; for FIELDATA, we just extract six 6-bit fields from
 *    each word, assume they're FIELDATA values, and convert to their
 *    ASCII equivalent).  The point of this is to be able to use something
 *    like "strings" to dig through a disk image, looking for ASCII strings.
 *    Since a disk image isn't really just a sequence of 9-bit ASCII
 *    characters nor is it just a sequence of 6-bit FIELDATA characters,
 *    most of the output will be garbage - but that's OK, because we'll
 *    further filter it using some other tool to see what we want to see.
 *
 *    We assume that every 9 bytes of a disk pack image corresponds
 *    to two 36-bit words, and interpret accordingly, in the most
 *    simple-minded way possible.  This doesn't have to be fast or
 *    efficient, because it's not something that anyone is going
 *    to do on any given image more than once, probably.  Yes, it's
 *    an incredibly brute-force approach to this.  Give me a break,
 *    it took me about 20 minutes to bang this out (the ASCII extraction
 *    part of it, anyway), and it shows. ;-)  If I wanted to be fancy
 *    about it, I could just mmap() the whole image file and work with
 *    it that way, and maybe I will if I get bored at some point.  But
 *    for now, this works just fine.
 */


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void image2ascii(int fd)
{
	int i; /* generic loop iteration variable */
	unsigned char disk_words[9];  /* The current set of bytes from
					 the image that we are turning
					 into 36-bit words. */
	unsigned char output_bytes[8]; /* We assemble the output into
					  this array. */
	for (i=0; i<9; i++) {
		disk_words[i] = '\0';
	}
	/* Yes, we are really going to read this file 9 bytes at
	 * a time, and write the output 8 bytes at a time...  I'm
	 * just not up for trying to make it more efficient right
	 * now...
	 */
	while (read(fd, disk_words, 9) > 0) {
		for (i=0; i < 8; i++) {
			output_bytes[i] = '\0';
		}
		output_bytes[0] = disk_words[0] << 1;
		output_bytes[0] |= ( disk_words[1] >> 7 );
		output_bytes[1] = disk_words[1] << 2;
		output_bytes[1] |= disk_words[2] >> 6;
		output_bytes[2] = disk_words[2] << 3;
		output_bytes[2] |= disk_words[3] >> 5;
		output_bytes[3] = disk_words[3] << 4;
		output_bytes[3] |= disk_words[4] >> 4;
		output_bytes[4] = disk_words[4] << 5;
		output_bytes[4] |= disk_words[5] >> 3;
		output_bytes[5] = disk_words[5] << 6;
		output_bytes[5] |= disk_words[6] >> 2;
		output_bytes[6] = disk_words[6] << 7;
		output_bytes[6] |= disk_words[7] >> 1;
		output_bytes[7] = disk_words[8];
		write(1, output_bytes, 8);
		for (i=0; i < 9; i++) {
			disk_words[i] = '\0';
		}
	}
}

void main(int argc, char *argv[]) {
	int pack_fd;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s -a|-f filename\n", argv[0]);
		exit(1);
	}
	
	pack_fd = open(argv[2], O_RDONLY);
	if (pack_fd < 0) {
		perror(argv[2]);
		exit(2);
	}
	if (strcmp(argv[1], "-a") == 0) {
		fprintf(stderr, "Extracting ASCII character data, stand by...\n");
		image2ascii(pack_fd);
		exit(0);
	}
	else if (strcmp(argv[1], "-r") == 0) {
		fprintf(stderr, "Sorry, FIELDATA character extraction isn't implemented yet!\n");
		exit(4);
	}
	else {
		fprintf(stderr, "%s: Unrecognized flag %s\n", argv[0], argv[1]);
		exit(5);
	}
}
