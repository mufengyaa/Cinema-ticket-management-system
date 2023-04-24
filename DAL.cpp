#define _CRT_SECURE_NO_WARNINGS

#include"work.h"
movie* head_movie, * tail_movie;  //��Ӱͷβ
people* head_people, * tail_people;   //�û�����ͷβ
people* head_personal, * tail_personal;  //���˶���ͷβ
people* head_refund, * tail_refund;//��Ʊ����ͷβ
int personal_order_num, order_num;                                                             
char acc[30], key[30]; char manager_acc[30], manager_key[30];
int number_ing, number_ed, number_refund;
char moviename[10][40] = { 0 };

void sort_movie_shun(people* head, int number) {
	people* p = NULL, * q = NULL;
	people t;
	int count = number;
	while (count--) {
		p = head->next; q = p->next;
		while (p && q) {
			if (strcmp(p->name, q->name) > 0) {
				t = *p;
				*p = *q;
				*q = t;
				q->next = p->next;
				p->next = q;
			}
			p = p->next;
			q = q->next;
		}
	}
	restore_personal(head, number);
}
void sort_movie_ni(people* head, int number) {
	people* p = NULL, * q = NULL;
	people t;
	int count = number;
	while (count--) {
		p = head->next; q = p->next;
		while (p && q) {
			if (strcmp(p->name, q->name) < 0) {
				t = *p;
				*p = *q;
				*q = t;
				q->next = p->next;
				p->next = q;
			}
			p = p->next;
			q = q->next;
		}
	}
	restore_personal(head, number);
}

void foundchain_people(people* head_people,const char* arr) {
	people* p = head_people, * neww = NULL;
	FILE* fp = fopen("����Ա\\��Ʊ��Ϣ.txt", arr);
	if (fp == NULL) {
		perror("fopen");
		exit(0);
	}
	else {
		if ((fgetc(fp) != EOF)) {
			fseek(fp, -1, SEEK_CUR);
			fscanf(fp,"%d\n", &order_num);
		}
		while (fgetc(fp) != EOF) {
			int i = 0;
			fseek(fp, -1, SEEK_CUR);
			neww = MALLOC(people, 1);
			fscanf(fp, "%s %s %s %s %d\n", neww->acc, neww->name, neww->date, neww->time,&neww->price);
			p->next = neww;
			p = neww;
		}
		p->next = NULL;
		fclose(fp);
	}
}
void foundchain_personal(people* head_personal, const char* arr) {
	people* p = head_personal, * neww = NULL;
	FILE* fp = fopen("�û�\\���˶���.txt", arr);
	if (fp == NULL) {
		perror("fopen");
		exit(0);
	}
	else {
		if ((fgetc(fp) != EOF)) {
			fseek(fp, -1, SEEK_CUR);
			fscanf(fp, "%d\n", &personal_order_num);
		}
		while (fgetc(fp) != EOF) {
			int i = 0;
			fseek(fp, -1, SEEK_CUR);
			neww = MALLOC(people, 1);
			fscanf(fp, "%s %s %s %d\n",neww->name, neww->date, neww->time, &neww->price);
			p->next = neww;
			p = neww;
		}
		p->next = NULL;
		fclose(fp);
	}
}
void foundchain_movie(movie* head_movie) {
	movie* p = head_movie, * neww = NULL;
	FILE* fp;
	fp = fopen("��Ӱ\\������ӳ��Ӱ.txt", "r");
	if (fp == NULL) {
		perror("fopen");
		exit(0);
	}
	else {
		if ((fgetc(fp) != EOF)) {
			fseek(fp, -1, SEEK_CUR);
			fscanf(fp, "%d\n", &number_ing);
		}
		while (fgetc(fp) != EOF) {
			int count_date = 0, count_time = 0;
			int i = 0;
			fseek(fp, -1, SEEK_CUR);
			neww = MALLOC(movie, 1);
			fscanf(fp, "%s %d %d\n", neww->name, &neww->day, &neww->price);
			fscanf(fp, "%d\n", &neww->allprice);
			int day = neww->day;
			while (day--) {
				fscanf(fp, "%s %d\n", neww->date[count_date++], &neww->count[i++]);
				int count = neww->count[i-1];
				while (count--) {
					fscanf(fp, "%s\n", neww->time[count_time++]);                
				}
			}
			p->next = neww;
			p = neww;
		}
		p->next = NULL;
		fclose(fp);
	}
}
void foundchain_refund(people* head_refund, const char* arr) {
	people* p = head_refund, * neww = NULL;
	FILE* fp;
	fp = fopen("����Ա\\��Ʊ��Ϣ.txt", arr);
	if (fp == NULL) {
		perror("fopen");
		exit(0);
	}
	else {
		if ((fgetc(fp) != EOF)) {
			fseek(fp, -1, SEEK_CUR);
			fscanf(fp, "%d\n", &number_refund);
		}
		while (fgetc(fp) != EOF) {
			int i = 0;
			fseek(fp, -1, SEEK_CUR);
			neww = MALLOC(people, 1);
			fscanf(fp, "%s %s %s %s %d\n", neww->acc,neww->name, neww->date, neww->time, &neww->price);
			p->next = neww;
			neww->period = p;
			p = neww;
		}
		p->next = NULL;
		fclose(fp);
	}
}

