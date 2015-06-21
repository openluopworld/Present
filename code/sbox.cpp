
#include"sbox.h"

/*
** S-boxes and inverse S-boxes
*/

// s0
int s0 ( int i ) {
	switch ( i ) {
		case 0: return 3;
		case 1: return 8;
		case 2: return 15;
		case 3: return 1;
		case 4: return 10;
		case 5: return 6;
		case 6: return 5;
		case 7: return 11;
		case 8: return 14;
		case 9: return 13;
		case 10: return 4;
		case 11: return 2;
		case 12: return 7;
		case 13: return 0;
		case 14: return 9;
		case 15: return 12;
		default: return -1;
	}
}

// s1
int s1 ( int i ) {
	switch ( i ) {
		case 0: return 15;
		case 1: return 12;
		case 2: return 2;
		case 3: return 7;
		case 4: return 9;
		case 5: return 0;
		case 6: return 5;
		case 7: return 10;
		case 8: return 1;
		case 9: return 11;
		case 10: return 14;
		case 11: return 8;
		case 12: return 6;
		case 13: return 13;
		case 14: return 3;
		case 15: return 4;
		default: return -1;
	}
}

// s2
int s2 ( int i ) {
	switch ( i ) {
		case 0: return 8;
		case 1: return 6;
		case 2: return 7;
		case 3: return 9;
		case 4: return 3;
		case 5: return 12;
		case 6: return 10;
		case 7: return 15;
		case 8: return 13;
		case 9: return 1;
		case 10: return 14;
		case 11: return 4;
		case 12: return 0;
		case 13: return 11;
		case 14: return 5;
		case 15: return 2;
		default: return -1;
	}
}

// s3
int s3 ( int i ) {
	switch ( i ) {
		case 0: return 0;
		case 1: return 15;
		case 2: return 11;
		case 3: return 8;
		case 4: return 12;
		case 5: return 9;
		case 6: return 6;
		case 7: return 3;
		case 8: return 13;
		case 9: return 1;
		case 10: return 2;
		case 11: return 4;
		case 12: return 10;
		case 13: return 7;
		case 14: return 5;
		case 15: return 14;
		default: return -1;
	}
}

// s4
int s4 ( int i ) {
	switch ( i ) {
		case 0: return 1;
		case 1: return 15;
		case 2: return 8;
		case 3: return 3;
		case 4: return 12;
		case 5: return 0;
		case 6: return 11;
		case 7: return 6;
		case 8: return 2;
		case 9: return 5;
		case 10: return 4;
		case 11: return 10;
		case 12: return 9;
		case 13: return 14;
		case 14: return 7;
		case 15: return 13;
		default: return -1;
	}
}

// s5
int s5 ( int i ) {
	switch ( i ) {
		case 0: return 15;
		case 1: return 5;
		case 2: return 2;
		case 3: return 11;
		case 4: return 4;
		case 5: return 10;
		case 6: return 9;
		case 7: return 12;
		case 8: return 0;
		case 9: return 3;
		case 10: return 14;
		case 11: return 8;
		case 12: return 13;
		case 13: return 6;
		case 14: return 7;
		case 15: return 1;
		default: return -1;
	}
}

// s6
int s6 ( int i ) {
	switch ( i ) {
		case 0: return 7;
		case 1: return 2;
		case 2: return 12;
		case 3: return 5;
		case 4: return 8;
		case 5: return 4;
		case 6: return 6;
		case 7: return 11;
		case 8: return 14;
		case 9: return 9;
		case 10: return 1;
		case 11: return 15;
		case 12: return 13;
		case 13: return 3;
		case 14: return 10;
		case 15: return 0;
		default: return -1;
	}
}

// s7
int s7 ( int i ) {
	switch ( i ) {
		case 0: return 1;
		case 1: return 13;
		case 2: return 15;
		case 3: return 0;
		case 4: return 14;
		case 5: return 8;
		case 6: return 2;
		case 7: return 11;
		case 8: return 7;
		case 9: return 4;
		case 10: return 12;
		case 11: return 10;
		case 12: return 9;
		case 13: return 3;
		case 14: return 5;
		case 15: return 6;
		default: return -1;
	}
}

