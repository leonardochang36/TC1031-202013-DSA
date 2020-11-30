#ifndef _LOG_H
#define _LOG_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

class Log
{
private:
    std::string date;
    std::string time;
    std::string src_ip;
    std::string src_port;
    std::string src_hostname;
    std::string dst_ip;
    std::string dst_port;
    std::string dst_hostname;

public:
    ~Log();
    Log();
    Log(std::string pdate,
        std::string ptime,
        std::string psrc_ip,
        std::string psrc_port,
        std::string psrc_hostname,
        std::string pdst_ip,
        std::string pdst_port,
        std::string pdst_hostname);

    std::string get_date() {return date;};
    std::string get_time() {return time;};
    std::string get_src_ip() {return src_ip;};
    std::string get_src_port() {return src_port;};
    std::string get_src_hostname() {return src_hostname;};
    std::string get_dst_ip() {return dst_ip;};
    std::string get_dst_port() {return dst_port;};
    std::string get_dst_hostname() {return dst_hostname;};

    void set_date(std::string val) {date = val;};
    void set_time(std::string val) {time = val;};
    void set_src_ip(std::string val) {src_ip = val;};
    void set_src_port(std::string val) {src_port = val;};
    void set_src_hostname(std::string val) {src_hostname = val;};
    void set_dst_ip(std::string val) {dst_ip = val;};
    void set_dst_port(std::string val) {dst_port = val;};
    void set_dst_hostname(std::string val) {dst_hostname = val;};

    static bool compare_src_hostname(Log &a, Log &b);

    static bool compare_equal_than(int &a, int &b);

    void print();   

};

#endif