#include"head.h" 
int query_precode(int code,int *precode)
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char* server="localhost";
	char* user="root";
	char* password="fengdou";
	char* database="test25";//要访问的数据库名称
	char query[300]={0};
	strcpy(query,"select * from vdir where code=");
	sprintf(query,"%s%d",query,code);
	int t;
	conn=mysql_init(NULL);
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
	{
		printf("Error connecting to database:%s\n",mysql_error(conn));
		return -1;
	}
	t=mysql_query(conn,query);
	if(t)
	{
		printf("Error making query:%s\n",mysql_error(conn));
		return -1;
	}else{
		//	printf("Query made...\n");
		res=mysql_use_result(conn);
		if(res)
		{
			row=mysql_fetch_row(res);
			*precode=atoi(row[1]);
		}
		mysql_free_result(res);
	}
	mysql_close(conn);
	return 0;
}
