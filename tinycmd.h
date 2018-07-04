#ifndef TINYCMDH
#define TINYCMDH

const int PATH_SIZE = 256;

class TinyCMD
{
public:
    TinyCMD();
    ~TinyCMD();    
    char cwd[PATH_SIZE];
    void _cd_(int argc, char *argv[]);
    void _copy_(int argc, char *argv[]);
    void _chdir_(int argc, char *argv[]);
    void _cls_(int argc, char *argv[]);
    void _date_(int argc, char *argv[]);
    void _del_(int argc, char *argv[]);
    void _dir_(int argc, char *argv[]);
    void _echo_(int argc, char *argv[]);
    void _edit_(int argc, char *argv[]);
    void _exit_(int argc, char *argv[]);
    void _fc_(int argc, char *argv[]);
    void _find_(int argc, char *argv[]);
    void _ipconfig_(int argc, char *argv[]);
    void _net_re_start_stop_(int argc, char *argv[]);
    void _mem_(int argc, char *argv[]);
    void _move_(int argc, char *argv[]);
    void _mkdir_(int argc, char *argv[]);
    void _more_(int argc, char *argv[]);
    void _netstat_(int argc, char *argv[]);
    void _nslookup_(int argc, char *argv[]);
    void _ping_(int argc, char *argv[]);
    void _ren_(int argc, char *argv[]);
    void _tracert_(int argc, char *argv[]);
    void _vim_(int argc, char *argv[]);
private:    
    char homeDirectory[PATH_SIZE];
    void execute(char *argv[]);
    char *stringCopy(char *dst, const char *src);
};

#endif // TINYCMDH
