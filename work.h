#pragma once
#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<io.h>
#include<graphics.h>
#include<easyx.h>
#include<conio.h>
#include <direct.h>

#define MALLOC(type, number) (type*)malloc(sizeof(type)*number)

typedef struct btnode {
	int x;
	int y;
	char text[30];
	int status;
} btnode;
typedef struct movie {
	char name[30];
	int day;
	int price;
	int allprice;
	char date[30][20];
	int count[10];//场次
	char time[30][20];  //时间
	//int count_seat;
	//int seat[4][4][10][10];
	struct movie* next;
}movie;
typedef struct people {
	char acc[30];
	char name[30];
	char date[30];
	char time[30];
	int price;
	struct people* next;
	struct people* period;
}people;

//UI
void init(btnode* men, int n);
void drawBtn(btnode t, int tx, int ty);
void drawup1(IMAGE upimg);
void drawdown1(IMAGE downimg, btnode* downmen);
int drawui1();
void drawup2(IMAGE upimg);
void drawdown2(IMAGE downimg, btnode* downmen);
int drawui2();
int drawui3();
void drawup4(IMAGE upimg);
void drawdown4(IMAGE downimg, btnode* downmen);
int drawui4();
int drawui5(int num, movie* head);
int drawmovie_day(char* name, int day, int price, movie* p);
int drawmovie_day1(movie* p,int n);
void drawup6(IMAGE upimg);
void drawdown6(IMAGE downimg, btnode* downmen);
int personal_information();
void drawBtn_individual_order(btnode t, int tx, int ty);
void drawup7(IMAGE upimg);
void drawdown7(IMAGE downimg, btnode* downmen, int num);
int individual_order(int num, people* head);
void drawup8(IMAGE upimg);
void drawdown8(IMAGE downimg, btnode* downmen);
int manager_information();
int drawui9();
void drawBtn9(btnode t, int tx, int ty);
void drawup9(IMAGE upimg);
void drawdown9(IMAGE downimg, btnode* downmen, int num);
int release_movie(int num, char arr[10][40]);
void drawBtn11(btnode t, int tx, int ty);
void drawup11(IMAGE upimg);
void drawdown11(IMAGE downimg, btnode* downmen, int num);
//int refundui(int num);
int refundui(people* p, int num, int curpage, int maxpage,int r);
int sortui();
void drawdownsort(IMAGE downimg, btnode* downmen);
void drawupsort(IMAGE upimg);
void drawup12(IMAGE upimg);
void drawdown12(IMAGE downimg, btnode* downmen);
int release_choose();

//BLL
int check_key_validity(char* p2);
int check_account_validity(char* p2);
int scanf_account(char* t1);
int scanf_key(char* t1, int flag);
int user_login();
int change_key(char* key, char* t);
int manager_login();
void release(movie* head_movie, movie** tail_movie, int a2);
void removal(int n, movie* head);
void sort_movie_shun(people* head, int count);
void sort_movie_ni(people* head, int count);
void release_input(movie* head_movie, movie* tail_movie);

//DAL
int check_file(const char* p);
//people
void logon_account();
void foundchain_people(people* head_people, const char* arr);
people* counttail_people(people* head);
people* init_people(people* head);
void restore_order(people* head, int num);
void shop(movie* head_movie, movie* p, people* head_people, people** tail_people, people* head_personal, people** tail_personal, int tt, int ttt);
void refund(people* head_people, people** tail_people, people* head_personal, people** tail_personal, movie* head_movie, people* head_refund, people** tail_refund, int num);
//personal
void foundchain_personal(people* head_people, const char* arr);
people* init_personal(people* head_personal);
people* counttail_personal(people* head_personal);
void restore_personal(people* head, int num);
//refund
people* init_refund(people* head_refund);
people* counttail_refund(people* head_refund);
void foundchain_refund(people* head_refund, const char* arr);
void restore_refund(people* head, int num);
//movie
void foundchain_movie(movie* head);
movie* counttail_movie(movie* head);
movie* init_movie(movie* head);
void restore(movie* head, const char* arr);
void storemovie_ed();












