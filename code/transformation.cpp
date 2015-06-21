
#include"transformation.h"

/*
** 线性变形与逆变形
** the linear transformation and the inverse linear transformation
*/

void transfor ( const unsigned int *const src, unsigned int *des ) {

	/*
	** 第0-15位
	*/
	des[0]   = ( src[16] + src[52] + src[56] + src[70] + src[83] + src[94] + src[105]) % 2;
	des[1]   = ( src[72] + src[114] + src[125] ) % 2;
	des[2]   = ( src[2] + src[9] + src[15] + src[30] + src[76] + src[84] + src[126]) % 2;
	des[3]   = ( src[36] + src[90] + src[103] ) % 2;
	des[4]   = ( src[20] + src[56] + src[60] + src[74] + src[87] + src[98] + src[109]) % 2;
	des[5]   = ( src[1] + src[76] + src[118] ) % 2;
	des[6]   = ( src[2] + src[6] + src[13] + src[19] + src[34] + src[80] + src[88]) % 2;
	des[7]   = ( src[40] + src[94] + src[107] ) % 2;

	des[8]   = ( src[24] + src[60] + src[64] + src[78] + src[91] + src[102] + src[113]) % 2;
	des[9]   = ( src[5] + src[80] + src[122] ) % 2;
	des[10]  = ( src[6] + src[10] + src[17] + src[23] + src[38] + src[84] + src[92]) % 2;
	des[11]  = ( src[44] + src[98] + src[111] ) % 2;
	des[12]  = ( src[28] + src[64] + src[68] + src[82] + src[95] + src[106] + src[117]) % 2;
	des[13]  = ( src[9] + src[84] + src[126] ) % 2;
	des[14]  = ( src[10] + src[14] + src[21] + src[27] + src[42] + src[88] + src[96]) % 2;
	des[15]  = ( src[48] + src[102] + src[115] ) % 2;

	/*
	** 第16-31位
	*/
	des[16]   = ( src[32] + src[68] + src[72] + src[86] + src[99] + src[110] + src[121]) % 2;
	des[17]   = ( src[2] + src[13] + src[88] ) % 2;
	des[18]   = ( src[14] + src[18] + src[25] + src[31] + src[46] + src[92] + src[100]) % 2;
	des[19]   = ( src[52] + src[106] + src[119] ) % 2;
	des[20]   = ( src[36] + src[72] + src[76] + src[90] + src[103] + src[114] + src[125]) % 2;
	des[21]   = ( src[6] + src[17] + src[92] ) % 2;
	des[22]   = ( src[18] + src[22] + src[29] + src[35] + src[50] + src[96] + src[104]) % 2;
	des[23]   = ( src[56] + src[110] + src[123] ) % 2;

	des[24]   = ( src[1] + src[40] + src[76] + src[80] + src[94] + src[107] + src[118]) % 2;
	des[25]   = ( src[10] + src[21] + src[96] ) % 2;
	des[26]   = ( src[22] + src[26] + src[33] + src[39] + src[54] + src[100] + src[108]) % 2;
	des[27]   = ( src[60] + src[114] + src[127] ) % 2;
	des[28]   = ( src[5] + src[44] + src[80] + src[84] + src[98] + src[111] + src[122]) % 2;
	des[29]   = ( src[14] + src[25] + src[100] ) % 2;
	des[30]   = ( src[26] + src[30] + src[37] + src[43] + src[58] + src[104] + src[112]) % 2;
	des[31]   = ( src[3] + src[118] ) % 2;

	/*
	** 第32-47位
	*/
	des[32]   = ( src[9] + src[48] + src[84] + src[88] + src[102] + src[115] + src[126]) % 2;
	des[33]   = ( src[18] + src[29] + src[104] ) % 2;
	des[34]   = ( src[30] + src[34] + src[41] + src[47] + src[62] + src[108] + src[116]) % 2;
	des[35]   = ( src[7] + src[122] ) % 2;
	des[36]   = ( src[2] + src[13] + src[52] + src[88] + src[92] + src[106] + src[119]) % 2;
	des[37]   = ( src[22] + src[33] + src[108] ) % 2;
	des[38]   = ( src[34] + src[38] + src[45] + src[51] + src[66] + src[112] + src[120]) % 2;
	des[39]   = ( src[11] + src[126] ) % 2;

	des[40]   = ( src[6] + src[17] + src[56] + src[92] + src[96] + src[110] + src[123]) % 2;
	des[41]   = ( src[26] + src[37] + src[112] ) % 2;
	des[42]   = ( src[38] + src[42] + src[49] + src[55] + src[70] + src[116] + src[124]) % 2;
	des[43]   = ( src[2] + src[15] + src[76] ) % 2;
	des[44]   = ( src[10] + src[21] + src[60] + src[96] + src[100] + src[114] + src[127]) % 2;
	des[45]   = ( src[30] + src[41] + src[116] ) % 2;
	des[46]   = ( src[0] + src[42] + src[46] + src[53] + src[59] + src[74] + src[120]) % 2;
	des[47]   = ( src[6] + src[19] + src[80] ) % 2;

	/*
	** 第48-63位
	*/
	des[48]   = ( src[3] + src[14] + src[25] + src[100] + src[104] + src[118] ) % 2;
	des[49]   = ( src[34] + src[45] + src[120] ) % 2;
	des[50]   = ( src[4] + src[46] + src[50] + src[57] + src[63] + src[78] + src[124]) % 2;
	des[51]   = ( src[10] + src[23] + src[84] ) % 2;
	des[52]   = ( src[7] + src[18] + src[29] + src[104] + src[108] + src[122] ) % 2;
	des[53]   = ( src[38] + src[49] + src[124] ) % 2;
	des[54]   = ( src[0] + src[8] + src[50] + src[54] + src[61] + src[67] + src[82]) % 2;
	des[55]   = ( src[14] + src[27] + src[88] ) % 2;

	des[56]   = ( src[11] + src[22] + src[33] + src[108] + src[112] + src[126] ) % 2;
	des[57]   = ( src[0] + src[42] + src[53] ) % 2;
	des[58]   = ( src[4] + src[12] + src[54] + src[58] + src[65] + src[71] + src[86]) % 2;
	des[59]   = ( src[18] + src[31] + src[92] ) % 2;
	des[60]   = ( src[2] + src[15] + src[26] + src[37] + src[76] + src[112] + src[116]) % 2;
	des[61]   = ( src[4] + src[46] + src[57] ) % 2;
	des[62]   = ( src[8] + src[16] + src[58] + src[62] + src[69] + src[75] + src[90]) % 2;
	des[63]   = ( src[22] + src[35] + src[96] ) % 2;

	/*
	** 第64-79位
	*/
	des[64]   = ( src[6] + src[19] + src[30] + src[41] + src[80] + src[116] + src[120]) % 2;
	des[65]   = ( src[8] + src[50] + src[61] ) % 2;
	des[66]   = ( src[12] + src[20] + src[62] + src[66] + src[73] + src[79] + src[94]) % 2;
	des[67]   = ( src[26] + src[39] + src[100] ) % 2;
	des[68]   = ( src[10] + src[23] + src[34] + src[45] + src[84] + src[120] + src[124]) % 2;
	des[69]   = ( src[12] + src[54] + src[65] ) % 2;
	des[70]   = ( src[16] + src[24] + src[66] + src[70] + src[77] + src[83] + src[98]) % 2;
	des[71]   = ( src[30] + src[43] + src[104] ) % 2;

	des[72]   = ( src[0] + src[14] + src[27] + src[38] + src[49] + src[88] + src[124]) % 2;
	des[73]   = ( src[16] + src[58] + src[69] ) % 2;
	des[74]   = ( src[20] + src[28] + src[70] + src[74] + src[81] + src[87] + src[102]) % 2;
	des[75]   = ( src[34] + src[47] + src[108] ) % 2;
	des[76]   = ( src[0] + src[4] + src[18] + src[31] + src[42] + src[53] + src[92]) % 2;
	des[77]   = ( src[20] + src[62] + src[73] ) % 2;
	des[78]   = ( src[24] + src[32] + src[74] + src[78] + src[85] + src[91] + src[106]) % 2;
	des[79]   = ( src[38] + src[51] + src[112] ) % 2;

	/*
	** 第80-95位
	*/
	des[80]   = ( src[4] + src[8] + src[22] + src[35] + src[46] + src[57] + src[96]) % 2;
	des[81]   = ( src[24] + src[66] + src[77] ) % 2;
	des[82]   = ( src[28] + src[36] + src[78] + src[82] + src[89] + src[95] + src[110]) % 2;
	des[83]   = ( src[42] + src[55] + src[116] ) % 2;
	des[84]   = ( src[8] + src[12] + src[26] + src[39] + src[50] + src[61] + src[100]) % 2;
	des[85]   = ( src[28] + src[70] + src[81] ) % 2;
	des[86]   = ( src[32] + src[40] + src[82] + src[86] + src[93] + src[99] + src[114]) % 2;
	des[87]   = ( src[46] + src[59] + src[120] ) % 2;

	des[88]   = ( src[12] + src[16] + src[30] + src[43] + src[54] + src[65] + src[104]) % 2;
	des[89]   = ( src[32] + src[74] + src[85] ) % 2;
	des[90]   = ( src[36] + src[90] + src[103] + src[118] ) % 2;
	des[91]   = ( src[50] + src[63] + src[124] ) % 2;
	des[92]   = ( src[16] + src[20] + src[34] + src[47] + src[58] + src[69] + src[108]) % 2;
	des[93]   = ( src[36] + src[78] + src[89] ) % 2;
	des[94]   = ( src[40] + src[94] + src[107] + src[122] ) % 2;
	des[95]   = ( src[0] + src[54] + src[67] ) % 2;

	/*
	** 第96-111位
	*/
	des[96]   = ( src[20] + src[24] + src[38] + src[51] + src[62] + src[73] + src[112]) % 2;
	des[97]   = ( src[40] + src[82] + src[93] ) % 2;
	des[98]   = ( src[44] + src[98] + src[111] + src[126] ) % 2;
	des[99]   = ( src[4] + src[58] + src[71] ) % 2;
	des[100]   = ( src[24] + src[28] + src[42] + src[55] + src[66] + src[77] + src[116]) % 2;
	des[101]   = ( src[44] + src[86] + src[97] ) % 2;
	des[102]   = ( src[2] + src[48] + src[102] + src[115] ) % 2;
	des[103]   = ( src[8] + src[62] + src[75] ) % 2;

	des[104]   = ( src[28] + src[32] + src[46] + src[59] + src[70] + src[81] + src[120]) % 2;
	des[105]   = ( src[48] + src[90] + src[101] ) % 2;
	des[106]   = ( src[6] + src[52] + src[106] + src[119] ) % 2;
	des[107]   = ( src[12] + src[66] + src[79] ) % 2;
	des[108]   = ( src[32] + src[36] + src[50] + src[63] + src[74] + src[85] + src[124]) % 2;
	des[109]   = ( src[52] + src[94] + src[105] ) % 2;
	des[110]   = ( src[10] + src[56] + src[110] + src[123] ) % 2;
	des[111]   = ( src[16] + src[70] + src[83] ) % 2;

	/*
	** 第112-127位
	*/
	des[112]   = ( src[0] + src[36] + src[40] + src[54] + src[67] + src[78] + src[89]) % 2;
	des[113]   = ( src[56] + src[98] + src[109] ) % 2;
	des[114]   = ( src[14] + src[60] + src[114] + src[127] ) % 2;
	des[115]   = ( src[20] + src[74] + src[87] ) % 2;
	des[116]   = ( src[4] + src[40] + src[44] + src[58] + src[71] + src[82] + src[93]) % 2;
	des[117]   = ( src[60] + src[102] + src[113] ) % 2;
	des[118]   = ( src[3] + src[18] + src[72] + src[114] + src[118] + src[125] ) % 2;
	des[119]   = ( src[24] + src[78] + src[91] ) % 2;

	des[120]   = ( src[8] + src[44] + src[48] + src[62] + src[75] + src[86] + src[97]) % 2;
	des[121]   = ( src[64] + src[106] + src[117] ) % 2;
	des[122]   = ( src[1] + src[7] + src[22] + src[76] + src[118] + src[122] ) % 2;
	des[123]   = ( src[28] + src[82] + src[95] ) % 2;
	des[124]   = ( src[12] + src[48] + src[52] + src[66] + src[79] + src[90] + src[101]) % 2;
	des[125]   = ( src[68] + src[110] + src[121] ) % 2;
	des[126]   = ( src[5] + src[11] + src[26] + src[80] + src[122] + src[126] ) % 2;
	des[127]   = ( src[32] + src[86] + src[99] ) % 2;

}

