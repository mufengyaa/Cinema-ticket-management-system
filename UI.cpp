#define _CRT_SECURE_NO_WARNINGS

#include"work.h"
extern int number_ed;
extern movie* head_movie, * tail_movie;
extern people* head_people, * tail_people;
extern people* head_personal, * tail_personal;
extern int maxpage;
int curpage;

void init(btnode* men,int n) {   //�ָ�ԭ��״̬
	for (int i = 0; i < n; i++) {
		men[i].status = 0;
	}
}
void drawBtn(btnode t,int tx,int ty) {    //���ư�ť
	if (t.status == 0) {
		setfillcolor(RGB(93, 107, 153));
	}
	else {
		setfillcolor(RGB(204, 213, 240));
	}
	setbkmode(TRANSPARENT);
	fillroundrect(t.x, t.y, t.x + 300, t.y + 100, 100, 100);  //��ťͼ���Ĵ�С

	settextstyle(35, 20, _T("����"));
	outtextxy(t.x + tx, t.y + ty,t.text);
}

void drawup1(IMAGE upimg) {   //��������ϲ�
	btnode upmen = { 30,10,"���ӰԺϵͳ" ,0};
	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(300, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown1(IMAGE downimg, btnode* downmen) {   //��������²�
	int i = 0;
	SetWorkingImage(&downimg);
	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < 2; i++) {
		drawBtn(downmen[i],70,38);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int drawui1() {   //ϵͳ������
	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;
	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;

	btnode downmen[2] = { {350,120,_T("����ϵͳ"),0} ,{350,250,_T("�˳�ϵͳ"),0} };
	while (1) {
		drawup1(upimg);
		drawdown1(downimg, downmen);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < 2; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 300 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 100 + 118)
				{
					init(downmen, 2);
					downmen[i].status = 1;
					drawdown1(downimg, downmen);
					return i + 1;
				}
			}
		}
	}
}

void drawup2(IMAGE upimg) {       //��¼������ϲ�
	btnode upmen = { 30,10,_T("��¼����") ,0 };
	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(370, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown2(IMAGE downimg, btnode* downmen) {   //��¼������²�
	int i = 0;
	SetWorkingImage(&downimg);
	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < 3; i++) {
		drawBtn(downmen[i],40,34);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int drawui2() {   //��¼����
	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;

	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;

	btnode downmen[3] = { {350,120,_T("   �˺�"),0} ,{350,250,_T("   ����"),0} ,{350,390,_T(" ���ؽ���"),0} };
	while (1) {
		drawup2(upimg);
		drawdown2(downimg, downmen);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < 3; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 300 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 100 + 118)
				{
					init(downmen, 3);
					downmen[i].status = 1;
					drawdown2(downimg, downmen);
					return i + 1;
				}
			}
		}
	}
}

int drawui3() {    //���ܲ˵�����
	const int width = 1000;
	const int height = 618;
	int i = 0, j = 0;
	MOUSEMSG msg;
	msg.uMsg;
	IMAGE img(width, height);
	btnode men[3] = { { 330,150,_T("  �鿴��Ӱ") ,0 },{ 330,300,_T("�鿴������Ϣ") ,0 },{330,450,_T("����������"),0} };
	SetWorkingImage(&img);
	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < 3; i++) {
		drawBtn(men[i], 36, 32);
	}
	while (1) {
		SetWorkingImage();
		putimage(0, 0, &img);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < 3; i++) {
				if (msg.x >= men[i].x && msg.x <= men[i].x + 300 && msg.y >= men[i].y && msg.y <= men[i].y + 100)
				{
					init(men, 3);
					men[i].status = 1;
					return i + 1;
				}
			}
		}
	}
}

void drawup4(IMAGE upimg) {   //ע�������ϲ�
	btnode upmen = { 30,10,_T("ע�����") ,0 };
	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(370, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown4(IMAGE downimg, btnode* downmen) {   //ע�������²�
	int i = 0;
	SetWorkingImage(&downimg);

	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < 2; i++) {
		drawBtn(downmen[i], 40, 34);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int drawui4() {   //ע�����
	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;

	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;

	btnode downmen[2] = { {350,120,_T("   �˺�"),0} ,{350,250,_T("   ����"),0} };
	while (1) {
		drawup4(upimg);
		drawdown4(downimg, downmen);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < 2; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 300 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 100 + 118)
				{
					init(downmen, 2);
					downmen[i].status = 1;
					drawdown4(downimg, downmen);
					return i + 1;
				}
			}
		}
	}
}

