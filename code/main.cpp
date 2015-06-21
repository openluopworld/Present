
#include<iostream>
#include"sbox.h"
#include"key.h"
#include"permutation.h"
#include"transformation.h"
using namespace std;

int rotateKeys[32][128];   // 加密的密钥

/*
** Encryption
** input: The input parameter stores the data that will be encrypted. Every char in the array is just 0 or 1 which
** is used to represent the bit 0 or 1.
** output: The output parameter stores the data that are encrypted.
** length: How many parameter are there is the array.
*/
void encrypt ( unsigned int input[], unsigned int output[], int length ) {
	
	int i = 0;
	int count = length/4;            // the input of S-box is 4 bits, so every time 4 bits are needed.
	int inputNumber, result;

	/*
	** 初始线性置换
	*/
	initialPer ( input, output );    // 置换后待加密的数据保存在output中，需要重新转移到input中
	for ( i = 0; i < length; i++ ) {
		input[i] = output[i];
	}
	/*
	** 前32轮是4次循环，每次循环分别用s3、s2、s1、s0、s7、s6、s5、s4加密
	*/
	for ( int times = 0; times < 4; times++ ) {

		/*
		** s3
		** 三个语句块分别完成：异或、S盒、变形
		*/
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[times*8+0][i])%2;
		}
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( input[i] + input[i+count]*2 + input[i+count*2]*4 + input[i+count*3]*8);
			result = s3(inputNumber);
			output[i] = result%2;
			result = result/2;
			output[i+count] = result%2;
			result = result/2;
			output[i+count*2] = result%2;
			result = result/2;
			output[i+count*3] = result%2;
		}
		transfor( output, input );

		/*
		** s2
		*/
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[times*8+1][i])%2;
		}
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( input[i] + input[i+count]*2 + input[i+count*2]*4 + input[i+count*3]*8);
			result = s2(inputNumber);
			output[i] = result%2;
			result = result/2;
			output[i+count] = result%2;
			result = result/2;
			output[i+count*2] = result%2;
			result = result/2;
			output[i+count*3] = result%2;
		}
		transfor( output, input );

		/*
		** s1
		*/
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[times*8+2][i])%2;
		}
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( input[i] + input[i+count]*2 + input[i+count*2]*4 + input[i+count*3]*8);
			result = s1(inputNumber);
			output[i] = result%2;
			result = result/2;
			output[i+count] = result%2;
			result = result/2;
			output[i+count*2] = result%2;
			result = result/2;
			output[i+count*3] = result%2;
		}
		transfor( output, input );

		/*
		** s0
		*/
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[times*8+3][i])%2;
		}
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( input[i] + input[i+count]*2 + input[i+count*2]*4 + input[i+count*3]*8);
			result = s0(inputNumber);
			output[i] = result%2;
			result = result/2;
			output[i+count] = result%2;
			result = result/2;
			output[i+count*2] = result%2;
			result = result/2;
			output[i+count*3] = result%2;
		}
		transfor( output, input );

		/*
		** s7
		*/
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[times*8+4][i])%2;
		}
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( input[i] + input[i+count]*2 + input[i+count*2]*4 + input[i+count*3]*8);
			result = s7(inputNumber);
			output[i] = result%2;
			result = result/2;
			output[i+count] = result%2;
			result = result/2;
			output[i+count*2] = result%2;
			result = result/2;
			output[i+count*3] = result%2;
	
		}
		transfor( output, input );

		/*
		** s6
		*/
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[times*8+5][i])%2;
		}
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( input[i] + input[i+count]*2 + input[i+count*2]*4 + input[i+count*3]*8);
			result = s6(inputNumber);
			output[i] = result%2;
			result = result/2;
			output[i+count] = result%2;
			result = result/2;
			output[i+count*2] = result%2;
			result = result/2;
			output[i+count*3] = result%2;
		}
		transfor( output, input );

		/*
		** s5
		*/
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[times*8+6][i])%2;
		}
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( input[i] + input[i+count]*2 + input[i+count*2]*4 + input[i+count*3]*8);
			result = s5(inputNumber);
			output[i] = result%2;
			result = result/2;
			output[i+count] = result%2;
			result = result/2;
			output[i+count*2] = result%2;
			result = result/2;
			output[i+count*3] = result%2;
	
		}
		transfor( output, input );

		/*
		** s4
		*/
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[times*8+7][i])%2;
		}
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( input[i] + input[i+count]*2 + input[i+count*2]*4 + input[i+count*3]*8);
			result = s4(inputNumber);
			output[i] = result%2;
			result = result/2;
			output[i+count] = result%2;
			result = result/2;
			output[i+count*2] = result%2;
			result = result/2;
			output[i+count*3] = result%2;
		}
		transfor( output, input );

	}

	/*
	** 至此共进行了32轮循环，第33轮循环与前面稍有不同
	** 三次循环分别完成：异或、S盒、置换
	*/
	for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[32][i])%2;
	}
	for ( i = 0; i < count; i++ ) {
		inputNumber = ( input[i] + input[i+count]*2 + input[i+count*2]*4 + input[i+count*3]*8);
		result = s3(inputNumber);
		output[i] = result%2;
		result = result/2;
		output[i+count] = result%2;
		result = result/2;
		output[i+count*2] = result%2;
		result = result/2;
		output[i+count*3] = result%2;
	}
	finalPer( output, input );
	
}


