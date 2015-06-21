
#include"key.h"
#include"sbox.h"

unsigned int getW ( unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int i);

/*
** �����������Կ�õ�ÿ�����ڼ��ܵ���Կ
** inputKey�����룩��256λ����Կ
** rotateKeys���������ÿ�����ڼ��ܵ���Կ����33�֣���0��32����ÿ��128λ���±�С�ı�ʾ��λ�������ʱ�õ���
** ˵����ֻҪ���ܺͽ��ܵ���Կ��ͬ������̫�ں�������Կ����������ʱ�ߵ�λ������
*/
void setKey ( const int *const inputKey, int rotateKeys[][128] ) {

	//unsigned int prekey[8];

	/*
	** 132��32λ�����������ڹ���rotateKeys
	** ���������8����������140��������һ�����ѭ��
	*/
	unsigned int w[140];      

	/*
	** ��256λ��������Կת��Ϊ8��32λ����
	*/
	for ( int i = 0; i < 8; i++ ) {
		w[i] = 0;
		for ( int j = 0; j < 32; j++ ) {
			w[i] = w[i]*2 + inputKey[i*32+j];
		}
	}

	/*
	** �õ���132��32λ����
	*/
	for ( unsigned int i = 8; i < 140; i++ ) {
		w[i] = getW( w[i-8], w[i-5], w[i-3], w[i-1], i);
	}

	/*
	** ����ÿ�ֵ���Կ
	** {k0, k1, k2, k3} = s3(w0, w1, w2, w3)
	** {k4, k5, k6, k7} = s2(w4, w5, w6, w7)
	** ...
	** {k124, k125, k126, k127} = s4(w124, w125, w126, w127)
	** {k128, k129, k130, k131} = s3(w128, w129, w130, w131)
	** �ڳ�����w��ǰ8�������ڱ����ʼ�������룬���Դ˴���w0��Ӧ�����е�w8����������
	*/
	int j = 0;
	int result;
	// ÿ8�ֺ�����ѭ�������һ�ε�������
	for ( int i = 0; i < 4; i++ ) {

		/*
		** s3���ֱ�ȡ��һλ�õ�����x��0<=x<=15��ͨ��s3�õ����y��0<=y<=15���ٽ�yת��Ϊ4��������λ
		** ��0�֡���8�֡���16�֡���24��
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
		** ��1�֡���9�֡���17�֡���25��
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
		** ��2�֡���10�֡���18�֡���26��
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
		** ��3�֡���11�֡���19�֡���27��
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
		** ��4�֡���12�֡���20�֡���28��
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
		** ��5�֡���13�֡���21�֡���29��
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
		** ��6�֡���14�֡���22�֡���30��
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
		** ��7�֡���15�֡���23�֡���31��
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
	** ��32��
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
** ����ǰ������õ�ÿһ��32λ���������ڹ���33��128λ������
*/
unsigned int getW ( unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int i) {

	/*
	** ���صĽ����a��b��c��d��i����0x9e3779b9�����Ľ��
	** 0x9e3779b9 = 1001 1110 0011 0111 0111 1001 1011 1001
	*/
	unsigned int result = 0;
	unsigned int CON = 0x9e3779b9;
	unsigned int bits[32];

	/*
	** �����Ľ����ע��˳�򣨽�һ��ʮ��������ת��Ϊ������������2ȡ�ֱ࣬�����Ϊ0��������
	*/
	for ( int count = 31; count >= 0; count-- ) {
		// (a%2 + b%2 + c%2 + d%2 + CON%2 + i%2)%2�õ�����һλ�����Ľ��
		bits[count] = (a%2 + b%2 + c%2 + d%2 + CON%2 + i%2)%2;
		a = a/2;
		b = b/2;
		c = c/2;
		d = d/2;
		i = i/2;
	}

	/*
	** ѭ������11λ
	*/
	unsigned int shifting[32];
	for ( int count = 0; count < 32; count++ ) {
		shifting[count] = bits[(count+11)%32];
	}

	/*
	** �õ���32λ����������ʾ������
	*/
	for ( int count = 0; count < 32; count++ ) {
		result = result * 2 + shifting[count];
	}

	return result;

}