void drawBtn5(btnode t, int tx, int ty) {    //���ư�ť
	if (t.status == 0) {
		setfillcolor(RGB(93, 107, 153));
	}
	else {
		setfillcolor(RGB(204, 213, 240));
	}
	setbkmode(TRANSPARENT);
	fillroundrect(t.x, t.y, t.x + 230, t.y + 100, 80, 80);

	settextstyle(35, 20, _T("����"));
	outtextxy(t.x + tx, t.y + ty, t.text);
}
void drawup5(IMAGE upimg) {   //��Ӱ�˵�������ϲ�
	btnode upmen = { 30,10,_T("   ��Ӱ�˵�") ,0 };
	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(300, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown5(IMAGE downimg, btnode* downmen, int num) {   //��Ӱ�˵�������²�
	int i = 0;
	SetWorkingImage(&downimg);

	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < num; i++) {
		drawBtn5(downmen[i], 21, 34);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int drawui5(int num, movie* head) {   //��Ӱ�˵�
	movie* p = head->next;
	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;

	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;

	btnode downmen[10] = { 0 };
	for (i = 0; i < num; i++) {
		if (i >= 0 && i < 3) {
			downmen[i] = { 100 + i * 300,100," ",0 };
			strcpy(downmen[i].text, p->name);
		}
		else {
			downmen[i] = { 100 + (i - 3) * 300,100 + 200," ",0 };
			strcpy(downmen[i].text, p->name);
		}
		p = p->next;
	}
	if (num >= 3) {
		downmen[num] = { 100 + (num - 3) * 300,100 + 200,_T("   ����"),0 };
	}
	else {
		downmen[num] = { 100 + num * 300,100,_T("   ����"),0 };
	}

	while (1) {
		drawup5(upimg);
		drawdown5(downimg, downmen, num+1);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < num+1; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 230
					&& msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 100 + 118)
				{
					init(downmen, num+1);
					downmen[i].status = 1;
					drawdown5(downimg, downmen, num+1);
					return i + 1;
				}
			}
		}
	}
}

void drawBtn_movie_day(btnode t, int tx, int ty) {    //���ư�ť
	if (t.status == 0) {
		setfillcolor(RGB(93, 107, 153));
	}
	else {
		setfillcolor(RGB(204, 213, 240));
	}
	setbkmode(TRANSPARENT);
	fillroundrect(t.x, t.y, t.x + 230, t.y + 100, 80, 80);

	settextstyle(35, 20, _T("����"));
	outtextxy(t.x + tx, t.y + ty, t.text);
}
void drawup_movie_day(IMAGE upimg,char* name,int price) {   //������ӳ��Ӱ������ϲ�
	btnode upmen = { 30,10," " ,0};
	strcpy(upmen.text, name);
	strcat(upmen.text, " Ʊ��:");
	char s[10] = { 0 };
	_itoa(price,s, 10);
	strcat(upmen.text, s);

	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(390, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown_movie_day(IMAGE downimg, btnode* downmen, int num) {   //������ӳ��Ӱ������²�
	int i = 0;
	SetWorkingImage(&downimg);

	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < num+1; i++) {
		drawBtn_movie_day(downmen[i], 27, 20);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int drawmovie_day(char* name,int day,int price,movie* p) {
	FILE* fp = fopen("��Ӱ\\������ӳ��Ӱ.txt", "r");

	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;

	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;

	btnode downmen[10] = { 0 };
	for (i = 0; i < day; i++) {
		downmen[i] = { 390,i * 140," ",0 };
		strcpy(downmen[i].text, p->date[i]);
	}
	downmen[day] = { 390,day * 140,"���ص�Ӱ",0 };
	while (1) {
		drawup_movie_day(upimg,p->name,p->allprice);
		drawdown_movie_day(downimg, downmen, day);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < day+1; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 230
					&& msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 100 + 118){
					init(downmen, day+1);
					downmen[i].status = 1;
					drawdown_movie_day(downimg, downmen, day);
					return i + 1;
				}
			}
		}
	}	
}

