#ifndef AUDIOPROCESS_H
#define AUDIOPROCESS_H

#include <QObject>
#include<QAudioInput>
class AudioProcess : public QObject
{
    Q_OBJECT
public:
    explicit AudioProcess(QObject *parent = nullptr);
    QAudioInput *input;

signals:

public slots:
    void test();
};

#endif // AUDIOPROCESS_H
