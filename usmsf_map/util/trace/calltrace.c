

main()
{
    char     buf[256], command[256];

    printf("������ ��ȣ�� �Է��Ͻÿ� : ");
    gets(buf);
    sprintf(command, "%s %s", "trace", buf);
    system(command);
}