people* counttail_people(people* head_people) {   //�ҳ�β���
	people* p = head_people;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = NULL;
	return p;
}
people* counttail_personal(people* head_personal) {   //�ҳ�β���
	people* p = head_personal;
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}
people* counttail_refund(people* head_refund) {   //�ҳ�β���
	people* p = head_refund;
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}
movie* counttail_movie(movie* head_movie) {   //�ҳ�β���
	movie* p = head_movie;
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}


movie* init_movie(movie* head_movie) {
	foundchain_movie(head_movie);
	return counttail_movie(head_movie);
}
people* init_people(people* head_people) {
	foundchain_people(head_people,"r");
	return counttail_people(head_people);
}
people* init_personal(people* head_personal) {
	foundchain_personal(head_personal, "r");
	return counttail_personal(head_personal);
}
people* init_refund(people* head_refund) {
	foundchain_refund(head_refund, "r");
	return counttail_refund(head_refund);
}

int check_file(const char* p) {  //����ļ����Ƿ�������
	FILE* fp;
	fp = fopen(p, "r");
	int fno = _fileno(fp);
	int fsize = _filelength(fno);
	fclose(fp);
	return fsize;
}
void storemovie_ed() {
	FILE* fp = fopen("��Ӱ\\���¼ܵ�Ӱ.txt", "r");
	if (fp == NULL) {
		perror("fopen");
		exit(0);
	}
	else {
		int i = 0;
		while (fgetc(fp) != EOF) {
			fseek(fp, -1, SEEK_CUR);
			fscanf(fp, "%s\n",moviename[i++]);
		}
		number_ed = i;
		fclose(fp);
	}
}
void logon_account() {   //ע���˺�
	FILE* fp = fopen("�û�\\�˺�����.txt", "w");
	if (fp == NULL) {
		perror("fopen");
		exit(0);
	}
	int flag1 = 0, flag2 = 0;
	int count = 0;
	while (1) { 
		if (flag1 && flag2) {
			break;
		}
		int a = drawui4();
		if (a == 1) {
			char c = 0;
			int i = 0;
			if (InputBox(acc, 40, NULL, _T("ע��"), _T("�������˺�"), 400, 200, false) == false) {
				continue;
			}
			int a1 = check_account_validity(acc);
			if (a1 == 0) {   //�Ϸ�
				if (strlen(acc) > 10) {
					memset(acc, 0, sizeof(acc));
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "����");
					MessageBox(hnd, "�˻����ȳ�������,����������", "��ʾ", MB_OKCANCEL);
					continue;
				}
				count++;
				flag1 = 1;
			}
			else {   //�Ƿ�
				memset(acc, 0, sizeof(acc));
				HWND hnd = GetHWnd();
				SetWindowText(hnd, "����");
				MessageBox(hnd, "����Ƿ��ַ�,����������", "��ʾ", MB_OKCANCEL);
				continue;
			}
		}
		else if (a == 2 && count) {
			char c = 0;
			int i = 0;
			if (InputBox(key, 40, NULL, _T("ע��"), _T("����������"), 400, 200, false) == false) {
				continue;
			}
			int a1 = check_key_validity(key);
			if (a1 == 0) {   //�Ϸ�
				if (strlen(key) > 10) {
					memset(key, 0, sizeof(key));
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "����");
					MessageBox(hnd, "���볤�ȳ�������,����������", "��ʾ", MB_OKCANCEL);
					continue;
				}
				flag2 = 1;
			}
			else {   //�Ƿ�
				memset(key, 0, sizeof(key));
				HWND hnd = GetHWnd();
				SetWindowText(hnd, "����");
				MessageBox(hnd, "����Ƿ��ַ�,����������", "��ʾ", MB_OKCANCEL);
				continue;
			}
		}
	}
	int len1 = strlen(key);
	for (int i = 0; i < len1; i++) {
		key[i] += '1';
	}
    fprintf(fp,"%s\n%s\n",acc,key);          
	fclose(fp);
}

