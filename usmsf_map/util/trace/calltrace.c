

main()
{
    char     buf[256], command[256];

    printf("추적할 번호를 입력하시오 : ");
    gets(buf);
    sprintf(command, "%s %s", "trace", buf);
    system(command);
}

