
#include"key.h"
#include"sbox.h"

unsigned int getW ( unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int i);

/*
** 根据输入的密钥得到每轮用于加密的密钥
** inputKey（输入）：256位的密钥
** rotateKeys（输出）：每轮用于加密的密钥，共33轮（从0到32），每轮128位（下标小的表示低位，求异或时用到）
** 说明：只要加密和解密的密钥相同，则不用太在乎输入密钥生成轮密码时高低位的问题
*/
void setKey ( const int *const inputKey, int rotateKeys[][128] ) {

	//unsigned int prekey[8];

	/*
	** 132个32位的整数，用于构成rotateKeys
	** 加上最初的8个，正好是140个，放在一起便于循环
	*/
	unsigned int w[140];      

	/*
	** 将256位的输入密钥转化为8个32位的数
	*/
	for ( int i = 0; i < 8; i++ ) {
		w[i] = 0;
		for ( int j = 0; j < 32; j++ ) {
			w[i] = w[i]*2 + inputKey[i*32+j];
		}
	}

	/*
	** 得到了132个32位的数
	*/
	for ( unsigned int i = 8; i < 140; i++ ) {
		w[i] = getW( w[i-8], w[i-5], w[i-3], w[i-1], i);
	}

	/*
	** 生成每轮的密钥
	** {k0, k1, k2, k3} = s3(w0, w1, w2, w3)
	** {k4, k5, k6, k7} = s2(w4, w5, w6, w7)
	** ...
	** {k124, k125, k126, k127} = s4(w124, w125, w126, w127)
	** {k128, k129, k130, k131} = s3(w128, w129, w130, w131)
	** 在程序中w的前8个数用于保存初始输入密码，所以此处的w0对应程序中的w8，依次类推
	*/
	int j = 0;
	int result;
	// 每8轮后重新循环，最后一次单独处理
	for ( int i = 0; i < 4; i++ ) {

		/*
		** s3：分别取出一位得到输入x，0<=x<=15，通过s3得到输出y，0<=y<=15，再将y转化为4个二进制位
		** 第0轮、第8轮、第16轮、第24轮
		*/
		for ( j = 0; j < 32; j++ ) {
			result = s3(w[i*32+8]%2 + w[i*32+9]%2*2 + w[i*32+10]%2*4 + w[i*32+11]%2*8);
			w[i*32+8] /= 2;
			w[i*32+9] /= 2;
			w[i*32+10] /= 2;
			w[i*32+11] /= 2;
			rotateKeys[i*8+0][j] = result % 2;
			result = result / 2;
			rotateKeys[i*8+0][j+32] = result % 2;
			result = result / 2;
			rotateKeys[i*8+0][j+64] = result % 2;
			result = result / 2;
			rotateKeys[i*8+0][j+96] = result % 2;
		}

		/*
		** s2
		** 第1轮、第9轮、第17轮、第25轮
		*/
		for ( j = 0; j < 32; j++ ) {
			result = s2(w[i*32+12]%2 + w[i*32+13]%2*2 + w[i*32+14]%2*4 + w[i*32+15]%2*8);
			w[i*32+12] /= 2;
			w[i*32+13] /= 2;
			w[i*32+14] /= 2;
			w[i*32+15] /= 2;
			rotateKeys[i*8+1][j] = result % 2;
			result = result / 2;
			rotateKeys[i*8+1][j+32] = result % 2;
			result = result / 2;
			rotateKeys[i*8+1][j+64] = result % 2;
			result = result / 2;
			rotateKeys[i*8+1][j+96] = result % 2;
		}

		/*
		** s1
		** 第2轮、第10轮、第18轮、第26轮
		**/
		for ( j = 0; j < 32; j++ ) {
			result = s1(w[i*32+16]%2 + w[i*32+17]%2*2 + w[i*32+18]%2*4 + w[i*32+19]%2*8);
			w[i*32+16] /= 2;
			w[i*32+17] /= 2;
			w[i*32+18] /= 2;
			w[i*32+19] /= 2;
			rotateKeys[i*8+2][j] = result % 2;
			result = result / 2;
			rotateKeys[i*8+2][j+32] = result % 2;
			result = result / 2;
			rotateKeys[i*8+2][j+64] = result % 2;
			result = result / 2;
			rotateKeys[i*8+2][j+96] = result % 2;
		}
		
		/*
		** s0
		** 第3轮、第11轮、第19轮、第27轮
		**/
		for ( j = 0; j < 32; j++ ) {
			result = s0(w[i*32+20]%2 + w[i*32+21]%2*2 + w[i*32+22]%2*4 + w[i*32+23]%2*8);
			w[i*32+20] /= 2;
			w[i*32+21] /= 2;
			w[i*32+22] /= 2;
			w[i*32+23] /= 2;
			rotateKeys[i*8+3][j] = result % 2;
			result = result / 2;
			rotateKeys[i*8+3][j+32] = result % 2;
			result = result / 2;
			rotateKeys[i*8+3][j+64] = result % 2;
			result = result / 2;
			rotateKeys[i*8+3][j+96] = result % 2;
		}

		/*
		** s7
		** 第4轮、第12轮、第20轮、第28轮
		**/
		for ( j = 0; j < 32; j++ ) {
			result = s7(w[i*32+24]%2 + w[i*32+25]%2*2 + w[i*32+26]%2*4 + w[i*32+27]%2*8);
			w[i*32+24] /= 2;
			w[i*32+25] /= 2;
			w[i*32+26] /= 2;
			w[i*32+27] /= 2;
			rotateKeys[i*8+4][j] = result % 2;
			result = result / 2;
			rotateKeys[i*8+4][j+32] = result % 2;
			result = result / 2;
			rotateKeys[i*8+4][j+64] = result % 2;
			result = result / 2;
			rotateKeys[i*8+4][j+96] = result % 2;
		}

		/*
		** s6
		** 第5轮、第13轮、第21轮、第29轮
		**/
		for ( j = 0; j < 32; j++ ) {
			result = s6(w[i*32+28]%2 + w[i*32+29]%2*2 + w[i*32+30]%2*4 + w[i*32+31]%2*8);
			w[i*32+28] /= 2;
			w[i*32+29] /= 2;
			w[i*32+30] /= 2;
			w[i*32+31] /= 2;
			rotateKeys[i*8+5][j] = result % 2;
			result = result / 2;
			rotateKeys[i*8+5][j+32] = result % 2;
			result = result / 2;
			rotateKeys[i*8+5][j+64] = result % 2;
			result = result / 2;
			rotateKeys[i*8+5][j+96] = result % 2;
		}

		/*
		** s5
		** 第6轮、第14轮、第22轮、第30轮
		**/
		for ( j = 0; j < 32; j++ ) {
			result = s5(w[i*32+32]%2 + w[i*32+33]%2*2 + w[i*32+34]%2*4 + w[i*32+35]%2*8);
			w[i*32+32] /= 2;
			w[i*32+33] /= 2;
			w[i*32+34] /= 2;
			w[i*32+35] /= 2;
			rotateKeys[i*8+6][j] = result % 2;
			result = result / 2;
			rotateKeys[i*8+6][j+32] = result % 2;
			result = result / 2;
			rotateKeys[i*8+6][j+64] = result % 2;
			result = result / 2;
			rotateKeys[i*8+6][j+96] = result % 2;
		}
		
		/*
		** s4
		** 第7轮、第15轮、第23轮、第31轮
		**/
		for ( j = 0; j < 32; j++ ) {
			result = s4(w[i*32+36]%2 + w[i*32+37]%2*2 + w[i*32+38]%2*4 + w[i*32+39]%2*8);
			w[i*32+36] /= 2;
			w[i*32+37] /= 2;
			w[i*32+38] /= 2;
			w[i*32+39] /= 2;
			rotateKeys[i*8+7][j] = result % 2;
			result = result / 2;
			rotateKeys[i*8+7][j+32] = result % 2;
			result = result / 2;
			rotateKeys[i*8+7][j+64] = result % 2;
			result = result / 2;
			rotateKeys[i*8+7][j+96] = result % 2;
		}

	}

	/*
	** s3
	** 第32轮
	**/
	for ( j = 0; j < 32; j++ ) {
		result = s5(w[136]%2 + w[137]%2*2 + w[138]%2*4 + w[139]%2*8);
		w[136] /= 2;
		w[137] /= 2;
		w[138] /= 2;
		w[139] /= 2;
		rotateKeys[32][j] = result % 2;
		result = result / 2;
		rotateKeys[32][j+32] = result % 2;
		result = result / 2;
		rotateKeys[32][j+64] = result % 2;
		result = result / 2;
		rotateKeys[32][j+96] = result % 2;
	}

}

