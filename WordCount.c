#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {//argc ��ʾ��������������ĸ������Կհ׷��ָ������ڶ���������argv[0]Ĭ���ǿ�ִ���ļ�����argv[1]��argv[2]�ǽ��ܵ��Ĳ���

	if( argc == 3 ) {//��ʾmain���ܵ������������� 

		//���Զ�ȡ�ļ�������
		char data;
		FILE *fp = fopen(argv[2],"r");//argv[2]�����������Ҫ��ȡ���ļ���,�ҵĲ����ļ�����Ϊ input.TXT 

		if(!fp) {  //�����ļ�Ϊ�� 
			printf("�����ļ���ȡʧ��\n");
			return -1;
		}

		//�Բ��������ж�
		if( !strcmp(argv[1],"-c") ) { //����ڶ�������argv[1]=="-c"����ͳ���ַ���
			char temp; 				//��ʾ��ǰ�ַ� 
			int bitnum = 0;			//�ַ��� 
			temp = fgetc(fp);		// fgetc��Ϊ���ļ�ָ��streamָ����ļ��ж�ȡһ���ַ�����ȡһ���ֽں󣬹��λ�ú���һ���ֽ� 
			while( temp != EOF ) {
				temp = fgetc(fp);
				bitnum++;
			}
			printf("�ַ���Ϊ��%d\n",bitnum);

		} else if( !strcmp(argv[1],"-w") ) { //����ڶ�������argv[1]=="-w"����ͳ�Ƶ�����
			int wordnum = 0;				//������Ŀ 
			char temp = fgetc(fp); 			//��ǰ�ַ������������ 
			while( temp != EOF) {
				if( (temp >='a' && temp <='z') || ( temp >='A' && temp <='Z')) {
					while( (temp >='a' && temp <='z') || ( temp >='A' && temp <='Z'))
						temp =fgetc(fp);
					wordnum++;
					temp =fgetc(fp);

				} else{
					temp =fgetc(fp);
				}	
			}
			printf("������Ϊ��%d\n",wordnum);
		} 
		else { 						 //�������-c��-w��֮��Ĳ��� 
			printf("���󣺲���������Χ��\n");
			printf("���������-c��-w \n");
		}
		int n=fclose(fp);
	} 
	else { 						//������������Ϊ3����ʾ������Ϣ������ʾ�������ȷ��ʽ�� 
		printf("�������в�������Ҫ3��\n");
		printf("�÷���WordCount.exe [parameter] [file_name]\n");// [parameter]Ϊ��-c�����ߡ�-w����[file_name]Ϊ���Ե��ļ���
		/*��������
		WordCount.exe -c input.TXT 
		*/ 
	}
	system("pause");
	return 0;
}

//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<windows.h>
////#define IN 1
////#define OUT 0
//void main()
//{
//    FILE *fp;
//    int length;
//    fp = fopen("input.TXT", "r");//��Ҫ�������ļ�
//    if (fp == NULL)
//	{
//
//        printf("can not open file");
//        exit(0);
//	}
//        fseek(fp, 00, SEEK_END);
//        length = ftell(fp);
//        printf("%d\n", length);//ȷ����Ҫ���ҵ��ļ������ַ������ȣ�������Ļ����ʾ����
//        rewind(fp);
//        char str[100000], c;
//        fread(str, sizeof(char), length, fp);//���ļ��ж�ȡ���е��ַ���str����
//        int i, num1 = 0, num2 = 0, num3, num4=0, word = 0;
//        for (i = 0; (c = str[i]) != '\0'; i++)
//		{
//
//            if (c == ' ')//�ж��ַ��е�����
//			{
//                  num2++;
//                  word = 0;
//			}
//            else
//			{
//                  if (word == 0)
//				  {
//                        word = 1;
//                        num1++;
//				  }
//			}
//            if ((c = str[i]) == '\n')
//			{
//                  num4++;
//			}
//		}
//        num3 = length - num2-num4*2;//�ַ���
//        num4++;//����
//        fclose(fp);
//        printf("�ո���Ϊ%d\n", num2);
//        printf("������Ϊ%d\n����Ϊ%d\n�ַ���Ϊ%d\n", num1, num4, num3);
//        system("pause");
//}
