#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

//#include "hinaLayer.h"
//#include "hinaLayer_comd.h"

#include<iostream>
#include<string>
#include<bitset>
#include<fstream>
#include<math.h>


// �⼸���������ļ�����Ҫ��ӣ�   
// ��Ϊ��Щ��OpenCV��ʹ�õĵ�������   
#pragma comment( lib, "libjasperd.lib" )   
#pragma comment( lib, "libjpegd.lib" )   
#pragma comment( lib, "libpngd.lib" )   
#pragma comment( lib, "libtiffd.lib" )   
#pragma comment( lib, "zlibd.lib" )  

// ���������ĳ�������������ļ�   
#pragma comment( lib, "opencv_core2410.lib" )   
#pragma comment( lib, "opencv_imgproc2410.lib" )   
#pragma comment( lib, "opencv_highgui2410.lib" )   
// �������������Ϊwin32����   
#pragma comment( lib, "vfw32.lib" )   
#pragma comment( lib, "comctl32.lib" )

void main()
{
	std::cout << 11;
}



//----����żλ������
//en_mig  in_flie info_img out_flie  rgb  ͼƬ����д��
//de_mig  in_flie  out_flie rgb	ͼƬ����д��
//read_mig in_flie rgb ��ʾ����ͼƬ����

//en_bin in_image_flie  info_bin �ļ�����д��
//de_bin in_image_flie	info_bin �ļ�����д��

//en_bin_A in_image_flie  info_bin ����Ӧ����ļ�����д��
//en_bin_A in_image_flie	info_bin ����Ӧ����ļ�����д��


//----��dtfƵ�򡿴���
//read_dtf in_flie rgb ��ɫͼƬָ��ͨ��dtfƵ��
//read_dtf_3 in_flie ��ɫͼƬ3ͨ��dtfƵ��

//en_dtf in_f info_f out_f rgb ͼƬָ��ͨ��dtfƵ����Ϣд��
//de_dtf in_f out_f rgb ͼƬָ��ͨ��dtfƵ����Ϣд��

//en_dtf_3 in_f info_f out_f  ͼƬ3ͨ��dtfƵ����Ϣд��
//de_dtf_3  in_f out_f ͼƬ3ͨ��dtfƵ����Ϣд��

//----������������
//resize in_f out_f w h









	//int act(int argc, char *argv[]);
	//act(argc, argv);
	//return 0;

	//en_eo_mask("test\\rr.jpg", "test\aaa.png", "test\out.png",2);
	//de_eo_mask("test\out.png", "test\out2.png", 3);
	//std::cout<<"��żλд��ˮӡ����"

	//en_eo_file("test\\rr.jpg", "test\\test.txt", "test\\out.png", 3);
	//de_eo_file("test\\out.png", "test\\out2.txt", 3);
	//std::cout<<"��żλд���ļ�����"

	//en_lsb_file("test\\rr.jpg", "test\\test.txt", "test\\out.png", 3);
	//de_lsb_file("test\\out.png", "test\\out2.txt", 3);
	//std::cout<<"���ص�λλд���ļ�����"

	//en_dtf_mask("test\\oo.jpg", "test\\pp2.png", "test\\out.png", 2);
	//de_dtf_mask("test\\out.png", "test\\out2.png", 3);
	//std::cout << "dtfƵ��д��ˮӡ����";

	//resize("test\\oo.jpg", "test\\out.jpg",303,230);
	//mirrorX("test\\out.jpg", "test\\out2.jpg");
	//mirrorY("test\\out2.jpg", "test\\out3.jpg");
	//std::cout << "�������ܲ���";


	//de_lsb_file("test\\b2.png", "test\\b2_out.exe", 3);
	//de_lsb_file("test\\b3.png", "test\\b3_out.exe", 3);
	//en_lsb_file("test\\b.png","test\\1.exe", "test\\b_insfile.png", 3);
	//de_lsb_file("test\\2.png", "test\\22.exe", 3);
	//de_lsb_file("test\\2.png", "test\\22.exe", 3);
	//string a;
	//hide_file("test\\p4.png", "test\\R",3,a);
	//cout << a << endl;
	//hide_file("test\\2.png", "test\\R\\oo.exe", 3,a);
	//cout << a << endl;


	//steg_write_file_lsb("test\\b.png", "test\\R\\1.zip", "test\\R\\b_out.png", 3);

	//steg_out_file_lsb("test\\R\\b_out.png", "test\\R", 3);
















/*
int main()
{
	cout<<11;
	hinaLayer j;
	j.open_file("rr.jpg");
	j.show("���ļ�");
	
	//j.eo_write_mask("aaa.png");
	//j.show_eo("д����żˮӡ");

	//j.eo_write_file("test.txt",2);
	//j.eo_out_file("1.txt",2);

	//j.eo_to_image(3);

	//j.show();
	//j.show_eo();



	//j.lsb_write_file("test.txt",0);
	//j.lsb_out_file("1.txt",0);
	//j.show("���");
	//cout << endl <<"��ȣ�"<< j.lsb_get_deep("test.txt") << endl;
	//cout <<"���ߴ磺"<< (j.lsb_get_max()) / 1000 << "KB" << endl;

	getchar();

	/*
	j.dtf_make(2);
	j.dtf_write_mask("pp2.png",2);
	//j.dtf_inverse_make(2);
	j.dtf_print(2);
	j.show_fdomain("2");
	j.show("nwe");
	*/	
//} 




