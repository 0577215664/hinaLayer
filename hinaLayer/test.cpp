#include "hinaLayer.h"
#include "hinaLayer_comd.h"
//C++
#include <iostream>
#include <string>
#include<bitset>
#include<fstream>
#include<math.h>
using namespace std;

int act()
{




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




/*
[��żλ]
en_eo_mask		in_file		info_file	out_file	rgb_	(en_mig)	��ͼƬ��żλ��д��ˮӡ
en_eo_file		in_file		info_file	out_file	rgb_	(en_bin)	��ͼƬ��żλ��д���ļ�.
de_eo_mask		in_file		out_file	rgb_				(de_mig)	����ͼƬ��żλˮӡ.
de_eo_file		in_file		out_file	rgb_				(de_bin)	����ͼƬ��żλ�ļ�.
read_eo			in_file		rgb								(read_mig)

[������λ]
en_lsb_file		in_file		info_file	out_file	rgb_	(en_bin_A)	��ͼƬ���ص�λ��д���ļ�.
de_lsb_file		in_file		out_file	rgb_				(de_bin_A)	����ͼƬ���ص�λ�ļ�.

[Ƶ��]
en_dtf_mask		in_file		info_file	out_file	rgb		(en_dtf)	��ͼƬDTFƵ����д��ˮӡ.
de_dtf_mask		in_file		out_file	rgb					(de_dtf)	����ͼƬDTFƵ��ˮӡ.
read_dtf		in_file		rgb
read_dtf_3		in_file

[��������]
resize			in_file		out_file	w			h					����ͼ���С�����ţ�.
mirrorX			in_file		out_file						(m_x)		ͼƬX�᾵��ˮƽ��ת��.
mirrorY			in_file		out_file						(m_y)		ͼƬY�᾵�񣨴�ֱ��ת��.

*/
















int main(int argc, char *argv[])
{

	std::cout << " hinaLayer - ver0.8 -  \n Simple Steganography tool \n (C)2014 BGLL\n\n\n";
	std::cout << "-----��żλ����-----\nen_mig  in_flie info_img out_flie  rgb  ͼƬ����д��\nde_mig  in_flie  out_flie rgb	ͼƬ����д��\nread_mig in_flie rgb ��ʾ����ͼƬ����\n\nen_bin in_image_flie  info_bin �ļ�����д��\nde_bin in_image_flie	info_bin �ļ�����д��\n\nen_bin_A in_image_flie  info_bin ����Ӧ����ļ�����д��\nen_bin_A in_image_flie	info_bin ����Ӧ����ļ�����д��\n\n-----DTFƵ����-----\nread_dtf in_flie rgb ��ɫͼƬָ��ͨ��dtfƵ��\nread_dtf_3 in_flie ��ɫͼƬ3ͨ��dtfƵ��\n\nen_dtf in_f info_f out_f rgb ͼƬָ��ͨ��dtfƵ����Ϣд��\nde_dtf in_f out_f rgb ͼƬָ��ͨ��dtfƵ����Ϣд��\n\nen_dtf_3 in_f info_f out_f  ͼƬ3ͨ��dtfƵ����Ϣд��\nde_dtf_3  in_f out_f ͼƬ3ͨ��dtfƵ����Ϣд��\n\n-----��������-----\nresize in_f out_f w h\n\n";


	for (int a = 0; a < argc; a++)
	{
		std::cout << a << "/" << argc << ":" << argv[a] << "\n";
	}


	string com;
	string comb,comb2;

	if (argc >= 2)
		com = argv[1];

	std::cout << "\n-----------------\n";
	if (argc == 6)
	{//en_mig  in_flie info_img out_flie  rgb 
		comb = "en_mig";
		comb2 = "en_eo_mask";

		if (com == comb || com == comb2 || com == comb || com == comb22)
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
			read_dtf(argv[2],3);
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
	getchar();

}
















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




