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


	int openfile(char* filename, int mono = 0);//���ļ�
	int writefile(char* filename);//д���ļ�
	void show();//Ԥ��ͼ��
	void show_fdomain();//Ԥ��Ƶ��ͼ��

	void resize(int w,int h);//����ͼ���С
	void mirrorY();//��ֱ����
	void mirrorX();//ˮƽ����

	int  dtf_make(int rgb = 3);//ͼ��ת����DTF�м����
	int  dtf_print(int rgb = 3);//DTF�м������ӻ���Ƶ��ͼ>>fdomain
	int  dtf_inverse_make(int rgb = 3);//DTF�м������ת����ͼ��
	int	 dtf_write_mask(Mat& mask, int rgb = 3);
	int	 dtf_write_mask(char* mask_file, int rgb = 3);
	void dtf_mmat_n2c(int rgb = 3);//DTF�м�������޵���
	

	void dtf_to_image(int rgb = 3);

	//out
};














#endif