void drawBtn_movie_day1(btnode t, int tx, int ty) {    //���ư�ť
	if (t.status == 0) {
		setfillcolor(RGB(93, 107, 153));
	}
	else {
		setfillcolor(RGB(204, 213, 240));
	}
	setbkmode(TRANSPARENT);
	fillroundrect(t.x, t.y, t.x + 230, t.y + 100, 80, 80);

	settextstyle(35, 20, _T("����"));
	outtextxy(t.x + tx, t.y + ty, t.text);
}
void drawup_movie_day1(IMAGE upimg, char* name, int price) {   //������ӳ��Ӱ������ϲ�
	btnode upmen = { 30,10," " ,0 };
	strcpy(upmen.text, name);

	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(390, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown_movie_day1(IMAGE downimg, btnode* downmen, int num) {   //������ӳ��Ӱ������²�
	int i = 0;
	SetWorkingImage(&downimg);

	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < num + 1; i++) {
		drawBtn_movie_day1(downmen[i], 27, 20);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int drawmovie_day1(movie* p,int a) {   //��ѡ��Ӱ��һ��ĳ���
	FILE* fp = fopen("��Ӱ\\������ӳ��Ӱ.txt", "r");
	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;

	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;

	int num = p->count[a];
	btnode downmen[10] = { 0 };
	for (i = 0; i < num; i++) {
		downmen[i] = { 390,i * 140," ",0 };
		strcpy(downmen[i].text, p->time[i]);
	}
	downmen[num] = { 390,num * 140,"��������",0 };
	while (1) {
		drawup_movie_day1(upimg, p->name,p->price);
		drawdown_movie_day1(downimg, downmen, num);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < num + 1; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 230
					&& msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 100 + 118) {
					init(downmen, num + 1);
					downmen[i].status = 1;
					drawdown_movie_day1(downimg, downmen, num);
					return i+1;
				}
			}
		}
	}
}

void drawBtn6(btnode t, int tx, int ty) {    //���ư�ť
	if (t.status == 0) {
		setfillcolor(RGB(93, 107, 153));
	}
	else {
		setfillcolor(RGB(204, 213, 240));
	}
	setbkmode(TRANSPARENT);
	fillroundrect(t.x, t.y, t.x + 300, t.y + 80, 100, 100);  //��ťͼ���Ĵ�С

	settextstyle(35, 20, _T("����"));
	outtextxy(t.x + tx, t.y + ty, t.text);
}
void drawup6(IMAGE upimg) {   //������Ϣ������ϲ�
	btnode upmen = { 30,10,_T("������Ϣ") ,0 };
	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(370, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown6(IMAGE downimg, btnode* downmen) {   //������Ϣ������²�
	int i = 0;
	SetWorkingImage(&downimg);

	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < 5; i++) {
		drawBtn6(downmen[i], 59, 31);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int personal_information() {   //������Ϣ����
	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;

	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;

	btnode downmen[5] = { {350,10,_T("���˶���"),0} ,{350,110,_T("��������"),0}, {350,210,_T("�޸�����"),0}, {350,310,_T("�˳���¼"),0},{350,410,_T("  ����"),0}};
	while (1) {
		drawup6(upimg);
		drawdown6(downimg, downmen);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < 5; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 300 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 100 + 118)
				{
					init(downmen, 5);
					downmen[i].status = 1;
					drawdown6(downimg, downmen);
					return i + 1;
				}
			}
		}
	}
}

