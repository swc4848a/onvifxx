#ifndef ONVIFXX_H
#define ONVIFXX_H

#include <memory>
#include <vector>
#include <string>

#define UNUSED(x) (void)x

struct soap;

namespace onvifxx {


static const std::string WSDD_URL = "soap.udp://239.255.255.250:3702";

class Exception : public std::exception
{
public:
    Exception();
    Exception(const char * msg);
    virtual const char* what() const noexcept;

protected:
    std::string & message();

private:
    std::string msg_;

};

class SoapException : public Exception
{
public:
    SoapException(soap * s);

    int code() const;

private:
    int code_;
};

class UnixException : public Exception
{
public:
    UnixException(int code = 0);

    int code() const;

private:
    int code_;
};


template<class T>
std::unique_ptr<T> proxy();

//template<class T>
//class Pimpl
//{
//public:
//    Pimpl() : p_(new T) { }
//    T * impl() { return p_.get(); }
//private:
//    std::shared_ptr<T> p_;
//};

} // namespace onvifxx

#endif //ONVIFXX_H