/*
** 根据前面的数得到每一个32位的数，用于构成33个128位的密码
*/
unsigned int getW ( unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int i) {

	/*
	** 返回的结果是a、b、c、d、i、和0x9e3779b9求异或的结果
	** 0x9e3779b9 = 1001 1110 0011 0111 0111 1001 1011 1001
	*/
	unsigned int result = 0;
	unsigned int CON = 0x9e3779b9;
	unsigned int bits[32];

	/*
	** 求异或的结果：注意顺序（将一个十进制整数转化为二进制数：除2取余，直至结果为0，再逆序）
	*/
	for ( int count = 31; count >= 0; count-- ) {
		// (a%2 + b%2 + c%2 + d%2 + CON%2 + i%2)%2得到的是一位求异或的结果
		bits[count] = (a%2 + b%2 + c%2 + d%2 + CON%2 + i%2)%2;
		a = a/2;
		b = b/2;
		c = c/2;
		d = d/2;
		i = i/2;
	}

	/*
	** 循环左移11位
	*/
	unsigned int shifting[32];
	for ( int count = 0; count < 32; count++ ) {
		shifting[count] = bits[(count+11)%32];
	}

	/*
	** 得到该32位二进制所表示的整数
	*/
	for ( int count = 0; count < 32; count++ ) {
		result = result * 2 + shifting[count];
	}

	return result;

}