void drawupsort(IMAGE upimg) {   //���������ϲ�
	btnode upmen = { 30,10,"��������" ,0 };
	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(360, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdownsort(IMAGE downimg, btnode* downmen) {   //���������²�
	int i = 0;
	SetWorkingImage(&downimg);
	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < 3; i++) {
		drawBtn(downmen[i], 18, 38);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int sortui() {     //�������
	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;
	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;

	btnode downmen[3] = { {350,100,_T("����Ӱ��˳��"),0} ,{350,250,_T("����Ӱ������"),0},{350,400,_T("     ����"),0} };
	while (1) {
		drawupsort(upimg);
		drawdownsort(downimg, downmen);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < 3; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 300 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 100 + 118)
				{
					init(downmen, 3);
					downmen[i].status = 1;
					drawdownsort(downimg, downmen);
					return i + 1;
				}
			}
		}
	}
}
void drawBtn_individual_order(btnode t, int tx, int ty) {    //���ư�ť
	if (t.status == 0) {
		setfillcolor(RGB(93, 107, 153));
	}
	else {
		setfillcolor(RGB(204, 213, 240));
	}
	setbkmode(TRANSPARENT);
	fillroundrect(t.x, t.y, t.x + 700, t.y + 65,50,50);  //��ťͼ���Ĵ�С

	settextstyle(35, 20, _T("����"));
	outtextxy(t.x + tx, t.y + ty, t.text);
}
void drawup7(IMAGE upimg) {   //������Ϣ������ϲ�
	btnode upmen = { 30,10,_T("���˶���") ,0 };
	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(370, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown7(IMAGE downimg, btnode* downmen,int num) {   //������Ϣ������²�
	int i = 0;
	SetWorkingImage(&downimg);

	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < num; i++) {
		drawBtn_individual_order(downmen[i], 130, 13);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int individual_order(int num,people* head) {   //���˶�������  ���������Ʊ
	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;

	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;
	IMAGE img(width, height);
	btnode downmen[10] = { 0 };
	people* p = head->next;
	char arr[200] = { 0 };
	for (i = 0; i < num; i++) {
		strcpy(arr, p->name);
		strcat(arr, " ");
		strcat(arr, p->date);
		strcat(arr, " ");
		strcat(arr, p->time);
		strcat(arr, " ");
		char t[5] = { 0 };  //�۸�ת�ַ���
		snprintf(t, sizeof(t), "%d", p->price);
		strcat(arr, t);
		downmen[i] = { 150,i * 75+5,"",0 };
		strcpy(downmen[i].text, arr);   //������text
		p = p->next;
	}
	downmen[num] = { 150,num * 75+5,"        ���ؽ���",0 };
	SetWorkingImage(&img);
	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	while (1) {
		drawup7(upimg);
		drawdown7(downimg, downmen,num+1);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < num+1; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 700 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 65 + 118)
				{
					init(downmen, num+1);
					downmen[i].status = 1;
					drawdown7(downimg, downmen,num+1);
					return i + 1;
				}
			}
		}
	}
}

int drawui9() {    //���ܲ˵�����
	const int width = 1000;
	const int height = 618;
	int i = 0, j = 0;
	MOUSEMSG msg;
	msg.uMsg;
	IMAGE img(width, height);
	btnode men[4] = { { 330,50,_T("  �ϼܵ�Ӱ") ,0 },{330,200,_T("  �¼ܵ�Ӱ"),0}, {330,350,_T("  �鿴��Ϣ") ,0},{330,500,_T(" ����������"),0}};
	SetWorkingImage(&img);
	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < 4; i++) {
		drawBtn(men[i], 36, 32);
	}
	while (1) {
		SetWorkingImage();
		putimage(0, 0, &img);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < 4; i++) {
				if (msg.x >= men[i].x && msg.x <= men[i].x + 300 && msg.y >= men[i].y && msg.y <= men[i].y + 100)
				{
					init(men, 4);
					men[i].status = 1;
					return i + 1;
				}
			}
		}
	}
}

