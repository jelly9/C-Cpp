//��������
#ifndef __CONTACT_H__
#define __CONTACT_H__

//ͷ�ļ��б�
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <string.h>

//���Ծ���
#pragma warning(disable:4996)

//��
#define INITCAP 128//��ʼ������
#define INCREMENT 32//��������
#define FILE_NAME "contact_back"

//������
//��ϵ�˽ṹ��
typedef struct person{
	char name[32];//���� �Ա� ���� �绰 ��ַ
	char sex[8];
	unsigned char age;
	char phone[16];
	char adds[64];
}person_t, *person_p, **person_pp;

//ͨѶ¼�ṹ��
typedef struct contact{
	int cap;//��󳤶�
	int size;//��ǰ����
	person_p contactList;//��ϵ���б�
}contact_t, *contact_p, **contact_pp;

//��������
void initContact(contact_pp c);//��ʼ��ͨѶ¼
void addContact(contact_p c, person_p p);//�����ϵ��
void showContact(contact_p c);//��ӡ��ϵ���б�
void delContact(contact_p c, char *del_name);//ɾ��
void emptyContact(contact_p c);//���
void destroyContact(contact_p c);//�ݻ�ͨѶ¼
int  searchContact(contact_p c, char *search_name);//����
void sortContact(contact_p c);//����
void modContact(contact_p c);//�޸�
void helpContact();//����
void exitContact(contact_p c);//�˳�
int  isContactEmpty(contact_p c);//�п�
int fileLoad(contact_p c);//���ص���Ŀ
int fileStore(contact_p c);//���浽�ļ�


#endif __CONTACT_H__ 
