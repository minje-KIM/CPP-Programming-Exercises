#include <cstdio>
#include "TimeHMS.h"

int main()
{
	int hour, min, sec;
	TimeHMS t1, t2;

	cout << "ù��° �ð��� �Է����ּ���! (�ð�-��-�� ������ �Է�) " << endl;
	cin >> t1;

	cout << "�ι�° �ð��� �Է����ּ���! (�ð�-��-�� ������ �Է�) " << endl;
	cin >> t2;

	cout << endl;
	cout << "ù��° �ð� : " << t1 << endl;
	cout << "�ι�° �ð� : " << t2 << endl;

	cout << endl;
	cout << "���� ���� ���	: " << t1 + t2 << endl;
	cout << "�E�� ���� ���	: " << t1 - t2 << endl;
	
	cout << endl;
	if (t1 == t2)
		cout << "�� ���� �ð��� �����ϴ�" << endl;
	if (t1 != t2)
		cout << "�� ���� �ð��� �ٸ��ϴ�" << endl;
	
	cout << endl;
	cout << "ù��° �ð����� �� �ð� �ø��� : " << ++t1 << endl;
	cout << "ù��° �ð����� �� �ð� ���̱� : " << --t1 << endl;

	cout << endl;
	cout << "ù��° �ð����� 1�� �ø��� : " << t1++ << endl;
	cout << "ù��° �ð����� 1�� ���̱� : " << t1-- << endl;

	cout << endl;
	cout << "���� ù��° �׸��� �ð� : " << t1[0] << "��" << t1[1] << "��" << t1[2] << "��" << endl;
	
	cout << endl;
	cout << "ù��° �ð��� �� ������ ǥ�� : " << int(t1) << "��" << endl;
	cout << "ù��° �ð��� �ð� ������ ǥ�� : " << double(t1) << "�ð�" << endl;
	
	cout << endl;
	cout << "ù��° �ð� 3�� ���� ���� ��� : " << 3 * t1 << endl;

	return 0;
}