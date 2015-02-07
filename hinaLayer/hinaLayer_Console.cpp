#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "hinaLayer.h"
#include "hinaLayer_comd.h"

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


void main(int argc, char *argv[])
{
	int act(int argc, char *argv[]);
	act(argc, argv);
}





/*
[�Զ���д]
s_in			in_file		info_file		out_file	rgb_	(steg_write_file_lsb)	��ͼƬ����д�ļ�(LSB).
s_out			in_file		out_file/dir	rgb_				(steg_out_file_lsb)		����ͼƬ����д���ļ�(LSB).

[��żλ]
en_eo_mask		in_file		info_file	out_file	rgb_	(en_mig)	��ͼƬ��żλ��д��ˮӡ
en_eo_file		in_file		info_file	out_file	rgb_	(en_bin)	��ͼƬ��żλ��д���ļ�.
de_eo_mask		in_file		out_file	rgb_				(de_mig)	����ͼƬ��żλˮӡ.
de_eo_file		in_file		out_file	rgb_				(de_bin)	����ͼƬ��żλ�ļ�.
read_eo			in_file		rgb								(read_mig)	�ڴ�����Ԥ��ͼƬ����żλͼ��.

[������λ]
en_lsb_file		in_file		info_file	out_file	rgb_	(en_bin_A)	��ͼƬ���ص�λ��д���ļ�.
de_lsb_file		in_file		out_file	rgb_				(de_bin_A)	����ͼƬ���ص�λ�ļ�.

[Ƶ��]
en_dtf_mask		in_file		info_file	out_file	rgb		(en_dtf)	��ͼƬDTFƵ����д��ˮӡ.
de_dtf_mask		in_file		out_file	rgb					(de_dtf)	����ͼƬDTFƵ��ˮӡ.
read_dtf		in_file		rgb											�ڴ�����Ԥ��ͼƬ�� DTFƵ�� ͼ��.
read_dtf_3		in_file													�ڴ�����Ԥ��ͼƬ�� DTFƵ�� ͼ����ͨ��.

[��������]
resize			in_file		out_file	w			h					����ͼ���С�����ţ�.
mirrorX			in_file		out_file						(m_x)		ͼƬX�᾵��ˮƽ��ת��.
mirrorY			in_file		out_file						(m_y)		ͼƬY�᾵�񣨴�ֱ��ת��.

*/

