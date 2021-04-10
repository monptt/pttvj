#include "audioprocess.h"
#include <QDebug>
#include <QAudioInput>
#include <QObject>
#include <QByteArray>
#include <algorithm>
AudioProcess::AudioProcess(QObject *parent) : QObject(parent)
{
    QAudioFormat format;
    // Set up the desired format, for example:
    format.setSampleRate(44100);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    this->input = new QAudioInput(format);
    this->inputDevice = this->input->start();
    QAudioInput::connect(this->inputDevice, SIGNAL(readyRead()), this, SLOT(readBuf()));

    qDebug() << "audio start";
}

void AudioProcess::readBuf(){
    QByteArray buf_byte = this->inputDevice->readAll();
    int N = buf_byte.size()/2;
    int16_t *buf = (int16_t *)buf_byte.data();
    int16_t M=0;
    for(int i=0; i<N; i++){
        M = std::max(M, buf[i]);
    }
}
