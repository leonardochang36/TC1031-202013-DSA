#include "log.h"

using namespace std;

Log::~Log()
{}

Log::Log()
{
    date = "";
    time = "";
    src_ip = "";
    src_port = "";
    src_hostname = "";
    dst_ip = "";
    dst_port = "";
    dst_hostname = "";
}

Log::Log(std::string pdate,
        std::string ptime,
        std::string psrc_ip,
        std::string psrc_port,
        std::string psrc_hostname,
        std::string pdst_ip,
        std::string pdst_port,
        std::string pdst_hostname)
{
    date = pdate;
    time = ptime;
    src_ip = psrc_ip;
    src_port = psrc_port;
    src_hostname = psrc_hostname;
    dst_ip = pdst_ip;
    dst_port = pdst_port;
    dst_hostname = pdst_hostname;
}

void Log::print()
{
    cout << date << ", ";
    cout << time << ", ";
    cout << src_ip << ", ";
    cout << src_port << ", ";
    cout << src_hostname << ", ";
    cout << dst_ip << ", ";
    cout << dst_port << ", ";
    cout << dst_hostname << endl;
}

bool Log::compare_src_hostname(Log &a, Log &b)
{
    stringstream ssa(a.get_src_hostname());
    string h1, h2;
    getline(ssa, h1, '.');
    stringstream ssb(b.get_src_hostname());
    getline(ssb, h2, '.');
    
    return h1 == h2;
}

bool Log::compare_equal_than(int &a, int &b)
{
    return a == b;
}