void drawBtn9(btnode t, int tx, int ty) {    //���ư�ť
	if (t.status == 0) {
		setfillcolor(RGB(93, 107, 153));
	}
	else {
		setfillcolor(RGB(204, 213, 240));
	}
	setbkmode(TRANSPARENT);
	fillroundrect(t.x, t.y, t.x + 230, t.y + 100, 80, 80);

	settextstyle(35, 20, _T("����"));
	outtextxy(t.x + tx, t.y + ty, t.text);
}
void drawup9(IMAGE upimg) {   //��Ӱ�˵�������ϲ�
	btnode upmen = { 30,10,_T("���¼ܵ�Ӱ") ,0 };
	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(300, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown9(IMAGE downimg, btnode* downmen, int num) {   //��Ӱ�˵�������²�
	int i = 0;
	SetWorkingImage(&downimg);

	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < num; i++) {
		drawBtn9(downmen[i], 21, 34);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int release_movie(int num, char arr[10][40]) {   //�ϼܵ�Ӱ����
	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;

	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;

	btnode downmen[10] = { 0 };
	for (i = 0; i < num; i++) {
		if (i >= 0 && i < 3) {
			downmen[i] = { 100 + i * 300,100," ",0 };
			strcpy(downmen[i].text, arr[i]);
		}
		else {
			downmen[i] = { 100 + (i - 3) * 300,100 + 200," ",0 };
			strcpy(downmen[i].text, arr[i]);
		}
	}
	if (num >= 3) {
		downmen[num] = { 100 + (num - 3) * 300,100 + 200,_T("   ����"),0 };
	}
	else {
		downmen[num] = { 100 + num * 300,100,_T("   ����"),0 };
	}

	while (1) {
		drawup9(upimg);
		drawdown9(downimg, downmen, num + 1);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < num + 1; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 230
					&& msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 100 + 118)
				{
					init(downmen, num + 1);
					downmen[i].status = 1;
					drawdown9(downimg, downmen, num + 1);
					return i + 1;
				}
			}
		}

	}
}

void drawBtn8(btnode t, int tx, int ty) {    //���ư�ť
	if (t.status == 0) {
		setfillcolor(RGB(93, 107, 153));
	}
	else {
		setfillcolor(RGB(204, 213, 240));
	}
	setbkmode(TRANSPARENT);
	fillroundrect(t.x, t.y, t.x + 300, t.y + 85, 100, 100);  //��ťͼ���Ĵ�С

	settextstyle(35, 20, _T("����"));
	outtextxy(t.x + tx, t.y + ty, t.text);
}
void drawup8(IMAGE upimg) {   //����Ա��Ϣ������ϲ�
	btnode upmen = { 30,10,_T("�鿴��Ϣ") ,0 };
	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(380, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown8(IMAGE downimg, btnode* downmen) {   //����Ա��Ϣ������²�
	int i = 0;
	SetWorkingImage(&downimg);

	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < 5; i++) {
		drawBtn8(downmen[i], 40, 34);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int manager_information() {
	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;

	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;

	btnode downmen[5] = { {350,10,_T(" ������Ϣ"),0},{350,110,_T(" ��Ʊ��Ϣ"),0}, {350,210,_T(" �޸�����"),0},{350,310,_T(" �˳���¼"),0},{350,410,_T("   ����")}};
	while (1) {
		drawup8(upimg);
		drawdown8(downimg, downmen);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < 5; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 300 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 100 + 118)
				{
					init(downmen, 5);
					downmen[i].status = 1;
					drawdown8(downimg, downmen);
					return i + 1;
				}
			}
		}
	}
}

