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
int check_account_validity(char* p2) { //检查账号是否非法
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
int check_key_validity(char* p2) {  //检查密码是否非法
	while (*p2 != '\0') {
		if ((*p2 >= '0' && *p2 <= '9') || (*p2 >= 'A' && *p2 <= 'Z') || (*p2 >= 'a' && *p2 <= 'z')) {
			p2++;
		}
		else {
			return 1;   //非法
		}
	}
	return 0;
}

int scanf_account(char* t1) {
	while (1) {
		char c = 0;
		int i = 0;
		if (InputBox(t1, 40, NULL, _T("登录"), _T("请输入账号"), 400, 200, false) == false) {
			return 0;
		}
		int a1 = check_account_validity(t1);
		if ( a1 == 0) {
			if (strlen(t1) > 10) {
				memset(t1, 0, sizeof(t1));
				HWND hnd = GetHWnd();
				SetWindowText(hnd, "窗口");
				MessageBox(hnd, "账号长度超过限制,请重新输入", "提示", MB_OKCANCEL);
				continue;
			}
			if (strcmp(acc, t1) == 0|| strcmp(manager_acc, t1) == 0) {    //合法且相等
				if (strcmp(acc, t1) == 0) {
					return 1;
				}
				return 2;
			}
			else {   //合法但不同
				memset(t1, 0, sizeof(t1));
				HWND hnd = GetHWnd();
				SetWindowText(hnd, "窗口");
				MessageBox(hnd, "账号错误,请重新输入", "提示", MB_OKCANCEL);
				continue;
			}
		}
        else {   //非法
			memset(t1, 0, sizeof(t1));
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "窗口");
			MessageBox(hnd, "输入非法字符,请重新输入", "提示", MB_OKCANCEL);
			continue;
		}
	}
}
int scanf_key(char* t2,int flag) {  //输入密码
	int i = 0;
	char a = 0;
	int t = 0;
	while (1) {
		if (t == 1) {
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "窗口");
			MessageBox(hnd, "您已失败1次,还有2次输入机会", "提示", MB_OKCANCEL);
		}
		else if (t == 2) {
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "窗口");
			MessageBox(hnd, "您已失败2次,还有1次输入机会", "提示", MB_OKCANCEL);
		}
		else if (t == 3) {
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "窗口");
			MessageBox(hnd, "您已失败3次,还有0次输入机会,即将返回主界面", "提示", MB_OKCANCEL);
			return 0;  //返回主界面
		}
		if (InputBox(t2, 40, NULL, _T("登录"), _T("请输入密码"), 400, 200, false) == false) {
			return 0;
		}
		//判断是否合法
		if (check_key_validity(t2) == 0) {
			if (strlen(t2) > 10) {
				memset(t2, 0, sizeof(t2));
				HWND hnd = GetHWnd();
				SetWindowText(hnd, "窗口");
				MessageBox(hnd, "密码长度超过限制,请重新输入", "提示", MB_OKCANCEL);
				continue;
			}
			if ((strcmp(key, t2) == 0 && flag == 1) || (strcmp(manager_key, t2) == 0 && flag == 2)) {    //合法且相等
				if (strcmp(key, t2) == 0 && flag==1) {
					return 1;
				}
  				if (strcmp(manager_key, t2) == 0 && flag == 2) {
					return 2;
				}
			}
			else {  //合法,不同
				memset(t2, 0, sizeof(t2));
				HWND hnd = GetHWnd();
				SetWindowText(hnd, "窗口");
				int a1 = MessageBox(hnd, "密码错误,请重新输入", "提示", MB_OKCANCEL);
				if (a1 == 1) {
					t++;  //错误次数累加
					continue;
				}
				continue;
			}
		}
		else {   //不合法
			memset(t2, 0, sizeof(t2));
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "窗口");
			MessageBox(hnd, "输入非法字符,请重新输入", "提示", MB_OKCANCEL);
			continue;
		}
	}
}

