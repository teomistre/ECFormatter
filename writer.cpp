#include "writer.h"

Writer::Writer(ZippedBufferPool &zippedBufferPool, const QString &fileName):
    zpPool_(zippedBufferPool)
{

}

void Writer::run()
{
    QPair<bool,ZippedBuffer> buffer;
    buffer = zpPool_.tryGet();
    while(buffer.first == true)
    {
        //A voir pour utiliser le QDataStream
    }
}
