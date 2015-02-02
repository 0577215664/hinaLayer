#include <iostream>
#include "hinaLayer.h"


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




int en_eo_mask(char* in_file, char* mask_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.eo_write_mask(mask_file, rgb);
	h.out_file(out_file);
	return 0;
}

int en_eo_file(char* in_file, char* info_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.eo_write_file(info_file, rgb);
	h.out_file(out_file);
	return 0;
}

int en_lsb_file(char* in_file, char* info_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.lsb_write_file(info_file, rgb);
	h.out_file(out_file);
	return 0;
}


int en_dtf_mask(char* in_file, char* mask_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.dtf_make(3);
	h.dtf_write_mask(mask_file, rgb);
	h.dtf_inverse_make(3);
	h.out_file(out_file);
	return 0;
}





int de_eo_mask(char* in_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.eo_to_image(rgb);
	h.out_file(out_file);
	return 0;
}


int de_eo_file(char* in_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.eo_out_file(out_file, rgb);
	return 0;
}

int de_lsb_file(char* in_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.lsb_out_file(out_file, rgb);
	return 0;
}

int de_dtf_mask(char* in_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.dtf_make(rgb);
	h.dtf_print(rgb);
	h.out_file_fdomain(out_file);
	return 0;
}


int main()
{
	//en_eo_mask("test\\rr.jpg", "test\aaa.png", "test\out.png",2);
	//de_eo_mask("test\out.png", "test\out2.png", 3);
	//cout<<"��żλд��ˮӡ����"

	//en_eo_file("test\\rr.jpg", "test\\test.txt", "test\\out.png", 3);
	//de_eo_file("test\\out.png", "test\\out2.txt", 3);
	//cout<<"��żλд���ļ�����"

	//en_lsb_file("test\\rr.jpg", "test\\test.txt", "test\\out.png", 3);
	//de_lsb_file("test\\out.png", "test\\out2.txt", 3);

	en_dtf_mask("test\\oo.jpg", "test\\pp2.png", "test\\out.png", 2);
	de_dtf_mask("test\\out.png", "test\\out2.png", 3);
	std::cout << "dtfƵ��д��ˮӡ����";

}


