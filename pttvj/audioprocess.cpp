#include "audioprocess.h"
#include <QDebug>
#include <QAudioInput>
#include <QObject>
#include <QByteArray>
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
    this->inputDevice = this->input->start();
    QAudioInput::connect(this->inputDevice, SIGNAL(readyRead()), this, SLOT(readBuf()));

    qDebug() << "audio start";
}

void AudioProcess::readBuf(){

QByteArray buf = this->inputDevice->readAll();

}