/*
** Decryption
** input: 存储的是经过加密后的数据，本方法将对input中的内容进行解密
** output: 保存解密后的数据
** length: How many parameter are there is the array.
*/
void decrypt ( unsigned int input[], unsigned int output[], int length ) {
	
	int i = 0;
	int count = length/4;            // the input of S-box is 4 bits, so every time 4 bits are needed.
	int inputNumber, result;

	/*
	** 做加密操作中第32轮的逆操作
	** 置换，S盒逆变换，异或
	*/
	initialPer ( input, output );    // 置换后待加密的数据保存在output中，需要重新转移到input中
	for ( i = 0; i < length; i++ ) {
		input[i] = output[i];
	}
	for ( i = 0; i < count; i++ ) {
		inputNumber = ( input[i] + input[i+count]*2 + input[i+count*2]*4 + input[i+count*3]*8);
		result = is3(inputNumber);
		output[i] = result%2;
		result = result/2;
		output[i+count] = result%2;
		result = result/2;
		output[i+count*2] = result%2;
		result = result/2;
		output[i+count*3] = result%2;
	}
	for ( i = 0; i < length; i++ ) {
		input[i] = (output[i] + rotateKeys[32][i])%2;
	}

	/*
	** 通过32轮的S盒逆置换
	*/
	for ( int times = 0; times < 4; times++ ) {

		/*
		** is4
		*/
		revTransfor( input, output );
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( output[i] + output[i+count]*2 + output[i+count*2]*4 + output[i+count*3]*8);
			result = is4(inputNumber);
			input[i] = result%2;
			result = result/2;
			input[i+count] = result%2;
			result = result/2;
			input[i+count*2] = result%2;
			result = result/2;
			input[i+count*3] = result%2;
		}
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[31-times*8][i])%2;
		}

		/*
		** is5
		*/
		revTransfor( input, output );
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( output[i] + output[i+count]*2 + output[i+count*2]*4 + output[i+count*3]*8);
			result = is5(inputNumber);
			input[i] = result%2;
			result = result/2;
			input[i+count] = result%2;
			result = result/2;
			input[i+count*2] = result%2;
			result = result/2;
			input[i+count*3] = result%2;
		}
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[30-times*8][i])%2;
		}

		/*
		** is6
		*/
		revTransfor( input, output );
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( output[i] + output[i+count]*2 + output[i+count*2]*4 + output[i+count*3]*8);
			result = is6(inputNumber);
			input[i] = result%2;
			result = result/2;
			input[i+count] = result%2;
			result = result/2;
			input[i+count*2] = result%2;
			result = result/2;
			input[i+count*3] = result%2;
		}
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[29-times*8][i])%2;
		}

		/*
		** is7
		*/
		revTransfor( input, output );
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( output[i] + output[i+count]*2 + output[i+count*2]*4 + output[i+count*3]*8);
			result = is7(inputNumber);
			input[i] = result%2;
			result = result/2;
			input[i+count] = result%2;
			result = result/2;
			input[i+count*2] = result%2;
			result = result/2;
			input[i+count*3] = result%2;
		}
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[28-times*8][i])%2;
		}

		/*
		** is0
		*/
		revTransfor( input, output );
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( output[i] + output[i+count]*2 + output[i+count*2]*4 + output[i+count*3]*8);
			result = is0(inputNumber);
			input[i] = result%2;
			result = result/2;
			input[i+count] = result%2;
			result = result/2;
			input[i+count*2] = result%2;
			result = result/2;
			input[i+count*3] = result%2;
		}
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[27-times*8][i])%2;
		}

		/*
		** is1
		*/
		revTransfor( input, output );
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( output[i] + output[i+count]*2 + output[i+count*2]*4 + output[i+count*3]*8);
			result = is1(inputNumber);
			input[i] = result%2;
			result = result/2;
			input[i+count] = result%2;
			result = result/2;
			input[i+count*2] = result%2;
			result = result/2;
			input[i+count*3] = result%2;
		}for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[26-times*8][i])%2;
		}


		/*
		** is2
		*/
		revTransfor( input, output );
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( output[i] + output[i+count]*2 + output[i+count*2]*4 + output[i+count*3]*8);
			result = is2(inputNumber);
			input[i] = result%2;
			result = result/2;
			input[i+count] = result%2;
			result = result/2;
			input[i+count*2] = result%2;
			result = result/2;
			input[i+count*3] = result%2;
		}
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[25-times*8][i])%2;
		}

		/*
		** is3
		*/
		revTransfor( input, output );
		for ( i = 0; i < count; i++ ) {
			inputNumber = ( output[i] + output[i+count]*2 + output[i+count*2]*4 + output[i+count*3]*8);
			result = is3(inputNumber);
			input[i] = result%2;
			result = result/2;
			input[i+count] = result%2;
			result = result/2;
			input[i+count*2] = result%2;
			result = result/2;
			input[i+count*3] = result%2;
		}
		for ( i = 0; i < length; i++ ) {
			input[i] = (input[i] + rotateKeys[24-times*8][i])%2;
		}

	}

	/*
	** 最后的置换对应加密中初始的置换
	*/
	finalPer( input, output );

}

