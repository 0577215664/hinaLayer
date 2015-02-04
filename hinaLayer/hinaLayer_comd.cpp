#include <iostream>
#include <string>
#include<bitset>
#include<fstream>
#include "hinaLayer.h"
#include <vector>
#include <algorithm>
#include <sys/stat.h>

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
using namespace std;


void wstring_to_string(wstring& wstr, string& str)
{
	str = "";
	for (int i = 0; i < wstr.size(); i++)
	{
		str = str + (char)wstr[i];
	}
}

void wstring_to_file(wstring& wstr, char* filename)
{
	wstring::iterator it;
	ofstream out(filename, ios::binary);
	it = wstr.begin();
	for (unsigned long i; it != wstr.end(); it++)
	{
		out.put((*it));
	}
	out.close();
}

void wstring_to_file(wstring& wstr, string filename)
{
	char* cstr = const_cast<char*>(filename.c_str());
	wstring_to_file(wstr, cstr);
}



string get_path_bef(string in, string bef)
{
	int i;
	i = in.rfind(bef);
	if (string::npos==i)
	{
		return "";
	}
	else
	{
		return in.substr(0, i);
	}
}

string get_path_add_bs(string in)
{
	char z;
	z = in[in.size()];
	if ('\0' == z && in.size() > 2);
	{
		z = in[in.size()-1];
	}

	if ('\\' == z)
	{
		return in;
	}
	else
	{
		return in + '\\';
	}
}

char* get_path_add_bs(char* in)
{
	string str;
	str = in;
	str = get_path_add_bs(str);
	char* cstr = const_cast<char*>(str.c_str());
	return cstr;
}


int file_test(const char* filename)
{
	struct _stat fileStat;


	if (-1 == _stat(filename, &fileStat))
		return -1;//�ļ����ļ��в�����

	if (fileStat.st_mode & _S_IFDIR)
		return 1;//���ļ���
	else
		return 0;//���ļ�
}



int hide_file(char* in_file, char* out_file, int rgb)
{

	if (-1 == file_test(in_file))
		return -1;//�����ļ������ڴ���
	if (-1 == file_test(out_file))
		return -2;//����ļ������ڴ���
	
	ifstream in;
	if (1 == file_test(out_file))
	{//���������Ŀ¼
		string tempf = get_path_add_bs(out_file) ;
		tempf = tempf + "temp_linalayer_temp.temp";
		char* ctemp = const_cast<char*>(tempf.c_str());

		de_lsb_file(in_file, ctemp, rgb);
		in.open(ctemp, ios::binary);
		
	}
	else
	{
		de_lsb_file(in_file, out_file, rgb);
		in.open(out_file, ios::binary);
	}



	//�����ļ�
	if (!in)
	{
		cerr << "open error!" << endl;
		abort();
	}
	
	//�ļ�д�� data �Թ�����
	wstring data;
	for (unsigned long i; true != in.eof(); i++)
	{
		data.push_back(in.get());
	}



	
	wstring b;

	if (255==data[0] && 254==data[1])
	{
		//��ȡԭ�ļ���
		wstring file_name;
		size_t pos = data.rfind({ 254, 255, 152, 10, 20, 253, 254, 255 });
		if (string::npos == pos)
			return -2; //û�н�β���

		b = data.substr(2, pos -2);

		size_t name_beg = b.rfind({ 254, 255 });
		if (string::npos == name_beg)
			return -3; //û���ļ������

		file_name = b.substr(name_beg + 2, b.size());
		string file_name_str;
		wstring_to_string(file_name, file_name_str);

		//��ȡԭ�ļ�����
		b = b.substr(0, name_beg);
		
		//�����ļ�
		if (1 == file_test(out_file))
		{//Ҫ������������ļ���
			out_file = get_path_add_bs(out_file);
			cout << endl << "out_file:" << out_file<<endl;
			wstring_to_file(b, out_file + file_name_str);

		}
		else
		{//�ļ�

		}

	
		



		
		

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


	//de_lsb_file("test\\b2.png", "test\\b2_out.exe", 3);
	//de_lsb_file("test\\b3.png", "test\\b3_out.exe", 3);
	//en_lsb_file("test\\b.png","test\\1.exe", "test\\b_insfile.png", 3);
	//de_lsb_file("test\\2.png", "test\\22.exe", 3);
	//de_lsb_file("test\\2.png", "test\\22.exe", 3);
	hide_file("test\\b2.png", "test\\R",3);

	



	getchar();

}


