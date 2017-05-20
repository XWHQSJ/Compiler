#pragma once
#ifndef _INCLUDE_PARASER_H_
#define _INCLUDE_PARASER_H_

#include <stdio.h>

#define MAX_COUNT 24


//��¼������Ϣ�ṹ��
typedef struct VARNODE  
{
	char *vname;
	char *vproc;
	char *vtype;
	int   vkind;
	int   vlev;
	int   vadr;
	struct VARNODE *next;
}*vNode;


//��¼������Ϣ�ṹ��
typedef struct PRONODE 
{
	char *pname;
	char *ptype;
	int plevNum;
	int fadr;
	int ladr;
	struct PRONODE *next;
}*pNode;


//��ջ����ڵ���Ϣ
typedef struct STACK
{
	pNode top;
	int size;
}*Stack;


//���溯���ṹ��
typedef struct FUNCNODE  
{
	char *fname;
	struct FUNCNODE *next;
}funcNode;


//ȫ�ֱ�������
pNode pnode;
Stack pstack;
funcNode *fhead, *f1, *f2;
vNode vhead, var1, var2;

//����������ļ�ָ��
FILE *fp_in, *fp_var, *fp_pro, *fp_out, *fp_err;

//����������ļ�·��
char *path1 = "D:\\test.dyd";
char *path2 = "D:\\test.var";
char *path3 = "D:\\test.pro";
char *path4 = "D:\\test.dys";
char *path5 = "D:\\test.err";

char *proc_name;			 //����������
char *name;				     //������
int symbols;				 //���ʷ����ֱ�
int lineNum = 1;			 //�к�
int plevNum = 1;			 //���̲��
char types[MAX_COUNT];	     //����
int varlocation = 1;		 //����λ��


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
J ������˵��			J->integer functions G(K); L
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


//�����ʽ��Ӧ�ĺ�������
//
//�﷨�������  
void program();

//�ַ�ָ�����
void advance();				 		 

//�﷨�����ֳ���
void partProgram();			

//˵������
void declareTable();		 

//������ݹ���µ�˵������
void MdeclareTable();

//˵�����
void declareStatement();

//������ݹ����˵�����
void MdeclareStatement();

//ִ������
void executeTable();	

//������ݹ���ִ�����
void MexecuteTable();

//ִ�����
void executeStatement();

//������/�β�д���������
void varTable(int kind);

//����
void variates();				 

//��ʶ��
void identifier();			 

//����˵��
void functionDelcare();		 

//����
void parameters();			 

//������
void functions();		  

//�����
void readStatement();		 

//д���
void writeStatement();		 

//��ֵ���
void assignStatement();		 

//�������ʽ
void algorithm();	

//������ݹ����������ʽ
void Malgorithm();

//��
void item();	

//������ݹ�����
void Mitem();

//����
void factor();				 

//��������
void callFunction();		

//�������
void conditionStatement();	 

//�������ʽ
void expression();			 

//��ϵ�����
void relationOperator();	


#endif // !_INCLUDE_PARASER_H_