#define _CRT_SECURE_NO_WARNINGS

#include"work.h"
extern movie* head_movie, * tail_movie;
extern people* head_people, * tail_people;
extern people* head_personal, * tail_personal;
extern people* head_refund, * tail_refund;
extern int number_ing, number_ed, number_refund;
extern char acc[30], key[30];
extern char manager_acc[30], manager_key[30];
extern int order_num, personal_order_num;
extern char moviename[10][40];
int maxpage;
extern int flag_refund;
int check_account_validity(char* p2) { //����˺��Ƿ�Ƿ�
	while (*p2 != '\0') {
		if ((*p2 >= '0' && *p2 <= '9')) {
			p2++;
		}
		else {
			return 1;
		}
	}
	return 0;
}
int check_key_validity(char* p2) {  //��������Ƿ�Ƿ�
	while (*p2 != '\0') {
		if ((*p2 >= '0' && *p2 <= '9') || (*p2 >= 'A' && *p2 <= 'Z') || (*p2 >= 'a' && *p2 <= 'z')) {
			p2++;
		}
		else {
			return 1;   //�Ƿ�
		}
	}
	return 0;
}

int scanf_account(char* t1) {
	while (1) {
		char c = 0;
		int i = 0;
		if (InputBox(t1, 40, NULL, _T("��¼"), _T("�������˺�"), 400, 200, false) == false) {
			return 0;
		}
		int a1 = check_account_validity(t1);
		if ( a1 == 0) {
			if (strlen(t1) > 10) {
				memset(t1, 0, sizeof(t1));
				HWND hnd = GetHWnd();
				SetWindowText(hnd, "����");
				MessageBox(hnd, "�˺ų��ȳ�������,����������", "��ʾ", MB_OKCANCEL);
				continue;
			}
			if (strcmp(acc, t1) == 0|| strcmp(manager_acc, t1) == 0) {    //�Ϸ������
				if (strcmp(acc, t1) == 0) {
					return 1;
				}
				return 2;
			}
			else {   //�Ϸ�����ͬ
				memset(t1, 0, sizeof(t1));
				HWND hnd = GetHWnd();
				SetWindowText(hnd, "����");
				MessageBox(hnd, "�˺Ŵ���,����������", "��ʾ", MB_OKCANCEL);
				continue;
			}
		}
        else {   //�Ƿ�
			memset(t1, 0, sizeof(t1));
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "����");
			MessageBox(hnd, "����Ƿ��ַ�,����������", "��ʾ", MB_OKCANCEL);
			continue;
		}
	}
}
int scanf_key(char* t2,int flag) {  //��������
	int i = 0;
	char a = 0;
	int t = 0;
	while (1) {
		if (t == 1) {
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "����");
			MessageBox(hnd, "����ʧ��1��,����2���������", "��ʾ", MB_OKCANCEL);
		}
		else if (t == 2) {
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "����");
			MessageBox(hnd, "����ʧ��2��,����1���������", "��ʾ", MB_OKCANCEL);
		}
		else if (t == 3) {
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "����");
			MessageBox(hnd, "����ʧ��3��,����0���������,��������������", "��ʾ", MB_OKCANCEL);
			return 0;  //����������
		}
		if (InputBox(t2, 40, NULL, _T("��¼"), _T("����������"), 400, 200, false) == false) {
			return 0;
		}
		//�ж��Ƿ�Ϸ�
		if (check_key_validity(t2) == 0) {
			if (strlen(t2) > 10) {
				memset(t2, 0, sizeof(t2));
				HWND hnd = GetHWnd();
				SetWindowText(hnd, "����");
				MessageBox(hnd, "���볤�ȳ�������,����������", "��ʾ", MB_OKCANCEL);
				continue;
			}
			if ((strcmp(key, t2) == 0 && flag == 1) || (strcmp(manager_key, t2) == 0 && flag == 2)) {    //�Ϸ������
				if (strcmp(key, t2) == 0 && flag==1) {
					return 1;
				}
  				if (strcmp(manager_key, t2) == 0 && flag == 2) {
					return 2;
				}
			}
			else {  //�Ϸ�,��ͬ
				memset(t2, 0, sizeof(t2));
				HWND hnd = GetHWnd();
				SetWindowText(hnd, "����");
				int a1 = MessageBox(hnd, "�������,����������", "��ʾ", MB_OKCANCEL);
				if (a1 == 1) {
					t++;  //��������ۼ�
					continue;
				}
				continue;
			}
		}
		else {   //���Ϸ�
			memset(t2, 0, sizeof(t2));
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "����");
			MessageBox(hnd, "����Ƿ��ַ�,����������", "��ʾ", MB_OKCANCEL);
			continue;
		}
	}
}

