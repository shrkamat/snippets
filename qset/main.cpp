#include <QDebug>
#include <QSet>
#include <qglobal.h>

#include <iostream>

class Key {
public:
    Key(int v): _v(v) {}
    int _v;

    bool operator==(const Key& rhs) const {
        return this->_v == rhs._v;
    }
};

uint qHash(const Key &key) {
    return key._v;
}

void print_qset( const std::string& prefix, const QSet<Key> keys)
{
    std::cout << prefix << ": [";

    foreach( const Key& key, keys) {
        std::cout << key._v << ", ";
    }

    std::cout << "]\n";
}

int main(int argc, const char** argv)
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    QSet<Key> currItems = {1, 2, 3, 4};

    QSet<Key> newItems = {3, 4, 5, 6};

    print_qset("orig    ", currItems);
    print_qset("new     ", newItems);
    print_qset("added   ", newItems - currItems);
    print_qset("removed ", currItems - newItems);

    return 0;
}
