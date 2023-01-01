//function for login
void login(void);
void login(void)
{
	char nam1[15],nam2[15];
	int pass;
	printf("ENTER YOUR NAME |>");
	scanf(" %s%s", nam1,nam2);
	printf("HI %s %s\n", nam1,nam2);
	printf("NOW GIVE YOUR PASWORD |>");
	do{
		scanf("%d", &pass);
		while(pass != 987){
            printf("WRONG PASSWORD\n GIVE IT AGAIN|>");
            break;
		}
	} while (pass != 987);
}
