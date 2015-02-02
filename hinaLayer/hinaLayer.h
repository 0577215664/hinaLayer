#ifndef HINALAYER_H
#define HINALAYER_H


//openCV 
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;


/// <summary>
/// Class hinaLayer.
/// </summary>
class hinaLayer
{
public:

	Mat image;//ͼ�����ݾ���
	Mat fdomain;//Ƶ���þ���
	Mat mmat[3];//DTF�任�þ���

	int open_file(char* filename, int mono = 0);//���ļ�
	int out_file(char* filename);//д���ļ�
	int out_file_fdomain(char* filename);//д���ļ�(Ƶ��ͼ��)
	void show(string title = "Ԥ��ԭͼ��image��");//Ԥ��ͼ��
	void show_fdomain(string title = "Ԥ��Ƶ��ͼ��fdomain��");//Ԥ��Ƶ��ͼ��
	void show_eo(string title = "��żͼ��", int rgb = 3);//Ԥ��Ƶ��ͼ��

	void resize(int w,int h);//����ͼ���С
	void mirrorY();//��ֱ����
	void mirrorX();//ˮƽ����

	int  dtf_make(int rgb = 3);//ͼ��ת����DTF�м����image >> mmat����ָ��ͨ��
	int  dtf_inverse_make(int rgb = 3);//DTF�м������ת����ͼ��mmat >> image����ָ��ͨ��
	int  dtf_print(int rgb = 3);//DTF�м������ӻ���mmat >> fdomain����ָ��ͨ��
	void dtf_mmat_n2c(int rgb = 3);//DTF�м����mmat�����޵�����ָ��ͨ��
	int	 dtf_write_mask(Mat& mask, int rgb = 3);//�� DTF�м����mask -> mmat�� д��ˮӡͼ�����ָ��ͨ��
	int	 dtf_write_mask(char* mask_file, int rgb = 3);//�� DTF�м����mask.png -> mmat�� д��ˮӡͼ���ļ���ָ��ͨ��

	void eo_to_image(int rgb = 3);//��żλ���ӻ���ͼ��ת����ͼ�����ݾ���(image)��
	void eo_write_mask(char* mask_file, int rgb = 3, int auto_size = 0);//��ͼ����żλ��д��ˮӡ��mask -> image����ָ��ͨ����auto_size �����Ƿ��Զ�����ˮӡ��С
	void eo_write_mask(Mat& mask, int rgb = 3, int auto_size = 0);//��ͼ����żλ��д��ˮӡ��mask.png -> image����ָ��ͨ����auto_size �����Ƿ��Զ�����ˮӡ��С
	void eo_write_file(char* info_file, int rgb = 3);//��ͼ����żλ��д���ļ����������ݣ�file -> image����ָ��ͨ��
	void eo_out_file(char* out_file, int rgb = 3);//��ͼ����żλ������Ϊ�����������ļ�д����image -> file����ָ��ͨ��


	void lsb_write_file(char* info_file, int rgb = 3);//��ͼ���������ݵ�λд���ļ����������ݣ�file -> image��
	void lsb_out_file(char* info_file, int rbg = 3, int en_deep = 0);//�ڰ�ͼ���������ݵ�λ��Ϊ�����������ļ�д����image -> file��;en_deep ǿ��ָ����ȣ�Ϊ0�Զ���ָ��ͨ��
	unsigned long lsb_get_max(int rgb = 3);//����ͼ������д����������ݵĴ�С����λ�ֽڣ�ָ��ͨ��
	int lsb_get_deep(char* file, int rgb = 3);// ����һ���ļ�д�뵽ͼ��Ӧ��ʹ�õ���ȣ�ָ��ͨ��

private:
	void dtf_to_image(int rgb = 3);//DTF�м����mmat��ת����ͼ�����ݾ���(image)

	//out
};


#endif