int act(int argc, char *argv[])
{
	std::cout << " hinaLayer - ver1.0 -  \n Simple Steganography tool \n (C)2015 BGLL\n\n\n";
	std::cout << "[�Զ���д]\ns_in  in_file info_file out_file rgb_ (steg_write_file_lsb) ��ͼƬ����д�ļ�(LSB).\ns_out  in_file out_file/dir rgb_  (steg_out_file_lsb) ����ͼƬ����д���ļ�(LSB).\n\n[��żλ]\nen_eo_mask in_file info_file out_file rgb_ (en_mig) ��ͼƬ��żλ��д��ˮӡ\nen_eo_file in_file info_file out_file rgb_ (en_bin) ��ͼƬ��żλ��д���ļ�.\nde_eo_mask in_file out_file rgb_  (de_mig) ����ͼƬ��żλˮӡ.\nde_eo_file in_file out_file rgb_  (de_bin) ����ͼƬ��żλ�ļ�.\nread_eo  in_file rgb    (read_mig) �ڴ�����Ԥ��ͼƬ����żλͼ��.\n\n[������λ]\nen_lsb_file in_file info_file out_file rgb_ (en_bin_A) ��ͼƬ���ص�λ��д���ļ�.\nde_lsb_file in_file out_file rgb_  (de_bin_A) ����ͼƬ���ص�λ�ļ�.\n\n[Ƶ��]\nen_dtf_mask in_file info_file out_file rgb (en_dtf) ��ͼƬDTFƵ����д��ˮӡ.\nde_dtf_mask in_file out_file rgb   (de_dtf) ����ͼƬDTFƵ��ˮӡ.\nread_dtf in_file rgb      �ڴ�����Ԥ��ͼƬ�� DTFƵ�� ͼ��.\nread_dtf_3 in_file       �ڴ�����Ԥ��ͼƬ�� DTFƵ�� ͼ����ͨ��.\n\n[��������]\nresize  in_file out_file w  h   ����ͼ���С�����ţ�.\nmirrorX  in_file out_file   (m_x) ͼƬX�᾵��ˮƽ��ת��.\nmirrorY  in_file out_file   (m_y) ͼƬY�᾵�񣨴�ֱ��ת��.\n\n*/";


	for (int a = 0; a < argc; a++)
	{
		std::cout << a << "/" << argc << ":" << argv[a] << "\n";
	}


	string com;
	string comb, comb2;

	if (argc >= 2)
		com = argv[1];

	std::cout << "\n-----------------\n";
	if (argc == 6)
	{//en_mig  in_flie info_img out_flie  rgb 
		comb = "en_mig";
		comb2 = "en_eo_mask";

		if (com == comb || com == comb2)
		{
			std::cout << "[en_eo_mask(en_mig)]\n";
			en_eo_mask(argv[2], argv[3], argv[4], atoi(argv[5]));
		}
	}

	if (argc == 4)
	{//read_mig in_flie rgb
		comb = "read_mig";
		comb2 = "read_eo";
		if (com == comb || com == comb2)
		{
			std::cout << "[read_eo(read_mig)]\n";
			read_eo(argv[2], atoi(argv[3]));
		}
	}

	if (argc == 5)
	{//de_mig  in_flie  out_flie rgb
		comb = "de_mig";
		comb2 = "de_eo_mask";
		if (com == comb || com == comb2)
		{
			std::cout << "de_eo_mask(de_mig)\n";
			de_eo_mask(argv[2], argv[3], atoi(argv[4]));
		}
	}

	if (argc == 5)
	{//en_bin in_image_flie  info_bin 
		comb = "en_bin";
		comb2 = "en_eo_file";
		if (com == comb || com == comb2)
		{
			std::cout << "en_eo_file(en_bin)\n";
			en_eo_file(argv[2], argv[3], argv[4]);
		}
	}
	if (argc == 6)
	{//== en_bin in_image_flie  info_bin rgb
		comb = "en_bin";
		comb2 = "en_eo_file";
		if (com == comb || com == comb2)
		{
			std::cout << "en_eo_file(en_bin)\n";
			en_eo_file(argv[2], argv[3], argv[4], atoi(argv[5]));
		}
	}


	if (argc == 5)
	{//en_bin_A in_image_flie  info_bin 
		comb = "en_bin_A";
		comb2 = "en_lsb_file";
		if (com == comb || com == comb2)
		{
			std::cout << "en_lsb_file(en_bin_A)\n";
			en_lsb_file(argv[2], argv[3], argv[4]);
		}
	}
	if (argc == 6)
	{//==en_bin_A in_image_flie  info_bin  rgb
		comb = "en_bin_A";
		comb2 = "en_lsb_file";
		if (com == comb || com == comb2)
		{
			std::cout << "en_lsb_file(en_bin_A)\n";
			en_lsb_file(argv[2], argv[3], argv[4], atoi(argv[5]));
		}
	}


	if (argc == 4)
	{//de_bin in_image_flie	out_file
		comb = "de_bin";
		comb2 = "de_eo_file";
		if (com == comb || com == comb2)
		{
			std::cout << "de_eo_file(de_bin)\n";
			de_eo_file(argv[2], argv[3]);
		}
	}
	if (argc == 5)
	{//== de_bin in_image_flie	out_file rgb
		comb = "de_bin";
		comb2 = "de_eo_file";
		if (com == comb || com == comb2)
		{
			std::cout << "de_eo_file(de_bin)\n";
			de_eo_file(argv[2], argv[3], atoi(argv[4]));
		}
	}




	if (argc == 4)
	{//en_bin_A in_image_flie out_file
		comb = "de_bin_A";
		comb2 = "de_lsb_file";
		if (com == comb || com == comb2)
		{
			std::cout << "de_lsb_file(de_bin_A)\n";
			de_lsb_file(argv[2], argv[3]);
		}
	}
	if (argc == 5)
	{//== en_bin_A in_image_flie out_file rgb
		comb = "de_bin_A";
		comb2 = "de_lsb_file";
		if (com == comb || com == comb2)
		{
			std::cout << "de_lsb_file(de_bin_A)\n";
			de_lsb_file(argv[2], argv[3], atoi(argv[4]));
		}
	}


	if (argc == 4)
	{//read_dtf in_flie rgb 
		comb = "read_dtf";
		comb2 = "read_dtf";
		if (com == comb || com == comb2)
		{
			std::cout << "read_dtf(read_dtf)\n";
			read_dtf(argv[2], atoi(argv[3]));
		}
	}

	if (argc == 3)
	{//read_dtf_3 in_flie 
		comb = "read_dtf_3";
		if (com == comb)
		{
			std::cout << "read_dtf_3\n";
			read_dtf(argv[2], 3);
		}
	}

	if (argc == 6)
	{//en_dtf in_f info_f out_f rgb 
		comb = "en_dtf";
		comb2 = "en_dtf_mask";
		if (com == comb || com == comb2)
		{
			std::cout << "en_dtf_mask(en_dtf)\n";
			en_dtf_mask(argv[2], argv[3], argv[4], atoi(argv[5]));
		}
	}

	if (argc == 5)
	{//de_dtf in_f out_f rgb 
		comb = "de_dtf";
		comb2 = "de_dtf_mask";
		if (com == comb || com == comb2)
		{
			std::cout << "de_dtf_mask(de_dtf)\n";
			de_dtf_mask(argv[2], argv[3], atoi(argv[4]));
		}
	}

	if (argc == 5)
	{//en_dtf_3 in_f info_f out_f  
		comb = "en_dtf_3";
		if (com == comb)
		{
			std::cout << "en_dtf_3\n";
			en_dtf_mask(argv[2], argv[3], argv[4], 3);
		}
	}


	if (argc == 4)
	{//de_dtf_3  in_f out_f 
		comb = "de_dtf_3";
		if (com == comb)
		{
			std::cout << "de_dtf_3\n";
			de_dtf_mask(argv[2], argv[3], 3);
		}
	}

	if (argc == 6)
	{//resize in_f out_f w h
		comb = "resize";
		if (com == comb)
		{
			std::cout << "resize\n";
			resize(argv[2], argv[3], atoi(argv[4]), atoi(argv[5]));
		}
	}

	if (argc == 4)
	{//mirrorX in_f out_f
		comb = "mirrorX";
		comb2 = "m_x";
		if (com == comb || com == comb2)
		{
			std::cout << "m_x(mirrorX)\n";
			mirrorX(argv[2], argv[2]);
		}
	}
	if (argc == 4)
	{//mirrorX in_f out_f
		comb = "mirrorY";
		comb2 = "m_y";
		if (com == comb || com == comb2)
		{
			std::cout << "m_y(mirrorY)\n";
			mirrorY(argv[2], argv[2]);
		}
	}


	if (argc == 6)
	{//steg_write_file_lsb  rgb
		comb = "steg_write_file_lsb";
		comb2 = "s_in";
		if (com == comb || com == comb2)
		{
			std::cout << "s_in(steg_write_file_lsb)\n";
			steg_write_file_lsb(argv[2], argv[3], argv[4], atoi(argv[5]));
		}
	}
	if (argc == 5)
	{// ==steg_write_file_lsb  
		comb = "steg_write_file_lsb";
		comb2 = "s_in";
		if (com == comb || com == comb2)
		{
			std::cout << "s_in(steg_write_file_lsb)\n";
			steg_write_file_lsb(argv[2], argv[3], argv[4], 3);
		}
	}


	if (argc == 5)
	{//steg_write_file_lsb  rgb
		comb = "steg_out_file_lsb";
		comb2 = "s_out";
		if (com == comb || com == comb2)
		{
			std::cout << "s_out(steg_out_file_lsb)\n";
			steg_out_file_lsb(argv[2], argv[3], atoi(argv[4]));
		}
	}
	if (argc == 4)
	{//== steg_write_file_lsb 
		comb = "steg_out_file_lsb";
		comb2 = "s_out";
		if (com == comb || com == comb2)
		{
			std::cout << "s_out(steg_out_file_lsb)\n";
			steg_out_file_lsb(argv[2], argv[3], 3);
		}
	}
	return 0;
}

































