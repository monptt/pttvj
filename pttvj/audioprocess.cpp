#include "audioprocess.h"
#include <QDebug>
#include <QAudioInput>
#include <QObject>
AudioProcess::AudioProcess(QObject *parent) : QObject(parent)
{
    QAudioFormat format;
    // Set up the desired format, for example:
    format.setSampleRate(44100);
    format.setChannelCount(2);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);


    this->input = new QAudioInput(format);
    QIODevice *in = this->input->start();
    QAudioInput::connect(in, SIGNAL(readyRead()), this, SLOT(test()));

    qDebug() << "audio start";
}

void AudioProcess::test(){
qDebug() << "test";
}
