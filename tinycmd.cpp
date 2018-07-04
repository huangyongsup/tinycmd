#include"tinycmd.h"
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include"mystring.h"

MyString mystr;

TinyCMD::TinyCMD()
{

}
TinyCMD::~TinyCMD()
{

}

void TinyCMD::execute(char *argv[])
{
    pid_t pid = fork();
    if(pid == 0)
    {
        if(execvp(argv[0], argv) < 0)
        {
            exit(1);
        }
    }
    else
    {
        int status;
        wait(&status);
    }
}

void TinyCMD::_cd_(int argc, char *argv[])
{
    if(argc == 1)
    {
        mystr.stringCopy(TinyCMD::cwd, "~");
        chdir(TinyCMD::cwd);
    }
    else if(argc == 2)
    {
        mystr.stringCopy(TinyCMD::cwd, argv[1]);
        chdir(TinyCMD::cwd);
    }

}
//Copy file
void TinyCMD::_copy_(int argc, char *argv[])
{
    argv[0] = "cp";
    execute(argv);
}

void TinyCMD::_chdir_(int argc, char *argv[])
{
    argv[0] = "pwd";
    if(argc == 1)
    {
        execute(argv);
    }
}
//Clear screen
void TinyCMD::_cls_(int argc, char *argv[])
{
    argv[0] = "clear";
    if(argc == 1)
    {
        execute(argv);
    }
}
//Show date
void TinyCMD::_date_(int argc, char *argv[])
{
    if(argc == 1)
    {
        execute(argv);
    }
}

void TinyCMD::_del_(int argc, char *argv[])
{
    argv[0] = "rm";
    if(argc == 2)
    {
        execute(argv);
    }
}
//Execute the Windows command 'dir' which can own a parameter like '/a'
void TinyCMD::_dir_(int argc, char *argv[])
{
    argv[0] = "ls";
    if(argc == 1)
    {
        execute(argv);
    }
    if(argc == 2)
    {
        if(!mystr.stringCompara(argv[1],"/a"))
        {
            argv[1] = "-a";
            execute(argv);
        }
    }
}

void TinyCMD::_echo_(int argc, char *argv[])
{
    if(argc == 2)
    {
        execute(argv);
    }
}

void TinyCMD::_edit_(int argc, char *argv[])
{
    argv[0] = "pico";
    if(argc == 2)
    {
        execute(argv);
    }
}
//Exit shell
void TinyCMD::_exit_(int argc, char *argv[])
{
    if(argc == 1)
    {
        exit(0);
    }
}
//List the differences between two file's content
void TinyCMD::_fc_(int argc, char *argv[])
{
    argv[0] = "diff";
    if(argc == 3)
    {
        execute(argv);
    }
}
//Find string in file
void TinyCMD::_find_(int argc, char *argv[])
{
    argv[0] = "grep";
    if(argc == 3)
    {
        execute(argv);
    }
}

void TinyCMD::_ipconfig_(int argc, char *argv[])
{
    argv[0] = "ifconfig";
        execute(argv);
}

void TinyCMD::_net_re_start_stop_(int argc, char *argv[])
{
    if(argc == 3)
    {
        char *temp = argv[1];
        argv[0] = "service";
        argv[1] = argv[3];
        argv[2] = temp;
        execute(argv);
    }
}

void TinyCMD::_mem_(int argc, char *argv[])
{
    argv[0] = "free";
    execute(argv);
}

void TinyCMD::_move_(int argc, char *argv[])
{
    argv[0] = "mv";
    if(argc == 3)
    {
        execute(argv);
    }
}

void TinyCMD::_mkdir_(int argc, char *argv[])
{
    execute(argv);
}

void TinyCMD::_more_(int argc, char *argv[])
{
    execute(argv);
}

void TinyCMD::_netstat_(int argc, char *argv[])
{
    execute(argv);
}

void TinyCMD::_nslookup_(int argc, char *argv[])
{
    argv[0] = "host";
    execute(argv);
}

void TinyCMD::_ping_(int argc, char *argv[])
{
    execute(argv);
}

void TinyCMD::_ren_(int argc, char *argv[])
{
    argv[0] = "mv";
    if(argc == 3)
    {
        execute(argv);
    }
}

void TinyCMD::_tracert_(int argc, char *argv[])
{
    argv[0] = "traceroute";
    execute(argv);
}

void TinyCMD::_vim_(int argc, char *argv[])
{
        execute(argv);
}
