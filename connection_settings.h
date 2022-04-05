#ifndef CONNECTION_SETTINGS_H
#define CONNECTION_SETTINGS_H

#include <QHostAddress>

namespace tcp_connection_settings {

    QHostAddress address = QHostAddress::Any;
    quint16 port = 3456;

}

#endif // CONNECTION_SETTINGS_H
