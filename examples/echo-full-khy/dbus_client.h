#pragma once
#include <dbus-c++-1/dbus-c++/dbus.h>
#include "dbus_glue.h"

class EchoClient
:  
	public org::freedesktop::DBus::EchoDemo_proxy,
	public DBus::IntrospectableProxy,
  	public DBus::ObjectProxy
{
public:

	EchoClient(DBus::Connection &connection, const char *path, const char *name);

	void Echoed(const DBus::Variant &value);

};
