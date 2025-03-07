#ifndef QARCHIVE_IO_READER_PRIVATE_HPP_INCLUDED
#define QARCHIVE_IO_READER_PRIVATE_HPP_INCLUDED
#include <QIODevice>
#include <QObject>
#include <QtGlobal>

namespace QArchive {
class IOReaderPrivate {
  public:
    void setBlockSize(int);
    void setIODevice(QIODevice*);

    bool isOpen() const;
    bool isReadable() const;
    bool isSequential() const;

    qint64 read(char*);
    qint64 seek(qint64, /*whence=*/int);
    qint64 skip(qint64);
  private:
    qint64 n_FilePointerPos = 0;
    int n_BlockSize = 10204; /* Default. */
    QIODevice *m_IODevice = nullptr;
};
}  // namespace QArchive

#endif // QARCHIVE_IO_READER_PRIVATE_HPP_INCLUDED