int main () {

	int plaintext[16];    // 明文
	int ciphertext[16];   // 密文
	unsigned int input[128];      // 明文对应的128个二进制位
	unsigned int output[128];     // 密文对应的128个二进制位
	int key[256];         // 密钥
	
	/*
	** 输入要加密的数据块
	*/
	int i = 0;
	int length = sizeof(plaintext)/sizeof(int);
	cout<<"Please input the "<<length<<" datas ([0,255]) to be encrypted："<<endl;
	for ( i = 0; i < length; i++ ) {
		cin>>plaintext[i];
	}
	cout<<endl;
	
	/*
	** 输出加密前的数据
	*/
	cout<<"Before encryption, the input is:"<<endl;
	for ( i = 0; i < length; i++ ) {
		cout<<plaintext[i]<<" ";
	}
	cout<<endl<<endl;
	
	/*
	** 将16字节的待加密数据转换成128位的二进制位
	*/
	for ( i = 0; i < length; i++ ) {
		input[i*8+7] = plaintext[i] % 2;
		plaintext[i] = plaintext[i] / 2;
		input[i*8+6] = plaintext[i] % 2;
		plaintext[i] = plaintext[i] / 2;
		input[i*8+5] = plaintext[i] % 2;
		plaintext[i] = plaintext[i] / 2;
		input[i*8+4] = plaintext[i] % 2;
		plaintext[i] = plaintext[i] / 2;
		input[i*8+3] = plaintext[i] % 2;
		plaintext[i] = plaintext[i] / 2;
		input[i*8+2] = plaintext[i] % 2;
		plaintext[i] = plaintext[i] / 2;
		input[i*8+1] = plaintext[i] % 2;
		plaintext[i] = plaintext[i] / 2;
		input[i*8+0] = plaintext[i] % 2;
	}

	/*
	** 假设256位密钥都为0
	*/
	for ( i = 0; i < sizeof(key)/sizeof(int); i++ ) {
		key[i] = 0;
	}

	/*
	** 得到加密用的密钥rotateKeys
	*/
	setKey( key, rotateKeys );

	/*
	** 加密
	*/
	encrypt( input, output, length*8 );

	/*
	** 将加密后的128为输出转换为16字节的整数，加密后的数据保存在input中
	*/
	for ( i = 0; i < length; i++ ) {
		ciphertext[i] = input[i*8+7] +
						input[i*8+6]*2 +
						input[i*8+5]*4 +
						input[i*8+4]*8 +
						input[i*8+3]*16 +
						input[i*8+2]*32 +
						input[i*8+1]*64 +
						input[i*8+0]*128;
	}

	/*
	** 输出加密后的结果
	*/
	cout<<"After encrypt, the result is:"<<endl;
	for ( i = 0; i < length; i++ ) {
		cout<<ciphertext[i]<<" ";
	}
	cout<<endl<<endl;
	
	/*
	** 解密
	** output：保存解密后的数据
	*/
	decrypt( input, output, length*8 );

	/*
	** 将解密后的128为输出转换为16字节的整数，解密后的数据保存在output中
	*/
	for ( i = 0; i < length; i++ ) {
		plaintext[i] = output[i*8+7] +
						output[i*8+6]*2 +
						output[i*8+5]*4 +
						output[i*8+4]*8 +
						output[i*8+3]*16 +
						output[i*8+2]*32 +
						output[i*8+1]*64 +
						output[i*8+0]*128;
	}

	/*
	** 输出解密后的结果
	*/
	cout<<"After decrypt, the result is:"<<endl;
	for ( i = 0; i < length; i++ ) {
		cout<<plaintext[i]<<" ";
	}
	cout<<endl<<endl;
	
	
}