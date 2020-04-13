#pragma once
#include <dbus-c++-1/dbus-c++/dbus.h>
#include <cassert>

namespace org {
namespace freedesktop {
namespace DBus {

class EchoDemo_proxy
: public ::DBus::InterfaceProxy
{
public:

    EchoDemo_proxy()
    : ::DBus::InterfaceProxy("aaaaa.serreberus")
    {
        connect_signal(EchoDemo_proxy, Echoed, _Echoed_stub);
    }

public:

    /* properties exported by this interface */
public:

    /* methods exported by this interface,
     * this functions will invoke the corresponding methods on the remote objects
     */
    int32_t Random()
    {
        ::DBus::CallMessage call;
        call.member("Random");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        int32_t argout;
        ri >> argout;
        return argout;
    }

    std::string Hello(const std::string& name)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << name;
        call.member("Hello");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        std::string argout;
        ri >> argout;
        return argout;
    }

    ::DBus::Variant Echo(const ::DBus::Variant& input)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << input;
        call.member("Echo");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        ::DBus::Variant argout;
        ri >> argout;
        return argout;
    }

    std::vector< uint8_t > Cat(const std::string& file)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << file;
        call.member("Cat");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        std::vector< uint8_t > argout;
        ri >> argout;
        return argout;
    }

    int32_t Sum(const std::vector< int32_t >& ints)
    {
        ::DBus::CallMessage call;
        ::DBus::MessageIter wi = call.writer();

        wi << ints;
        call.member("Sum");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        int32_t argout;
        ri >> argout;
        return argout;
    }

    std::map< std::string, std::string > Info()
    {
        ::DBus::CallMessage call;
        call.member("Info");
        ::DBus::Message ret = invoke_method (call);
        ::DBus::MessageIter ri = ret.reader();

        std::map< std::string, std::string > argout;
        ri >> argout;
        return argout;
    }


public:

    /* signal handlers for this interface
     */
    virtual void Echoed(const ::DBus::Variant& value) = 0;

private:

    /* unmarshalers (to unpack the DBus message before calling the actual signal handler)
     */
    void _Echoed_stub(const ::DBus::SignalMessage &sig)
    {
        ::DBus::MessageIter ri = sig.reader();

        ::DBus::Variant value;
        ri >> value;
        Echoed(value);
    }
};

} } } 