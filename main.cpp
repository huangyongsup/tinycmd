#include<iostream>
#include"tinycmd.h"
#include"mystring.h"
#include<string.h>
#include<unistd.h>

using namespace std;

const int ARGV_SIZE = 32;
const int CMD_SIZE = 256;

TinyCMD tinycmd;
MyString mystring;

bool currentWorkDirectory()
{
    if(getcwd(tinycmd.cwd, sizeof(tinycmd.cwd)))
    {
        cout <<"huangyong@Ubuntu:" << tinycmd.cwd << "# ";
    }
    return true;
}

int main()
{
    char cmd[CMD_SIZE];
    while(currentWorkDirectory() && cin.getline(cmd, CMD_SIZE))
    {
        if(mystring.stringLength(cmd))
        {
            int argc = 0;
            char *argv[ARGV_SIZE];
            argv[argc] = strtok(cmd, " ");
            while(argv[argc])
            {
                ++argc;
                argv[argc] = strtok(NULL, " ");
            }
                if(!mystring.stringCompara(argv[0], "cd"))
                    tinycmd._cd_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "copy"))
                    tinycmd._copy_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "chdir"))
                    tinycmd._chdir_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "cls"))
                    tinycmd._cls_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "date"))
                    tinycmd._date_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "del"))
                    tinycmd._del_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "dir"))
                    tinycmd._dir_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "echo"))
                    tinycmd._echo_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "edit"))
                    tinycmd._edit_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "exit"))
                    tinycmd._exit_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "fc"))
                    tinycmd._fc_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "find"))
                    tinycmd._find_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "ipconfig"))
                    tinycmd._ipconfig_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "net") && !mystring.stringCompara(argv[1], "start"))
                        tinycmd._net_re_start_stop_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "net") && !mystring.stringCompara(argv[1], "restart"))
                        tinycmd._net_re_start_stop_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "net") && !mystring.stringCompara(argv[1], "stop"))
                        tinycmd._net_re_start_stop_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "mem"))
                    tinycmd._mem_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "move"))
                    tinycmd._move_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "mkdir"))
                    tinycmd._mkdir_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "more"))
                    tinycmd._more_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "netstat"))
                    tinycmd._netstat_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "nslookup"))
                    tinycmd._nslookup_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "ping"))
                    tinycmd._ping_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "ren"))
                    tinycmd._ren_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "tracert"))
                    tinycmd._tracert_(argc, argv);
                else if(!mystring.stringCompara(argv[0], "vim"))
                    tinycmd._vim_(argc, argv);
                else
                    cout << "No such command! \n";
            }
        }
    return 0;
}
