#pragma once

/*����ļ��ĸ�ʽ:�ַ�/�ַ���  ��Ӧ������*/

////////���Ƿ� -- ������
#define $BEGIN     1	
#define $END       2
#define $INTEGER   3
#define $IF        4
#define $THEN      5
#define $ELSE      6
#define $FUNCTION  7
#define $READ      8
#define $WRITE     9
#define $SYMBOL   10	 // ��ʶ��
#define $CONSTANT 11     // ����
#define $E        12	 // =
#define $LG		  13     // <>
#define $LE		  14     // <=
#define $L		  15     // <
#define $GE		  16     // >=
#define $G		  17     // >
#define $SUB	  18	 // -
#define $MUL	  19	 // *
#define $ME		  20     // :=
#define $LPAR	  21     // ��
#define $RPAR	  22     // ��
#define $SEG	  23     // ��
#define $N		  24     // \n
#define $EOF	  25     // EOF

//����ȫ�ֱ���
#define RESERVE_COUNT 9
#define TRUE		  1
#define FALSE         0
#define LF            10 
#define CR			  13