void drawBtn11(btnode t, int tx, int ty) {    //���ư�ť
	setfillcolor(RGB(93, 107, 153));
	setbkmode(TRANSPARENT);
	fillroundrect(t.x, t.y, t.x + 700, t.y + 65, 50, 50);  //��ťͼ���Ĵ�С

	settextstyle(35, 20, _T("����"));
	outtextxy(t.x + tx, t.y + ty, t.text);
}
void drawup11(IMAGE upimg) {   //������Ϣ������ϲ�
	btnode upmen = { 30,10,_T("���˶���") ,0 };
	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(370, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown11(IMAGE downimg, btnode* downmen, int num) {   //������Ϣ������²�
	int i = 0;
	SetWorkingImage(&downimg);

	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < num + 1; i++) {
		drawBtn11(downmen[i], 50, 10);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
//int refundui(int num) {
//	int i = 0, j = 0;
//	const int width = 1000;
//	const int height = 618;
//
//	IMAGE upimg(width, 118);
//	IMAGE downimg(width, height - 118);
//	MOUSEMSG msg;
//	msg.uMsg;
//	IMAGE img(width, height);
//	btnode downmen[10] = { 0 };
//	FILE* fp = fopen("����Ա\\��Ʊ��Ϣ.txt", "r");
//	char t[30] = { 0 };
//	fgets(t, 200, fp);
//	char arr[10][200] = { 0 };
//	for (int i = 0; i < num; i++) {
//		downmen[i] = { 150,i * 75 + 5,"",0 };
//		fgets(downmen[i].text, 200, fp);
//	}
//	fclose(fp);
//	downmen[num] = { 150,num * 75 + 5,"        ���ؽ���",0 };
//	SetWorkingImage(&img);
//	setbkcolor(RGB(247, 249, 254));
//	cleardevice();
//
//	while (1) {
//		drawup11(upimg);
//		drawdown11(downimg, downmen, num);
//		msg = GetMouseMsg();
//		if (msg.uMsg == WM_LBUTTONDOWN) {
//			for (i = 0; i < num + 1; i++) {
//				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 700 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 65 + 118)
//				{
//					return i + 1;
//				}
//			}
//		}
//	}
//}
int flag_refund = 0;
int refundui(people* p, int num, int curpage, int maxpage,int r) {
	if (flag_refund == 1) {
		return 1;
	}
	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;

	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;
	IMAGE img(width, height);
	btnode downmen[10] = { 0 };
	char t[30] = { 0 };
	char arr[300] = { 0 };
	if (num <= 6 && curpage == 1) {
		p = p->next;
		for (int i = 0; i < num; i++) {
			strcpy(arr, p->acc);
			strcpy(arr, p->name);
			strcat(arr, " ");
			strcat(arr, p->date);
			strcat(arr, " ");
			strcat(arr, p->time);
			strcat(arr, " ");
			char t[5] = { 0 };  //�۸�ת�ַ���
			snprintf(t, sizeof(t), "%d", p->price);
			strcat(arr, t);
			downmen[i] = { 150,i * 75 + 5,"",0 };
			strcpy(downmen[i].text, arr);   //������text
			p = p->next;
		}
		downmen[num] = { 150,num * 75 + 5,"        ���ؽ���",0 };
	}
	else if (num > 6 && curpage == 1) {
		p = p->next;
		for (int i = 0; i < 5; i++) {
			strcpy(arr, p->acc);
			strcpy(arr, p->name);
			strcat(arr, " ");
			strcat(arr, p->date);
			strcat(arr, " ");
			strcat(arr, p->time);
			strcat(arr, " ");
			char t[5] = { 0 };  //�۸�ת�ַ���
			snprintf(t, sizeof(t), "%d", p->price);
			strcat(arr, t);
			downmen[i] = { 150,i * 75 + 5,"",0 };
			strcpy(downmen[i].text, arr);   //������text
			p = p->next;
		}
		downmen[5] = { 150,5 * 75 + 5,"           ��һҳ",0 };
		downmen[6] = { 150,6 * 75 + 5,"         ���ؽ���",0 };
	}
	else if (num > 6 && curpage > 1 && curpage< maxpage) {
		for (int i = 0; i < 5; i++) {
			strcpy(arr, p->acc);
			strcpy(arr, p->name);
			strcat(arr, " ");
			strcat(arr, p->date);
			strcat(arr, " ");
			strcat(arr, p->time);
			strcat(arr, " ");
			char t[5] = { 0 };  //�۸�ת�ַ���
			snprintf(t, sizeof(t), "%d", p->price);
			strcat(arr, t);
			downmen[i] = { 150,i * 75 + 5,"",0 };
			strcpy(downmen[i].text, arr);   //������text
			p = p->next;
		}
		downmen[5] = { 150,5 * 75 + 5,"           ��һҳ",0 };
		downmen[6] = { 150,6 * 75 + 5,"           ��һҳ",0 };
	}
	else if (curpage == maxpage) {
		for (int i = 0; i < r; i++) {
			strcpy(arr, p->acc);
			strcpy(arr, p->name);
			strcat(arr, " ");
			strcat(arr, p->date);
			strcat(arr, " ");
			strcat(arr, p->time);
			strcat(arr, " ");
			char t[5] = { 0 };  //�۸�ת�ַ���
			snprintf(t, sizeof(t), "%d", p->price);
			strcat(arr, t);
			downmen[i] = { 150,i * 75 + 5,"",0 };
			strcpy(downmen[i].text, arr);   //������text
			if (i != r - 1) {
				p = p->next;
			}
		}
		downmen[r] = { 150,r * 75 + 5,"           ��һҳ",0 };
	}
	SetWorkingImage(&img);
	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	while (1) {
		if (flag_refund == 1) {
			return 1;
		}
		drawup11(upimg);
		if ((num <= 6 && curpage == 1)) {
			drawdown11(downimg, downmen, num);
		}
		else if(curpage < maxpage){
			drawdown11(downimg, downmen, 6);
		}
		else {
			drawdown11(downimg, downmen, r);
		}
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && curpage == 1 && maxpage == 1) {
			for (i = 0; i < num + 1; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 700 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 65 + 118)
				{
					if (i == num) {
						flag_refund = 1;
						return 1;
						if (flag_refund == 1) {
							return 1;
						}
					}
				}
			}
		}
		else if (msg.uMsg == WM_LBUTTONDOWN && curpage == 1 && maxpage > 1) {
			for (i = 0; i < 7; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 700 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 65 + 118)
				{
					if (i == 5) {   //��һҳ
						refundui(p, num, curpage + 1, maxpage,r);
					}
					if (i == 6) {
						flag_refund = 1;
						return 1;
						if (flag_refund == 1) {
							return 1;
						}
					}
				}
			}
		}
		else if (msg.uMsg == WM_LBUTTONDOWN && curpage > 1 && curpage < maxpage) {
			for (i = 0; i < 7; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 700 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 65 + 118)
				{
					if (i == 5) {  //��һҳ
						int tmp = 5;
						while (tmp--) {
							p = p->period;
						}
						tmp = 5;
						while (tmp--) {
							p = p->period;
						}
						refundui(p, num, curpage - 1, maxpage,r);
					}
					else if (i == 6) {   //��һҳ
						refundui(p, num, curpage + 1, maxpage,r);
					}
				}
			}
		}
		else if (msg.uMsg == WM_LBUTTONDOWN && curpage == maxpage) {
			for (i = 0; i < r + 1; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 700 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 65 + 118) {
					if (i == r) {
						int tmp = r;
						while (tmp--) {
							p = p->period;
						}
						tmp = 5;
						while (tmp--) {
							p = p->period;
						}
						refundui(p, num, curpage - 1, maxpage,r);
					}
				}
			}
		}
	}
}