int select_movie_date(movie* p) {
	while (1) {
		int day = p->day;  //ȷ���õ�Ӱ��Ƭ��
		int a3 = drawmovie_day(p->name,p->day,p->allprice, p);   //ѡ������
		if (a3 == day + 1) {
			return 1;  //�ص���Ӱ����
		}
		else {
			int a5 = p->count[a3 - 1];   //ȷ������ĳ���
			int a4 = drawmovie_day1(p, a3 - 1);  //ѡ��ʱ��  //a3-1�Ǹ����Ӧ���±�  
			if (a4 == a5 + 1) {   //ѡ�������һ����ť
				continue;  //����
			}
			else {
				shop(head_movie,p, head_people,&tail_people,head_personal,&tail_personal,a3, a4);
				return 0;  //������ɺ�ص��û��˵�����
			}
		}
	}
}
int select_movie(movie* head) {
	while (1) {
		movie* p = head_movie;
		int a1 = drawui5(number_ing, head_movie); //��Ӱ����
		if (personal_order_num == 6) {
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "����");
			MessageBox(hnd, "����ӵ�е�Ʊ���ѳ�������", "��ʾ", MB_OKCANCEL);
			return 0;
		}
		if (a1 == number_ing + 1) {
			return 0;
		}
		while (a1--) {
			p = p->next;   //ѭ����pָ��õ�Ӱ
		}
		int a2 = select_movie_date(p);
		if (a2 == 1) {
			continue;
		}
		else if (a2 == 0) {
			return 0;
		}
	}
}
int change_key(char* key,char* t) {
	HWND hnd = GetHWnd();
	SetWindowText(hnd, "����");
	int a = MessageBox(hnd, "�Ƿ�Ҫ�޸�����", "��ʾ", MB_OKCANCEL);
	if (a == 1) {
		while (1) {
			char c = 0;
			int i = 0;
			InputBox(t, 40, NULL, _T("�޸�����"), _T("��������Ҫ�޸ĵ�����"), 400, 200, false);
			while (c != '\0') {
				scanf("%c", &c);
				t[i++] = c;
			}
			int a1 = check_key_validity(t);
			if (a1 == 0) {   //�Ϸ�
				if (strlen(t) > 10) {
					memset(t, 0, sizeof(t));
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "����");
					MessageBox(hnd, "���볤�ȳ�������,����������", "��ʾ", MB_OKCANCEL);
					continue;
				}
				if (strcmp(t, key) == 0) {  //��ԭ������ͬ
					memset(t, 0, sizeof(t));
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "����");
					MessageBox(hnd, "�������µ�����", "��ʾ", MB_OKCANCEL);
					continue;
				}
				return 1;
			}
			else {   //�Ƿ�
				memset(t, 0, sizeof(t));
				HWND hnd = GetHWnd();
				SetWindowText(hnd, "����");
				MessageBox(hnd, "����Ƿ��ַ�,����������", "��ʾ", MB_OKCANCEL);
				continue;
			}
		}
	}
}
void release(movie* head_movie,movie** tail_movie,int a2) {   //��ӳ��Ӱ
	char t1[20] = { 0 }; int day = 0, i = 0, count[10] = { 0 }, t = 0;
	movie* neww = MALLOC(movie, 1);
	strcpy(neww->name, moviename[a2 - 1]);
	InputBox(t1, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������õ�Ӱ���ϼ�����"), 400, 200, false);
	const char* ptr = t1;
	while (*ptr) {
		day *= 10;
		day += *ptr - '0';
		ptr++;
	}
	neww->day = day;
	memset(t1, 0, sizeof(t1));
	InputBox(t1, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������õ�Ӱ��Ʊ��"), 400, 200, false);
	ptr = t1;
	while (*ptr) {
		t *= 10;
		t += *ptr - '0';
		ptr++;
	}
	neww->price = t;
	t = 0; memset(t1, 0, sizeof(t1));
	InputBox(t1, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������õ�Ӱ�ĳ�ʼƱ��"), 400, 200, false);
	ptr = t1;
	while (*ptr) {
		t *= 10;
		t += *ptr - '0';
		ptr++;
	}
	neww->allprice = t;
	for (i = 0; i < day; i++) {
		t = 0; memset(t1, 0, sizeof(t1));
		InputBox(t1, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������õ�Ӱ���ϼ�����(һ��ֻ������һ������)"), 400, 200, false);
		strcpy(neww->date[i], t1);

		InputBox(t1, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������õ�Ӱ������ϼܳ���"), 400, 200, false);
		ptr = t1;
		while (*ptr) {
			t *= 10;
			t += *ptr - '0';
			ptr++;
		}
		neww->count[i] = t;
		for (int j = 0; j < t; j++) {
			memset(t1, 0, sizeof(t1));
			InputBox(t1, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������õ�Ӱ����ÿ����ʼ��ʱ��(һ��ֻ������һ��ʱ��)"), 400, 200, false);
			strcpy(neww->time[j], t1);
		}
	}
	(*(tail_movie ))->next= neww;
	(*(tail_movie)) = neww;
	(*(tail_movie))->next = NULL;
	number_ing++;

	for (i = a2 - 1; i < number_ed - 1; i++) {    //ɾ��moviename���ϼܵĵ�Ӱ
		strcpy(moviename[i], moviename[i + 1]);
	}
	--number_ed;

	FILE* fp = fopen("��Ӱ\\���¼ܵ�Ӱ.txt", "w");
	if (fp == NULL) {
		perror("fopen");
		exit(0);
	}
	else {
		for (i = 0; i < number_ed; i++) {
			fprintf(fp, "%s\n", moviename[i]);
		}
		fclose(fp);
	}

	restore(head_movie, "��Ӱ\\������ӳ��Ӱ.txt");
}
void release_input(movie* head_movie, movie* tail_movie) {
	char t1[20] = { 0 }; int day = 0, i = 0, count[10] = { 0 }, t = 0;
	tail_movie->next = MALLOC(movie, 1);
	char t2[200] = { 0 };
	InputBox(t2, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������Ҫ�ϼܵ�Ӱ�ĵ�Ӱ��"), 400, 200, false);
	strcpy(tail_movie->next->name, t2);
	InputBox(t1, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������õ�Ӱ���ϼ�����"), 400, 200, false);
	const char* ptr = t1;
	while (*ptr) {
		day *= 10;
		day += *ptr - '0';
		ptr++;
	}
	tail_movie->next->day = day;
	memset(t1, 0, sizeof(t1));
	InputBox(t1, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������õ�Ӱ��Ʊ��"), 400, 200, false);
	ptr = t1;
	while (*ptr) {
		t *= 10;
		t += *ptr - '0';
		ptr++;
	}
	tail_movie->next->price = t;
	t = 0; memset(t1, 0, sizeof(t1));
	InputBox(t1, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������õ�Ӱ�ĳ�ʼƱ��"), 400, 200, false);
	ptr = t1;
	while (*ptr) {
		t *= 10;
		t += *ptr - '0';
		ptr++;
	}
	tail_movie->next->allprice = t;
	for (i = 0; i < day; i++) {
		t = 0; memset(t1, 0, sizeof(t1));
		InputBox(t1, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������õ�Ӱ���ϼ�����(һ��ֻ������һ������)"), 400, 200, false);
		strcpy(tail_movie->next->date[i], t1);

		InputBox(t1, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������õ�Ӱ������ϼܳ���"), 400, 200, false);
		ptr = t1;
		while (*ptr) {
			t *= 10;
			t += *ptr - '0';
			ptr++;
		}
		tail_movie->next->count[i] = t;
		for (int j = 0; j < t; j++) {
			memset(t1, 0, sizeof(t1));
			InputBox(t1, 40, NULL, _T("�ϼܵ�Ӱ"), _T("������õ�Ӱ����ÿ����ʼ��ʱ��(һ��ֻ������һ��ʱ��)"), 400, 200, false);
			strcpy(tail_movie->next->time[j], t1);
		}
	}
	tail_movie = tail_movie->next;
	tail_movie->next = NULL;
	number_ing++;
	restore(head_movie, "��Ӱ\\������ӳ��Ӱ.txt");
}
void removal(int n,movie* head) {    //�¼ܵ�Ӱ
	movie* p = head, *q = NULL;
	while (--n) {
		p = p->next;
	}
	q = p->next;
	number_ed++;
	strcpy(moviename[number_ed-1], q->name);  //��Ӹո��¼ܵĵ�Ӱ
	FILE* fp = fopen("��Ӱ\\���¼ܵ�Ӱ.txt", "w");
	for (int i = 0; i < number_ed; i++) {
		fprintf(fp, "%s\n", moviename[i]);
	}
	fclose(fp);
	p->next = q->next;
	free(q);
	--number_ing;
	restore(head_movie, "��Ӱ\\������ӳ��Ӱ.txt");
}
int user_login() {   //�û�����
	while (1) {
		int a1 = drawui3();  //�û��˵�����
		if (a1 == 1) {  //�鿴������ӳ��Ӱ
			//ѡ���Ӱ
			int a2 = select_movie(head_movie);
			if (a2 == 0) {   //����
				continue;
			}
		}
		else if (a1 == 2) {  //�鿴��Ϣ
			while (1) {
				int a2 = personal_information();
				if (a2 == 1) {  //���˶���
					int a3 = individual_order(personal_order_num, head_personal);
					if (a3 == personal_order_num + 1) {
						continue;
					}
					else {
						refund(head_people,&tail_people,head_personal,&tail_personal,head_movie,head_refund,&tail_refund,a3);
					}
				}
				else if (a2 == 2) {   //���˶���������
					int a3 = sortui();
					if (a3 == 1) {   //˳��
						sort_movie_shun(head_personal, personal_order_num);
					}
					else if (a3 == 2) {   //����
						sort_movie_ni(head_personal, personal_order_num);
					}
					else if (a3 == 3) {   //����
						continue;
					}
				}
				else if (a2 == 3) {    //�޸�����
					char t[30] = { 0 };
					int a3 = change_key(key,t);
					if (a3 == 1) {
						strcpy(key, t);
						int len1 = strlen(key);
						for (int i = 0; i < len1; i++) {
							key[i] += '1';
						}
						FILE* fp = fopen("�û�\\�˺�����.txt", "w");
						fprintf(fp,"%s\n%s\n", acc, key);
						fclose(fp);
						return 0;
					}

				}
				else if (a2 == 4) {   //�˳���¼
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "����");
					int a3 = MessageBox(hnd, "�Ƿ��˳���¼", "��ʾ", MB_OKCANCEL);
					if (a3 == 1) {
						return 0;  //����������
					}
				}
				else if (a2 == 5) {   //����
					break;
				}
				
			}
		}
		else if (a1 == 3) {
			return 0;  //����������
		}
	}
}
int manager_login() {   //����Ա����
	while (1) {
		int a1 = drawui9();  //����Ա�˵�����
		storemovie_ed();  //���¼ܵ�Ӱ���ļ��ж�ȡ��moviename������
		if (a1 == 1) {  //�ϼܵ�Ӱ
			while (1) {
				if (number_ing >= 5) {
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "����");
					MessageBox(hnd, "��Ӱ�����Ѵ�����", "��ʾ", MB_OKCANCEL);
					break;
				}
				int a3 =  release_choose();
				if (a3 == 1) {
					//ѡ���Ӱ
					if (number_ed == 0) {
						FILE* fp = fopen("��Ӱ\\���¼ܵ�Ӱ.txt", "w");
						if (fp == NULL) {
							perror("fopen");
							exit(0);
						}
						else {
							fprintf(fp, "0\n");
							fclose(fp);
						}
						HWND hnd = GetHWnd();
						SetWindowText(hnd, "����");
						MessageBox(hnd, "��⵽���ļ���������,��ȷ��", "��ʾ", MB_OKCANCEL);
						continue;
					}
					else {
						int a2 = release_movie(number_ed, moviename);   //��������ϼ�
						if (a2 == number_ed + 1) {   //����
							break;
						}
						else {
							HWND hnd = GetHWnd();
							SetWindowText(hnd, "����");
							int a2 = MessageBox(hnd, "�Ƿ�ȷ���ϼܵ�Ӱ", "��ʾ", MB_OKCANCEL);
							if (a2 == 1) {
								release(head_movie, &tail_movie, a2);
							}
							else {
								continue;
							}
						}
					}
				}
				else if (a3 == 2) {
					//�����Ӱ��
					release_input(head_movie, tail_movie);
				}
				else if (a3 == 3) {
					break;
				}
			}
		}
		else if (a1 == 2) {  //�¼ܵ�Ӱ
			while (1) {
				int a1 = drawui5(number_ing, head_movie); //��Ӱ����
				if (a1 == number_ing + 1) {
					break;
				}
				else {
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "����");
					int a2 = MessageBox(hnd, "�Ƿ�ȷ���¼ܵ�Ӱ", "��ʾ", MB_OKCANCEL);
					if (a2 == 1) {
						removal(a1, head_movie);
					}
					else {
						continue;
					}
				}
			}
		}
		else if (a1 == 3) {   //�鿴��Ϣ
			while (1) {
				int a2 = manager_information();
				if (a2 == 1) {  //������Ϣ
					int a3 = individual_order(order_num, head_people);
					if (a3 == order_num + 1) {
						continue;
					}
				}
				else if (a2 == 2) {   //��Ʊ��Ϣ
					while (1) {
						maxpage = number_refund / 5;
						if (number_refund % 5) {
							maxpage++;
						}
						int a3 = refundui(head_refund, number_refund, 1, maxpage, number_refund - (maxpage - 1) * 5);
						if (a3 == 1) {
							flag_refund = 0;
							break;
						}
					}
				}
				else if (a2 == 3) {    //�޸�����
					char t[30] = { 0 };
					int a3 = change_key(manager_key, t);
					if (a3 == 1) {
						strcpy(manager_key, t);
						int len1 = strlen(manager_key);
						for (int i = 0; i < len1; i++) {
							manager_key[i] += '1';
						}
						FILE* fp = fopen("����Ա\\�˺�����.txt", "w");
						fprintf(fp, "%s\n%s\n", manager_acc, manager_key);
						fclose(fp);
						return 0;
					}

				}
				else if (a2 == 4) {   //�˳���¼
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "����");
					int a3 = MessageBox(hnd, "�Ƿ��˳���¼", "��ʾ", MB_OKCANCEL);
					if (a3 == 1) {
						return 0;  //����������
					}
				}
				else if (a2 == 5) {   //����
					break;
				}
			}
		}
		else if (a1 == 4) {
			return 0;  //����������
		}
	}
}
//����ϵͳ
int enter_system() {
	int flag1 = 0, flag2 = 0;
	int count = 0;
	head_movie = MALLOC(movie, 1);  //��������
	tail_movie = init_movie(head_movie);

	head_people = MALLOC(people, 1);
	tail_people = init_people(head_people);

	head_personal = MALLOC(people, 1);
	tail_personal = init_personal(head_personal);

	head_refund = MALLOC(people, 1);
	tail_refund = init_refund(head_refund);
	while (1) {
		if (flag1 == 1 && flag2 == 1) {
			int a6 = user_login();//��½�ɹ�,�����û�����
			if (a6 == 0) {
				break;
			}
		}
		else if (flag1 == 2 && flag2 == 2) {
			int a6 = manager_login();//��½�ɹ�,�������Ա����
			if (a6 == 0) {
				break;
			}
		}
		int a3 = drawui2();  //��¼����
		if (a3 >= 1 && a3 <= 2) {
			//���˺�,ע���˺�
			if (check_file("�û�\\�˺�����.txt") == 0) {
				logon_account();
				continue;   //ע�����,���ؽ���
			}
			//��ʱ�����˺�,�����˺�����
			int i = 0;
			FILE* fp = fopen("�û�\\�˺�����.txt", "r");
			char t1[30] = { 0 }, t2[30] = { 0 };
			fscanf(fp, "%s\n%s\n", acc, key);
			int len = strlen(key);
			for (i = 0; i < len; i++) {
				key[i] -= '1';
			}
			fclose(fp);

			fp = fopen("����Ա\\�˺�����.txt", "r");
			memset(t1, 0, sizeof(t1));memset(t2, 0, sizeof(t2));
			fscanf(fp, "%s\n%s\n", manager_acc, manager_key);
			len = strlen(manager_key);
			for (i = 0; i < len; i++) {
				manager_key[i] -= '1';
			}
			fclose(fp);
			//��ʼ��¼
			if (a3 == 1) {   //�����˺�
				int a4 = scanf_account(t1);
				if (a4 == 1) {   //�����ȷ����
					flag1 = 1;
					count++;
					continue;
				}
				if (a4 == 2) {
					flag1 = 2;
					count++;
					continue;
				}
				else {
					continue;
				}
			}
			else if (a3 == 2) {  //��������
				if (count) {
					int a5 = scanf_key(t2,flag1);
					if (a5 == 1) {   //�����ȷ����
						flag2 = 1;
						continue;
					}
					if (a5 == 2) {
						flag2 = 2;
						continue;
					}
					else {
						continue;
					}
				}
				else {
					continue;
				}
			}
		}
		else if (a3 == 3) {  //����������
			return 0;
		}
	}
}
int main() {
	const int width = 1000;
	const int height = 618;
	initgraph(width, height, EW_NOCLOSE);
	while (1) {
		int a1 = drawui1();   //������
		if (a1 == 1) {  //����ϵͳ
			int a2 = enter_system();
			if (a2 == 0) {
				continue;
			}
		}
		else if (a1 == 2) {
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "����");
			int a2 = MessageBox(hnd, "�Ƿ��˳�ϵͳ", "��ʾ", MB_OKCANCEL);
			if (a2 == 1) {
				break;  //����������
			}
		}
	}
	closegraph();
	return 0;
}
