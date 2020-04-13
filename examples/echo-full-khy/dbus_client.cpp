
#include "dbus_client.h"
#include <cstdio>
#include <iostream>
#include <signal.h>

using namespace std;

static const char *ECHO_SERVER_NAME = "aaaaa.serreberus";
static const char *ECHO_SERVER_PATH = "/home/keny/Bureau";

EchoClient::EchoClient(DBus::Connection &connection, const char *path, const char *name)
: DBus::ObjectProxy(connection, path, name)
{
}

void EchoClient::Echoed(const DBus::Variant &value)
{
	cout << "!";
}

DBus::BusDispatcher dispatcher;

int main()
{
	DBus::default_dispatcher = &dispatcher;

	DBus::Connection conn = DBus::Connection::SessionBus();

	EchoClient client(conn, ECHO_SERVER_PATH, ECHO_SERVER_NAME);

        cout << client.Random() << endl;
        cout << client.Hello("Hello") << endl;
        try
        {
          client.Cat("foobar");
        }
        catch(DBus::Error &e)
        {
          cout << "Caught error: " << e.name() << endl
               << "\t" << e.message() << endl;
        }
	client.Cat("/etc/hosts");

	return 0;
}
