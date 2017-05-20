#pragma once
#ifndef _INCLUDE_SYNTAXANALYZE_H_
#define _INCLUDE_SYNTAXANALYZE_H_

#include <stdio.h>

#define MAX_COUNT			1024   
#define SIGN_UNDEFINED_ERR	1     //����δ�������
#define SIGN_REDEFINED_ERR	2	  //�����ظ��������
#define SIGN_EXECUTE_ERR	3     //����ִ�д���
#define NO_SIGN_ERR			4     //�޷��Ŵ���
#define SIGN_RESERVE_ERR	5     //����ƥ�����
#define NO_PARA_ERR			6     //����ƥ�����

//֧�����ͼ���types
typedef enum {integer}types;

//��¼������Ϣ
typedef struct VARRECORD
{
	int vlev;
	int vadr;
	char vname[17];
	char vproc[17];
	bool vkind;
	types vtype;
}varRecord;

//��¼������Ϣ
typedef struct PRORECORD
{
	int plev;
	int varNum;
	int ladr;
	int fadr;
	int parameter;
	char pname[17];
	bool parameterIsDefined;
	types ptype;
}proRecord;

//�ķ�����ʽ
/************************************************************************
A ������				A->B
B ���ֳ���			B->begin C; M end
C ��˵������		C->DC'
C'����˵������		C'->;DC' | ��
D ��˵�����			D->E | J
E ������˵��			E->integer F
F ������				F->G
G ����ʶ��			G->HG'
G'���±�־��			G'->HG' | IG'|��
H ����ĸ				H->a | ... | z | A | ... | Z
I ������				I->0 | 1 | ... | 9
J ������˵��			J->integer function G(K); L
K ������				K->F
L ��������			L->begin C; M end
M ��ִ������		M->NM'
M'����ִ������		M'->;NM' | ��
N ��ִ�����			N->O | P | Q | W
O �������			O->read(F)
P ��д���			P->write(F)
Q ����ֵ���			Q->F: = R
R ���������ʽ		R->SR'
R'�����������ʽ		R'->-SR' | ��
S ����				S->TS'
S'������				S'->*TS' | ��
T ������				T->F | U | Z
U ������				U->V
V ���޷�������		V->IV'
V'�����޷�������		V'->IV' | ��
W ���������			W->if X then N else N
X ���������ʽ		X->RYR
Y ����ϵ�����		Y->< | <= | > | >= |= | <>
Z ����������			Z->G(R)
************************************************************************/

//��������
//�������ʽ����
void syntaxA();
void syntaxB();
void syntaxC();
void syntaxC_();
void syntaxD();
void syntaxE();
void syntaxF();
void syntaxG();
void syntaxJ();
void syntaxK();
void syntaxL();
void syntaxM();
void syntaxM_();
void syntaxN();
void syntaxO();
void syntaxP();
void syntaxQ();
void syntaxR();
void syntaxR_();
void syntaxS();
void syntaxS_();
void syntaxT();
void syntaxU();
void syntaxW();
void syntaxX();
void syntaxY();
void syntaxZ();

//��ʼ������
bool init();

//����������
bool finals();

//��������
bool error(int, const char*);

//�жϻ�ȡ��һ���ź���
bool nextToken();

//�жϻ�ȡ��ǰ���ŵ���һ�ַ�����
bool nextChar();

//�жϱ������ں���
bool isVarExisted(char*, char*, bool);

//�жϹ��̴��ں���
bool isProExisted(char*);

//�����һ���ź���
int getNextToken();

//ȫ�ֱ���
char input[MAX_COUNT][17];		//��������ļ������з�������
int kind[MAX_COUNT];
int inputCount;					//������ŵ�����
int pToken;						//ָ��ǰ�����ַ�
int pChar;						//ָ��ǰ�����ַ��ĵ�ǰ�ַ�

varRecord currentVar;			//��ŵ�ǰ��������Ϣ
proRecord currentPro;			//��ŵ�ǰ���̵���Ϣ
varRecord var[MAX_COUNT];		//��ű���������
proRecord pro[MAX_COUNT];		//��Ź���������

int varCount;					//��������
int proCount;					//��������
int lineNum;					//��ŵ�ǰ�к�

FILE *inFile;					//�����ļ�ָ��
FILE *outFile;					//����ļ�ָ��
FILE *errFile;					//�����ļ�ָ��
FILE *varFile;					//�����ļ�ָ��
FILE *proFile;					//�����ļ�ָ��

char *path1 = "D:\\test.dyd";	//�����ļ�·��
char *path2 = "D:\\test.dys";	//����ļ�·��
char *path3 = "D:\\test.err";	//�����ļ�·��
char *path4 = "D:\\test.var";	//�����ļ�·��
char *path5 = "D:\\test.pro";	//�����ļ�·��

#endif // !_INCLUDE_SYNTAXANALYZE_H_


