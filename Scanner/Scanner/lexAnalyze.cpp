#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexAnalyze.h"

//ȫ���ַ���������������ַ�
char character;

//ȫ���ַ����飬��Ŷ�����ַ����У�ֻ��ͬһ��������
char token[25];

//ȫ���ļ�ָ�룬�������ݶ��롢����������
FILE *fp;
FILE *fp_out;
FILE *fp_err;

//��������i
unsigned int i;

//��������
int row_num = 1;

//�ؼ��ֱ���Ӧ���Ƿ���
char *keyWord[RESERVE_COUNT] = { "begin","end","integer","if","then",
								 "else","function","read","write" };

//��ȡ�ַ�����
int lex_getchar()
{
	if ((character = getc(fp)) != EOF)
	{
		return TRUE;
	}

	return FALSE;
}


//��ȡ�ǿ��ַ���
void lex_getnbc()
{
	while (character == ' '  ||
		   character == '\t' ||
		   character == 'LF' ||
		   character == 'CR')
	{
		character = getc(fp);
	}
}


//�����ַ�Ϊ�ַ���
void lex_concat()
{
	token[i] = character;
	i++;
}


//�ж��ַ�Ϊ��ĸ
int lex_letter()
{
	if ((character >= 'a' && character <= 'z') ||
		(character >= 'A' && character <= 'Z'))
	{
		return TRUE;
	}

	return FALSE;
}


//�ж��ַ�Ϊ����
int lex_digit()
{
	if (character >= '0' && character <= '9')
	{
		return TRUE;
	}

	return FALSE;
}


//��ؼ��ֱ�
int lex_reserve()
{
	int k;
	for (k = 0; k < RESERVE_COUNT; k++)
	{
		if (strcmp(keyWord[k], token) == 0)
		{
			return (k + 1);
		}
	}

	return 0;
}


//�˻��ַ����ֽ���
void lex_retract()
{
	ungetc(character, fp);
}


//����ֵ��ӡ
void lex_return(char *word_ch,int type,FILE *stream)
{
	printf("%s		%d\n", word_ch, type);
	fprintf(stream, "%s		%d\n", word_ch, type);
	fflush(stream);
}


//������
void lex_error(FILE *stream)
{
	fprintf(stream, "***LINE: %d  ", row_num);
	fprintf(stream, "'%c' is illegal!\n", token[0]);
	//printf("***LINE: %d  '%c' is illegal!\n", row_num, token[0]);
}


//�ʷ�����
int lexAnalyze()
{
	memset(token, 0, sizeof(token));
	int num;

	i = 0;

	if (lex_getchar() == FALSE)
	{
		return FALSE;
	}
	lex_getnbc();

	if (character == -1)
	{
		return FALSE;
	}

	
	switch (character)
	{
	case'a':
	case'b':
	case'c':
	case'd':
	case'e':
	case'f':
	case'g':
	case'h':
	case'i':
	case'j':
	case'k':
	case'l':
	case'm':
	case'n':
	case'o':
	case'p':
	case'q':
	case'r':
	case's':
	case't':
	case'u':
	case'v':
	case'w':
	case'x':
	case'y':
	case'z':
		while (lex_letter() || lex_digit())
		{
			lex_concat();
			lex_getchar();
		}

		lex_retract();
		num = lex_reserve();

		if (num != 0)
		{
			lex_return(token, num, fp_out);
		}
		else
		{
			lex_return(token, $SYMBOL, fp_out);
		}
		break;

	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		while (lex_digit())
		{
			lex_concat();
			lex_getchar();
		}
		
		lex_retract();

		lex_return(token, $CONSTANT, fp_out);
		break;
	case '<':
		lex_concat();
		lex_getchar();
		if (character == '=')
		{
			lex_concat();
			lex_return(token, $LE, fp_out);
		}
		else if (character == '>')
		{
			lex_concat();
			lex_return(token, $LG, fp_out);
		}
		else
		{
			lex_retract();
			lex_return(token, $L, fp_out);
		}
		break;
	case '>':
		lex_concat();
		lex_getchar();

		if (character == '=')
		{
			lex_concat();
			lex_return(token, $GE, fp_out);
		}
		else
		{
			lex_retract();
			lex_return(token, $G, fp_out);
		}
		break;
	case '=':
		lex_concat();
		lex_return(token, $E, fp_out);
		break;
	case ':':
		lex_concat();
		lex_getchar();
		if (character == '=')
		{
			lex_concat();
			lex_return(token, $ME, fp_out);
		}
		else
		{
			lex_retract();
			lex_error(fp_err);
		}
		break;
	case '-':
		lex_concat();
		lex_return(token, $SUB, fp_out);
		break;
	case '*':
		lex_concat();
		lex_return(token, $MUL, fp_out);
		break;
	case '(':
		lex_concat();
		lex_return(token, $LPAR, fp_out);
		break;
	case ')':
		lex_concat();
		lex_return(token, $RPAR, fp_out);
		break;
	case ';':
		lex_concat();
		lex_return(token, $SEG, fp_out);
		break;
	case '\n':
		token[0] = 'E';
		token[1] = 'O';
		token[2] = 'L';
		token[3] = 'N';
		row_num++;
		lex_return(token, $N, fp_out);
		break;
	default:
		lex_concat();
		lex_error(fp_err);
		break;
	}

	return TRUE;
}

int main()
{
	char *path1 = "D:\\test.pas";
	char *path2 = "D:\\test.dyd";
	char *path3 = "D:\\test.err";

	fp	   = fopen(path1, "rb");
	fp_out = fopen(path2, "wb");
	fp_err = fopen(path3, "wb");

	if (!fp)
	{
		fprintf(stderr, "cann't open this file!");
		exit(-1);
	}

	if (!fp_out)
	{
		fprintf(stderr, "cann't find this file!");
		exit(-1);
	}

	if (!fp_err)
	{
		fprintf(stderr, "cann't find this file!");
		exit(-1);
	}


	while (lexAnalyze())
	{
		;
	}

	if (feof(fp))
	{
		memset(token, 0, sizeof(token));
		token[0] = 'E';
		token[1] = 'O';
		token[2] = 'F';

		lex_return(token, $EOF, fp_out);
	}

	fclose(fp);
	fclose(fp_out);
	fclose(fp_err);

	printf("\n");
	printf("Compiling Finished!\n");

	return 0;
}


