
#include<iostream>
#include"sbox.h"
#include"key.h"
#include"permutation.h"
#include"transformation.h"
using namespace std;

int rotateKeys[32][128];   // ���ܵ���Կ

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
	** ��ʼ�����û�
	*/
	initialPer ( input, output );    // �û�������ܵ����ݱ�����output�У���Ҫ����ת�Ƶ�input��
	for ( i = 0; i < length; i++ ) {
		input[i] = output[i];
	}
	/*
	** ǰ32����4��ѭ����ÿ��ѭ���ֱ���s3��s2��s1��s0��s7��s6��s5��s4����
	*/
	for ( int times = 0; times < 4; times++ ) {

		/*
		** s3
		** ��������ֱ���ɣ����S�С�����
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
	** ���˹�������32��ѭ������33��ѭ����ǰ�����в�ͬ
	** ����ѭ���ֱ���ɣ����S�С��û�
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
** input: �洢���Ǿ������ܺ�����ݣ�����������input�е����ݽ��н���
** output: ������ܺ������
** length: How many parameter are there is the array.
*/
void decrypt ( unsigned int input[], unsigned int output[], int length ) {
	
	int i = 0;
	int count = length/4;            // the input of S-box is 4 bits, so every time 4 bits are needed.
	int inputNumber, result;

	/*
	** �����ܲ����е�32�ֵ������
	** �û���S����任�����
	*/
	initialPer ( input, output );    // �û�������ܵ����ݱ�����output�У���Ҫ����ת�Ƶ�input��
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
	** ͨ��32�ֵ�S�����û�
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
	** �����û���Ӧ�����г�ʼ���û�
	*/
	finalPer( input, output );

}

int main () {

	int plaintext[16];    // ����
	int ciphertext[16];   // ����
	unsigned int input[128];      // ���Ķ�Ӧ��128��������λ
	unsigned int output[128];     // ���Ķ�Ӧ��128��������λ
	int key[256];         // ��Կ
	
	/*
	** ����Ҫ���ܵ����ݿ�
	*/
	int i = 0;
	int length = sizeof(plaintext)/sizeof(int);
	cout<<"Please input the "<<length<<" datas ([0,255]) to be encrypted��"<<endl;
	for ( i = 0; i < length; i++ ) {
		cin>>plaintext[i];
	}
	cout<<endl;
	
	/*
	** �������ǰ������
	*/
	cout<<"Before encryption, the input is:"<<endl;
	for ( i = 0; i < length; i++ ) {
		cout<<plaintext[i]<<" ";
	}
	cout<<endl<<endl;
	
	/*
	** ��16�ֽڵĴ���������ת����128λ�Ķ�����λ
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
	** ����256λ��Կ��Ϊ0
	*/
	for ( i = 0; i < sizeof(key)/sizeof(int); i++ ) {
		key[i] = 0;
	}

	/*
	** �õ������õ���ԿrotateKeys
	*/
	setKey( key, rotateKeys );

	/*
	** ����
	*/
	encrypt( input, output, length*8 );

	/*
	** �����ܺ��128Ϊ���ת��Ϊ16�ֽڵ����������ܺ�����ݱ�����input��
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
	** ������ܺ�Ľ��
	*/
	cout<<"After encrypt, the result is:"<<endl;
	for ( i = 0; i < length; i++ ) {
		cout<<ciphertext[i]<<" ";
	}
	cout<<endl<<endl;
	
	/*
	** ����
	** output��������ܺ������
	*/
	decrypt( input, output, length*8 );

	/*
	** �����ܺ��128Ϊ���ת��Ϊ16�ֽڵ����������ܺ�����ݱ�����output��
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
	** ������ܺ�Ľ��
	*/
	cout<<"After decrypt, the result is:"<<endl;
	for ( i = 0; i < length; i++ ) {
		cout<<plaintext[i]<<" ";
	}
	cout<<endl<<endl;
	
	
}