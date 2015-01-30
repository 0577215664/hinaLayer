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
	Mat mmat[3];//Ƶ���þ���
	int openfile(char* filename, int mono = 0);//���ļ�
	int writefile(char* filename);//д���ļ�
	void show();//Ԥ��ͼ��

	void resize(int w,int h);//����ͼ���С
	void mirrorY();//��ֱ����
	void mirrorX();//ˮƽ����

	int  dtf_make(int rgb = 3);
	int  dtf_print(int rgb = 3);

	//out
};














#endif



