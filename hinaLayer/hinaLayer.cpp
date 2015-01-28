#include "hinaLayer.h"
//C++
#include <iostream>
#include <string>
#include<bitset>
#include<fstream>
#include<math.h>
//openCV 
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;



//����


/// <summary>
/// ���ļ��Դ��� hinaLayer ��������
/// </summary>
/// <param name="filename">Ҫ�򿪵�ͼ���ļ���.</param>
/// <param name="mono">�Ƿ����Ϊ��ɫͼ��0Ϊ��ɫ��1Ϊ��ɫ��ȱʡΪ0.</param>
/// <returns>����0���ļ�ʧ��</returns>
int hinaLayer::openfile(char* filename, int mono = 0)
{
	auto image = imread(filename,(mono==1)?0:1);
	if(image.empty())
	{
		cerr << "����ͼƬ: "<<filename<<" ʧ�ܡ�" << endl;
		return 0;
	}
	return 1;
}

int writefile(char* filename)
{
	
}






/// <summary>
/// ��������ͼ���С��ͼ�����ݽ�������.
/// </summary>
/// <param name="w">��ͼ���� w.</param>
/// <param name="h">��ͼ��߶� h.</param>
/// <returns>int.</returns>
void hinaLayer::resize(int w,int h)
{
	Mat temp(w,h,image.type());
    cv::resize(image,temp,temp.size(),0,0,CV_INTER_NN);
	temp.copyTo(image);
}





















