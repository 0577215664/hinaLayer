#include <iostream>
#include <string>
#include<bitset>
#include<fstream>
#include "hinaLayer.h"
#include <vector>
#include <algorithm>


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




/// <summary>
/// ��ͼƬ��żλ��д��ˮӡ.
/// </summary>
/// <param name="in_file">Ҫд��ˮӡ��ͼƬ�ļ�.</param>
/// <param name="mask_file">��Ϊˮӡ��ͼƬ�ļ�.</param>
/// <param name="out_file">��������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int en_eo_mask(char* in_file, char* mask_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.eo_write_mask(mask_file, rgb);
	h.out_file(out_file);
	return 0;
}

/// <summary>
/// ��ͼƬ��żλ��д���ļ�.
/// </summary>
/// <param name="in_file">Ҫд���ļ���ͼƬ�ļ�.</param>
/// <param name="info_file">��Ϊд����Ϣ���ļ�.</param>
/// <param name="out_file">��������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int en_eo_file(char* in_file, char* info_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.eo_write_file(info_file, rgb);
	h.out_file(out_file);
	return 0;
}

/// <summary>
/// ��ͼƬ���ص�λ��д���ļ�.
/// </summary>
/// <param name="in_file">Ҫд���ļ���ͼƬ�ļ�.</param>
/// <param name="info_file">��Ϊд����Ϣ���ļ�.</param>
/// <param name="out_file">��������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int en_lsb_file(char* in_file, char* info_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.lsb_write_file(info_file, rgb);
	h.out_file(out_file);
	return 0;
}

/// <summary>
/// ��ͼƬDTFƵ����д��ˮӡ.
/// </summary>
/// <param name="in_file">Ҫд��ˮӡ��ͼƬ�ļ�.</param>
/// <param name="mask_file">��Ϊˮӡ��ͼƬ�ļ�.</param>
/// <param name="out_file">��������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
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



/// <summary>
/// ����ͼƬ��żλˮӡ.
/// </summary>
/// <param name="in_file">Ҫ����ˮӡ��ͼƬ�ļ�.</param>
/// <param name="out_file">���浼�������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int de_eo_mask(char* in_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.eo_to_image(rgb);
	h.out_file(out_file);
	return 0;
}

/// <summary>
/// ����ͼƬ��żλ�ļ�.
/// </summary>
/// <param name="in_file">Ҫ�����ļ���ͼƬ�ļ�.</param>
/// <param name="out_file">���浼�������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int de_eo_file(char* in_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.eo_out_file(out_file, rgb);
	return 0;
}

/// <summary>
/// ����ͼƬ���ص�λ�ļ�.
/// </summary>
/// <param name="in_file">Ҫ�����ļ���ͼƬ�ļ�.</param>
/// <param name="out_file">���浼�������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int de_lsb_file(char* in_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.lsb_out_file(out_file, rgb);
	return 0;
}

/// <summary>
/// ����ͼƬDTFƵ��ˮӡ.
/// </summary>
/// <param name="in_file">Ҫ����ˮӡ��ͼƬ�ļ�</param>
/// <param name="out_file">���浼�������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int de_dtf_mask(char* in_file, char* out_file, int rgb)
{
	hinaLayer h;
	h.open_file(in_file);
	h.dtf_make(rgb);
	h.dtf_print(rgb);
	h.out_file_fdomain(out_file);
	return 0;
}


/// <summary>
/// ����ͼ���С�����ţ�.
/// </summary>
/// <param name="in_file">Ҫ���д���ͼƬ�ļ�.</param>
/// <param name="out_file">���洦������ͼƬ�ļ�.</param>
/// <param name="w">ͼƬ�µĿ��.</param>
/// <param name="h">ͼƬ�µĸ߶�.</param>
void resize(char* in_file, char* out_file, int w, int h)
{
	hinaLayer hl;
	hl.open_file(in_file);
	hl.resize(w, h);
	hl.out_file(out_file);
}

/// <summary>
/// ͼƬY�᾵�񣨴�ֱ��ת��.
/// </summary>
/// <param name="in_file">Ҫ���д���ͼƬ�ļ�.</param>
/// <param name="out_file">���洦������ͼƬ�ļ�.</param>
void mirrorY(char* in_file, char* out_file)
{
	hinaLayer hl;
	hl.open_file(in_file);
	hl.mirrorY();
	hl.out_file(out_file);
}

/// <summary>
/// ͼƬX�᾵��ˮƽ��ת��.
/// </summary>
/// <param name="in_file">Ҫ���д���ͼƬ�ļ�.</param>
/// <param name="out_file">���洦������ͼƬ�ļ�.</param>
void mirrorX(char* in_file, char* out_file)
{
	hinaLayer hl;
	hl.open_file(in_file);
	hl.mirrorX();
	hl.out_file(out_file);
}



//=====================================================================================
//�ļ���д���ܣ�
//=====================================================================================


int hide_file(char* in_file, char* out_file, int rgb)
{
	using namespace std;
	//de_lsb_file(in_file, out_file, rgb);



	//_DEBUG ifstream in(out_file, ios::binary);
	ifstream in(in_file, ios::binary);

	//�����ļ�
	if (!in)
	{
		cerr << "open error!" << endl;
		abort();
	}

	in.seekg(0, ios::end);
	//in.tellg();//�����ļ���С
	in.seekg(0, ios::beg);


	wstring data;

	for (unsigned long i; true != in.eof(); i++)
	{
		data.push_back(in.get());
	}
	cout << (unsigned int)data[0];
	
	ofstream out(out_file, ios::binary);

	
	wstring::iterator it;
	it = data.begin();
	for (unsigned long i; it != data.end(); it++)
	{
		out.put((*it));

	}


}







int main()
{
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


	//de_lsb_file("test\\rr_INfile1.png", "test\\outttttttt.txt", 3);
	hide_file("test\\1.zip", "test\\2.zip",3);
	getchar();

}


