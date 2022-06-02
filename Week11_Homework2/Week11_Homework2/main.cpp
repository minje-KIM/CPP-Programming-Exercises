#include <cstdio>
#include "TimeHMS.h"

int main()
{
	int hour, min, sec;
	TimeHMS t1, t2;

	cout << "첫번째 시간을 입력해주세요! (시간-분-초 순으로 입력) " << endl;
	cin >> t1;

	cout << "두번째 시간을 입력해주세요! (시간-분-초 순으로 입력) " << endl;
	cin >> t2;

	cout << endl;
	cout << "첫번째 시간 : " << t1 << endl;
	cout << "두번째 시간 : " << t2 << endl;

	cout << endl;
	cout << "덧셈 연산 결과	: " << t1 + t2 << endl;
	cout << "뺼셈 연산 결과	: " << t1 - t2 << endl;
	
	cout << endl;
	if (t1 == t2)
		cout << "두 개의 시간이 같습니다" << endl;
	if (t1 != t2)
		cout << "두 개의 시간이 다릅니다" << endl;
	
	cout << endl;
	cout << "첫번째 시간에서 한 시간 늘리기 : " << ++t1 << endl;
	cout << "첫번째 시간에서 한 시간 줄이기 : " << --t1 << endl;

	cout << endl;
	cout << "첫번째 시간에서 1초 늘리기 : " << t1++ << endl;
	cout << "첫번째 시간에서 1초 줄이기 : " << t1-- << endl;

	cout << endl;
	cout << "현재 첫번째 항목의 시간 : " << t1[0] << "시" << t1[1] << "분" << t1[2] << "초" << endl;
	
	cout << endl;
	cout << "첫번째 시간을 초 단위로 표현 : " << int(t1) << "초" << endl;
	cout << "첫번째 시간을 시간 단위로 표현 : " << double(t1) << "시간" << endl;
	
	cout << endl;
	cout << "첫번째 시간 3배 곱셈 연산 결과 : " << 3 * t1 << endl;

	return 0;
}