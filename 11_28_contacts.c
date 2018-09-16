#include "11_28_contacts.h"

//�п�
//�գ�1
//���գ�0
int isContactEmpty(contact_p c)
{
	assert(c);

	return c->size == 0 ? 1 : 0;
}

//��ʼ��
void initContact(contact_pp c)
{
	assert(c);

	//����ͨѶ¼�ռ�
	*c = (contact_p)malloc(sizeof(contact_t));
	if(NULL == *c){
		perror("malloc");
		exit(1);
	}

	//�����Ա�ռ�
	(*c)->contactList = (person_p)malloc(sizeof(person_t)*INITCAP);
	if(NULL == (*c)->contactList){
		perror("malloc");
		exit(2);
	}

	//��ʼ�����Ⱥ�����
	(*c)->cap = INITCAP;
	(*c)->size = 0;

	fileLoad(*c);
}

//���ļ���ȡͨѶ¼��Ϣ
int fileLoad(contact_p c)
{
	FILE *fp;
	person_t p;
	int i = 0;

	assert(c);

	//���ļ�
	fp = fopen(FILE_NAME,"rb");
	if(NULL == fp){
		perror("fopen");
		return -2;
	}

	while(1){
		//��ȡ��p
		fread(&p, sizeof(person_t), 1, fp);
		if(0 != feof(fp)){
			break;
		}
		//����ȡ����ӵ�ͨѶ¼
		addContact(c, &p);
	}
	fclose(fp);

	return 0;
}


//����
//����1 
//δ����0
static int isContactFull(contact_p c)
{
	assert(c);

	return c->size >= c-> cap ? 1 : 0;
}


//����
static int incContact(contact_p c)
{
	person_p new_c = NULL;

	assert(c);

	//�����¿ռ�
	new_c = (person_p)realloc(c->contactList, (c->cap+INCREMENT)*sizeof(person_t));
	if(NULL == new_c){
		perror("realloc");
		return 0;
	}
	
	//���¿ռ������ɿռ�
	c->contactList = new_c;
	c->cap += INCREMENT;
	printf("Is full, increse success!\n");
	return 1;
}

//�����ϵ��
void addContact(contact_p c, person_p p)
{
	assert(c);
	assert(p);

	//�������ֱ����ӣ�����վ������������
	if(!isContactFull(c) || incContact(c)){
		c->contactList[c->size] = *p;
		c->size++;
	}
}

//����
//�ǿյģ���ӡ��
//û�ҵ������� -1
//�ҵ��������±�
int searchContact(contact_p c, char *search_name)
{
	int i = 0;

	assert(c);
	assert(search_name);

	//ͨѶ¼�ǿյ�
	if(isContactEmpty(c)){
		printf("Contact is empty!\n");
	}

	for(i = 0; i < c->size; i++){
		if( 0 == strcmp(c->contactList[i].name, search_name) ){
			break;
		}
	}

	//û�ҵ�
	if(i == c->size)
	{
		return -1;
	}

	//�ҵ������±�
	return i;


}


//����������
void sortContact(contact_p c)
{
	int i = 0;
	int j = 0;
	int pos = 0;
	person_t temp;

	assert(c);

	//�ǿյľͲ�����
	if(isContactEmpty(c)){
		printf("Contact is empty!\n");
		return ;
	}

	//������ð�ݷ�����������
	for(i = c->size-1; i>0; i--){
		for(j = 0; j<i; j++){
			if(1 == strcmp(c->contactList[j].name, c->contactList[j+1].name)){
				temp = c->contactList[j];
				c->contactList[j] = c->contactList[j+1];
				c->contactList[j+1] = temp;
				pos = 1;
			}
		}
		if(0 == pos)
		{

			break;
		}
	}

	printf("Done...\n");
}

