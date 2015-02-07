#ifndef HINALAYER_COMD_H
#define HINALAYER_COMD_H

#include <string>


/// <summary>
/// ��ͼƬ��żλ��д��ˮӡ.
/// </summary>
/// <param name="in_file">Ҫд��ˮӡ��ͼƬ�ļ�.</param>
/// <param name="mask_file">��Ϊˮӡ��ͼƬ�ļ�.</param>
/// <param name="out_file">��������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int en_eo_mask(char* in_file, char* mask_file, char* out_file, int rgb = 3);

/// <summary>
/// ��ͼƬ��żλ��д���ļ�.
/// </summary>
/// <param name="in_file">Ҫд���ļ���ͼƬ�ļ�.</param>
/// <param name="info_file">��Ϊд����Ϣ���ļ�.</param>
/// <param name="out_file">��������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int en_eo_file(char* in_file, char* info_file, char* out_file, int rgb = 3);

/// <summary>
/// ��ͼƬ���ص�λ��д���ļ�.
/// </summary>
/// <param name="in_file">Ҫд���ļ���ͼƬ�ļ�.</param>
/// <param name="info_file">��Ϊд����Ϣ���ļ�.</param>
/// <param name="out_file">��������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int en_lsb_file(char* in_file, char* info_file, char* out_file, int rgb = 3);

/// <summary>
/// ��ͼƬDTFƵ����д��ˮӡ.
/// </summary>
/// <param name="in_file">Ҫд��ˮӡ��ͼƬ�ļ�.</param>
/// <param name="mask_file">��Ϊˮӡ��ͼƬ�ļ�.</param>
/// <param name="out_file">��������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int en_dtf_mask(char* in_file, char* mask_file, char* out_file, int rgb = 3);

/// <summary>
/// ����ͼƬ��żλˮӡ.
/// </summary>
/// <param name="in_file">Ҫ����ˮӡ��ͼƬ�ļ�.</param>
/// <param name="out_file">���浼�������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int de_eo_mask(char* in_file, char* out_file, int rgb = 3);

/// <summary>
/// ����ͼƬ��żλ�ļ�.
/// </summary>
/// <param name="in_file">Ҫ�����ļ���ͼƬ�ļ�.</param>
/// <param name="out_file">���浼�������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int de_eo_file(char* in_file, char* out_file, int rgb = 3);

/// <summary>
/// ����ͼƬ���ص�λ�ļ�.
/// </summary>
/// <param name="in_file">Ҫ�����ļ���ͼƬ�ļ�.</param>
/// <param name="out_file">���浼�������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int de_lsb_file(char* in_file, char* out_file, int rgb = 3);

/// <summary>
/// ����ͼƬDTFƵ��ˮӡ.
/// </summary>
/// <param name="in_file">Ҫ����ˮӡ��ͼƬ�ļ�</param>
/// <param name="out_file">���浼�������ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int de_dtf_mask(char* in_file, char* out_file, int rgb = 3);

/// <summary>
/// ����ͼ���С�����ţ�.
/// </summary>
/// <param name="in_file">Ҫ���д���ͼƬ�ļ�.</param>
/// <param name="out_file">���洦������ͼƬ�ļ�.</param>
/// <param name="w">ͼƬ�µĿ��.</param>
/// <param name="h">ͼƬ�µĸ߶�.</param>
void resize(char* in_file, char* out_file, int w, int h);

/// <summary>
/// ͼƬY�᾵�񣨴�ֱ��ת��.
/// </summary>
/// <param name="in_file">Ҫ���д���ͼƬ�ļ�.</param>
/// <param name="out_file">���洦������ͼƬ�ļ�.</param>
void mirrorY(char* in_file, char* out_file);

/// <summary>
/// ͼƬX�᾵��ˮƽ��ת��.
/// </summary>
/// <param name="in_file">Ҫ���д���ͼƬ�ļ�.</param>
/// <param name="out_file">���洦������ͼƬ�ļ�.</param>
void mirrorX(char* in_file, char* out_file);

/// <summary>
/// ��ͼƬ����д�ļ�(LSB).
/// </summary>
/// <param name="in_file">Ҫд�����ݵ�ͼƬ�ļ�.</param>
/// <param name="info_file">��д��ͼƬ���ļ�.</param>
/// <param name="out_file">���洦������ͼƬ�ļ�.</param>
/// <param name="rgb">��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int steg_write_file_lsb(char* in_file, char* info_file, char* out_file, int rgb = 3);

/// <summary>
/// ��ȡͼƬ����д���ļ����ļ���(LSB).
/// </summary>
/// <param name="in_file">ͼƬ�ļ�.</param>
/// <param name="rgb">��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>string.</returns>
std::string steg_get_name_lsb(char* in_file, int rgb = 3);

/// <summary>
/// ����ͼƬ����д���ļ�(LSB).
/// </summary>
/// <param name="in_file">ͼƬ�ļ�.</param>
/// <param name="out_file">���浼�����ݵ��ļ��л��ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ����.</param>
/// <returns>int.</returns>
int steg_out_file_lsb(char* in_file, char* out_file, int rgb = 3);

/// <summary>
/// �ڴ�����Ԥ��ͼƬ����żλͼ��.
/// </summary>
/// <param name="in_file">Ҫ�鿴��ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ��).</param>
void read_eo(char* in_file, int rgb = 3);

/// <summary>
/// �ڴ�����Ԥ��ͼƬ�� DTFƵ�� ͼ��.
/// </summary>
/// <param name="in_file">Ҫ�鿴��ͼƬ�ļ�.</param>
/// <param name="rgb">ʹ��ɫ��ͨ����012˳��BGR��3Ϊʹ��ȫ��ͨ��).</param>
void read_dtf(char* in_file, int rgb = 3);

/// <summary>
/// �ж��ļ����ͣ�����-1Ϊ�����ڣ�0Ϊ�ļ���1Ϊ�ļ���.
/// </summary>
/// <param name="filename">�ļ���.</param>
/// <returns>int.</returns>
int file_test(const char* filename);

#endif