void restore(movie* head,const char* arr) {  
	FILE* fp;
	movie* p = head->next;
	fp = fopen(arr, "w");
	if (fp == NULL) {
		perror("fopen");
		exit(0);
	}
	else {
		int i = 0, j = 0, k = 0;
		fprintf(fp, "%d\n", number_ing);
		while (p != NULL) {
			int i = 0, j = 0, k = 0;
			fprintf(fp, "%s %d %d\n", p->name, p->day, p->price);
			fprintf(fp, "%d\n", p->allprice);
			int day = p->day;
			while (day--) {
				fprintf(fp, "%s %d\n", p->date[j++], p->count[i++]);
				int count = p->count[i - 1];
				while (count--) {
					fprintf(fp, "%s\n", p->time[k++]);
				}
			}
			p = p->next;
		}
		fclose(fp);
	}
}
void restore_order(people* head,int num) {
	FILE* fp = fopen("����Ա\\��Ʊ��Ϣ.txt", "w");
	fprintf(fp, "%d\n", num);
	people* p = head->next;
	while (p != NULL) {
		fprintf(fp, "%s %s %s %s %d\n", p->acc,p->name, p->date, p->time, p->price);
		p = p->next;
	}
	fclose(fp);
}
void restore_personal(people* head, int num) {
	FILE* fp = fopen("�û�\\���˶���.txt", "w");
	fprintf(fp, "%d\n",num);
	people* p = head->next;
	while (p != NULL) {
		fprintf(fp, "%s %s %s %d\n", p->name, p->date, p->time, p->price);
		p = p->next;
	}
	fclose(fp);
}
void restore_refund(people* head, int num) {
	FILE* fp = fopen("����Ա\\��Ʊ��Ϣ.txt", "w");
	fprintf(fp, "%d\n", num);
	people* p = head->next;
	while (p != NULL) {
		fprintf(fp, "%s %s %s %s %d\n",p->acc, p->name, p->date, p->time, p->price);
		p = p->next;
	}
	fclose(fp);
}
void shop(movie* head_movie,movie* p,people* head_people,people** tail_people,people* head_personal,people** tail_personal,int tt,int ttt) {
	HWND hnd = GetHWnd();
	SetWindowText(hnd, "����");
	int a1 = MessageBox(hnd, "�Ƿ�ȷ�Ϲ���", "��ʾ", MB_OKCANCEL);
	if (a1 == 1) {
		people* neww = MALLOC(people, 1);
		strcpy(neww->acc, acc);   //���¹�Ʊ����
		strcpy(neww->name, p->name);
		strcpy(neww->date, p->date[tt - 1]);
		strcpy(neww->time, p->time[ttt - 1]);   //t->next���¼���Ľ��
		neww->price = p->price;
		(*(tail_people))->next = neww;
		(*(tail_people)) = neww;
		(*(tail_people))->next = NULL;
		order_num++;
		restore_order(head_people, order_num);
		
		people* neww1 = MALLOC(people, 1);
		strcpy(neww1->name, p->name);  //���¸�������
		strcpy(neww1->date, p->date[tt - 1]);
		strcpy(neww1->time, p->time[ttt - 1]);
		neww1->price = p->price;
		(*(tail_personal))->next = neww1;
		(*(tail_personal)) = neww1;
		(*(tail_personal))->next = NULL;
		personal_order_num++;
		restore_personal(head_personal, personal_order_num);

		p->allprice += p->price;
		restore(head_movie, "��Ӱ\\������ӳ��Ӱ.txt");  //����Ʊ��
	}
}
void refund(people* head_people,people** tail_people,people* head_personal, people** tail_personal,movie* head_movie, people* head_refund, people** tail_refund,int num) {
	HWND hnd = GetHWnd();
	SetWindowText(hnd, "����");
	int a1 = MessageBox(hnd, "�Ƿ�ȷ����Ʊ", "��ʾ", MB_OKCANCEL);
	people* e = head_people, * w = head_personal, * q = NULL;
	movie* p = head_movie->next;
	int tmp = num;   //numָ �㵽�Ķ������
	if (a1 == 1) {
		while (tmp--) {   //��ʱwָ����Ʊ���  //wΪ���˶���������
			e = e->next;
		}
		if (head_refund->next == NULL) {   //������Ʊ��Ϣ����
			people* t = MALLOC(people, 1);
			strcpy(t->acc, e->acc);
			strcpy(t->name, e->name);
			strcpy(t->date, e->date);
			strcpy(t->time, e->time);
			t->price = e->price;
			number_refund++;
			t->next = NULL;
			head_refund->next = t;
		}
		else {
			q = MALLOC(people, 1);
			strcpy(q->acc, e->acc);
			strcpy(q->name, e->name);
			strcpy(q->date, e->date);
			strcpy(q->time, e->time);
			q->price = e->price;
			(*(tail_refund))->next = q;
			(*(tail_refund)) = q;
			(*(tail_refund))->next = NULL;
			number_refund++;
		}
		restore_refund(head_refund, number_refund);

		//��������
		while (p != NULL && strcmp(p->name, e->name) != 0) {
			p = p->next;//pָ��õ�Ӱ
		}
		p->allprice -= p->price;
		--personal_order_num; 
		--order_num;
		restore(head_movie, "��Ӱ\\������ӳ��Ӱ.txt");  //����Ʊ��

		//������˶���
		if (personal_order_num == 0) {
			FILE* fp = fopen("�û�\\���˶���.txt", "w");
			fprintf(fp, "0\n");
			fclose(fp);
			head_personal->next = NULL;
			(*(tail_personal)) = head_personal;
		}
		else {
			tmp = num;
			while (--tmp) {   //��ʱwָ����Ʊ����ǰһ���ڵ�
				w = w->next;
			}
			people* r = w->next;
			w->next = r->next;
			free(r);
			(*(tail_personal)) = counttail_personal(head_personal);
			restore_personal(head_personal, personal_order_num);
		}

		//����Ʊ��Ϣ
		if (order_num == 0) {
			FILE* fp = fopen("����Ա\\��Ʊ��Ϣ.txt", "w");
			fprintf(fp, "0\n");
			fclose(fp);
			head_people->next = NULL;
			(*(tail_people)) = head_people;
		}
		else {
			tmp = num;
			e = head_people;
			while (--tmp) {   //��ʱeָ����Ʊ����ǰһ���ڵ�
				e = e->next;
			}
			people* rr = e->next;
			e->next = rr->next;
			free(rr);
			(*(tail_people)) = counttail_people(head_people);
			restore_order(head_people, order_num);
		}
	}
}
