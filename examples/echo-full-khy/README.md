*Description:

DBus est un bus de communication interprocessus.

L'utilisation standard de DBus est l'échange de donnée entre binaire par Méthodes et signaux partagés (glue.h).

*Guide d'utilisation:

1- il est nécessaire de changer dans tous les fichiers sources le chemin "PATH" par un chemin dans votre session

2- il faut recompiler le client ainsi que le server à l'aide de la commande:
 "g++ dbus_client -l dbus-c++-1 -o client" pour le client
 "g++ dbus_server -l dbus-c++-1 -o server" pour le server

3- lancer l'exécutable server puis le client

*nb: vérifiez que la "libdbus-c++-1" est présente.
(apt install libdbus-c++-1) 

