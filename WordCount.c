#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {//argc 表示命令行输入参数的个数（以空白符分隔）；第二个参数：argv[0]默认是可执行文件本身，argv[1]、argv[2]是接受到的参数

	if( argc == 3 ) {//表示main接受到了三个参数。 

		//尝试读取文件的内容
		char data;
		FILE *fp = fopen(argv[2],"r");//argv[2]这个参数就是要读取的文件名,我的测试文件名称为 input.TXT 

		if(!fp) {  //测试文件为空 
			printf("错误：文件读取失败\n");
			return -1;
		}

		//对参数进行判断
		if( !strcmp(argv[1],"-c") ) { //如果第二个参数argv[1]=="-c"，则统计字符数
			char temp; 				//表示当前字符 
			int bitnum = 0;			//字符数 
			temp = fgetc(fp);		// fgetc意为从文件指针stream指向的文件中读取一个字符，读取一个字节后，光标位置后移一个字节 
			while( temp != EOF ) {
				temp = fgetc(fp);
				bitnum++;
			}
			printf("字符数为：%d\n",bitnum);

		} else if( !strcmp(argv[1],"-w") ) { //如果第二个参数argv[1]=="-w"，则统计单词数
			int wordnum = 0;				//单词数目 
			char temp = fgetc(fp); 			//当前字符，逐个往后移 
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
			printf("单词数为：%d\n",wordnum);
		} 
		else { 						 //当输入除-c、-w、之外的参数 
			printf("错误：参数超出范围！\n");
			printf("允许参数：-c，-w \n");
		}
		int n=fclose(fp);
	} 
	else { 						//当参数个数不为3，提示错误信息，并提示输入的正确格式。 
		printf("错误：运行参数必须要3个\n");
		printf("用法：WordCount.exe [parameter] [file_name]\n");// [parameter]为“-c”或者“-w”，[file_name]为测试的文件名
		/*测试用例
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
//    fp = fopen("input.TXT", "r");//打开要计数的文件
//    if (fp == NULL)
//	{
//
//        printf("can not open file");
//        exit(0);
//	}
//        fseek(fp, 00, SEEK_END);
//        length = ftell(fp);
//        printf("%d\n", length);//确定所要查找的文件中总字符数长度，并在屏幕中显示出来
//        rewind(fp);
//        char str[100000], c;
//        fread(str, sizeof(char), length, fp);//从文件中读取所有的字符到str序列
//        int i, num1 = 0, num2 = 0, num3, num4=0, word = 0;
//        for (i = 0; (c = str[i]) != '\0'; i++)
//		{
//
//            if (c == ' ')//判断字符中单词数
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
//        num3 = length - num2-num4*2;//字符数
//        num4++;//行数
//        fclose(fp);
//        printf("空格数为%d\n", num2);
//        printf("单词数为%d\n行数为%d\n字符数为%d\n", num1, num4, num3);
//        system("pause");
//}