//�޸���ϵ��
void modContact(contact_p c)
{
	char name[32];
	int i = 0;
	char key_mod[8];

	assert(c);


	if(isContactEmpty(c)){
		printf("Contact is empty!\n");
		return ;
	}

	//����Ҫ�޸ĵ��˵�����
	printf("Please input the name whicth you want to modify:");
	scanf("%s", name);

	//����Ҫ�޸��˵��±�
	i = searchContact(c, name);
	if(-1 == i)
	{
		printf("Not find!\n");
		return ;
	}

	//��ӡ��Ϣ
	printf("------------------------------------------------------------------------------\n");
	printf("| name      | sex  | age | phone           | adds                            |\n");
	printf("| %-10s| %-5s| %-4d| %-16s| %-32s|\n",c->contactList[i].name, \
	c->contactList[i].sex,c->contactList[i].age, \
	c->contactList[i].phone,c->contactList[i].adds);
	printf("------------------------------------------------------------------------------\n");

	//����Ҫ�޸ĵĹؼ���
	printf("Please input the infor whicth you want to modify:");
	fflush(stdin);
	scanf("%s", key_mod);
	
	//Ѱ��Ҫ�޸ĵĹؼ���

	//���Ҫ�޸�����
	if(0 == strcmp("name", key_mod)){
		printf("Please input new name:");
		fflush(stdin);//ע��Ҫ������뻺����
		scanf("%s", c->contactList[i].name);
		printf("Done...\n");
		return ;
	}

	//���Ҫ�޸��Ա�
	if(0 == strcmp("sex", key_mod)){
		printf("Please input new sex:");
		fflush(stdin);
		scanf("%s", c->contactList[i].sex);
		printf("Done...\n");
		return ;
	}

	//���Ҫ�޸�����
	if(0 == strcmp("age", key_mod)){
		printf("Please input new age:");
		fflush(stdin);
		scanf("%d", &c->contactList[i].age);
		printf("Done...\n");
		return ;
	}

	//���Ҫ�޸ĵ绰����
	if(0 == strcmp("phone", key_mod)){
		printf("Please input new phone:");
		fflush(stdin);
		scanf("%s", c->contactList[i].phone);
		printf("Done...\n");
		return ;
	}

	//���Ҫ�޸ĵ�ַ
	if(0 == strcmp("adds", key_mod)){
		printf("Please input new adds:");
		fflush(stdin);
		scanf("%s", c->contactList[i].adds);
		printf("Done...\n");
		return ;
	}
	
	//û���ҵ�Ҫ�޸ĵĹؼ���
	printf("ERROR!!\n");
}

//ɾ��
void delContact(contact_p c, char *del_name)
{
	int i = 0;
	int j = 0;
	assert(c);
	
	i = searchContact(c, del_name);
	if(-1 == i)
	{
		printf("Not find!\n");
		return ;
	}
	
	//������ĳ�Աǰ��
	for(j = i;j<c->size; j++){
		c->contactList[j] = c->contactList[j+1];
	}

	c->size--;
	printf("Done...\n");
}

//���ͨѶ¼
void emptyContact(contact_p c)
{
	assert(c);

	//ֱ�ӽ���ǰ��С��0
	c->size = 0;
	printf("Done...\n");
}

//��ӡ��Ϣ
void showContact(contact_p c)
{
	int i = 0;

	assert(c);

	if(isContactEmpty(c)){
		printf("Contact is empty!\n");
		return ;
	}

	printf("\ntotal:%d\n", c->size);//��ӡ������

	//��ӡ��ϸ��Ϣ
	printf("------------------------------- contacts -------------------------------------\n");
	printf("| name      | sex  | age | phone           | adds                            |\n");
	printf("------------------------------------------------------------------------------\n");
	for(; i < c->size; i++){
		printf("| %-10s| %-5s| %-4d| %-16s| %-32s|\n",c->contactList[i].name, \
		c->contactList[i].sex,c->contactList[i].age, \
		c->contactList[i].phone,c->contactList[i].adds);
	}
	printf("------------------------------------------------------------------------------\n\n");
}
 
//������ʹ���ֲᣩ
void helpContact()
{
	printf("\n");
	printf("-----------------------------------  HELP  -----------------------------------\n");
	printf("| You could use this app store up some information about your friends.       |\n");
	printf("| 1��you can add information by choose ( 1 ).                                |\n");
	printf("| 2��you can delect someone by choose ( 2 ).                                 |\n");
	printf("| 3��you can search someone by choose ( 3 ).                                 |\n");
	printf("| 4��you can change some's information by choose ( 4 ).                      |\n");
	printf("| 5��you can show information list by choose ( 5 ).                          |\n");
	printf("| 6��you can empty all information by choose ( 6 ).                          |\n");
	printf("| 7��you can sort people by choose ( 7 ).                                    |\n");
	printf("------------------------------------------------------------------------------\n\n");
}



//���浽�ļ�
int fileStore(contact_p c)
{
	FILE *fp;
	int i = 0;

	assert(c);

	//���ļ�
	fp = fopen(FILE_NAME,"wb");
	if(NULL == fp){
		perror("fopen");
		return -1;
	}

	//һ�δ���һ���˴�С������
	for(; i<c->size; i++){
		fwrite(c->contactList+i, sizeof(person_t), 1, fp);
	}

	fclose(fp);

	return 0;
}

//�ݻ�ͨѶ¼
void destroyContact(contact_p c)
{
	assert(c);

	fileStore(c);
	free(c->contactList);//�ͷų���
	c->contactList = NULL;
	free(c);//�ͷ�����
	c = NULL;
}

//�˳�
void exitContact(contact_p c)
{
	int n = 0;
	printf("\nAre you sure quit ?\n");
	while(1)
	{
		printf("----------------\n");
		printf("| 1.YES | 2.NO |\n");
		printf("----------------\n");

		scanf("%d", &n);
		if( 1 == n)
		{
			destroyContact(c);
			exit(0);
		}
		else if( 2 == n )
		{
			return;
		}
		else
		{
			printf("Error �� \n");
		}
	}
	
}