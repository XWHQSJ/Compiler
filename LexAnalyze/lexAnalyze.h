#ifndef LEXANALYZE_H
#define LEXANALYZE_H

#include <stdio.h>
#include <stdlib.h>

//���ʷ��ŵı���
#define $SYMBOL		1
#define $CONSTANT	2
#define $INT		3
#define $IF			4
#define $ELSE		5
#define $WHILE		6
#define $FOR		7
#define $READ		8
#define $WRITE		9
#define $ADD		10
#define $SUB		11
#define $MUL		12
#define $DIV		13
#define $L			14
#define $LE			15
#define $G			16
#define $GE			17
#define $NE			18
#define $E			19
#define $ASSIGN		20
#define $LPAR		21
#define $RPAR		22
#define $COM		23
#define $SEM		24

//�հ��ַ�
#define NUL		    0		//�հ׷�   '\0'
#define BS			8		//�˸�     '\b'
#define HT			9		//�����Ʊ� '\t'
#define LF			10		//����     '\n'
#define CR			13		//�س�     '\r'


const static int RESERVED_COUNT = 7;	//�ؼ�����
const static int LETTER_COUNT = 26;     //��ĸ��
const static int DIGIT_COUNT = 10;      //������


//��Ԫ���ṹ��
typedef struct Word_Struct
{
	int number;				//�ַ�����
	int position;			//�ַ�λ��
}WORDS;


//�ؼ��ֱ�
char *keyWords[RESERVED_COUNT] = { "int","if","else","while","for","read","write" };

//��ĸ��
char *letters[LETTER_COUNT] = { 'a','b','c','d','e','f','g','h','i','j','k','l',
									'm','n','o','p','q','r','s','t','u','v','w',
									'x','y','z','A','B','C','D','E','F','G','H',
									'I','J','K','L','M','N','O','P','Q','R','S',
									'U','V','W','X','Y','Z' };

//���ֱ�
char *digits[DIGIT_COUNT] = { '0','1','2','3','4','5','6','7','8','9};


//�ж��Ƿ�Ϊ��
bool is_space(char );

//����һ���ַ�����
void lex_getchar();

//����ǿհ��ַ�����
void lex_getnbc();

//�����ַ�������
void lex_concat();

//�ж���ĸ����
bool is_letter();

//�ж����ֺ���
bool is_digit();

//�����ַ�����
void lex_retract();

//�������ֺ���
int lex_reserve();

//�����ʶ������
int lex_symbol();

//�������볣������
int lex_constant();

//���ض�Ԫ������
WORDS word_return(int ,int );

//��������
void lex_error();

//�ʷ�����������
WORDS lexAnalyze(WORDS words);

#endif // !LEXANALYZE_H