// is0
int is0 ( int i ) {
	switch ( i ) {
		case 0: return 13;
		case 1: return 3;
		case 2: return 11;
		case 3: return 0;
		case 4: return 10;
		case 5: return 6;
		case 6: return 5;
		case 7: return 12;
		case 8: return 1;
		case 9: return 14;
		case 10: return 4;
		case 11: return 7;
		case 12: return 15;
		case 13: return 9;
		case 14: return 8;
		case 15: return 2;
		default: return -1;
	}
}

// is1
int is1 ( int i ) {
	switch ( i ) {
		case 0: return 5;
		case 1: return 8;
		case 2: return 2;
		case 3: return 14;
		case 4: return 15;
		case 5: return 6;
		case 6: return 12;
		case 7: return 3;
		case 8: return 11;
		case 9: return 4;
		case 10: return 7;
		case 11: return 9;
		case 12: return 1;
		case 13: return 13;
		case 14: return 10;
		case 15: return 0;
		default: return -1;
	}
}

// is2
int is2 ( int i ) {
	switch ( i ) {
		case 0: return 12;
		case 1: return 9;
		case 2: return 15;
		case 3: return 4;
		case 4: return 11;
		case 5: return 14;
		case 6: return 1;
		case 7: return 2;
		case 8: return 0;
		case 9: return 3;
		case 10: return 6;
		case 11: return 13;
		case 12: return 5;
		case 13: return 8;
		case 14: return 10;
		case 15: return 7;
		default: return -1;
	}
}

// is3
int is3 ( int i ) {
	switch ( i ) {
		case 0: return 0;
		case 1: return 9;
		case 2: return 10;
		case 3: return 7;
		case 4: return 11;
		case 5: return 14;
		case 6: return 6;
		case 7: return 13;
		case 8: return 3;
		case 9: return 5;
		case 10: return 12;
		case 11: return 2;
		case 12: return 4;
		case 13: return 8;
		case 14: return 15;
		case 15: return 1;
		default: return -1;
	}
}

// is4
int is4 ( int i ) {
	switch ( i ) {
		case 0: return 5;
		case 1: return 0;
		case 2: return 8;
		case 3: return 3;
		case 4: return 10;
		case 5: return 9;
		case 6: return 7;
		case 7: return 14;
		case 8: return 2;
		case 9: return 12;
		case 10: return 11;
		case 11: return 6;
		case 12: return 4;
		case 13: return 15;
		case 14: return 13;
		case 15: return 1;
		default: return -1;
	}
}

// is5
int is5 ( int i ) {
	switch ( i ) {
		case 0: return 8;
		case 1: return 15;
		case 2: return 2;
		case 3: return 9;
		case 4: return 4;
		case 5: return 1;
		case 6: return 13;
		case 7: return 14;
		case 8: return 11;
		case 9: return 6;
		case 10: return 5;
		case 11: return 3;
		case 12: return 7;
		case 13: return 12;
		case 14: return 10;
		case 15: return 0;
		default: return -1;
	}
}

// is6
int is6 ( int i ) {
	switch ( i ) {
		case 0: return 15;
		case 1: return 10;
		case 2: return 1;
		case 3: return 13;
		case 4: return 5;
		case 5: return 3;
		case 6: return 6;
		case 7: return 0;
		case 8: return 4;
		case 9: return 9;
		case 10: return 14;
		case 11: return 7;
		case 12: return 2;
		case 13: return 12;
		case 14: return 8;
		case 15: return 11;
		default: return -1;
	}
}

// is7
int is7 ( int i ) {
	switch ( i ) {
		case 0: return 3;
		case 1: return 0;
		case 2: return 6;
		case 3: return 13;
		case 4: return 9;
		case 5: return 14;
		case 6: return 15;
		case 7: return 8;
		case 8: return 5;
		case 9: return 12;
		case 10: return 11;
		case 11: return 7;
		case 12: return 10;
		case 13: return 1;
		case 14: return 4;
		case 15: return 2;
		default: return -1;
	}
}