/*
** 线性逆变换
*/
void revTransfor ( const unsigned int *const src, unsigned int *des ) {

	/*
	** 第0-15位
	*/
	des[0]   = ( src[53] + src[55] + src[72] ) % 2;
	des[1]   = ( src[1] + src[5] + src[20] + src[90] ) % 2;
	des[2]   = ( src[15] + src[102] ) % 2;
	des[3]   = ( src[3] + src[31] + src[90] ) % 2;
	des[4]   = ( src[57] + src[59] + src[76] ) % 2;
	des[5]   = ( src[5] + src[9] + src[24] + src[94] ) % 2;
	des[6]   = ( src[19] + src[106] ) % 2;
	des[7]   = ( src[7] + src[35] + src[94] ) % 2;

	des[8]   = ( src[61] + src[63] + src[80] ) % 2;
	des[9]   = ( src[9] + src[13] + src[28] + src[98] ) % 2;
	des[10]  = ( src[23] + src[110] ) % 2;
	des[11]  = ( src[11] + src[39] + src[98] ) % 2;
	des[12]  = ( src[65] + src[67] + src[84] ) % 2;
	des[13]  = ( src[13] + src[17] + src[32] + src[102] ) % 2;
	des[14]  = ( src[27] + src[114] ) % 2;
	des[15]  = ( src[1] + src[3] + src[15] + src[20] + src[43] + src[102] ) % 2;

	/*
	** 第16-31位
	*/
	des[16]   = ( src[69] + src[71] + src[88] ) % 2;
	des[17]   = ( src[17] + src[21] + src[36] + src[106] ) % 2;
	des[18]   = ( src[1] + src[31] + src[118] ) % 2;
	des[19]   = ( src[5] + src[7] + src[19] + src[24] + src[47] + src[106] ) % 2;
	des[20]   = ( src[73] + src[75] + src[92] ) % 2;
	des[21]   = ( src[21] + src[25] + src[40] + src[110] ) % 2;
	des[22]   = ( src[5] + src[35] + src[122] ) % 2;
	des[23]   = ( src[9] + src[11] + src[23] + src[28] + src[51] + src[110] ) % 2;

	des[24]   = ( src[77] + src[79] + src[96] ) % 2;
	des[25]   = ( src[25] + src[29] + src[44] + src[114] ) % 2;
	des[26]   = ( src[9] + src[39] + src[126] ) % 2;
	des[27]   = ( src[13] + src[15] + src[27] + src[32] + src[55] + src[114]) % 2;
	des[28]   = ( src[81] + src[83] + src[100] ) % 2;
	des[29]   = ( src[1] + src[29] + src[33] + src[48] + src[118] ) % 2;
	des[30]   = ( src[2] + src[13] + src[43] ) % 2;
	des[31]   = ( src[1] + src[17] + src[19] + src[31] + src[36] + src[59] + src[118] ) % 2;

	/*
	** 第32-47位
	*/
	des[32]   = ( src[85] + src[87] + src[104] ) % 2;
	des[33]   = ( src[5] + src[33] + src[37] + src[52] + src[122] ) % 2;
	des[34]   = ( src[6] + src[17] + src[47] ) % 2;
	des[35]   = ( src[5] + src[21] + src[23] + src[35] + src[40] + src[63] + src[122] ) % 2;
	des[36]   = ( src[89] + src[91] + src[108] ) % 2;
	des[37]   = ( src[9] + src[37] + src[41] + src[56] + src[126] ) % 2;
	des[38]   = ( src[10] + src[21] + src[51] ) % 2;
	des[39]   = ( src[9] + src[25] + src[27] + src[39] + src[44] + src[67] + src[126] ) % 2;

	des[40]   = ( src[93] + src[95] + src[112] ) % 2;
	des[41]   = ( src[2] + src[13] + src[41] + src[45] + src[60] ) % 2;
	des[42]   = ( src[14] + src[25] + src[55] ) % 2;
	des[43]   = ( src[2] + src[13] + src[29] + src[31] + src[43] + src[48] + src[71] ) % 2;
	des[44]   = ( src[97] + src[99] + src[116] ) % 2;
	des[45]   = ( src[6] + src[17] + src[45] + src[49] + src[64] ) % 2;
	des[46]   = ( src[18] + src[29] + src[59] ) % 2;
	des[47]   = ( src[6] + src[17] + src[33] + src[35] + src[47] + src[52] + src[75] ) % 2;

	/*
	** 第48-63位
	*/
	des[48]   = ( src[101] + src[103] + src[120] ) % 2;
	des[49]   = ( src[10] + src[21] + src[49] + src[53] + src[68] ) % 2;
	des[50]   = ( src[22] + src[33] + src[63] ) % 2;
	des[51]   = ( src[10] + src[21] + src[37] + src[39] + src[51] + src[56] + src[79] ) % 2;
	des[52]   = ( src[105] + src[107] + src[124] ) % 2;
	des[53]   = ( src[14] + src[25] + src[53] + src[57] + src[72] ) % 2;
	des[54]   = ( src[26] + src[37] + src[67] ) % 2;
	des[55]   = ( src[14] + src[25] + src[41] + src[43] + src[55] + src[60] + src[83] ) % 2;

	des[56]   = ( src[0] + src[109] + src[111] ) % 2;
	des[57]   = ( src[18] + src[29] + src[57] + src[61] + src[76] ) % 2;
	des[58]   = ( src[30] + src[41] + src[71] ) % 2;
	des[59]   = ( src[18] + src[29] + src[45] + src[47] + src[59] + src[64] + src[87] ) % 2;
	des[60]   = ( src[4] + src[113] + src[115] ) % 2;
	des[61]   = ( src[22] + src[33] + src[61] + src[65] + src[80] ) % 2;
	des[62]   = ( src[34] + src[45] + src[75] ) % 2;
	des[63]   = ( src[22] + src[33] + src[49] + src[51] + src[63] + src[68] + src[91] ) % 2;

	/*
	** 第64-79位
	*/
	des[64]   = ( src[8] + src[117] + src[119] ) % 2;
	des[65]   = ( src[26] + src[37] + src[65] + src[69] + src[84] ) % 2;
	des[66]   = ( src[38] + src[49] + src[79] ) % 2;
	des[67]   = ( src[26] + src[37] + src[53] + src[55] + src[67] + src[72] + src[95] ) % 2;
	des[68]   = ( src[12] + src[121] + src[123] ) % 2;
	des[69]   = ( src[30] + src[41] + src[69] + src[73] + src[88] ) % 2;
	des[70]   = ( src[42] + src[53] + src[83] ) % 2;
	des[71]   = ( src[30] + src[41] + src[57] + src[59] + src[71] + src[76] + src[99] ) % 2;

	des[72]   = ( src[16] + src[125] + src[127] ) % 2;
	des[73]   = ( src[34] + src[45] + src[73] + src[77] + src[92] ) % 2;
	des[74]   = ( src[46] + src[57] + src[87] ) % 2;
	des[75]   = ( src[34] + src[45] + src[61] + src[63] + src[75] + src[80] + src[103] ) % 2;
	des[76]   = ( src[1] + src[3] + src[20] ) % 2;
	des[77]   = ( src[38] + src[49] + src[77] + src[81] + src[96] ) % 2;
	des[78]   = ( src[50] + src[61] + src[91] ) % 2;
	des[79]   = ( src[38] + src[49] + src[65] + src[67] + src[79] + src[84] + src[107] ) % 2;

	/*
	** 第80-95位
	*/
	des[80]   = ( src[5] + src[7] + src[24] ) % 2;
	des[81]   = ( src[42] + src[53] + src[81] + src[85] + src[100] ) % 2;
	des[82]   = ( src[54] + src[65] + src[95] ) % 2;
	des[83]   = ( src[42] + src[53] + src[69] + src[71] + src[83] + src[88] + src[111] ) % 2;
	des[84]   = ( src[9] + src[11] + src[28] ) % 2;
	des[85]   = ( src[46] + src[57] + src[85] + src[89] + src[104] ) % 2;
	des[86]   = ( src[58] + src[69] + src[99] ) % 2;
	des[87]   = ( src[46] + src[57] + src[73] + src[75] + src[87] + src[92] + src[115] ) % 2;

	des[88]   = ( src[13] + src[15] + src[32] ) % 2;
	des[89]   = ( src[50] + src[61] + src[89] + src[93] + src[108] ) % 2;
	des[90]   = ( src[62] + src[73] + src[103] ) % 2;
	des[91]   = ( src[50] + src[61] + src[77] + src[79] + src[91] + src[96] + src[119] ) % 2;
	des[92]   = ( src[17] + src[19] + src[36] ) % 2;
	des[93]   = ( src[54] + src[65] + src[93] + src[97] + src[112] ) % 2;
	des[94]   = ( src[66] + src[77] + src[107] ) % 2;
	des[95]   = ( src[54] + src[65] + src[81] + src[83] + src[95] + src[100] + src[123] ) % 2;

	/*
	** 第96-111位
	*/
	des[96]   = ( src[21] + src[23] + src[40] ) % 2;
	des[97]   = ( src[58] + src[69] + src[97] + src[101] + src[116] ) % 2;
	des[98]   = ( src[70] + src[81] + src[111] ) % 2;
	des[99]   = ( src[58] + src[69] + src[85] + src[87] + src[99] + src[104] + src[127] ) % 2;
	des[100]   = ( src[25] + src[27] + src[44] ) % 2;
	des[101]   = ( src[62] + src[73] + src[101] + src[105] + src[120] ) % 2;
	des[102]   = ( src[74] + src[85] + src[115] ) % 2;
	des[103]   = ( src[3] + src[62] + src[73] + src[89] + src[91] + src[103] + src[108] ) % 2;

	des[104]   = ( src[29] + src[31] + src[48] ) % 2;
	des[105]   = ( src[66] + src[77] + src[105] + src[109] + src[124] ) % 2;
	des[106]   = ( src[78] + src[89] + src[119] ) % 2;
	des[107]   = ( src[7] + src[66] + src[77] + src[93] + src[95] + src[107] + src[112] ) % 2;
	des[108]   = ( src[33] + src[35] + src[52] ) % 2;
	des[109]   = ( src[0] + src[70] + src[81] + src[109] + src[113] ) % 2;
	des[110]   = ( src[82] + src[93] + src[123] ) % 2;
	des[111]   = ( src[11] + src[70] + src[81] + src[97] + src[99] + src[111] + src[116] ) % 2;

	/*
	** 第112-127位
	*/
	des[112]   = ( src[37] + src[39] + src[56] ) % 2;
	des[113]   = ( src[4] + src[74] + src[85] + src[113] + src[117] ) % 2;
	des[114]   = ( src[86] + src[97] + src[127] ) % 2;
	des[115]   = ( src[15] + src[74] + src[85] + src[101] + src[103] + src[115] + src[120] ) % 2;
	des[116]   = ( src[41] + src[43] + src[60] ) % 2;
	des[117]   = ( src[8] + src[78] + src[89] + src[117] + src[121] ) % 2;
	des[118]   = ( src[3] + src[90] ) % 2;
	des[119]   = ( src[19] + src[78] + src[89] + src[105] + src[107] + src[119] + src[124] ) % 2;

	des[120]   = ( src[45] + src[47] + src[64] ) % 2;
	des[121]   = ( src[12] + src[82] + src[93] + src[121] + src[125] ) % 2;
	des[122]   = ( src[7] + src[94] ) % 2;
	des[123]   = ( src[0] + src[23] + src[82] + src[93] + src[109] + src[111] + src[123] ) % 2;
	des[124]   = ( src[49] + src[51] + src[68] ) % 2;
	des[125]   = ( src[1] + src[16] + src[86] + src[97] + src[125] ) % 2;
	des[126]   = ( src[11] + src[98] ) % 2;
	des[127]   = ( src[4] + src[27] + src[86] + src[97] + src[113] + src[115] + src[127] ) % 2;

}