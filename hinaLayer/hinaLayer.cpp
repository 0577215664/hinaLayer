#include "hinaLayer.h"
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
int hinaLayer::openfile(char* filename, int mono)
{
	image = imread(filename,(mono==1)?0:1);
	if(image.empty())
	{
		cerr << "����ͼƬ: "<<filename<<" ʧ�ܡ�" << endl;
		return 0;
	}
	return 1;
}

/// <summary>
/// д������ hinaLayer ��ͼ��.
/// </summary>
/// <param name="filename">д���ļ���.</param>
/// <returns>int.</returns>
int hinaLayer::writefile(char* filename)
{
	bool b = imwrite(filename,image);
	if (b!=true)
	{
		cerr<<"д���ļ�"<<filename<<"ʧ��";
		return 0;
	}
	
	return 1;
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


/// <summary>
/// ��һ����������ʾ��ǰ hinaLayer ͼ��.
/// </summary>
void hinaLayer::show()
{
	imshow("Ԥ��", image);
	waitKey(0);
}


/// <summary>
/// ˮƽ����.
/// </summary>
void hinaLayer::mirrorX()
{	
	Mat temp;
	image.copyTo(temp);
	void MirrorX(const Mat &in, Mat &out);
	MirrorX(temp, image);
}

/// <summary>
/// ��ֱ����.
/// </summary>
void hinaLayer::mirrorY()
{
	Mat temp;
	image.copyTo(temp);
	void MirrorY(const Mat &in, Mat &out);
	MirrorY(temp, image);
	
}



int hinaLayer::dtf_make(int rgb)
{
	void make_mmat(Mat& temp, Mat& mmat);
	
	Mat imageSplit[3];
	split(image, imageSplit);

	if (3 == rgb)
	{
		for (int i = 0; i < 3; i++)
		{
			make_mmat(imageSplit[i],mmat[i]);
		}
	}
	else
	{
		make_mmat(imageSplit[rgb], mmat[rgb]);
	}
}



int hinaLayer::dtf_print(int rgb /*= 3*/)
{



}




//openCV ����-----------------------------------


void make_mmat(Mat& in, Mat& out) //Ԥ����������ͼ��ת��Ϊ�ܽ���DFT���м����,����&in,���&out
{
	//ʵ������	
	Mat real_image;

	//��չͼƬ�߽��Ϊ������
	copyMakeBorder(in, real_image,
		0, getOptimalDFTSize(in.rows) - in.rows,
		0, getOptimalDFTSize(in.cols) - in.cols,
		BORDER_CONSTANT,
		Scalar::all(0));

	//���측����Mat0���ͼƬ���ݣ�Mat1���0
	Mat planes[] = { Mat_<float>(real_image), Mat::zeros(real_image.size(), CV_32F) };

	//�ϲ�2MatΪһ��2ͨ��Mat
	merge(planes, 2, out);
}


void show_dft(Mat& in, Mat& out)//��dftת�����Mat���ӻ�����Ϊ0~255�ľ���
{

	//����2��Mat planes��Ϊ���� ������2ͨ���� &in ���� 
	Mat planes[2];
	split(in, planes);

	//������ת��Ϊ����
	magnitude(planes[0], planes[1], out);//��ģ

	//�����߶�(logarithmic scale)����
	out += Scalar::all(1);//ÿ�����ؼ�1
	log(out, out);//����

	void mat_n2c(Mat& in);
	mat_n2c(out);

	//��һ�������0~1
	normalize(out, out, 0, 1, CV_MINMAX);
}







/// <summary>
/// ͼ��ֱ����
/// </summary>
/// <param name="in">����Ҫ�����ͼ��.</param>
/// <param name="out">���뱣������ͼ��.</param>
void MirrorY(const Mat &in, Mat &out)
{
	CV_Assert(in.depth() == CV_8U);
	out.create(in.rows, in.cols, in.type());

	int rows = in.rows;

	for (int i = 0; i < rows; i++)
		in.row(rows - i - 1).copyTo(out.row(i));

}


/// <summary>
/// ͼ��ˮƽ����
/// </summary>
/// <param name="in">����Ҫ�����ͼ��.</param>
/// <param name="out">���뱣������ͼ��.</param>
void MirrorX(const Mat &in, Mat &out)
{
	CV_Assert(in.depth() == CV_8U);
	out.create(in.rows, in.cols, in.type());

	int rows = in.rows;
	int cols = in.cols;

	switch (in.channels())
	{
	case 1:
		const uchar *origal;
		uchar *p;
		for (int i = 0; i < rows; i++){
			origal = in.ptr<uchar>(i);
			p = out.ptr<uchar>(i);
			for (int j = 0; j < cols; j++){
				p[j] = origal[cols - 1 - j];
			}
		}
		break;
	case 3:
		const Vec3b *origal3;
		Vec3b *p3;
		for (int i = 0; i < rows; i++) {
			origal3 = in.ptr<Vec3b>(i);
			p3 = out.ptr<Vec3b>(i);
			for (int j = 0; j < cols; j++){
				p3[j] = origal3[cols - 1 - j];
			}
		}
		break;
	default:
		break;
	}
}































