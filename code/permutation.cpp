
#include"permutation.h"

/*
** the initial permutation and final permutation
*/

/*
** the initial permutation
*/
void initialPer ( const unsigned int *const src, unsigned int *des ) {
	
	des[0] = src[0];    des[1] = src[32];   des[2] = src[64];   des[3] = src[96]; 
	des[4] = src[1];    des[5] = src[33];   des[6] = src[65];   des[7] = src[97];
	des[8] = src[2];    des[9] = src[34];   des[10] = src[66];  des[11] = src[98];
	des[12] = src[3];   des[13] = src[35];  des[14] = src[67];  des[15] = src[99];

	des[16] = src[4];   des[17] = src[36];  des[18] = src[68];  des[19] = src[100]; 
	des[20] = src[5];   des[21] = src[37];  des[22] = src[69];  des[23] = src[101];
	des[24] = src[6];   des[25] = src[38];  des[26] = src[70];  des[27] = src[102];
	des[28] = src[7];   des[29] = src[39];  des[30] = src[71];  des[31] = src[103];

	des[32] = src[8];   des[33] = src[40];  des[34] = src[72];  des[35] = src[104]; 
	des[36] = src[9];   des[37] = src[41];  des[38] = src[73];  des[39] = src[105];
	des[40] = src[10];  des[41] = src[42];  des[42] = src[74];  des[43] = src[106];
	des[44] = src[11];  des[45] = src[43];  des[46] = src[75];  des[47] = src[107];

	des[48] = src[12];  des[49] = src[44];  des[50] = src[76];  des[51] = src[108]; 
	des[52] = src[13];  des[53] = src[45];  des[54] = src[77];  des[55] = src[109];
	des[56] = src[14];  des[57] = src[46];  des[58] = src[78];  des[59] = src[110];
	des[60] = src[15];  des[61] = src[47];  des[62] = src[79];  des[63] = src[111];

	des[64] = src[16];  des[65] = src[48];  des[66] = src[80];  des[67] = src[112]; 
	des[68] = src[17];  des[69] = src[49];  des[70] = src[81];  des[71] = src[113];
	des[72] = src[18];  des[73] = src[50];  des[74] = src[82];  des[75] = src[114];
	des[76] = src[19];  des[77] = src[51];  des[78] = src[83];  des[79] = src[115];

	des[80] = src[20];  des[81] = src[52];  des[82] = src[84];  des[83] = src[116]; 
	des[84] = src[21];  des[85] = src[53];  des[86] = src[85];  des[87] = src[117];
	des[88] = src[22];  des[89] = src[54];  des[90] = src[86];  des[91] = src[118];
	des[92] = src[23];  des[93] = src[55];  des[94] = src[87];  des[95] = src[119];
	
	des[96] = src[24];  des[97] = src[56];  des[98] = src[88];  des[99] = src[120]; 
	des[100] = src[25]; des[101] = src[57]; des[102] = src[89]; des[103] = src[121];
	des[104] = src[26]; des[105] = src[58]; des[106] = src[90]; des[107] = src[122];
	des[108] = src[27]; des[109] = src[59]; des[110] = src[91]; des[111] = src[123];

	des[112] = src[28]; des[113] = src[60]; des[114] = src[92]; des[115] = src[124]; 
	des[116] = src[29]; des[117] = src[61]; des[118] = src[93]; des[119] = src[125];
	des[120] = src[30]; des[121] = src[62]; des[122] = src[94]; des[123] = src[126];
	des[124] = src[31]; des[125] = src[63]; des[126] = src[95]; des[127] = src[127];
	
}

/*
** the final permutation
*/
void finalPer ( const unsigned int *const src, unsigned int *des ) {

	des[0] = src[0];     des[1] = src[4];    des[2] = src[8];    des[3] = src[12]; 
	des[4] = src[16];    des[5] = src[20];   des[6] = src[24];   des[7] = src[28];
	des[8] = src[32];    des[9] = src[36];   des[10] = src[40];  des[11] = src[44];
	des[12] = src[48];   des[13] = src[52];  des[14] = src[56];  des[15] = src[60];

	des[16] = src[64];   des[17] = src[68];  des[18] = src[72];  des[19] = src[76]; 
	des[20] = src[80];   des[21] = src[84];  des[22] = src[88];  des[23] = src[92];
	des[24] = src[96];   des[25] = src[100]; des[26] = src[104]; des[27] = src[108];
	des[28] = src[112];  des[29] = src[116]; des[30] = src[120]; des[31] = src[124];

	des[32] = src[1];    des[33] = src[5];   des[34] = src[9];   des[35] = src[13]; 
	des[36] = src[17];   des[37] = src[21];  des[38] = src[25];  des[39] = src[29];
	des[40] = src[33];   des[41] = src[37];  des[42] = src[41];  des[43] = src[45];
	des[44] = src[49];   des[45] = src[53];  des[46] = src[57];  des[47] = src[61];

	des[48] = src[65];   des[49] = src[69];  des[50] = src[73];  des[51] = src[77]; 
	des[52] = src[81];   des[53] = src[85];  des[54] = src[89];  des[55] = src[93];
	des[56] = src[97];   des[57] = src[101]; des[58] = src[105]; des[59] = src[109];
	des[60] = src[113];  des[61] = src[117]; des[62] = src[121]; des[63] = src[125];

	des[64] = src[2];    des[65] = src[6];   des[66] = src[10];  des[67] = src[14]; 
	des[68] = src[18];   des[69] = src[22];  des[70] = src[26];  des[71] = src[30];
	des[72] = src[34];   des[73] = src[38];  des[74] = src[42];  des[75] = src[46];
	des[76] = src[50];   des[77] = src[54];  des[78] = src[58];  des[79] = src[62];

	des[80] = src[66];   des[81] = src[70];  des[82] = src[74];  des[83] = src[78]; 
	des[84] = src[82];   des[85] = src[86];  des[86] = src[90];  des[87] = src[94];
	des[88] = src[98];   des[89] = src[102]; des[90] = src[106]; des[91] = src[110];
	des[92] = src[114];  des[93] = src[118]; des[94] = src[122]; des[95] = src[126];
	
	des[96] = src[3];    des[97] = src[7];   des[98] = src[11];  des[99] = src[15]; 
	des[100] = src[19];  des[101] = src[23]; des[102] = src[27]; des[103] = src[31];
	des[104] = src[35];  des[105] = src[39]; des[106] = src[43]; des[107] = src[47];
	des[108] = src[51];  des[109] = src[55]; des[110] = src[59]; des[111] = src[63];

	des[112] = src[67];  des[113] = src[71]; des[114] = src[75]; des[115] = src[79]; 
	des[116] = src[83];  des[117] = src[87]; des[118] = src[91]; des[119] = src[95];
	des[120] = src[99];  des[121] = src[103];des[122] = src[107];des[123] = src[111];
	des[124] = src[115]; des[125] = src[119];des[126] = src[123];des[127] = src[127];

}