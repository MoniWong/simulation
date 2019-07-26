#pragma once
#include <opencv2/core/core.hpp>
// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� ADDSNOW_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ���Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// ADDRAIN_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef ADDRAIN_EXPORTS
#define ADDRAIN_API __declspec(dllexport)
#else
#define ADDRAIN_API __declspec(dllimport)
#endif
int whether(int, int);
std::vector<int> getRandList(int, int);
ADDRAIN_API cv::Mat addRain(cv::Mat oriImg, double alpha, std::string);