void drawup12(IMAGE upimg) {   //��������ϲ�
	btnode upmen = { 30,10,"  ��ӳ��Ӱ" ,0 };
	SetWorkingImage(&upimg);
	setbkcolor(RGB(93, 107, 153));
	cleardevice();
	settextstyle(50, 30, _T("����"));
	outtextxy(300, 35, upmen.text);
	SetWorkingImage();
	putimage(0, 0, &upimg);
}
void drawdown12(IMAGE downimg, btnode* downmen) {   //��������²�
	int i = 0;
	SetWorkingImage(&downimg);
	setbkcolor(RGB(247, 249, 254));
	cleardevice();

	for (i = 0; i < 3; i++) {
		drawBtn(downmen[i], 10, 38);
	}
	SetWorkingImage();
	putimage(0, 119, &downimg);
}
int release_choose() {
	int i = 0, j = 0;
	const int width = 1000;
	const int height = 618;
	IMAGE upimg(width, 118);
	IMAGE downimg(width, height - 118);
	MOUSEMSG msg;
	msg.uMsg;

	btnode downmen[3] = { {350,120,_T("�鿴���¼ܵ�Ӱ"),0} ,{350,240,_T("   ������Ӱ"),0},{350,360,_T("     ����"),0} };
	while (1) {
		drawup12(upimg);
		drawdown12(downimg, downmen);
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			for (i = 0; i < 3; i++) {
				if (msg.x >= downmen[i].x && msg.x <= downmen[i].x + 300 && msg.y >= downmen[i].y + 118 && msg.y <= downmen[i].y + 100 + 118)
				{
					init(downmen, 3);
					downmen[i].status = 1;
					drawdown12(downimg, downmen);
					return i + 1;
				}
			}
		}
	}
}