int select_movie_date(movie* p) {
	while (1) {
		int day = p->day;  //确定该电影的片次
		int a3 = drawmovie_day(p->name,p->day,p->allprice, p);   //选择日期
		if (a3 == day + 1) {
			return 1;  //回到电影界面
		}
		else {
			int a5 = p->count[a3 - 1];   //确定该天的场次
			int a4 = drawmovie_day1(p, a3 - 1);  //选择时间  //a3-1是该天对应的下标  
			if (a4 == a5 + 1) {   //选择了最后一个按钮
				continue;  //返回
			}
			else {
				shop(head_movie,p, head_people,&tail_people,head_personal,&tail_personal,a3, a4);
				return 0;  //购买完成后回到用户菜单界面
			}
		}
	}
}
int select_movie(movie* head) {
	while (1) {
		movie* p = head_movie;
		int a1 = drawui5(number_ing, head_movie); //电影界面
		if (personal_order_num == 6) {
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "窗口");
			MessageBox(hnd, "您所拥有的票数已超过限制", "提示", MB_OKCANCEL);
			return 0;
		}
		if (a1 == number_ing + 1) {
			return 0;
		}
		while (a1--) {
			p = p->next;   //循环至p指向该电影
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
	SetWindowText(hnd, "窗口");
	int a = MessageBox(hnd, "是否要修改密码", "提示", MB_OKCANCEL);
	if (a == 1) {
		while (1) {
			char c = 0;
			int i = 0;
			InputBox(t, 40, NULL, _T("修改密码"), _T("请输入您要修改的密码"), 400, 200, false);
			while (c != '\0') {
				scanf("%c", &c);
				t[i++] = c;
			}
			int a1 = check_key_validity(t);
			if (a1 == 0) {   //合法
				if (strlen(t) > 10) {
					memset(t, 0, sizeof(t));
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "窗口");
					MessageBox(hnd, "密码长度超过限制,请重新输入", "提示", MB_OKCANCEL);
					continue;
				}
				if (strcmp(t, key) == 0) {  //和原密码相同
					memset(t, 0, sizeof(t));
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "窗口");
					MessageBox(hnd, "请输入新的密码", "提示", MB_OKCANCEL);
					continue;
				}
				return 1;
			}
			else {   //非法
				memset(t, 0, sizeof(t));
				HWND hnd = GetHWnd();
				SetWindowText(hnd, "窗口");
				MessageBox(hnd, "输入非法字符,请重新输入", "提示", MB_OKCANCEL);
				continue;
			}
		}
	}
}
void release(movie* head_movie,movie** tail_movie,int a2) {   //上映电影
	char t1[20] = { 0 }; int day = 0, i = 0, count[10] = { 0 }, t = 0;
	movie* neww = MALLOC(movie, 1);
	strcpy(neww->name, moviename[a2 - 1]);
	InputBox(t1, 40, NULL, _T("上架电影"), _T("请输入该电影的上架天数"), 400, 200, false);
	const char* ptr = t1;
	while (*ptr) {
		day *= 10;
		day += *ptr - '0';
		ptr++;
	}
	neww->day = day;
	memset(t1, 0, sizeof(t1));
	InputBox(t1, 40, NULL, _T("上架电影"), _T("请输入该电影的票价"), 400, 200, false);
	ptr = t1;
	while (*ptr) {
		t *= 10;
		t += *ptr - '0';
		ptr++;
	}
	neww->price = t;
	t = 0; memset(t1, 0, sizeof(t1));
	InputBox(t1, 40, NULL, _T("上架电影"), _T("请输入该电影的初始票房"), 400, 200, false);
	ptr = t1;
	while (*ptr) {
		t *= 10;
		t += *ptr - '0';
		ptr++;
	}
	neww->allprice = t;
	for (i = 0; i < day; i++) {
		t = 0; memset(t1, 0, sizeof(t1));
		InputBox(t1, 40, NULL, _T("上架电影"), _T("请输入该电影的上架日期(一次只需输入一个日期)"), 400, 200, false);
		strcpy(neww->date[i], t1);

		InputBox(t1, 40, NULL, _T("上架电影"), _T("请输入该电影该天的上架场次"), 400, 200, false);
		ptr = t1;
		while (*ptr) {
			t *= 10;
			t += *ptr - '0';
			ptr++;
		}
		neww->count[i] = t;
		for (int j = 0; j < t; j++) {
			memset(t1, 0, sizeof(t1));
			InputBox(t1, 40, NULL, _T("上架电影"), _T("请输入该电影该天每场开始的时间(一次只需输入一个时间)"), 400, 200, false);
			strcpy(neww->time[j], t1);
		}
	}
	(*(tail_movie ))->next= neww;
	(*(tail_movie)) = neww;
	(*(tail_movie))->next = NULL;
	number_ing++;

	for (i = a2 - 1; i < number_ed - 1; i++) {    //删除moviename中上架的电影
		strcpy(moviename[i], moviename[i + 1]);
	}
	--number_ed;

	FILE* fp = fopen("电影\\已下架电影.txt", "w");
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

	restore(head_movie, "电影\\正在上映电影.txt");
}
void release_input(movie* head_movie, movie* tail_movie) {
	char t1[20] = { 0 }; int day = 0, i = 0, count[10] = { 0 }, t = 0;
	tail_movie->next = MALLOC(movie, 1);
	char t2[200] = { 0 };
	InputBox(t2, 40, NULL, _T("上架电影"), _T("请输入要上架电影的电影名"), 400, 200, false);
	strcpy(tail_movie->next->name, t2);
	InputBox(t1, 40, NULL, _T("上架电影"), _T("请输入该电影的上架天数"), 400, 200, false);
	const char* ptr = t1;
	while (*ptr) {
		day *= 10;
		day += *ptr - '0';
		ptr++;
	}
	tail_movie->next->day = day;
	memset(t1, 0, sizeof(t1));
	InputBox(t1, 40, NULL, _T("上架电影"), _T("请输入该电影的票价"), 400, 200, false);
	ptr = t1;
	while (*ptr) {
		t *= 10;
		t += *ptr - '0';
		ptr++;
	}
	tail_movie->next->price = t;
	t = 0; memset(t1, 0, sizeof(t1));
	InputBox(t1, 40, NULL, _T("上架电影"), _T("请输入该电影的初始票房"), 400, 200, false);
	ptr = t1;
	while (*ptr) {
		t *= 10;
		t += *ptr - '0';
		ptr++;
	}
	tail_movie->next->allprice = t;
	for (i = 0; i < day; i++) {
		t = 0; memset(t1, 0, sizeof(t1));
		InputBox(t1, 40, NULL, _T("上架电影"), _T("请输入该电影的上架日期(一次只需输入一个日期)"), 400, 200, false);
		strcpy(tail_movie->next->date[i], t1);

		InputBox(t1, 40, NULL, _T("上架电影"), _T("请输入该电影该天的上架场次"), 400, 200, false);
		ptr = t1;
		while (*ptr) {
			t *= 10;
			t += *ptr - '0';
			ptr++;
		}
		tail_movie->next->count[i] = t;
		for (int j = 0; j < t; j++) {
			memset(t1, 0, sizeof(t1));
			InputBox(t1, 40, NULL, _T("上架电影"), _T("请输入该电影该天每场开始的时间(一次只需输入一个时间)"), 400, 200, false);
			strcpy(tail_movie->next->time[j], t1);
		}
	}
	tail_movie = tail_movie->next;
	tail_movie->next = NULL;
	number_ing++;
	restore(head_movie, "电影\\正在上映电影.txt");
}
void removal(int n,movie* head) {    //下架电影
	movie* p = head, *q = NULL;
	while (--n) {
		p = p->next;
	}
	q = p->next;
	number_ed++;
	strcpy(moviename[number_ed-1], q->name);  //添加刚刚下架的电影
	FILE* fp = fopen("电影\\已下架电影.txt", "w");
	for (int i = 0; i < number_ed; i++) {
		fprintf(fp, "%s\n", moviename[i]);
	}
	fclose(fp);
	p->next = q->next;
	free(q);
	--number_ing;
	restore(head_movie, "电影\\正在上映电影.txt");
}
int user_login() {   //用户界面
	while (1) {
		int a1 = drawui3();  //用户菜单界面
		if (a1 == 1) {  //查看正在上映电影
			//选择电影
			int a2 = select_movie(head_movie);
			if (a2 == 0) {   //返回
				continue;
			}
		}
		else if (a1 == 2) {  //查看信息
			while (1) {
				int a2 = personal_information();
				if (a2 == 1) {  //个人订单
					int a3 = individual_order(personal_order_num, head_personal);
					if (a3 == personal_order_num + 1) {
						continue;
					}
					else {
						refund(head_people,&tail_people,head_personal,&tail_personal,head_movie,head_refund,&tail_refund,a3);
					}
				}
				else if (a2 == 2) {   //个人订单的排序
					int a3 = sortui();
					if (a3 == 1) {   //顺序
						sort_movie_shun(head_personal, personal_order_num);
					}
					else if (a3 == 2) {   //倒序
						sort_movie_ni(head_personal, personal_order_num);
					}
					else if (a3 == 3) {   //返回
						continue;
					}
				}
				else if (a2 == 3) {    //修改密码
					char t[30] = { 0 };
					int a3 = change_key(key,t);
					if (a3 == 1) {
						strcpy(key, t);
						int len1 = strlen(key);
						for (int i = 0; i < len1; i++) {
							key[i] += '1';
						}
						FILE* fp = fopen("用户\\账号密码.txt", "w");
						fprintf(fp,"%s\n%s\n", acc, key);
						fclose(fp);
						return 0;
					}

				}
				else if (a2 == 4) {   //退出登录
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "窗口");
					int a3 = MessageBox(hnd, "是否退出登录", "提示", MB_OKCANCEL);
					if (a3 == 1) {
						return 0;  //返回主界面
					}
				}
				else if (a2 == 5) {   //返回
					break;
				}
				
			}
		}
		else if (a1 == 3) {
			return 0;  //返回主界面
		}
	}
}
int manager_login() {   //管理员界面
	while (1) {
		int a1 = drawui9();  //管理员菜单界面
		storemovie_ed();  //将下架电影从文件中读取到moviename数组中
		if (a1 == 1) {  //上架电影
			while (1) {
				if (number_ing >= 5) {
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "窗口");
					MessageBox(hnd, "电影数量已达上限", "提示", MB_OKCANCEL);
					break;
				}
				int a3 =  release_choose();
				if (a3 == 1) {
					//选择电影
					if (number_ed == 0) {
						FILE* fp = fopen("电影\\已下架电影.txt", "w");
						if (fp == NULL) {
							perror("fopen");
							exit(0);
						}
						else {
							fprintf(fp, "0\n");
							fclose(fp);
						}
						HWND hnd = GetHWnd();
						SetWindowText(hnd, "窗口");
						MessageBox(hnd, "检测到该文件下无内容,请确认", "提示", MB_OKCANCEL);
						continue;
					}
					else {
						int a2 = release_movie(number_ed, moviename);   //点击进行上架
						if (a2 == number_ed + 1) {   //返回
							break;
						}
						else {
							HWND hnd = GetHWnd();
							SetWindowText(hnd, "窗口");
							int a2 = MessageBox(hnd, "是否确定上架电影", "提示", MB_OKCANCEL);
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
					//输入电影名
					release_input(head_movie, tail_movie);
				}
				else if (a3 == 3) {
					break;
				}
			}
		}
		else if (a1 == 2) {  //下架电影
			while (1) {
				int a1 = drawui5(number_ing, head_movie); //电影界面
				if (a1 == number_ing + 1) {
					break;
				}
				else {
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "窗口");
					int a2 = MessageBox(hnd, "是否确定下架电影", "提示", MB_OKCANCEL);
					if (a2 == 1) {
						removal(a1, head_movie);
					}
					else {
						continue;
					}
				}
			}
		}
		else if (a1 == 3) {   //查看信息
			while (1) {
				int a2 = manager_information();
				if (a2 == 1) {  //订单信息
					int a3 = individual_order(order_num, head_people);
					if (a3 == order_num + 1) {
						continue;
					}
				}
				else if (a2 == 2) {   //退票信息
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
				else if (a2 == 3) {    //修改密码
					char t[30] = { 0 };
					int a3 = change_key(manager_key, t);
					if (a3 == 1) {
						strcpy(manager_key, t);
						int len1 = strlen(manager_key);
						for (int i = 0; i < len1; i++) {
							manager_key[i] += '1';
						}
						FILE* fp = fopen("管理员\\账号密码.txt", "w");
						fprintf(fp, "%s\n%s\n", manager_acc, manager_key);
						fclose(fp);
						return 0;
					}

				}
				else if (a2 == 4) {   //退出登录
					HWND hnd = GetHWnd();
					SetWindowText(hnd, "窗口");
					int a3 = MessageBox(hnd, "是否退出登录", "提示", MB_OKCANCEL);
					if (a3 == 1) {
						return 0;  //返回主界面
					}
				}
				else if (a2 == 5) {   //返回
					break;
				}
			}
		}
		else if (a1 == 4) {
			return 0;  //返回主界面
		}
	}
}
//进入系统
int enter_system() {
	int flag1 = 0, flag2 = 0;
	int count = 0;
	head_movie = MALLOC(movie, 1);  //创建链表
	tail_movie = init_movie(head_movie);

	head_people = MALLOC(people, 1);
	tail_people = init_people(head_people);

	head_personal = MALLOC(people, 1);
	tail_personal = init_personal(head_personal);

	head_refund = MALLOC(people, 1);
	tail_refund = init_refund(head_refund);
	while (1) {
		if (flag1 == 1 && flag2 == 1) {
			int a6 = user_login();//登陆成功,进入用户界面
			if (a6 == 0) {
				break;
			}
		}
		else if (flag1 == 2 && flag2 == 2) {
			int a6 = manager_login();//登陆成功,进入管理员界面
			if (a6 == 0) {
				break;
			}
		}
		int a3 = drawui2();  //登录界面
		if (a3 >= 1 && a3 <= 2) {
			//无账号,注册账号
			if (check_file("用户\\账号密码.txt") == 0) {
				logon_account();
				continue;   //注册完毕,返回界面
			}
			//此时已有账号,读出账号密码
			int i = 0;
			FILE* fp = fopen("用户\\账号密码.txt", "r");
			char t1[30] = { 0 }, t2[30] = { 0 };
			fscanf(fp, "%s\n%s\n", acc, key);
			int len = strlen(key);
			for (i = 0; i < len; i++) {
				key[i] -= '1';
			}
			fclose(fp);

			fp = fopen("管理员\\账号密码.txt", "r");
			memset(t1, 0, sizeof(t1));memset(t2, 0, sizeof(t2));
			fscanf(fp, "%s\n%s\n", manager_acc, manager_key);
			len = strlen(manager_key);
			for (i = 0; i < len; i++) {
				manager_key[i] -= '1';
			}
			fclose(fp);
			//开始登录
			if (a3 == 1) {   //输入账号
				int a4 = scanf_account(t1);
				if (a4 == 1) {   //完成正确输入
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
			else if (a3 == 2) {  //输入密码
				if (count) {
					int a5 = scanf_key(t2,flag1);
					if (a5 == 1) {   //完成正确输入
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
		else if (a3 == 3) {  //返回主界面
			return 0;
		}
	}
}
int main() {
	const int width = 1000;
	const int height = 618;
	initgraph(width, height, EW_NOCLOSE);
	while (1) {
		int a1 = drawui1();   //主界面
		if (a1 == 1) {  //进入系统
			int a2 = enter_system();
			if (a2 == 0) {
				continue;
			}
		}
		else if (a1 == 2) {
			HWND hnd = GetHWnd();
			SetWindowText(hnd, "窗口");
			int a2 = MessageBox(hnd, "是否退出系统", "提示", MB_OKCANCEL);
			if (a2 == 1) {
				break;  //返回主界面
			}
		}
	}
	closegraph();
	return 0;
}
