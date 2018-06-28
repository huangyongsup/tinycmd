#include"tinycmd.h"
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
#include<iostream>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

TinyCMD::TinyCMD()
{

}
TinyCMD::~TinyCMD()
{

}

bool TinyCMD::currentWorkDirectory()
{
    char cwd[PATH_SIZE];
    if(getcwd(cwd, sizeof(cwd)))
    {
        cout << cwd << "# ";
    }
    return true;
}

char** TinyCMD::replace(char *argv[])
  {
    for(int column = 0; argv[1][column] != '\0'; ++column)
    {
         if(argv[1][column] == '\\')
        {
            argv[1][column] = '/';
        }
    }
     if(argv[1][1] == ':')
     {
         for(int column = 2; argv[1][2] == '/'; ++column)
         {
            argv[1][column] = argv[1][column + 1];
         }
     }
     return argv;
}

void TinyCMD::execute(char *argv[])
{
    pid_t pid;
    if(pid = fork() == 0)
    {
        if(execvp(argv[0], argv) < 0)
        {
            cout << "failed error code:" << errno << endl;
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
    if(argc == 2)
    {
        execute(argv);
    }

}
//Copy file
void TinyCMD::_copy_(int argc, char *argv[])
{
    argv[0] = "cp";
    if(argc == 3)
    {
        execute(argv);
    }
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
    else
    {
        cout << "Too many parameters!";
    }
}
//Show date
void TinyCMD::_date_(int argc, char *argv[])
{
    if(argc == 1)
    {
        execute(argv);
    }
    else
    {
        cout << "Too many parameters! ";
    }
}

void TinyCMD::_del_(int argc, char *argv[])
{
    argv[0] = "rm";
    //if(argc == 2)
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
        if(!strcmp(argv[1],"/a"))
        {
            argv[1] = "-a";
            execute(argv);
        }
        else
        {
            cout << "Incorrent parameters! " << endl;
        }
    }
    if(argc > 2)
    {
        cout << "Too many parameters! ";
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
    else
    {
        cout<<"Too many parameters! ";
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
    if(argc == 1)
    {
        execute(argv);
    }
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
